#include <iostream>
#include <string>
#include <format>
#include <vector>

std::string getHoursMinutesSeconds(int total_seconds);

int main(void)
{
    int total_seconds;
    std::cout << "Enter Seconds: ";
    std::cin >> total_seconds;
    std::string result = getHoursMinutesSeconds(total_seconds);
    std::cout << "The result is: " << result << "\n";
    return 0;
}

std::string getHoursMinutesSeconds(int total_seconds)
{
    if (total_seconds <= 0)
    {
        return "0s";
    }
    int hours = total_seconds / 3600;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;
    
    std::vector<std::string> parts;
    if (hours > 0) parts.push_back(std::format("{}h", hours));
    if (minutes > 0) parts.push_back(std::format("{}m", minutes));
    if (seconds > 0) parts.push_back(std::format("{}s", seconds));

    std::string result = "";
    int i = 0;
    while (i < parts.size())
    {
        result += parts[i] + (i + 1 < parts.size() ? " " : "");
        i++;
    }

    return result;
}