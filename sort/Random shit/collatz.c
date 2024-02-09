#include <stdio.h>
#include <cs50.h>

int main (void)
{
    // Collatz conjecture,  can allways reach n = 1 if follow these steps
    // 1. if n = 1 stop
    // 2. if n = even/2
    // 3. if n = (odd*3)+1

    int n = get_int("Input: ");

    if (n == 1)
    {
        printf("done\n");
        return 0;
    }

    else if (n % 2 == 0)
    {
        return 11;
    }

    else
    {
        return 11;
    }
}