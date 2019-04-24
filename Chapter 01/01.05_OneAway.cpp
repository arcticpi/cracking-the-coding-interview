// There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

#include <iostream>
#include <array>
#include <map>
// #include <utility>

bool OneAway(std::string string1, std::string string2)
{
    int a = string1.length();
    int b = string2.length();

    if (a - b > +1 || a - b < -1)
    {
        return false;
    }

    std::map<char, int> letters;

    for (char c : string1)
    {
        letters[c] += 1;
    }

    bool flag = false;

    for (char c : string2)
    {
        letters[c] -= 1;

        if (letters[c] < -1)
        {
            return false;
        }
        else if (letters[c] == -1 && flag == false)
        {
            flag = true;
        }
        else if (letters[c] == -1 && flag == true)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::array<std::pair<std::string, std::string>, 4> words;
    words[0] = {"pale", "ple"};
    words[1] = {"pales", "pale"};
    words[2] = {"pale", "bale"};
    words[3] = {"pale", "bake"};

    for (std::pair<std::string, std::string> pair : words)
    {
        std::cout << pair.first << ", " << pair.second << " -> " << OneAway(pair.first, pair.second) << std::endl;
    }

    return 0;
}