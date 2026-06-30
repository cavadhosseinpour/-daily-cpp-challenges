#include <iostream>

std::string getTitleCase(const std::string &str_input);

int main()
{
    std::cout << getTitleCase("hello, 324(world!") << "\n";
    return 0;
}

std::string getTitleCase(const std::string &str_input)
{
    if (str_input.empty()) return "";
    std::string result;
    bool capitalizeNext = true;

    for (char c : str_input)
    {
        if (capitalizeNext && std::islower(static_cast<unsigned char>(c)))
        {
            result.push_back(std::toupper(static_cast<unsigned char>(c)));
            capitalizeNext = false;
        }
        else if (std::isspace(static_cast<unsigned char>(c)) ||
                 std::ispunct(static_cast<unsigned char>(c)) ||
                 std::isdigit(static_cast<unsigned char>(c)) )
        {
            result.push_back(std::tolower(static_cast<unsigned char>(c)));
            capitalizeNext = true;
        }
        else
        {
            result.push_back(std::tolower(static_cast<unsigned char>(c)));
            capitalizeNext = false;
        }
    }

    return result;
}
/*
std::string getTitleCase(const std::string &str_input)
{
    if (str_input.empty()) return "";

    std::string result;

    for (int i = 0; i < str_input.length(); ++i)
    {
        if (i == 0)
        {
            result.push_back(static_cast<char>(str_input[0] - ('a' - 'A')));
        }
        else if (str_input[i - 1] >= ' ' && str_input[i - 1] <= '@' &&
                str_input[i] >= 'a' && str_input[i] <= 'z')
        {
            result.push_back(static_cast<char>(str_input[i] - ('a' - 'A')));
        }
        else
        {
            result.push_back(static_cast<char>(str_input[i]));
        }
    }

    return result;
}
*/