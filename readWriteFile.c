#include <stdio.h>

void writeToFile(char *file_name, char *text);
void appendToFile(char *file_name, char *text);
void readFromFile(char *file_name);

int main(void)
{
    writeToFile("greet.txt", "Hello!");
    appendToFile("greet.txt", "Goodbye!");
    readFromFile("greet.txt");

    return 0;
}

void writeToFile(char *file_name, char *text)
{
    FILE *file = fopen(file_name, "w");
    if (file != NULL)
    {
        fprintf(file, "%s\n", text);
    }

    fclose(file);
}

void appendToFile(char *file_name, char *text)
{
    FILE *file = fopen(file_name, "a");
    if (file != NULL)
    {
        fprintf(file, "%s\n", text);
    }

    fclose(file);
}

void readFromFile(char *file_name)
{
    char buffer[255];

    FILE *file = fopen(file_name, "r");
    if (file != NULL)
    {
        while(fgets(buffer, 255, file))
        {
            printf("%s", buffer);
        }
    }

    fclose(file);
}