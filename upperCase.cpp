#include <iostream>

std::string getUpperCase(const std::string &str_input);

int main()
{
    std::cout << getUpperCase("jaVad!") << "\n";

    return 0;
}

std::string getUpperCase(const std::string &str_input)
{
    if (str_input.empty()) return "";

    std::string result;

    for (char c : str_input)
    {
        if (c >= 'a' && c <= 'z')
        {
            result.push_back(c - ('a' - 'A'));
        }
        else
        {
            result.push_back(c);
        }
    }
    return result;
}