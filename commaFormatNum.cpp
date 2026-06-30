#include <iostream>
#include <string>

std::string commaFormat(const auto number);

int main()
{
    std::cout << commaFormat(1234567.34456) << "\n";

    return 0;
}

std::string commaFormat(const auto number)
{
    std::string strNum = std::to_string(number);
    int strNumLen = strNum.length();
    std::string result;
    
    int dotIndex = strNumLen - 1;
    for (int i = 0; i < strNumLen; ++i)
    {
        if (strNum[i] == '.') dotIndex = i;
    }

    for (int i = strNumLen - 1; i >= dotIndex; --i)
    {
        result = strNum[i] + result;
    }

    int count = 0;

    for (int i = dotIndex - 1; i >= 0; --i)
    {
        if (count == 3)
        {
            result = "," + result;
            count = 0;
        }

        result = strNum[i] + result;
        count++;

    }
    return result;
}