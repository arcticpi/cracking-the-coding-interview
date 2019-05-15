#include <iostream>
#include <set>

template <typename T>
class ListNode
{
public:
    T data;
    ListNode *next;
};

template <typename T>
class LinkedList
{
public:
    ListNode<T> *head = nullptr;
    void insert(T data);
    void append(T data);
    void remove(T data);
    void show();
    void RemoveDups1();
    void RemoveDups2(); // without a temporary buffer
    void KthToLast1(int index); // O(n^2)
    void KthToLast2(int index); // O(n) time & O(1) space
    ListNode<T> *GetKthNode(int k);
    void DeleteMiddleNode(ListNode<T> *node);
    LinkedList<T> &operator=(const LinkedList<T> &other);
    void append(ListNode<T> *node);
    void Partition(T value);
    // void SumLists1(const LinkedList<T> &l1, const LinkedList<T> &l2); // reverse order
    void SumLists1(LinkedList<T> *l1, LinkedList<T> *l2);
    int length();
    void padding(int nodes);
    // void ForwardOrder(ListNode<T> *p1, ListNode<T> *p2);
    // void SumLists2(const LinkedList<T> &l1, const LinkedList<T> &l2); // forward order
    void SumLists2(LinkedList<T> *l1, LinkedList<T> *l2);
    bool palindrome();
    static ListNode<T> *intersection(LinkedList<T> *l1, LinkedList<T> *l2);
    ListNode<T> *LoopDetection();
};

template <typename T>
void LinkedList<T>::insert(T data)
{
    ListNode<T> *node = new ListNode<T>();
    node->data = data;
    node->next = head;

    head = node;
}

template <typename T>
void LinkedList<T>::append(T data)
{
    ListNode<T> *node = new ListNode<T>();
    node->data = data;
    node->next = nullptr;

    if (head == nullptr)
    {
        head = node;
        return;
    }

    ListNode<T> *ptr = head;

    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }

    ptr->next = node;
}

template <typename T>
void LinkedList<T>::remove(T data)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->data == data)
    {
        ListNode<T> *node = head;
        head = head->next;
        delete node;
        return;
    }

    ListNode<T> *ptr = head;

    while (ptr->next != nullptr)
    {
        if (ptr->next->data == data)
        {
            ListNode<T> *node = ptr->next;
            ptr->next = node->next;
            delete node;
            return;
        }

        ptr = ptr->next;
    }
}

template <typename T>
void LinkedList<T>::show()
{
    if (head == nullptr)
    {
        std::cout << "list empty" << std::endl;
        return;
    }

    ListNode<T> *ptr = head;

    if (LoopDetection() != nullptr)
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << ptr->data << " -> ";
            ptr = ptr->next;
        }

        std::cout << "..." << std::endl;
        return;
    }

    while (ptr != nullptr)
    {
        std::cout << ptr->data;
        ptr = ptr->next;

        if (ptr != nullptr)
        {
            std::cout << " -> ";
        }
        else
        {
            std::cout << std::endl;
        }
    }
}

template <typename T>
void LinkedList<T>::RemoveDups1()
{
    std::set<T> set;

    ListNode<T> *ptr = head;
    ListNode<T> *prev = nullptr;

    while (ptr != nullptr)
    {
        if (set.find(ptr->data) != set.end())
        {
            prev->next = ptr->next;

            delete ptr;
            ptr = nullptr;
        }
        else
        {
            set.insert(ptr->data);
            prev = ptr;
        }

        // ptr = ptr->next;
        ptr = ptr != nullptr ? ptr->next : prev->next;
    }
}

template <typename T>
void LinkedList<T>::RemoveDups2()
{
    ListNode<T> *ptr = head;

    while (ptr != nullptr)
    {
        ListNode<T> *runner = ptr->next;
        ListNode<T> *prev = ptr;

        while (runner != nullptr)
        {
            if (runner->data == ptr->data)
            {
                prev->next = runner->next;

                delete runner;
                runner = nullptr;
            }
            else
            {
                prev = runner;
            }

            // runner = runner->next;
            runner = runner != nullptr ? runner->next : prev->next;
        }

        ptr = ptr->next;
    }
}

template <typename T>
void LinkedList<T>::KthToLast1(int index)
{
    if (index < 1)
    {
        std::cout << "KthToLast(index) : index must be positive" << std::endl;
        return;
    }

    ListNode<T> *ptr = head;
    int n = 0;

    while (ptr != nullptr)
    {
        n += 1;
        ptr = ptr->next;
    }

    // std::cout << n << std::endl;

    index = n - index + 1;

    if (index < 1)
    {
        std::cout << "KthToLast(index) : index must be between 1 and list size" << std::endl;
        return;
    }

    ptr = head;

    while (ptr != nullptr)
    {
        if (index == 1)
        {
            std::cout << ptr->data << std::endl;
            return;
        }
        else
        {
            index -= 1;
        }

        ptr = ptr->next;
    }
}

template <typename T>
void LinkedList<T>::KthToLast2(int index)
{
    if (index < 1)
    {
        std::cout << "KthToLast(index) : index must be positive" << std::endl;
        return;
    }

    ListNode<T> *p1 = head;
    ListNode<T> *p2 = head;

    while (p1 != nullptr && index > 0)
    {
        p1 = p1->next;
        index -= 1;
    }

    if (index > 0)
    {
        std::cout << "KthToLast(index) : index must be between 1 and list size" << std::endl;
        return;
    }

    while (p1 != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    std::cout << p2->data << std::endl;
}

template <typename T>
ListNode<T> *LinkedList<T>::GetKthNode(int k)
{
    ListNode<T> *ptr = head;

    while (ptr != nullptr && k > 0)
    {
        ptr = ptr->next;
        k -= 1;
    }

    return ptr;
}

template <typename T>
void LinkedList<T>::DeleteMiddleNode(ListNode<T> *node)
{
    if (node != nullptr)
    {
        // delete node;
        *node = *(node->next);
    }
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
    head = other.head;
    return *this;
}

template <typename T>
void LinkedList<T>::append(ListNode<T> *node)
{
    if (head == nullptr)
    {
        head = node;
        return;
    }

    ListNode<T> *ptr = head;

    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }

    ptr->next = node;
}

