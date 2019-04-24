// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

#include <iostream>
#include <map>

// O(n^2) : without using additional data structures

bool IsUnique1(std::string string)
{
    int n = string.length();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (string[i] == string[j])
            {
                return false;
            }
        }
    }

    return true;
}

// O(n) time, O(n) space

bool IsUnique2(std::string string)
{
    std::map<char, int> map;

    for (char c : string)
    {
        if (++map[c] > 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::cout << "abcde is unique? " << IsUnique2("abcde") << std::endl;
    std::cout << "abcda is unique? " << IsUnique2("abcda") << std::endl;
    return 0;
}