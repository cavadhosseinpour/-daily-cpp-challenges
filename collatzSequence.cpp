#include <iostream>
#include <vector>

std::vector<int> collatz(const int &startingNumber);

int main()
{
    std::cout << "Starting number for Collatz sequence: ";
    int startingNumber;
    std::cin >> startingNumber;

    std::vector<int> result = collatz(startingNumber);

    std::cout << "{";
    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i];
        if (i < result.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";

    return 0;
}

std::vector<int> collatz(const int &startingNumber)
{
    std::vector<int> result;
    int num = startingNumber;
    if (num <= 0) return {};
    result.push_back(static_cast<int>(num));

    while (num > 1)
    {
        if (num % 2 == 1)
        {
            num = 3 * num + 1;
        }
        else
        {
            num /= 2;
        }
        result.push_back(static_cast<int>(num));
    }
    return result;
}