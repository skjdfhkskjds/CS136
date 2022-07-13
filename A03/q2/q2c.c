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

const int NOT_COMMENT = 0;
const int IN_LINE = 1;
const int MULT_LINE = 2;
const int STRING = 3;

int main(void) {
    char c = 0;
    char prev = 0;
    
    bool is_comment = 0;
    int comment_type = NOT_COMMENT;

    while (scanf("%c", &c) == 1) {
        if (is_comment && comment_type == 1 && c == '\n') {
            is_comment = 0;
            comment_type = NOT_COMMENT;
        }
        else if (is_comment && comment_type == 2 && c == '/' && prev == '*') {
            is_comment = 0;
            comment_type = NOT_COMMENT;
        }
        else if (comment_type == 3 && c == '"') {
            comment_type = NOT_COMMENT;
        }

        if (!is_comment && c == '"') {
            comment_type = STRING;
        }
        else if (!is_comment && c == '/' && prev == '/' && comment_type != STRING) {
            is_comment = 1;
            comment_type = IN_LINE;
        }
        else if (!is_comment && c == '*' && prev == '/' && comment_type != STRING) {
            is_comment = 1;
            comment_type = MULT_LINE;
        }
        else if (!is_comment && c == '/' && comment_type != STRING) {
            prev = c;
            continue;
        }

        if (!is_comment) {
            printf("%c", c);
        }

        prev = c;
    }
}
