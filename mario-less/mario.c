#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    //This where i use do while loop to take Piramid hight
    do
    {
        h = get_int("Height(1 to 8): ");
    }
    while (h < 1 || h >  8);     //this is condition prompt ask question if input is not desired
    int n = 0;
    for (int i = 0; i < h;)       //this is loop to create pyramids height i removed incrementation
    {
        n++;
        while (i < h - 1)         //this is loop to to create spaces before upper levels
        {
            printf(" ");
            i++;
        }
        for (i = 0; i < n; i++)    //this is loop to include no. of "#" to include according to level
        {
            printf("#");
        }
        printf("\n");
    }
}