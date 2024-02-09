#include <stdio.h>
#include <cs50.h>

int main(void)
// get array length from user
{
   int length;
   do
    {
      length = get_int("Length: ");
    }
   while (length < 1);
// declare array
   int twice[length];
// set first value
   twice[0] = 1;

   printf("%i\n", twice[0]);

   for (int i = 1;i < length; i++)
   // double each following array value 
   {
     twice[i] = 2 * twice[i-1];
     printf("%i\n", twice[i]);
   }

}