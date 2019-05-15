// Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If xis contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.

#include "LinkedList.hpp"

int main()
{
    LinkedList<int> list;

    for (int i = 0; i < 10; i++)
    {
        list.append(1 + rand() % 9);
    }

    list.show();

    list.Partition(5);

    list.show();

    return 0;
}