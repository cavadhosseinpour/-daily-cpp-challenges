#include <algorithm>
#include <iostream>
#include <string>
#include <random>

std::string generatePassword(int &password_length);

int main(void)
{
    int password_length = 10;
    std::cout << "Your password is: " << generatePassword(password_length) << "\n";
    return 0;
}

std::string generatePassword(int &password_length)
{
    if (password_length < 12) password_length = 12;

    std::string uppers    = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lowers    = "abcdefghijklmnopqrstuvwxyz";
    std::string specials  = "~!@#$%^&*()_+";
    std::string digits    = "0123456789";
    std::string all_chars = uppers + lowers + specials + digits;

    std::random_device rd;
    std::mt19937 g(rd());

    // Guarantee the mandatory base requirements first
    std::string password = "";
    password += uppers[g() % uppers.length()];
    password += lowers[g() % lowers.length()];
    password += specials[g() % specials.length()];
    password += digits[g() % digits.length()];

    // Fill the REMAINING characters from the total pooled characters
    while (password.length() < static_cast<size_t>(password_length))
    {
        password += all_chars[g() % all_chars.length()];
    }

    // Modern std::shuffle takes the generator 'g' object directly 
    std::shuffle(password.begin(), password.end(), g);

    return password;
}