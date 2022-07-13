///////////////////////////////////////////////////////////////////////////// 
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:a
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with: None
 
// Name: Colin Chu
// login ID: ckychu
///////////////////////////////////////////////////////////////////////////// 

#include <stdio.h>
#include <string.h>
#include "cs136-trace.h"

// main.c reads in words from I/O and prints the lexicographically first and 
// last string if at least one string is read and NO STRINGS otherwise.
// requires: each of the words read in are max 100 characters including the 
// null terminator [NOT ASSERTED]
// time: O(n - 1), where n is the total number of input words

const int MAX_LEN = 100;

int main(void) {
    char in[100];
    char first[100] = "";
    char last[100] = "";
    if (scanf("%s", &in) == 1) {
        strcpy(first, in);
        strcpy(last, in);
    } else {
        printf("NO STRINGS\n");
        return 1;
    }
    
    while (scanf("%s", &in) == 1) {
        if (strcmp(first, in) > 0) {
            strcpy(first, in);
        } else if (strcmp(last, in) < 0) {
            strcpy(last, in);
        }
    }

    printf("%s %s\n", first, last);
}
