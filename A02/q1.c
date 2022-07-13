/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// Name: Colin Chu
// login ID: ckychu
/////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

int main(void)
{
    int words = 0;
    int characters = 0;
    int lines = 0;

    char prev_char = 1; // unused char

    while (1)
    {
        char input = read_char(0);
        if (input == READ_CHAR_FAIL)
        {
            if (prev_char != '\n')
            {
                if (prev_char != ' ')
                {
                    words++;
                }
                lines++;
            }
            break;
        }

        if (input == '\n')
        {
            if (prev_char != ' ' && prev_char != '\n')
            {
                words++;
            }
            lines++;
        }
        else if (input == ' ' && prev_char != ' ' && prev_char != '\n')
        {
            words++;
        }
        characters++;
        prev_char = input;
    }

    printf("Lines: %d\nWords: %d\nCharacters: %d\n", lines, words, characters);
}
