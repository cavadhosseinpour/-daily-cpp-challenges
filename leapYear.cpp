#include <iostream>

bool isLeapYear(const int &year);

int main(void)
{
    std::cout << "What year: ";
    int year;
    std::cin >> year;

    if (isLeapYear(year))
    {
        std::cout << year << " is a leap year.\n";
    }
    else
    {
        std::cout << year << " is NOT a leap year.\n";
    }

    return 0;
}

bool isLeapYear(const int &year)
{
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) return true;
    else return false;
}