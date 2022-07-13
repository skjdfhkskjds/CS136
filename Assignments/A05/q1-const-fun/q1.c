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

#include <assert.h>
#include <stdio.h>
#include "const-fun.h"

/////////////////////////////////////////////////////////////////////////////
// BLACK QUESTION


// see const-fun.h
void even_odd(const int a[], int len, int *even, int *odd) {
    assert(len > 0);
    assert(a);
    int total_even = 0;
    int total_odd = 0;

    for (int i = 0; i < len; ++i) {
        if ((a[i] % 2) == 0) {
            total_even++;
        } else {
            total_odd++;;
        }
    }
    *even = total_even;
    *odd = total_odd;
    return;
}

/////////////////////////////////////////////////////////////////////////////
// GOLD QUESTIONS


// see const-fun.h
int most_freq(const int a[], int len) {
    assert(len > 0);
    assert(a);
    int max_count = 0;
    int most_freq = a[0];

    for (int i = 0; i < len; ++i) {
        // breaks loop since remaining total cannot exceed the max count
        if (max_count > len - i) {
            break;
        }

        int count = 0;

        for (int j = i; j < len; ++j) {
            if (a[i] == a[j]) {
                count++;
            }
        }

        if (count > max_count) {
            max_count = count;
            most_freq = a[i];
        }
    }
    return most_freq;
}


// see const-fun.h
int longest_arith_prog(const int a[], int len) {
    assert(len > 0);
    assert(a);
    // base cases
    if (len == 1 || len == 2) {
        return len;
    }

    // if not base case, max_len is min 2
    int max_len = 2;

    for (int i = 0; i < len - 1; ++i) {
        int difference = a[i + 1] - a[i];
        int count = 2;
        for (int j = i + 1; j < len - 1; ++j) {
            if (a[j + 1] - a[j] != difference) {
                break;
            }
            count++;
        }

        // updates max_len
        max_len = (count > max_len) ? count : max_len;
    }
    return max_len;
}


// see const-fun.h
int largest_sum_of_n(const int a[], int len, int n) {
    assert(len > 0);
    assert(1 <= n);
    assert(n <= len);
    assert(a);
    int max_sum = 0;

    for (int i = 0; i < (len - n + 1); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += a[i + j];
        }

        // updates max_sum
        max_sum = (sum > max_sum) ? sum : max_sum;
    }
    return max_sum;
}
