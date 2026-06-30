#include <iostream>
#include <string>

void drawRectangle(const int width, const int height);
void drawBorder(const int width, const int height);

int main(void)
{
    // drawRectangle(10, 4);
    drawBorder(16, 4);
    return 0;
}

void drawRectangle(const int width, const int height)
{
    if (height < 1 || width < 1) return;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << "#";
        }
        std::cout << "\n";
    }
}

void drawBorder(const int width, const int height)
{
    if (height < 2 || width < 2) return;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (i == 0 || i == height - 1)
            {
                if (j == 0 || j == width - 1)
                {
                    std::cout << "+";
                }
                else
                {
                    std::cout << "-";
                }
            }
            else
            {
                if (j == 0 || j == width - 1)
                {
                    std::cout << "|";
                }
                else
                {
                    std::cout << " ";
                }
            }
        }
        std::cout << "\n";
    }
}

// Better alternative for border drawing

/* void drawBorder(const int width, const int height) {
    if (width < 2 || height < 2) return;

    // Top border
    std::cout << '+' << std::string(width - 2, '-') << "+\n";

    // Middle rows
    const std::string middle = '|' + std::string(width - 2, ' ') + "|\n";
    for (int i = 0; i < height - 2; ++i) {
        std::cout << middle;
    }

    // Bottom border (only drawn if height > 1, which is covered by the guard)
    std::cout << '+' << std::string(width - 2, '-') << "+\n";
} */