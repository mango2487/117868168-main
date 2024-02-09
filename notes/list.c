#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node * next;
}
node;

int main(int arc, char* argv[])
{
    node *list = NULL;
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n = NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }

}