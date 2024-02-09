#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 0;
    do
    {
        n = get_int("Height: ");
       // get_int("Height: \n", & n) or printf("Height:")
       // scanf("%d", & n)
    }
    while (n < 1 || n > 8);
    printf("Check for valid input %i\n", n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        if (i + j < n -1)
        {
            printf(" ");
        }
        else
        {
            printf("#");
        }
    printf("\n");
    }
}