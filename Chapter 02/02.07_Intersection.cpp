// Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node.
// Note that the intersection is defined based on reference, not value. That is,
// if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list,
// then they are intersecting.

#include "LinkedList.hpp"

int main()
{
    LinkedList<int> l1;
    LinkedList<int> l2;

    for (int i = 1; i < 6; i++)
    {
        l1.append(i);
    }

    l1.show();

    for (int i = 6; i < 9; i++)
    {
        l2.append(i);
    }

    // l2.show();

    auto ptr = l1.head;
    ptr = ptr->next->next;

    l2.append(ptr);

    l2.show();

    std::cout << LinkedList<int>::intersection(&l1, &l2)->data << std::endl;

    return 0;
}