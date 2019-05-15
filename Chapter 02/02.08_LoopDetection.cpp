// Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

#include "LinkedList.hpp"

int main()
{
    LinkedList<int> l1;

    for (int i = 1; i < 6; i++)
    {
        l1.append(i);
    }

    l1.show();
    l1.LoopDetection();

    auto LoopStart = l1.head;
    LoopStart = LoopStart->next->next;

    auto LastNode = l1.head;
    while (LastNode->next != nullptr)
    {
        LastNode = LastNode->next;
    }

    LastNode->next = LoopStart;

    l1.show();
    auto ptr = l1.LoopDetection();

    if (ptr != nullptr)
    {
        std::cout << "loop starts at node " << ptr->data << std::endl;
    }
    else
    {
        std::cout << "no loop" << std::endl;
    }

    return 0;
}