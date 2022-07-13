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
#include "cs136-trace.h"
#include "stack.h"

int main(void) {
    struct stack *input_stack = stack_create();
    int in = read_symbol();
    while (in != INVALID_SYMBOL) {
        print_symbol(in);
        printf("\n");
        stack_push(in, input_stack);
        in = read_symbol();
    }
    while (!stack_is_empty(input_stack)) {
        int out = stack_pop(input_stack);
        print_symbol(out);
        printf("\n");
    }
    stack_destroy(input_stack);
}
