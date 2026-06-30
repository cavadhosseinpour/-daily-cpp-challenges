#include <stdio.h>

void fizzBuzz(int number);

int main(void)
{
    int number;
    printf("Enter the number: ");
    scanf("%i", &number);

    fizzBuzz(number);

    return 0;
}

void fizzBuzz(int number)
{
    for (int i = 1; i <= number; i++)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
        {
            printf("FizzBuzz ");
        }
        else if (i % 3 == 0)
        {
            printf("Fizz ");
        }
        else if (i % 5 == 0)
        {
            printf("Buzz ");
        }
        else
        {
            printf("%i ", i);
        }
    }
    printf("\n");
}