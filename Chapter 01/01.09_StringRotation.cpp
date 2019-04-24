#include <iostream>

bool StringRotation(std::string s1, std::string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    
    return (s2 + s2).find(s1) != std::string::npos;
}

int main()
{
    std::string s1 = "waterbottle";
    std::string s2 = "erbottlewat";

    std::cout << s1 << ", " << s2 << " -> " << StringRotation(s1, s2) << std::endl;
}