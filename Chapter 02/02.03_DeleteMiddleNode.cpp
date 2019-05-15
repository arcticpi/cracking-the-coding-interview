// Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node,
// not necessarily the exact middle) of a singly linked list, given only access to that node.

#include "LinkedList.hpp"

int main()
{
    LinkedList<int> list;
    ListNode<int> *node;

    for (int i = 0; i < 5; i++)
    {
        list.append(1 + rand() % 5);
    }

    list.show();

    /*
    for (int i = 0; i < 5; i++)
    {
        node = list.GetKthNode(i);
        std::cout << "list.GetKthNode(" << i << ") = " << (node != nullptr ? node->data : -1) << std::endl;
    }
    */

    list.DeleteMiddleNode(list.GetKthNode(3));

    list.show();

    return 0;
}