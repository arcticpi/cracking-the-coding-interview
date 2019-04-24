// Write a method to replace all spaces in a string with '%20'.
// You may assume that the string has sufficient space at the end to hold the additional characters,
// and that you are given the "true" length of the string.

#include <iostream>

// O(n^2)

std::string URLify1(std::string string, int length)
{
    int k = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        if (string[i] == ' ')
        {
            k++;

            for (int j = length - 1 + k * 2; j > i; j--)
            {
                string[j] = string[j - 2];
            }

            string[i + 0] = '%';
            string[i + 1] = '2';
            string[i + 2] = '0';
        }
    }

    return string;
}

// O(n)

std::string URLify2(std::string string, int length)
{
    int k = 0; // number of spaces

    for (int i = 0; i < length; i++)
    {
        if (string[i] == ' ')
        {
            k++;
        }
    }

    int i = length - 1 + k * 2;

    for (int j = length - 1; j >= 0; j--)
    {
        if (string[j] == ' ')
        {
            string[i - 0] = '0';
            string[i - 1] = '2';
            string[i - 2] = '%';
            i -= 3;
        }
        else
        {
            string[i] = string[j];
            i -= 1;
        }
    }

    return string;
}

int main()
{
    std::cout << "Mr John Smith    " << " -> " << URLify1("Mr John Smith    ", 13) << std::endl;
    std::cout << "Mr John Smith    " << " -> " << URLify2("Mr John Smith    ", 13) << std::endl;
    return 0;
}