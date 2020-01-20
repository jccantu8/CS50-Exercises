// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

//Contains the structs used here
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy scale_factor infile outfile\n");
        return 1;
    }

    //convert our scale factor into an integer
    int n = atoi(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    //make sure file can be opened
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER (fread("where to store read info, size of elements, # of elements, "where to get info from iput"))
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER (fwrite("where to get info, size of elements, # of elements, "where to store info in output"))
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines in the INPUT file
    int oldpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //original width and height of bitmap image
    int oldheight = abs(bi.biHeight);
    int oldwidth = abs(bi.biWidth);

    //new width and height of bitmap image after scaling by n
    bi.biWidth *= n;
    bi.biHeight *= n;

    // determine padding for scanlines in the OUTPUT file
    int newpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //calculate new sizes of bitmap for the OUTPUT file after scaling by n
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + newpadding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0; i < oldheight; i++)
    {
        //vertical scaling
        for (int z = 0; z < n - 1; z++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < oldwidth; j++)
            {

                // temporary storage create variable triple of type RGBTRIPLE defined in bmp.h
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile; horizontal scaling
                for (int m = 0; m < n; m++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }

            // add newpadding to output file
            for (int a = 0; a < newpadding; a++)
            {
                fputc(0x00, outptr);
            }

            // set cursor at beginning of scanline in order to read it once more for vertical scaling
            fseek(inptr, -oldwidth*sizeof(RGBTRIPLE), SEEK_CUR);

        }

        //repeat(write) the current row one last time before moving to next row to scan and scale
        for (int j = 0; j < oldwidth; j++)
        {
            RGBTRIPLE triple;

            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            for (int m = 0; m < n; m++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        // add newpadding to the output file for the final time to the current row
        for (int a = 0; a < newpadding; a++)
        {
            fputc(0x00, outptr);
        }

        // skip to the end of the scanline in order to read the next row from the input file
        fseek(inptr, oldpadding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}