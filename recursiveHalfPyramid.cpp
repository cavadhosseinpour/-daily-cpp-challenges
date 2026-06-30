#include <iostream>
#include <string>

void halfPyramid(const int n);
int sumSeries(const int n);
int PowersOfTwo(const int n);
int sumPowersOfTwo(const int n, int currentPower);

int main()
{
    // halfPyramid(5);
    // std::cout << sumSeries(5) << "\n";
    std::cout << PowersOfTwo(3) << "\n";
    std::cout << sumPowersOfTwo(3, 1) << "\n";
    return 0;
}

void halfPyramid(const int n)
{
    if (n < 1) return;

    halfPyramid(n - 1);

    std::cout << std::string(n, '#') << "\n";
}

int sumSeries(const int n)
{
    if (n <= 1) return n;

    return n + sumSeries(n - 1);
}

int PowersOfTwo(const int n)
{
    if (n == 0) return 1;
    if (n == 1)
    {
        return 2;
    }
    else if (n % 2 == 0)
    {
        int result = PowersOfTwo(n / 2);
        return result * result;
    }
    else
    {
        int result = PowersOfTwo(n / 2);
        return 2 * result * result;
    }
}

int sumPowersOfTwo(const int n, int currentPower)
{
    if (n == 0) {
        return currentPower; // Base case: returns 2^0 (1) on the final step
    }
    // Adds the current power of 2 to the sum of the remaining terms
    // multiplying currentPower * 2 moves it to the next power (e.g., 1 -> 2 -> 4 -> 8)
    return currentPower + sumPowersOfTwo(n - 1, currentPower * 2);
}
