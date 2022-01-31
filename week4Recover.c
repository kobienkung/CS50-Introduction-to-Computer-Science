#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{

    FILE* ptr = fopen(argv[1], "r");

    if (ptr == NULL)
    {
        printf("Could not open %s", argv[1]);
        return 1;
    }

    int size = 512, count = 0, fileNo = -1;
    unsigned char buffer[size];
    FILE* picture;
    while (fread(buffer, size, 1, ptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0 ) == 0xe0)
        {
            count++;
            fileNo++;
            if (count == 2)
            {
                fclose(picture);
                count = 1;
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", fileNo);
            picture = fopen(filename, "a");
        }

        if (count == 1)
        {
            fwrite(buffer, size, 1, picture);
        }



    }
    fclose(picture);
    fclose(ptr);
}
