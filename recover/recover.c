#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    //cheking count of argument and telling right way
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    else
    {
        //opening file
        FILE *file = fopen(argv[1], "r");
        if (file == NULL)
        {
            printf("could not open %s\n", argv[1]);
            return 1;
        }
        //creating buffer

        BYTE buffer[512];
        int flag = 1;
        char *name = malloc(10 * sizeof(char));
        if (name == NULL)
        {
            printf("ran out of memory");
            return 2;
        }
        int i = 1;
        int counter = 1;
        FILE *img = fopen("000.jpg", "w"); //file img pointer
        //reading
        while (fread(buffer, sizeof(BYTE), 512, file) == 512)
        {
            // checking for first jpeg file
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                if (flag == 1)
                {

                    fwrite(buffer, 1, 512, img);//writing
                    flag = 0;
                }
                else
                {
                    fclose(img);
                    counter++;
                    //setting name
                    while (i < counter)
                    {
                        sprintf(name, "%03i.jpg", i);
                        i++;
                    }
                    img = fopen(name, "w");
                    fwrite(buffer, 1, 512, img);
                }

            }
            //if already exist close and open new file

            else
            {
                if (flag == 0)
                {

                    fwrite(buffer, 1, 512, img);

                }
            }

        }
        fclose(file);
        fclose(img);
        free(name);

    }
}
