#include <stdio.h>
#include <stdlib.h>

void asciiTable(int begin, int end);

int main(void)
{
    asciiTable(32, 126);
    return 0;
}

void asciiTable(int begin, int end)
{
    for (int i = begin; i <= end; i++)
    {
        printf("%i  ", i);
        printf("%c", (char)i);
        printf("\n");
    }
}