#include <iostream>
#include <vector>
#include <random>
#include <string>

void randomShuffle(auto &my_list, std::mt19937 &gen);

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    /*
        // Use a backup seed source (time) in case std::random_device is broken on your compiler
        unsigned int seed = rd.entropy() ? rd() : std::random_device{}() ^ std::time(nullptr);
        std::mt19937 gen(seed);
    */

    // std::vector<int> my_list = {1,2,3,4,5,6,7,8,9,10};
    std::vector<std::string> my_list = {"dog", "cat", "horse", "dd"};
    randomShuffle(my_list, gen);

    std::cout << "{";
    for (int i = 0; i < my_list.size(); ++i)
    {
        std::cout << my_list[i];
        if (i < my_list.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";

    return 0;
}

void randomShuffle(auto &my_list, std::mt19937 &gen)
{
    if (my_list.empty()) return;

    std::uniform_int_distribution<int> distrib(0, my_list.size() - 1);

    for (int i = 0; i < my_list.size(); ++i)
    {
        int random = distrib(gen);

        auto a = my_list[i];
        my_list[i] = my_list[random];
        my_list[random] = a;
    }
}