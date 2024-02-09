#include <stdio.h>
#include <cs50.h>

int main(void)

{
    float x = 0, z = 0, y = 0;
    do
    {
     x = get_float("Triangle x value: ");
     y = get_float("Triangle y value: ");
     z = get_float("Triangle z value: ");
    }
    while(x < 0 || y < 0 || z < 0 || x + y < z );




}