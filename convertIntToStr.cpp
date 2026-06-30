#include <iostream>
#include <unordered_map>
#include <string>

std::string convertIntToStr(const int &integerNum);

int main()
{

    std::cout << convertIntToStr(-356) << "\n";
    return 0;
}

/*
    The standard C++ functions for these conversions are std::to_string (integer to string) and
    std::stoi (string to integer).
    They are both found in the standard <string> header [cppreference].
*/

std::string convertIntToStr(const int &integerNum)
{
    if (integerNum == 0) return "0";

    std::unordered_map<int, std::string> intToStrMap =
    {
        {0, "0"}, {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"},
        {5, "5"}, {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}
    };

    std::string result;
    int number = std::abs(integerNum);
    int temp;

    while (number > 0)
    {
        temp = number % 10;
        result = intToStrMap[temp] + result;
        number = number / 10;
    }

    if (integerNum < 0)
    {
        result = '-' + result;
    }

    /*
    std::string new_result(result.length(), ' ');

    for (int i = 0; i < result.size(); ++i)
    {
        new_result[i] = result[result.size() - 1 - i];
    }
    */

    return result;
}