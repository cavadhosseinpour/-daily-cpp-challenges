#include <iostream>
#include <string>

std::string rot13(const std::string &text);

int main()
{
    std::string text = "abcdxyz1234ABCDXYZ";
    std::cout << rot13(text) << "\n";

    return 0;
}

std::string rot13(const std::string &text)
{
    // if (text.empty()) return ""; // This line is not necessary

    std::string result;
    result.reserve(text.size());

    for (char c : text)
    {
        if (c >= 'a' && c <= 'z')
        {
            result.push_back(static_cast<char>('a' + (c - 'a' + 13) % 26));
            /*
            if (c + 13 <= 'z')
            {
                result.push_back(static_cast<char>(c + 13));
            }
            else
            {
                result.push_back(static_cast<char>(c + 12 - ('z' - 'a')));
            }
            */
        }
        else if (c >= 'A' && c <= 'Z')
        {
            result.push_back(static_cast<char>('A' + (c - 'A' + 13) % 26));
            /*
            if (c + 13 <= 'Z')
            {
                result.push_back(static_cast<char>(c + 13));
            }
            else
            {
                result.push_back(static_cast<char>(c + 12 - ('Z' - 'A')));
            }
            */
        }
        else
        {
            result.push_back(static_cast<char>(c));
        }
    }

    return result;
}