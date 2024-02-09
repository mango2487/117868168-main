#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int start, end, years = 0;
  do
  {
   printf("Enter starting population size: ");
   scanf("%i", &start);
   }
   while (start < 9);

   do
   {
   printf("Enter ending population size(minimum %d): ",start);
   scanf("%d", &end);
   }
   while (end < start);

   while (start < end)
   {
   start = start + start / 3 - start / 4;
   years++;
   }

   printf("Years: %d\n", years);
   return 0;

}


// Prompt user for end pop
// Formulate years from start to end with equation
// printf result