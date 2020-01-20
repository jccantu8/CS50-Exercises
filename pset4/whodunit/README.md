# Questions

## What's `stdint.h`?

TODO: To create new integer types that will be guaranteed to work on all systems.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

TODO: States how the data will be used.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

TODO: 1, 4, 4, 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

TODO: The first two bytes of a BMP is a WORD and denotes bfType, which specifies the file type. It must be
 	set to the signature word BM (0x4D42) to indicate bitmap.

## What's the difference between `bfSize` and `biSize`?

TODO: bfSize is the number of bytes in the bitmap file whereas bisize is the number of bytes required by the structure

## What does it mean if `biHeight` is negative?

TODO: the bitmap is a top-down Device Independent Bitmap and its origin is the upper-left corne

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

TODO: biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

TODO: no file pointer may be returned (i.e. no file to open)

## Why is the third argument to `fread` always `1` in our code?

TODO: there is only 1 file header and info header

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

TODO: 3

## What does `fseek` do?

TODO: sets the file position of the stream to the given offset (skips over padding)

## What is `SEEK_CUR`?

TODO: It moves file pointer position to given location.

## Whodunit?

TODO: It was Professor Plum with the candlestick in the library
