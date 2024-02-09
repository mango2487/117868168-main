#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < width; row++)
    {
        for (int collum = 0; collum < height; collum++)
        if (image[collum][row].rgbtRed == 0 && image[collum][row].rgbtGreen == 0 && image[collum][row].rgbtBlue == 0)
        {
            image[collum][row].rgbtGreen = 255;
            image[collum][row].rgbtRed = 0;
            image[collum][row].rgbtBlue = 255;
        }
     }
   }
