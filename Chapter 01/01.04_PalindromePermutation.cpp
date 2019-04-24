// Given a string, write a function to check if it is a permutation of a palindrome.
// A palindrome is a word or phrase that is the same forwards and backwards.
// A permutation is a rearrangement of letters.
// The palindrome does not need to be limited to just dictionary words.
// You can ignore casing and non-letter characters.

#include <iostream>

bool PalindromePermutation(std::string string)
{
    char letters[26] = {};
    int n = string.length();

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        char c = string[i];

        if ('a' <= c && c <= 'z')
        {
            letters[c - 'a'] += 1;
            k += 1;
        }
        
        if ('A' <= c && c <= 'Z')
        {
            letters[c - 'A'] += 1;
            k += 1;
        }
    }

    if (k % 2 == 0)
    {
        for (int i = 0; i < 26; i++)
        {
            if (letters[i] % 2 != 0)
            {
                return false;
            }
        }
    }
    else
    {
        bool flag = false;

        for (int i = 0; i < 26; i++)
        {
            if (letters[i] % 2 == 1 && flag == false)
            {
                flag = true;
            }
            else if (letters[i] % 2 == 1 && flag == true)
            {
                return false;
            }
            else if (letters[i] % 2 != 0)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    std::cout << "Tact Coa" << " -> " << PalindromePermutation("Tact Coa") << std::endl;
    std::cout << "Tact Cxa" << " -> " << PalindromePermutation("Tact Cxa") << std::endl;
    std::cout << "Tact Zoa" << " -> " << PalindromePermutation("Tact Zoa") << std::endl;
    std::cout << "Tact Coa " << " -> " << PalindromePermutation("Tact Coa ") << std::endl;
    std::cout << "Tact CoaO" << " -> " << PalindromePermutation("Tact CoaO") << std::endl;
    return 0;
}