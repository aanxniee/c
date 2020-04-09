#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// define the block size
#define SIZE 512
typedef uint8_t BYTE; // create a data type called byte

int main(int argc, char *argv[])
{
    // if the command line does not have 2 commands, display error
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // create a string called file and set it to the command line argument
    char *file = argv[1];

    // open the file for reading
    FILE *inptr = fopen(file, "r");

    // if the file cannot be opened, display error message
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s\n", file);
        return 2;
    }

    // create a buffer arrah and a count to count the number of recovered images
    BYTE buffer[SIZE];
    int counter = 0;

    // create an array to store the jpegs and a file pointer
    char picture[8];
    FILE *outptr = NULL;

    while (fread(buffer, sizeof(buffer), 1, inptr) == 1)
    {
        // check for a jpeg header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if it is not the first jpg image, close the already opened file
            if (counter > 0)
            {
                fclose(outptr);

                // name the file that is being created with the jpeg
                sprintf(picture, "%03i.jpg", counter);
                counter += 1; // increment the counter

                // open the new file for writing and write to it
                outptr = fopen(picture, "w");
                fwrite(buffer, sizeof(buffer), 1, outptr);
            }

            // if it is the first jpg image, no files need to be closed
            if (counter == 0)
            {
                // name the file that is being created with the jpeg
                sprintf(picture, "%03i.jpg", counter);
                counter += 1; // increment the counter

                // open the new file for writing and write to it
                outptr = fopen(picture, "w");
                fwrite(buffer, sizeof(buffer), 1, outptr);
            }
        }

        // if a file is ope, write to it
        else if (counter > 0)
        {
            fwrite(buffer, sizeof(buffer), 1, outptr);
        }

    }

    // close the original file and the new file
    fclose(outptr);
    fclose(inptr);

    return 0;


}
