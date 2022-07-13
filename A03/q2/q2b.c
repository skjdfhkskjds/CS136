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

char lowercase(char c) {
    if (c >= 65 && c <= 90) {
        return (c + up_to_low);
    }
    return c;
}

bool is_letter(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return 1;
    }
    return 0;
}

int main(void) {
    char c = 0;
    int count = 0;
    while (scanf("%c", &c) == 1) {
        char out = lowercase(c);
        if ((count % 2) == 0) {
            printf("%c", out);
        }
        else if (is_letter(out)) {
            printf("%c", (out - up_to_low));
        }
        else {
            printf("%c", out);
        }

        if (is_letter(c)) {
            count++;
        }
    }
}