//#include <bool>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

int convertStrToInt(const std::string &stringNum);

int main()
{
    std::cout << convertStrToInt("-356") << "\n";
    return 0;
}

int convertStrToInt(const std::string &stringNum)
{
    std::unordered_map<char, int> charToIntMap = 
    {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
        {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
    };

    if (stringNum == "0") return 0;

    bool isNegative = false;
    if (stringNum[0] == '-')
    {
        isNegative = true;
    }

    int result = 0;

    for (int i = stringNum.length() - 1; (isNegative ? i > 0 : i >= 0); --i)
    {
        result = result + charToIntMap[stringNum[i]] * std::pow(10, stringNum.length() - i - 1);
    }

    if (isNegative) result = result * (-1);

    return result;
}

/*
    the following is a standard C++ code for the above functionality:

#include <iostream>
#include <string>
#include <stdexcept>

int convertStrToInt(const std::string &stringNum)
{
    // 1. Handle empty string safety check
    if (stringNum.empty()) {
        throw std::invalid_argument("Empty string");
    }

    // 2. Determine sign and start index
    bool isNegative = (stringNum[0] == '-');
    size_t startIndex = (isNegative || stringNum[0] == '+') ? 1 : 0;

    // 3. Handle string with only a sign character
    if (startIndex == stringNum.length()) {
        throw std::invalid_argument("Invalid input string");
    }

    long long result = 0; // Use long long to safely catch overflows

    // 4. Process left-to-right (removes need for pow)
    for (size_t i = startIndex; i < stringNum.length(); ++i)
    {
        // Validate character is a digit
        if (stringNum[i] < '0' || stringNum[i] > '9') {
            throw std::invalid_argument("Non-numeric character found");
        }

        // ASCII Math: '5' - '0' equals the integer 5
        int digit = stringNum[i] - '0'; 
        
        result = (result * 10) + digit;

        // 5. Overflow checks
        if (!isNegative && result > INT_MAX) {
            throw std::out_of_range("Integer overflow");
        }
        if (isNegative && -result < INT_MIN) {
            throw std::out_of_range("Integer underflow");
        }
    }

    return isNegative ? static_cast<int>(-result) : static_cast<int>(result);
}

int main()
{
    try {
        std::cout << convertStrToInt("-356") << "\n";
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    return 0;
}

*/