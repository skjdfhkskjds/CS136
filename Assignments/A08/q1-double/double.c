/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with: None

// Name: Colin Chu
// login ID: ckychu
/////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <string.h>
#include "double.h"

char *double_str(const char *s) {
    char *str = malloc((2 * strlen(s) * sizeof(char)) + 1);
    int len = 0;
    while (*s) {
        str[len] = *s;
        str[len + 1] = *s;
        len += 2;
        ++s;
    }
    str[len] = '\0';
    return str;
}