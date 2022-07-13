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
    struct stack *second_stack = stack_create();
    //first loop reads in values and pushes to input_stack
    // result: all symbols are now in reverse order (last read is on top)
    int in = read_symbol();
    while (in != INVALID_SYMBOL) {
        print_symbol(in);
        printf("\n");
        stack_push(in, input_stack);
        in = read_symbol();
    }
    //second loop reads input_stack values and prints + pushes to second_stack
    // result: all symbols are now in original order (first read is on top)
    while (!stack_is_empty(input_stack)) {
        int out = stack_pop(input_stack);
        print_symbol(out);
        printf("\n");
        stack_push(out, second_stack);
    }
    //third loop reads second_stack values and prints + pushes to third_stack
    // result: all symbols are now in reverse order (last read is on top)
    stack_destroy(input_stack);
    struct stack *third_stack = stack_create();
    while (!stack_is_empty(second_stack)) {
        int out = stack_pop(second_stack);
        print_symbol(out);
        printf("\n");
        stack_push(out, third_stack);
    }
    //fourth loop reads third_stack and prints all in reverse order
    stack_destroy(second_stack);
    while (!stack_is_empty(third_stack)) {
        int out = stack_pop(third_stack);
        print_symbol(out);
        printf("\n");
    }
    stack_destroy(third_stack);
}
