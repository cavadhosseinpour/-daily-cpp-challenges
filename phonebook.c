#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");

    char *name = malloc(100);
    char *number = malloc(100);

    printf("Name: ");
    scanf("%s", name);

    printf("Number: ");
    scanf("%s", number);

    fprintf(file, "%s,%s\n", name, number);
    fclose(file);

}