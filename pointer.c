#include <stdio.h>

typedef char *string;

int main(void)
{

    int number = 50;
    int *p = &number;

    printf("The value is %i\n", number);
    printf("The value is stored in %p\n", p);
    printf("The value is stored in %p\n", &number);
    printf("The value is %i\n", *p);

    int list[] = {0, 1, 2};

    printf("The address of list is: %p\n", list);
    printf("The address of list[0] is: %p\n", &list[0]);
    printf("The address of list[1] is: %p\n", &list[1]);
    printf("The address of list[2] is: %p\n", &list[2]);
    printf("The address of list[3] is: %p\n", &list[3]);
    // printf("The value of list[3] is: %i\n", list[3]);

    char *name = "Javad!";
    printf("The name is: %s\n", name);

    string namename = "JavadHP!";
    printf("The name is %p\n", namename);
    printf("The name is %p\n", &namename[0]);
    printf("The name is %c\n", *namename);
    printf("The name is %c\n", *(namename + 1));
    printf("The name is %c\n", *(namename + 8));
    printf("The name is %s\n", namename + 1);
}