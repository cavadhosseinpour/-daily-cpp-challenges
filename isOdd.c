#include <stdio.h>
#include <stdbool.h>

bool is_Odd(int number);

int main(void)
{
    printf("What is the integer number you want to evaluate? ");
    int number;
    scanf("%i", &number);
    if (is_Odd(number))
    {
        printf("%i is an odd number.\n", number);
    }
    else
    {
        printf("%i is an even number.\n", number);
    }

    return 0;

}

bool is_Odd(int number)
{
    if (number % 2 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}