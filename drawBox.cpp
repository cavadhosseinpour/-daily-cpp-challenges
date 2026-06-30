#include <iostream>
#include <string>

void drawBox(const int size);

int main()
{
    drawBox(20);
    return 0;
}

void drawBox(const int size)
{
    if (size < 1) return;

    std::cout << std::string(size + 1, ' ') << '+' << std::string(size * 2, '-') << "+\n";

    for (int i = 0; i < size; ++i)
    {
        std::cout << std::string(size - i, ' ') << "/" << std::string(size * 2, ' ') << '/' << std::string(i, ' ') << "|\n";
    }

    std::cout << '+' << std::string(size * 2, '-') << '+' << std::string(size, ' ') << "+\n";

    for (int i = 0; i < size; ++i)
    {
        std::cout << '|' << std::string(size * 2, ' ') << '|' << std::string(size - i - 1, ' ') << "/\n";
    }

    std::cout << '+' << std::string(size * 2, '-') << "+\n";
}