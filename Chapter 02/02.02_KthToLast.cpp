// Implement an algorithm to find the kth to last element of a singly linked list.

#include "LinkedList.hpp"

int main()
{
    LinkedList<int> list;

    for (int i = 0; i < 5; i++)
    {
        list.append(1 + rand() % 5);
    }

    list.show();

    for (int i = -1; i < 7; i++)
    {
        list.KthToLast2(i);
    }

    return 0;
}