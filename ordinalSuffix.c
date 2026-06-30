#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ordinalSuffix(char *number);

int main(void)
{

    char number[50];
    printf("Enter your number: ");
    scanf("%s", number);

    ordinalSuffix(number);

    return 0;
}

void ordinalSuffix(char *number)
{
    int len = strlen(number);

    int lastTwoDigits = atoi(number + (len - 2));
    int lastOneDigit = atoi(number + (len - 1));
    
    if (lastTwoDigits == 11 || lastTwoDigits == 12 || lastTwoDigits == 13)
    {
        printf("%sth\n", number);
    }
    else
    {
        switch (lastOneDigit)
        {
            case 1: printf("%sst\n", number); break;
            case 2: printf("%snd\n", number); break;
            case 3: printf("%srd\n", number); break;
            default: printf("%sth\n", number); break;
        }
    }
}