// Helper functions for music

#include <cs50.h>

#include "helpers.h"

#include <math.h>

#include <string.h>

#include <stdlib.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    return (fraction[0] - 48) * (8 / (fraction[2] - 48));
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{

    int n;


    /*Use a switch statement to determine the amount of semitones our note is from A4 depending only on the letter*/
    switch (note[0])
    {
        case 'A':
            n = 0;
            break;
        case 'B':
            n = 2;
            break;
        case 'C':
            n = -9;
            break;
        case 'D':
            n = -7;
            break;
        case 'E':
            n = -5;
            break;
        case 'F':
            n = -4;
            break;
        case 'G':
            n = -2;
            break;
    }

    /*Adds a semitone if our note has a sharp in it while also calculating how many semitones our note is from A4 depending ont he Octave*/
    if (note[1] == '#')
    {
        n++;
        n += 12 * (note[2] - 52);
    }
    /*Adds a semitone if our note has a flat in it while also calculating how many semitones our note is from A4 depending ont he Octave*/
    else if (note[1] == 'b')
    {
        n--;
        n += 12 * (note[2] - 52);
    }
    else
        /*Adds the amount of semitones our note is from A4 depending on the octave*/
    {
        n += 12 * (note[1] - 52);
    }

    /*Calculate the frequency of our note by using the total amount of semitones our note is from A4*/
    return round(pow(2, n / 12.0) * 440);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
