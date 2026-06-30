#include <cmath>
#include <iostream>
#include <string>

void drawPyramid(const int height);

int main(void)
{
    drawPyramid(9);

    return 0;
}

void drawPyramid(const int height)
{
    if (height < 1) return;

    int total = std::pow(((height + 1) / 2), 2);

    int j = 1;

    for (int i = 0; i < height; ++i)
    {
        std::cout << std::string(total / 2 - i, ' ');
        std::cout << std::string(j, '#');
        std::cout << std::string(total / 2 - i, ' ') << "\n";
        j+= 2;
    }

}