#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main()
{
    node *list = NULL;

    for(int i = 0; i < 3; i++)
    {
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            return 1;
        }

        tmp->number = i;
        tmp->next = NULL;

        tmp->next = list;
        list = tmp;
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }
}