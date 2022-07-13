/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS (v2)

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
//
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff, which you do not have to mention)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from and/or collaborated with: None

// Name: Colin Chu
// login ID: ckychu
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int main(void) {
    char in = 0;
    int counter = 0;
    while (scanf("%c", &in) == 1) {
        if (in == '(') {
            counter++;
        }
        else if (in == ')') {
            counter--;
        }
    }
    if (counter == 0) {
        printf("balanced\n");
    }
    else {
        printf("unbalanced\n");
    }
}