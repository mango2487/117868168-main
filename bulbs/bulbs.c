#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit); //THIS IS AN EDIT tempt
// this is my second edit 
// why is this nit working 

int main(void)
{
    // prompt user
    string s = get_string("Input: ");

    //itterate through each character of the string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
       int binary[] = {0,0,0,0,0,0,0,0};

       // convert char into ASCII4
       int decimal = s[i];

       //convert ASCII into binary
       int j = 0;
       while (decimal > 0)
       {
          binary[j] = decimal % 2;
          decimal = decimal / 2;
          j++;
       }

       // print the binary in reverse
       for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
       {
          print_bulb(binary[k]);
       }
       printf("\n");
    }
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
