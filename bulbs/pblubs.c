#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
   // Prompt user
   string s = get_string("Input: \n");

   // itterate through each char of string
   for (int i = 0, strlen(s); i < n; i++)
   {
   int binary[] = {0,0,0,0,0,0,0,0};

   // Char -> ASCII
   int decimal = s[i];

   // ASCII -> Binary
   int 
   // Print the reverse output
   return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
