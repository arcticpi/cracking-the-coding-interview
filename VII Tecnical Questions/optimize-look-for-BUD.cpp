#include <iostream>
#include <map>
#include <list>
using namespace std;

void brute_force(int n)
{
    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= n; b++)
        {
            for (int c = 1; c <= n; c++)
            {
                for (int d = 1; d <= n; d++)
                {
                    if (a * a * a + b * b * b == c * c * c + d * d * d)
                    {
                        std::cout << a << ", " << b << ", " << c << ", " << d << std::endl;
                    }
                }
            }
        }
    }
}

void unnecessary_work() {}

void duplicated_work(int n)
{
    std::map<int, std::list<std::pair<int, int>>> map;

    for (int c = 1; c <= n; c++)
    {
        for (int d = 1; d <= n; d++)
        {
            int key = c * c * c + d * d * d;
            map[key].push_back({c, d});
        }
    }

    for (auto i = map.begin(); i != map.end(); i++)
    {
        // auto key = i->first;
        auto list = i->second;
        for (auto j = list.begin(); j != list.end(); j++)
        {
            for (auto k = list.begin(); k != list.end(); k++)
            {
                // std::cout << key << " : " << j->first << ", " << j->second << std::endl;
                std::cout << j->first << ", " << j->second << " : " << k->first << ", " << k->second << std::endl;
            }
        }
    }
}

int main()
{
    int n = 1000;

    // brute_force(n);
    duplicated_work(10);
    return 0;
}