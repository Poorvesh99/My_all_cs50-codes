#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++) // I don't under stand why this program don't work assiging image to rgb triple
    {
        for (int j = 0; j < width; j++) // this loop to iterate through second part of program
        {
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00)
            {
                image[i][j].rgbtBlue = 0x50;   // checking whether it is black or not if so changing the colors
                image[i][j].rgbtGreen = 0xF4;
                image[i][j].rgbtRed = 0xAB;
            }
        }
    }
}
