#include <stdio.h>
#include <cs50.h>

int main(void)

{
    int start, end, years  = 0;
    do
    {
    printf("What is the starting population: ");
    scanf("%d", &start);
    }
    while (start<9);

    do
    {
        printf("What is the end population (minimun%d): ",start);
        scanf("%d", &end);
    }
    while (end<start);

    while (start<end)
    {
        start = start + start/3 - start/4;
        years++;
    }

    printf("Years: %d\n", years);
    return 0;
}
check50 cs50/labs/2023/x/population

style50 population.c