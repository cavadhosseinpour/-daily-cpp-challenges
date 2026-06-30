#include <stdio.h>

void getChessSquareColor(int i, int j);

int main(void)
{
    int i,j;
    printf("Enter chess board number i: ");
    scanf("%i", &i);
    printf("Enter chess board number j: ");
    scanf("%i", &j);
    getChessSquareColor(i,j);
    return 0;
}

void getChessSquareColor(int i, int j)
{
    if (i > 7 || j > 7)
    {
        return;
    }
    else if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
    {
        printf("white\n");
    }
    else
    {
        printf("black\n");
    }
}