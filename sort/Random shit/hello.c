#include <stdio.h>
#include <cs50.h>

int main(void)
{
  string answer = get_string("What is your name? ");
  printf("You shall now be known as, %s\n", answer);
}
