#include <iostream>
#include <format>

int main(void)
{

    // Optimize standard I/O operations for speed
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::format("  |");

    for (int i = 1; i < 11; ++i)
    {
        std::cout << std::format("{:>4}", i);
    }

    std::cout << "\n";
    std::cout << std::format("--+");

    for (int i = 1; i < 11; ++i)
    {
        std::cout << std::format("----");
    }

    std::cout << "\n";

    for (int i = 1; i < 11; ++i)
    {
        std::cout << std::format("{:>2}|", i);
        for (int j = 1; j < 11; ++j)
        {
            std::cout << std::format("{:>4}", i * j);
        }
        std::cout << "\n";
    }
    return 0;
}