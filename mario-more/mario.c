#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for brick input
    int size = 0;
    do
    {
    printf("Input mario brick size (1-8): ");
    scanf("%d", & size);
    }
    while (size<=0 || size>=9);

    // Printing fuction


   for (int i = 0; i < size; i++)
    {
    printf("#\n");
    }

    return 0;



}