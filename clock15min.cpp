#include <iostream>
#include <format>

int main(void)
{
    for(int total_minutes = 0; total_minutes < 1440; total_minutes+=15)
    {
        int hour_24 = total_minutes / 60;
        int minutes = total_minutes % 60;

        int hour_12 = (hour_24 % 12 == 0) ? 12 : hour_24 % 12;
        const char *period = (hour_24 < 12) ? "am" : "pm";

        std::cout << std::format("{:02}:{:02} {}\n", hour_12, minutes, period);
    }
    return 0;
}