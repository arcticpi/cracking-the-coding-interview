// Implement a method to perform basic string compression using the counts of repeated characters.
// For example, the string aabcccccaaa would become a2blc5a3.
// If the "compressed" string would not become smaller than the original string, your method should return the original string.
// You can assume the string has only uppercase and lowercase letters (a-z).

#include <iostream>
#include <sstream>

std::string StringCompression(std::string string)
{
    char v = string.at(0);
    int k = 0;

    std::ostringstream stream;

    for (char c : string)
    {
        if (c == v)
        {
            k += 1;
        }
        else
        {
            stream << v << k;
            v = c;
            k = 1;
        }
    }
    
    stream << v << k;
    std::string output = stream.str();
    
    return output.length() >= string.length() ? string : output;
}

int main()
{
    std::cout << "aabcccccaaa" << " -> " << StringCompression("aabcccccaaa") << std::endl;
    return 0;
}