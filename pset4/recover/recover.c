#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//define BYTE as a type of unsigned 8 bit integer
typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover image\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    // open input (memory card) file
    FILE *inptr = fopen(infile, "r");

    //make sure file can be opened
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //declare an array called buffer of type BYTE with 512 elements
    BYTE buffer[512] = {0};
    //declare ans as a var of type size_t. This will be used to store the returned value of our fread calls
    size_t ans;
    //initialize a counter for the number of jpegs
    int counter = 0;
    //declare a file pointer to be used to write the jpegs
    FILE *img;
    //declare an array of 8 chars for our filenames that are of form "000.jpg" which is 7 chars but we also need the sentinel char
    char filename[8];

    //load the first block of 512 bytes into buffer
    ans = fread(buffer, 512, 1, inptr);

    //create while loop that executes only when we have blocks of 512 bytes to read from. This means the loop ends at EOF
    while (ans == 1)
    {
        //check first four bytes of buffer to determine if we are at the start of a jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //start first jpeg
            if (counter == 0)
            {
                //create a string for our filename based on counter
                sprintf(filename, "%03i.jpg", counter);
                //create a jpeg and write the current 512 bytes
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                //increment counter for the next jpeg
                counter++;
            }
            //start diff jpeg
            else
            {
                //close previous jpeg
                fclose(img);
                //create and write into the new jpeg
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                counter++;
            }
        }
        //enter this else statement when we arent at the start of a jpeg
        else
        {
            //enter this if statement once we have found our section of the memory card with contiguous jpeg bytes.
            // i.e. enter only once we've skipped the garbage data at the start of the memory card
            if (counter >= 1)
            {
                fwrite(buffer, 512, 1, img);
            }
        }

        // load next 512 bytes into buffer
        ans = fread(buffer, 512, 1, inptr);

     }

    //close last jpeg file
    fclose(img);

    //close memory card file
    fclose(inptr);


}