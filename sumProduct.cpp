#include <iostream>
#include <vector>
#include <format>

enum operation 
{
    SUM, PROD, AVG
};

template <typename T>

T calculate(std::vector<T> &list, operation op);

int main(void)
{
    std::vector<double> list = {1,1,1,1.34567342344,1,1,1,8.2f,9.1f};
    std::cout << "The result of the list is: " << std::format("{:.5f}", calculate(list, AVG)) << "\n";
    return 0;
}

template <typename T>

T calculate(std::vector<T> &list, operation op)
{
    if (list.empty()) return 0;
    int size = list.size();

    T result = (op == SUM)? 0.0f : 1.0f;

    int i = 0;
    while (i < size)
    {
        if (op == SUM)
        {
            result += list[i];
        }
        else if (op == PROD)
        {
            result *= list[i];
        }
        i++;
    }

    if (op == AVG)
    {
        int i = 0;
        while (i < size)
        {
            result += list[i];
            i++;
        }
        result = result / size;
    }

    return result;
}