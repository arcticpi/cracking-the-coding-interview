#include <iostream>

class ListNodeInt
{
  public:
    int data;
    ListNodeInt *next;
};

class LinkedListInt
{
    ListNodeInt *head = nullptr;

  public:
    void show();

    void add(int data);
    void remove(int data);
};

void LinkedListInt::show()
{
    ListNodeInt *ptr = head;

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

void LinkedListInt::add(int data)
{
    ListNodeInt *node = new ListNodeInt();
    node->data = data;
    node->next = head;

    head = node;
}