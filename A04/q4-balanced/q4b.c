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
#include <stdbool.h>
#include "cs136-trace.h"
#include "stack.h"

bool opposites(char a, char b) {
    if ((a == '(' && b == ')')) {
        return true;
    }
    else if ((a == '{' || a == '<' || a == '[') && b == (a + 2)) {
        return true;
    }
    return false;
}

int main(void) {
    char in = 0;
    struct stack *open_stack = stack_create();
    struct stack *close_stack = stack_create();
    while (scanf("%c", &in) == 1) {
        if (in == '{' || in == '<' || in == '[' || in == '(') {
            stack_push(in, open_stack);
        }
        else if (in == '}' || in == '>' || in == ']' || in == ')') {
            stack_push(in, close_stack);
        }
    }
    //reverses the close stack
    struct stack *reverse_close_stack = stack_create();
    while (!stack_is_empty(close_stack)) {
        stack_push(stack_pop(close_stack), reverse_close_stack);
    }
    stack_destroy(close_stack);

    //checks if each corresponding element in both stacks are "opposites"
    while (!stack_is_empty(open_stack)) {
        if (stack_is_empty(reverse_close_stack)) {
            //garbage collection
            stack_destroy(open_stack);
            stack_destroy(reverse_close_stack);
            printf("unbalanced\n");
            return 0;
        }
        if (!opposites(stack_pop(open_stack), stack_pop(reverse_close_stack))) {
            //garbage collection
            stack_destroy(open_stack);
            stack_destroy(reverse_close_stack);
            printf("unbalanced\n");
            return 0;
        }
    }
    //if both stacks are empty, then each element was corresponding
    if (stack_is_empty(reverse_close_stack)) {
        //garbage collection
        stack_destroy(open_stack);
        stack_destroy(reverse_close_stack);
        printf("balanced\n");
        return 0;
    }
    //garbage collection
    stack_destroy(open_stack);
    stack_destroy(reverse_close_stack);
    printf("unbalanced\n");
}

