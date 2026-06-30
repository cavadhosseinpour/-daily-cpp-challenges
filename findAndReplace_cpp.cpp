#include <iostream>
#include <string>

std::string findAndReplace(std::string &text, std::string &old_text, std::string &new_text);

int main(void)
{
    std::string text;
    std::cout << "Enter the text: ";
    std::getline(std::cin, text);

    std::string old_text;
    std::cout << "Enter the text you want to replace: ";
    std::getline(std::cin, old_text);

    std::string new_text;
    std::cout << "Enter the new text you want to add: ";
    std::getline(std::cin, new_text);

    std::string result = findAndReplace(text, old_text, new_text);
    std::cout << "The new text is: " << result << "\n";

    return 0;
}

std::string findAndReplace(std::string &text, std::string &old_text, std::string &new_text)
{
    if (old_text.empty()) return text;

    int text_len = text.length();
    int old_text_len = old_text.length();
    int new_text_len = new_text.length();

    std::string replaced_string = "";
    int i = 0;
    while (i < text_len)
    {
        if (i + old_text_len <= text_len && text.substr(i,old_text_len) == old_text)
        {
            replaced_string += new_text;
            i += old_text_len;
        }
        else
        {
            replaced_string += text[i];
            i++;
        }
    }

    return replaced_string;

    return 0;
}