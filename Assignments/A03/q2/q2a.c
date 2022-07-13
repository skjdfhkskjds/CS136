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

const int up_to_low = 32;

int main(void) {
    char c = 0;
    while (scanf("%c", &c) == 1) {
        if (c >= 97 && c <= 122) {
            printf("%c", (c - up_to_low));
        }
        else {
            printf("%c", c);
        }
    }
}
