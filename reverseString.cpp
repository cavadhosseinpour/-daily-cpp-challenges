#include <iostream>

std::string reverseString(const std::string &str_input);

int main()
{

    std::cout << reverseString("Hello, World!") << "\n";
    return 0;
}

std::string reverseString(const std::string &str_input)
{
    if (str_input.empty()) return "";

    int str_length = str_input.length();
    
    std::string result = "";
    for (int i = 0; i < str_length; ++i)
    {
        result.push_back(static_cast<unsigned char>(str_input[str_length - i - 1]));
    }

    return result;
}