template <typename T>
void LinkedList<T>::Partition(T value)
{
    LinkedList<T> left;
    LinkedList<T> right;

    ListNode<T> *ptr = head;

    while (ptr != nullptr)
    {
        if (ptr->data < value)
        {
            left.append(ptr->data);
        }
        else
        {
            right.append(ptr->data);
        }

        ptr = ptr->next;
    }

    *this = left;
    append(right.head);
}

template <typename T>
// void LinkedList<T>::SumLists1(const LinkedList<T> &l1, const LinkedList<T> &l2)
void LinkedList<T>::SumLists1(LinkedList<T> *l1, LinkedList<T> *l2)
{
    ListNode<T> *p1 = l1->head;
    ListNode<T> *p2 = l2->head;

    int carry = 0;

    while (p1 != nullptr && p2 != nullptr)
    {
        int sum = p1->data + p2->data + carry;
        append(sum % 10);
        carry = sum >= 10 ? 1 : 0;

        p1 = p1->next;
        p2 = p2->next;
    }

    while (p1 != nullptr)
    {
        int sum = p1->data + carry;
        append(sum % 10);
        carry = sum >= 10 ? 1 : 0;

        p1 = p1->next;
    }

    while (p2 != nullptr)
    {
        int sum = p2->data + carry;
        append(sum % 10);
        carry = sum >= 10 ? 1 : 0;

        p2 = p2->next;
    }

    if (carry == 1)
    {
        append(1);
    }
}

template <typename T>
int LinkedList<T>::length()
{
    ListNode<T> *ptr = head;
    int len = 0;

    while (ptr != nullptr)
    {
        len += 1;
        ptr = ptr->next;
    }

    return len;
}

template <typename T>
void LinkedList<T>::padding(int nodes)
{
    while (nodes > 0)
    {
        insert(0);
        nodes -= 1;
    }
}

template <typename T>
// void LinkedList<T>::SumLists2(const LinkedList<T> &l1, const LinkedList<T> &l2)
void LinkedList<T>::SumLists2(LinkedList<T> *l1, LinkedList<T> *l2)
{
    int len1 = l1->length();
    int len2 = l2->length();

    if (len1 < len2)
    {
        l1->padding(len2 - len1);
    }
    else
    {
        l2->padding(len1 - len2);
    }

    l1->show();
    l2->show();
}

template <typename T>
bool LinkedList<T>::palindrome()
{
    int n = length();

    if (n <= 1)
    {
        return true;
    }

    LinkedList<T> list;
    ListNode<T> *p1 = head;

    // std::cout << n / 2 << std::endl;

    int i = 0;

    for (; i < n / 2; i++)
    {
        list.insert(p1->data);
        p1 = p1->next;
    }

    // list.show();

    // p1 = p1->next;

    if (n % 2 == 1)
    {
        i += 1;
        p1 = p1->next;
    }

    ListNode<T> *p2 = list.head;

    for (; i < n; i++)
    {
        // std::cout << i << " " << p1->data << " " << p2->data << " " << std::endl;

        if (p1->data != p2->data)
        {
            return false;
        }

        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

template <typename T>
ListNode<T> *LinkedList<T>::intersection(LinkedList<T> *l1, LinkedList<T> *l2)
{
    ListNode<T> *p1 = l1->head;
    ListNode<T> *p2 = l2->head;

    if (p1 == nullptr || p2 == nullptr)
    {
        return nullptr;
    }

    int a = 1;
    int b = 1;

    while (p1->next != nullptr || p2->next != nullptr)
    {
        if (p1->next != nullptr)
        {
            p1 = p1->next;
            a += 1;
        }

        if (p2->next != nullptr)
        {
            p2 = p2->next;
            b += 1;
        }
    }

    std::cout << a << " " << b << std::endl;

    if (p1 != p2)
    {
        return nullptr;
    }

    // int padding = abs(a - b);

    p1 = l1->head;
    p2 = l2->head;

    while (a < b)
    {
        p2 = p2->next;
        a += 1;
    }

    while (b < a)
    {
        p1 = p1->next;
        b += 1;
    }

    while (p1->next != nullptr || p2->next != nullptr)
    {
        if (p1 == p2)
        {
            break;
        }

        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

template <typename T>
ListNode<T> *LinkedList<T>::LoopDetection()
{
    ListNode<T> *SlowRunner = head;
    ListNode<T> *FastRunner = head;

    while (FastRunner != nullptr)
    {
        SlowRunner = SlowRunner->next;
        FastRunner = (FastRunner->next != nullptr) ? FastRunner->next->next : nullptr;

        if (SlowRunner == FastRunner)
        {
            break;
        }
    }

    if (FastRunner == nullptr)
    {
        // no loop
        // std::cout << "no loop" << std::endl;
        return nullptr;
    }

    // std::cout << "collision point : " << SlowRunner->data << std::endl;

    SlowRunner = head;

    while (FastRunner != nullptr)
    {
        SlowRunner = SlowRunner->next;
        FastRunner = FastRunner->next;

        if (SlowRunner == FastRunner)
        {
            break;
        }
    }

    return SlowRunner;
}
