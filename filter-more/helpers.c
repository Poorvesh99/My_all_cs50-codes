#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int pixel = 0x00;
    //row loop
    for (int i = 0; i < height; i++)
    {
        //coloum loop
        for (int j = 0; j < width; j++)
        {
            //finding average
            //use 3.0 to make calculation in decimal otherwise it gives value in int
            pixel = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = pixel;
            image[i][j].rgbtRed = pixel;
            image[i][j].rgbtGreen = pixel;
        }
    }
    return;
}
///
//
//
//

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //row loop
    for (int i = 0; i < height; i++)
    {
        //coloumn loop
        for (int j = 0; j < width / 2; j++)
        {
            int temp = image[i][(width - 1) - j].rgbtBlue; // i doudt this well styled but till can be checked//
            image[i][(width - 1) - j].rgbtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = temp;
            temp = image[i][(width - 1) - j].rgbtRed;
            image[i][(width - 1) - j].rgbtRed = image[i][j].rgbtRed;
            image[i][j].rgbtRed = temp;
            temp = image[i][(width - 1) - j].rgbtGreen;
            image[i][(width - 1) - j].rgbtGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = temp;
        }
    }
    return;
}
//
//
//

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE holder[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            holder[i][j].rgbtRed = image[i][j].rgbtRed;
            holder[i][j].rgbtBlue = image[i][j].rgbtBlue;
            holder[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }

    int red, green, blue;
    //row loop
    for (int i = 0; i < height; i++)
    {
        //coloumn loop
        for (int j = 0; j < width; j++)
        {
            //4 pixel for corner
            if (i == 0 && j == 0) // crner1
            {
                //averaging the no.
                red = round((holder[i][j].rgbtRed + holder[i][j + 1].rgbtRed + holder[i + 1][j].rgbtRed + holder[i + 1][j + 1].rgbtRed) / 4.0);
                blue = round((holder[i][j].rgbtBlue + holder[i][j + 1].rgbtBlue + holder[i + 1][j].rgbtBlue + holder[i + 1][j + 1].rgbtBlue) / 4.0);
                green = round((holder[i][j].rgbtGreen + holder[i][j + 1].rgbtGreen + holder[i + 1][j].rgbtGreen + holder[i + 1][j + 1].rgbtGreen) /
                              4.0);

                //applying value
                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i == 0 && j == width - 1) // corner 2
            {
                red = round((holder[i][j].rgbtRed + holder[i][j - 1].rgbtRed + holder[i + 1][j].rgbtRed + holder[i + 1][j - 1].rgbtRed) / 4.0);
                blue = round((holder[i][j].rgbtBlue + holder[i][j - 1].rgbtBlue + holder[i + 1][j].rgbtBlue + holder[i + 1][j - 1].rgbtBlue) / 4.0);
                green = round((holder[i][j].rgbtGreen + holder[i][j - 1].rgbtGreen + holder[i + 1][j].rgbtGreen + holder[i + 1][j - 1].rgbtGreen) /
                              4.0);

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i == height - 1 && j == width - 1) // corner 3
            {
                red = round((holder[i][j].rgbtRed + holder[i][j - 1].rgbtRed + holder[i - 1][j].rgbtRed + holder[i - 1][j - 1].rgbtRed) / 4.0);
                blue = round((holder[i][j].rgbtBlue + holder[i][j - 1].rgbtBlue + holder[i - 1][j].rgbtBlue + holder[i - 1][j - 1].rgbtBlue) / 4.0);
                green = round((holder[i][j].rgbtGreen + holder[i][j - 1].rgbtGreen + holder[i - 1][j].rgbtGreen + holder[i - 1][j - 1].rgbtGreen) /
                              4.0);

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i == height - 1 && j == 0) // corner 4
            {
                red = round((holder[i][j].rgbtRed + holder[i][j + 1].rgbtRed + holder[i - 1][j].rgbtRed + holder[i - 1][j + 1].rgbtRed) / 4.0);
                blue = round((holder[i][j].rgbtBlue + holder[i][j + 1].rgbtBlue + holder[i - 1][j].rgbtBlue + holder[i - 1][j + 1].rgbtBlue) / 4.0);
                green = round((holder[i][j].rgbtGreen + holder[i][j + 1].rgbtGreen + holder[i - 1][j].rgbtGreen + holder[i - 1][j + 1].rgbtGreen) /
                              4.0);

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            //6 pixel for edges
            else if (i != 0 && i != height - 1 && j == 0) // Edge 1
            {
                red = round((holder[i][j].rgbtRed + holder[i][j + 1].rgbtRed + holder[i + 1][j].rgbtRed + holder[i + 1][j + 1].rgbtRed + holder[i -
                             1][j].rgbtRed + holder[i - 1][j + 1].rgbtRed) / 6.0);
                blue = round((holder[i][j].rgbtBlue + holder[i][j + 1].rgbtBlue + holder[i + 1][j].rgbtBlue + holder[i + 1][j + 1].rgbtBlue +
                              holder[i - 1][j].rgbtBlue + holder[i - 1][j + 1].rgbtBlue) /
                             6.0);
                green = round((holder[i][j].rgbtGreen + holder[i][j + 1].rgbtGreen + holder[i + 1][j].rgbtGreen + holder[i + 1][j + 1].rgbtGreen +
                               holder[i - 1][j].rgbtGreen + holder[i - 1][j + 1].rgbtGreen) /
                              6.0);

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i != 0 && i != height - 1 && j == width - 1) // edge
            {
                red = round((holder[i][j].rgbtRed + holder[i][j - 1].rgbtRed + holder[i + 1][j].rgbtRed + holder[i + 1][j - 1].rgbtRed + holder[i -
                             1][j].rgbtRed + holder[i - 1][j - 1].rgbtRed) / 6.0);
                blue = round((holder[i][j].rgbtBlue + holder[i][j - 1].rgbtBlue + holder[i + 1][j].rgbtBlue + holder[i + 1][j - 1].rgbtBlue +
                              holder[i - 1][j].rgbtBlue + holder[i - 1][j - 1].rgbtBlue) /
                             6.0);
                green = round((holder[i][j].rgbtGreen + holder[i][j - 1].rgbtGreen + holder[i + 1][j].rgbtGreen + holder[i + 1][j - 1].rgbtGreen +
                               holder[i - 1][j].rgbtGreen + holder[i - 1][j - 1].rgbtGreen) /
                              6.0);

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i == height - 1 && j != width - 1 && j != 0) // edge 3
            {
                red = round((holder[i][j].rgbtRed + holder[i][j - 1].rgbtRed + holder[i - 1][j].rgbtRed + holder[i - 1][j - 1].rgbtRed +
                             holder[i - 1][j + 1].rgbtRed + holder[i][j + 1].rgbtRed) /
                            6.0);
                blue = round((holder[i][j].rgbtBlue + holder[i][j - 1].rgbtBlue + holder[i - 1][j].rgbtBlue + holder[i - 1][j - 1].rgbtBlue +
                              holder[i - 1][j + 1].rgbtBlue + holder[i][j + 1].rgbtBlue) /
                             6.0);
                green = round((holder[i][j].rgbtGreen + holder[i][j - 1].rgbtGreen + holder[i - 1][j].rgbtGreen + holder[i - 1][j - 1].rgbtGreen +
                               holder[i - 1][j + 1].rgbtGreen + holder[i][j + 1].rgbtGreen) /
                              6.0);

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i == 0 && j != 0 && j != width - 1) // edge 4
            {
                red = round((holder[i][j].rgbtRed + holder[i][j - 1].rgbtRed + holder[i + 1][j].rgbtRed + holder[i + 1][j - 1].rgbtRed + holder[i][j
                             + 1].rgbtRed + holder[i + 1][j + 1].rgbtRed) / 6.0);
                blue = round((holder[i][j].rgbtBlue + holder[i][j - 1].rgbtBlue + holder[i + 1][j].rgbtBlue + holder[i + 1][j - 1].rgbtBlue +
                              holder[i][j + 1].rgbtBlue + holder[i + 1][j + 1].rgbtBlue) / 6.0);
                green = round((holder[i][j].rgbtGreen + holder[i][j - 1].rgbtGreen + holder[i + 1][j].rgbtGreen + holder[i + 1][j - 1].rgbtGreen +
                               holder[i][j + 1].rgbtGreen + holder[i + 1][j + 1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else//all 9 pixel
            {
                red = round((holder[i][j].rgbtRed + holder[i][j + 1].rgbtRed + holder[i + 1][j].rgbtRed + holder[i + 1][j + 1].rgbtRed + holder[i +
                             1][j - 1].rgbtRed + holder[i][j - 1].rgbtRed + holder[i - 1][j + 1].rgbtRed + holder[i - 1][j].rgbtRed + holder[i - 1][j -
                                     1].rgbtRed) / 9.0);
                blue = round((holder[i][j].rgbtBlue + holder[i][j + 1].rgbtBlue + holder[i + 1][j].rgbtBlue + holder[i + 1][j + 1].rgbtBlue +
                              holder[i + 1][j - 1].rgbtBlue + holder[i][j - 1].rgbtBlue + holder[i - 1][j + 1].rgbtBlue + holder[i - 1][j].rgbtBlue +
                              holder[i - 1][j - 1].rgbtBlue) / 9.0);
                green = round((holder[i][j].rgbtGreen + holder[i][j + 1].rgbtGreen + holder[i + 1][j].rgbtGreen + holder[i + 1][j + 1].rgbtGreen +
                               holder[i + 1][j - 1].rgbtGreen + holder[i][j - 1].rgbtGreen + holder[i - 1][j + 1].rgbtGreen +
                               holder[i - 1][j].rgbtGreen + holder[i - 1][j - 1].rgbtGreen) / 9.0);

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
        }
    }
    return;
}
///////
///
//

//
//

///

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
// please keep thing in order while doing it it  keeps it easy to mange later
{
    //this is to make a copy
    RGBTRIPLE holder[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            holder[i][j].rgbtRed = image[i][j].rgbtRed;
            holder[i][j].rgbtBlue = image[i][j].rgbtBlue;
            holder[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }
    //actual effecting code
    int red, green, blue, gxred, gyred, gxgreen, gygreen, gxblue, gyblue;
    //gx and gy value to to assign to algorithm
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0) // crner1
            {
                //giving value to each one of the following
                gxred = (0 * holder[i][j].rgbtRed + 2 * holder[i][j + 1].rgbtRed) + (0 * holder[i + 1][j].rgbtRed +
                        1 * holder[i + 1][j + 1].rgbtRed);
                gyred = (0 * holder[i][j].rgbtRed + 0 * holder[i][j + 1].rgbtRed) + (2 * holder[i + 1][j].rgbtRed +
                        1 * holder[i + 1][j + 1].rgbtRed);

                gxblue = (0 * holder[i][j].rgbtBlue + 2 * holder[i][j + 1].rgbtBlue) + (0 * holder[i + 1][j].rgbtBlue +
                         1 * holder[i + 1][j + 1].rgbtBlue);
                gyblue = (0 * holder[i][j].rgbtBlue + 0 * holder[i][j + 1].rgbtBlue) + (2 * holder[i + 1][j].rgbtBlue +
                         1 * holder[i + 1][j + 1].rgbtBlue);

                gxgreen = (0 * holder[i][j].rgbtGreen + 2 * holder[i][j + 1].rgbtGreen) + (0 * holder[i + 1][j].rgbtGreen +
                          1 * holder[i + 1][j + 1].rgbtGreen);
                gygreen = (0 * holder[i][j].rgbtGreen + 0 * holder[i][j + 1].rgbtGreen) + (2 * holder[i + 1][j].rgbtGreen +
                          1 * holder[i + 1][j + 1].rgbtGreen);

                // to check if value exceed 255
                if ((red = round(sqrt(gxred * gxred + gyred * gyred))) > 255)
                {
                    red = 255;
                }
                if ((blue = round(sqrt(gxblue * gxblue + gyblue * gyblue))) > 255)
                {
                    blue = 255;
                }
                if ((green = round(sqrt(gxgreen * gxgreen + gygreen * gygreen))) > 255)
                {
                    green = 255;
                }

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i == 0 && j == width - 1) // corner 2
            {
                gxred = (0 * holder[i][j].rgbtRed + -2 * holder[i][j - 1].rgbtRed + 0 * holder[i + 1][j].rgbtRed +
                         -1 * holder[i + 1][j - 1].rgbtRed);
                gyred = (0 * holder[i][j].rgbtRed + 0 * holder[i][j - 1].rgbtRed + 2 * holder[i + 1][j].rgbtRed +
                         1 * holder[i + 1][j - 1].rgbtRed);

                gxblue = (0 * holder[i][j].rgbtBlue + -2 * holder[i][j - 1].rgbtBlue + 0 * holder[i + 1][j].rgbtBlue +
                          -1 * holder[i + 1][j - 1].rgbtBlue);
                gyblue = (0 * holder[i][j].rgbtBlue + 0 * holder[i][j - 1].rgbtBlue + 2 * holder[i + 1][j].rgbtBlue +
                          1 * holder[i + 1][j - 1].rgbtBlue);

                gxgreen = (0 * holder[i][j].rgbtGreen + -2 * holder[i][j - 1].rgbtGreen + 0 * holder[i + 1][j].rgbtGreen +
                           -1 * holder[i + 1][j - 1].rgbtGreen);
                gygreen = (0 * holder[i][j].rgbtGreen + 0 * holder[i][j - 1].rgbtGreen + 2 * holder[i + 1][j].rgbtGreen +
                           1 * holder[i + 1][j - 1].rgbtGreen);

                if ((red = round(sqrt(gxred * gxred + gyred * gyred))) > 255)
                {
                    red = 255;
                }
                if ((blue = round(sqrt(gxblue * gxblue + gyblue * gyblue))) > 255)
                {
                    blue = 255;
                }
                if ((green = round(sqrt(gxgreen * gxgreen + gygreen * gygreen))) > 255)
                {
                    green = 255;
                }
                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i == height - 1 && j == width - 1) // corner 3
            {
                gxred = (0 * holder[i][j].rgbtRed + -2 * holder[i][j - 1].rgbtRed + 0 * holder[i - 1][j].rgbtRed + -1 * holder[i - 1][j -
                         1].rgbtRed);
                gyred = (0 * holder[i][j].rgbtRed + 0 * holder[i][j - 1].rgbtRed + -2 * holder[i - 1][j].rgbtRed + -1 * holder[i - 1][j -
                         1].rgbtRed);

                gxblue = (0 * holder[i][j].rgbtBlue + -2 * holder[i][j - 1].rgbtBlue + 0 * holder[i - 1][j].rgbtBlue + -1 * holder[i - 1][j -
                          1].rgbtBlue);
                gyblue = (0 * holder[i][j].rgbtBlue + 0 * holder[i][j - 1].rgbtBlue + -2 * holder[i - 1][j].rgbtBlue + -1 * holder[i - 1][j -
                          1].rgbtBlue);

                gxgreen = (0 * holder[i][j].rgbtGreen + -2 * holder[i][j - 1].rgbtGreen + 0 * holder[i - 1][j].rgbtGreen + -1 * holder[i - 1][j -
                           1].rgbtGreen);
                gygreen = (0 * holder[i][j].rgbtGreen + 0 * holder[i][j - 1].rgbtGreen + -2 * holder[i - 1][j].rgbtGreen + -1 * holder[i -
                           1][j - 1].rgbtGreen);

                //contain square root value
                if ((red = round(sqrt(gxred * gxred + gyred * gyred))) > 255)
                {
                    red = 255;
                }
                if ((blue = round(sqrt(gxblue * gxblue + gyblue * gyblue))) > 255)
                {
                    blue = 255;
                }
                if ((green = round(sqrt(gxgreen * gxgreen + gygreen * gygreen))) > 255)
                {
                    green = 255;
                }

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i == height - 1 && j == 0) // corner 4
            {
                gxred = (0 * holder[i][j].rgbtRed + 2 * holder[i][j + 1].rgbtRed + 0 * holder[i - 1][j].rgbtRed +
                         1 * holder[i - 1][j + 1].rgbtRed);
                gyred = (0 * holder[i][j].rgbtRed + 0 * holder[i][j + 1].rgbtRed + -2 * holder[i - 1][j].rgbtRed +
                         -1 * holder[i - 1][j + 1].rgbtRed);

                gxblue = (0 * holder[i][j].rgbtBlue + 2 * holder[i][j + 1].rgbtBlue + 0 * holder[i - 1][j].rgbtBlue +
                          1 * holder[i - 1][j + 1].rgbtBlue);
                gyblue = (0 * holder[i][j].rgbtBlue + 0 * holder[i][j + 1].rgbtBlue + -2 * holder[i - 1][j].rgbtBlue +
                          -1 * holder[i - 1][j + 1].rgbtBlue);

                gxgreen = (0 * holder[i][j].rgbtGreen + 2 * holder[i][j + 1].rgbtGreen + 0 * holder[i - 1][j].rgbtGreen +
                           1 * holder[i - 1][j + 1].rgbtGreen);
                gygreen = (0 * holder[i][j].rgbtGreen + 0 * holder[i][j + 1].rgbtGreen + -2 * holder[i - 1][j].rgbtGreen +
                           -1 * holder[i - 1][j + 1].rgbtGreen);

                if ((red = round(sqrt(gxred * gxred + gyred * gyred))) > 255)
                {
                    red = 255;
                }
                if ((blue = round(sqrt(gxblue * gxblue + gyblue * gyblue))) > 255)
                {
                    blue = 255;
                }
                // even this to be round
                if ((green = round(sqrt(gxgreen * gxgreen + gygreen * gygreen))) > 255)
                {
                    green = 255;
                }

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i != 0 && i != height - 1 && j == 0) // Edge 1
            {
                gxred = (0 * holder[i][j].rgbtRed + 2 * holder[i][j + 1].rgbtRed + 0 * holder[i + 1][j].rgbtRed +
                         1 * holder[i + 1][j + 1].rgbtRed + 0 * holder[i - 1][j].rgbtRed + 1 * holder[i - 1][j + 1].rgbtRed);
                gyred = (0 * holder[i][j].rgbtRed + 0 * holder[i][j + 1].rgbtRed + 2 * holder[i + 1][j].rgbtRed +
                         1 * holder[i + 1][j + 1].rgbtRed + -2 * holder[i - 1][j].rgbtRed + -1 * holder[i - 1][j + 1].rgbtRed);

                gxblue = (0 * holder[i][j].rgbtBlue + 2 * holder[i][j + 1].rgbtBlue + 0 * holder[i + 1][j].rgbtBlue +
                          1 * holder[i + 1][j + 1].rgbtBlue + 0 * holder[i - 1][j].rgbtBlue + 1 * holder[i - 1][j + 1].rgbtBlue);
                gyblue = (0 * holder[i][j].rgbtBlue + 0 * holder[i][j + 1].rgbtBlue + 2 * holder[i + 1][j].rgbtBlue +
                          1 * holder[i + 1][j + 1].rgbtBlue + -2 * holder[i - 1][j].rgbtBlue + -1 * holder[i - 1][j + 1].rgbtBlue);

                gxgreen = (0 * holder[i][j].rgbtGreen + 2 * holder[i][j + 1].rgbtGreen + 0 * holder[i + 1][j].rgbtGreen +
                           1 * holder[i + 1][j + 1].rgbtGreen + 0 * holder[i - 1][j].rgbtGreen + 1 * holder[i - 1][j + 1].rgbtGreen);
                gygreen = (0 * holder[i][j].rgbtGreen + 0 * holder[i][j + 1].rgbtGreen + 2 * holder[i + 1][j].rgbtGreen +
                           1 * holder[i + 1][j + 1].rgbtGreen + -2 * holder[i - 1][j].rgbtGreen + -1 * holder[i - 1][j + 1].rgbtGreen);

                if ((red = round(sqrt(gxred * gxred + gyred * gyred))) > 255)
                {
                    red = 255;
                }
                if ((blue = round(sqrt(gxblue * gxblue + gyblue * gyblue))) > 255)
                {
                    blue = 255;
                }
                if ((green = round(sqrt(gxgreen * gxgreen + gygreen * gygreen))) > 255)
                {
                    green = 255;
                }

                //applying the value to the image
                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i != 0 && i != height - 1 && j == width - 1) // edge
            {
                gxred = (0 * holder[i][j].rgbtRed + -2 * holder[i][j - 1].rgbtRed + 0 * holder[i + 1][j].rgbtRed +
                         -1 * holder[i + 1][j - 1].rgbtRed + 0 * holder[i - 1][j].rgbtRed + -1 * holder[i - 1][j - 1].rgbtRed);
                gyred = (0 * holder[i][j].rgbtRed + 0 * holder[i][j - 1].rgbtRed + 2 * holder[i + 1][j].rgbtRed +
                         1 * holder[i + 1][j - 1].rgbtRed + -2 * holder[i - 1][j].rgbtRed + -1 * holder[i - 1][j - 1].rgbtRed);

                gxblue = (0 * holder[i][j].rgbtBlue + -2 * holder[i][j - 1].rgbtBlue + 0 * holder[i + 1][j].rgbtBlue +
                          -1 * holder[i + 1][j - 1].rgbtBlue + 0 * holder[i - 1][j].rgbtBlue + -1 * holder[i - 1][j - 1].rgbtBlue);
                gyblue = (0 * holder[i][j].rgbtBlue + 0 * holder[i][j - 1].rgbtBlue + 2 * holder[i + 1][j].rgbtBlue +
                          1 * holder[i + 1][j - 1].rgbtBlue + -2 * holder[i - 1][j].rgbtBlue + -1 * holder[i - 1][j - 1].rgbtBlue);

                gxgreen = (0 * holder[i][j].rgbtGreen + -2 * holder[i][j - 1].rgbtGreen + 0 * holder[i + 1][j].rgbtGreen +
                           -1 * holder[i + 1][j - 1].rgbtGreen + 0 * holder[i - 1][j].rgbtGreen + -1 * holder[i - 1][j - 1].rgbtGreen);
                gygreen = (0 * holder[i][j].rgbtGreen + 0 * holder[i][j - 1].rgbtGreen + 2 * holder[i + 1][j].rgbtGreen +
                           1 * holder[i + 1][j - 1].rgbtGreen + -2 * holder[i - 1][j].rgbtGreen + -1 * holder[i - 1][j - 1].rgbtGreen);

                if ((red = round(sqrt(gxred * gxred + gyred * gyred))) > 255)
                {
                    red = 255;
                }
                if ((blue = round(sqrt(gxblue * gxblue + gyblue * gyblue))) > 255)
                {
                    blue = 255;
                }
                if ((green = round(sqrt(gxgreen * gxgreen + gygreen * gygreen))) > 255)
                {
                    green = 255;
                }

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i == height - 1 && j != width - 1 && j != 0) // edge 3
            {
                gxred = (0 * holder[i][j].rgbtRed + -2 * holder[i][j - 1].rgbtRed + 0 * holder[i - 1][j].rgbtRed +
                         -1 * holder[i - 1][j - 1].rgbtRed + 1 * holder[i - 1][j + 1].rgbtRed + 2 * holder[i][j + 1].rgbtRed);
                gyred = (0 * holder[i][j].rgbtRed + 0 * holder[i][j - 1].rgbtRed + -2 * holder[i - 1][j].rgbtRed +
                         -1 * holder[i - 1][j - 1].rgbtRed + -1 * holder[i - 1][j + 1].rgbtRed + 0 * holder[i][j + 1].rgbtRed);

                gxblue = (0 * holder[i][j].rgbtBlue + -2 * holder[i][j - 1].rgbtBlue + 0 * holder[i - 1][j].rgbtBlue +
                          -1 * holder[i - 1][j - 1].rgbtBlue + 1 * holder[i - 1][j + 1].rgbtBlue + 2 * holder[i][j + 1].rgbtBlue);
                gyblue = (0 * holder[i][j].rgbtBlue + 0 * holder[i][j - 1].rgbtBlue + -2 * holder[i - 1][j].rgbtBlue +
                          -1 * holder[i - 1][j - 1].rgbtBlue + -1 * holder[i - 1][j + 1].rgbtBlue + 0 * holder[i][j + 1].rgbtBlue);

                gxgreen = (0 * holder[i][j].rgbtGreen + -2 * holder[i][j - 1].rgbtGreen + 0 * holder[i - 1][j].rgbtGreen +
                           -1 * holder[i - 1][j - 1].rgbtGreen + 1 * holder[i - 1][j + 1].rgbtGreen + 2 * holder[i][j + 1].rgbtGreen);
                gygreen = (0 * holder[i][j].rgbtGreen + 0 * holder[i][j - 1].rgbtGreen + -2 * holder[i - 1][j].rgbtGreen +
                           -1 * holder[i - 1][j - 1].rgbtGreen + -1 * holder[i - 1][j + 1].rgbtGreen + 0 * holder[i][j + 1].rgbtGreen);

                if ((red = round(sqrt(gxred * gxred + gyred * gyred))) > 255)
                {
                    red = 255;
                }
                if ((blue = round(sqrt(gxblue * gxblue + gyblue * gyblue))) > 255)
                {
                    blue = 255;
                }
                if ((green = round(sqrt(gxgreen * gxgreen + gygreen * gygreen))) > 255)
                {
                    green = 255;
                }

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else if (i == 0 && j != 0 && j != width - 1) // edge 4
            {
                gxred = (0 * holder[i][j].rgbtRed + -2 * holder[i][j - 1].rgbtRed + 0 * holder[i + 1][j].rgbtRed +
                         -1 * holder[i + 1][j - 1].rgbtRed + 2 * holder[i][j + 1].rgbtRed + 1 * holder[i + 1][j + 1].rgbtRed);
                gyred = (0 * holder[i][j].rgbtRed + 0 * holder[i][j - 1].rgbtRed + 2 * holder[i + 1][j].rgbtRed +
                         1 * holder[i + 1][j - 1].rgbtRed + 0 * holder[i][j + 1].rgbtRed + 1 * holder[i + 1][j + 1].rgbtRed);

                gxblue = (0 * holder[i][j].rgbtBlue + -2 * holder[i][j - 1].rgbtBlue + 0 * holder[i + 1][j].rgbtBlue +
                          -1 * holder[i + 1][j - 1].rgbtBlue + 2 * holder[i][j + 1].rgbtBlue + 1 * holder[i + 1][j + 1].rgbtBlue);
                gyblue = (0 * holder[i][j].rgbtBlue + 0 * holder[i][j - 1].rgbtBlue + 2 * holder[i + 1][j].rgbtBlue +
                          1 * holder[i + 1][j - 1].rgbtBlue + 0 * holder[i][j + 1].rgbtBlue + 1 * holder[i + 1][j + 1].rgbtBlue);

                gxgreen = (0 * holder[i][j].rgbtGreen + -2 * holder[i][j - 1].rgbtGreen + 0 * holder[i + 1][j].rgbtGreen +
                           -1 * holder[i + 1][j - 1].rgbtGreen + 2 * holder[i][j + 1].rgbtGreen + 1 * holder[i + 1][j + 1].rgbtGreen);
                gygreen = (0 * holder[i][j].rgbtGreen + 0 * holder[i][j - 1].rgbtGreen + 2 * holder[i + 1][j].rgbtGreen +
                           1 * holder[i + 1][j - 1].rgbtGreen + 0 * holder[i][j + 1].rgbtGreen + 1 * holder[i + 1][j + 1].rgbtGreen);

                if ((red = round(sqrt(gxred * gxred + gyred * gyred))) > 255)
                {
                    red = 255;
                }
                if ((blue = round(sqrt(gxblue * gxblue + gyblue * gyblue))) > 255)
                {
                    blue = 255;
                }
                if ((green = round(sqrt(gxgreen * gxgreen + gygreen * gygreen))) > 255)
                {
                    green = 255;
                }

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
            else
            {
                gxred = (0 * holder[i][j].rgbtRed + 2 * holder[i][j + 1].rgbtRed) + (0 * holder[i + 1][j].rgbtRed +
                        1 * holder[i + 1][j + 1].rgbtRed) + (-1 * holder[i + 1][j - 1].rgbtRed + -2 * holder[i][j - 1].rgbtRed) +
                        (1 * holder[i - 1][j + 1].rgbtRed + 0 * holder[i - 1][j].rgbtRed + -1 * holder[i - 1][j - 1].rgbtRed);
                gyred = (0 * holder[i][j].rgbtRed + 0 * holder[i][j + 1].rgbtRed) + (2 * holder[i + 1][j].rgbtRed +
                        1 * holder[i + 1][j + 1].rgbtRed) + (1 * holder[i + 1][j - 1].rgbtRed + 0 * holder[i][j - 1].rgbtRed) +
                        (-1 * holder[i - 1][j + 1].rgbtRed + -2 * holder[i - 1][j].rgbtRed + -1 * holder[i - 1][j - 1].rgbtRed);

                gxblue = (0 * holder[i][j].rgbtBlue + 2 * holder[i][j + 1].rgbtBlue) + (0 * holder[i + 1][j].rgbtBlue +
                         1 * holder[i + 1][j + 1].rgbtBlue) + (-1 * holder[i + 1][j - 1].rgbtBlue +
                                 -2 * holder[i][j - 1].rgbtBlue) + (1 * holder[i - 1][j + 1].rgbtBlue + 0 * holder[i - 1][j].rgbtBlue +
                                         -1 * holder[i - 1][j - 1].rgbtBlue);
                gyblue = (0 * holder[i][j].rgbtBlue + 0 * holder[i][j + 1].rgbtBlue) + (2 * holder[i + 1][j].rgbtBlue +
                         1 * holder[i + 1][j + 1].rgbtBlue) + (1 * holder[i + 1][j - 1].rgbtBlue +
                                 0 * holder[i][j - 1].rgbtBlue) + (-1 * holder[i - 1][j + 1].rgbtBlue + -2 * holder[i - 1][j].rgbtBlue +
                                         -1 * holder[i - 1][j - 1].rgbtBlue);

                gxgreen = (0 * holder[i][j].rgbtGreen + 2 * holder[i][j + 1].rgbtGreen) + (0 * holder[i + 1][j].rgbtGreen +
                          1 * holder[i + 1][j + 1].rgbtGreen) + (-1 * holder[i + 1][j - 1].rgbtGreen + -2 * holder[i][j - 1].rgbtGreen) +
                          (1 * holder[i - 1][j + 1].rgbtGreen + 0 * holder[i - 1][j].rgbtGreen +
                           -1 * holder[i - 1][j - 1].rgbtGreen);
                gygreen = (0 * holder[i][j].rgbtGreen + 0 * holder[i][j + 1].rgbtGreen) + (2 * holder[i + 1][j].rgbtGreen +
                          1 * holder[i + 1][j + 1].rgbtGreen) + (1 * holder[i + 1][j - 1].rgbtGreen +
                                  0 * holder[i][j - 1].rgbtGreen) + (-1 * holder[i - 1][j + 1].rgbtGreen +
                                          -2 * holder[i - 1][j].rgbtGreen + -1 * holder[i - 1][j - 1].rgbtGreen);

                if ((red = round(sqrt(gxred * gxred + gyred * gyred))) > 255)
                {
                    red = 255;
                }
                if ((blue = round(sqrt(gxblue * gxblue + gyblue * gyblue))) > 255)
                {
                    blue = 255;
                }
                if ((green = round(sqrt(gxgreen * gxgreen + gygreen * gygreen))) > 255)
                {
                    green = 255;
                }

                image[i][j].rgbtBlue = blue;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
            }
        }
    }

    return;
}
///
///
///
