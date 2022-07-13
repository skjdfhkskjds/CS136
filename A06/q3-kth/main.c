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

#include <stdio.h>
#include "cs136-trace.h"
#include "array-helpers.h"

// This program reads integers from input stores them in an array
// and then executes queries/requests to find the kth largest element
// in the input

// Assume that the length of the array is n and the number of 
//   queries/requests in the input is m.
// Your efficiency analysis below must be framed in terms of n and m
// NOTE: That although MAX_LEN is a constant here
//       when analysing efficency -- assume that the array can be any length
// time: O(m * n log n)

// Use this for maximum length of an array
// DO NOT TREAT THIS AS A CONSTANT WHEN ANALYZING EFFICIENCY
static const int MAX_LEN = 10000;

int main(void) {
    const char ARRAY_READ[] = "array_read";
    const char KTH[] = "kth";
    int A_READ = lookup_symbol(ARRAY_READ);
    int K = lookup_symbol(KTH);
    int input[10000] = {0};
    int count = 0;
    int in = read_symbol();
    while (in != INVALID_SYMBOL) {
        if (in == A_READ) {
            count = array_read(input, MAX_LEN);
            merge_sort(input, count);
        } else if (in == K) {
            int n = 0;
            if (scanf("%d", &n) == 1) {
                if (n >= 1 && n <= count) {
                    int k = count - n;
                    printf("%d: %d\n", n, input[k]);
                } else {
                    printf("%d: Error\n", n);
                }
            }
        }
        in = read_symbol();
    }
}
