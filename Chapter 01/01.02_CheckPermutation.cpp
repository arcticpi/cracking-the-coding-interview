// Given two strings, write a method to decide if one is a permutation of the other.

#include <iostream>
#include <algorithm>
#include <array>

// O(n log n)

bool CheckPermutation1(std::string s1, std::string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    return s1 == s2;
}

// O(n)

bool CheckPermutation2(std::string s1, std::string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    
    std::array<int, 128> ascii = {};

    for (char c : s1)
    {
        ascii[c] += 1;
    }

    for (char c : s2)
    {
        ascii[c] -= 1;

        if (ascii[c] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string s1 = "abcde";
    std::string s2 = "abdec";
    std::string s3 = "abdef";
    
    std::cout << s1 << " , " << s2 << " : " << CheckPermutation2(s1, s2) << std::endl;
    std::cout << s1 << " , " << s3 << " : " << CheckPermutation2(s1, s3) << std::endl;

    return 0;
}