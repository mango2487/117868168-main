#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char *s = "Hi!";

    printf("%p\n",s);
    printf("%p\n",(s+1));
    printf("%p\n",(s+2));

}