// You have two numbers represented by a linked list, where each node contains a single digit.
// The digits are stored in reverse order, such that the 1 's digit is at the head of the list.
// Write a function that adds the two numbers and returns the sum as a linked list.
// FOLLOW UP : Suppose the digits are stored in forward order. Repeat the above problem.

#include "LinkedList.hpp"

int main()
{
    LinkedList<int> l1;
    // l1.append(7);
    // l1.append(1);
    // l1.append(6);
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.append(4);

    LinkedList<int> l2;
    // l2.append(5);
    // l2.append(9);
    // l2.append(2);
    l2.append(5);
    l2.append(6);
    l2.append(7);

    // l1.show();
    // l2.show();

    LinkedList<int> list;
    list.SumLists2(&l1, &l2);
    list.show();

    return 0;
}