// Write code to remove duplicates from an unsorted linked list.
// How would you solve this problem if a temporary buffer is not allowed?

#include "LinkedList.hpp"

int main()
{
    LinkedList<int> list;

    for (int i = 0; i < 10; i++)
    {
        list.append(1 + rand() % 5);
    }

    list.show();

    list.RemoveDups2();

    list.show();

    return 0;
}