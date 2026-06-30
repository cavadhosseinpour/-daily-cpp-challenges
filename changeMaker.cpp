#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> makeChange(const int &amount);

int main()
{
    std::cout << "Enter the amount in cents: ";
    int cents;
    std::cin >> cents;
    std::unordered_map<std::string, int> result;

    result = makeChange(cents);

    std::vector<std::string> coin_order = {"Quarters", "Dimes", "Nickels", "Pennies"};

    std::cout << "The change for " << cents << " is:\n";
    for (const auto &key : coin_order)
    {
        if (result.count(key))
        {
            std::cout << key << ": " << result[key] << "\n";
        }
    }
    return 0;
}

std::unordered_map<std::string, int> makeChange(const int &amount)
{
    std::unordered_map<std::string, int> result;
    result.reserve(4);

    int cents = amount;


    int quarters = cents / 25;
    if (quarters > 0) result["Quarters"] = quarters;
    cents %= 25;

    int dimes = cents / 10;
    if (dimes > 0) result["Dimes"] = dimes;
    cents %= 10;

    int nickels = cents / 5;
    if (nickels > 0) result["Nickels"] = nickels;
    cents %= 5;

    int pennies = cents;
    if (pennies > 0) result["Pennies"] = cents;

    return result;
}