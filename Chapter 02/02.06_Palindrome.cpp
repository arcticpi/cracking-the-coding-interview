// Implement a function to check if a linked list is a palindrome.

#include "LinkedList.hpp"

int main()
{
    LinkedList<int> list;
    
    // list.append(6);

    for (int i = 1; i < 6; i++)
    {
        list.append(i);
    }

    // list.append(6);
    // list.append(7);
    // list.append(6);

    for (int i = 5; i > 0; i--)
    {
        list.append(i);
    }

    // list.append(0);

    list.show();

    std::cout << list.palindrome() << std::endl;

    return 0;
}