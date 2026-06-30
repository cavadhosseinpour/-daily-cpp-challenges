#include <iostream>
#include <ctime>
#include <cstdlib>

int rollDice(int &roll_count);

int main(void)
{
    int roll_count;
    std::cout << "How many times you wann roll the dice? ";
    std::cin >> roll_count;

    std::cout << "The dice roll result is: " << rollDice(roll_count) << "\n";

    return 0;
}

int rollDice(int &roll_count)
{
    srand(time(0));
    int sum = 0;

    for (int i = 0; i < roll_count; ++i)
    {
        sum += (rand() % 6) + 1;
    }
    return sum;
}