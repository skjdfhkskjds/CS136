/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from the following sources: None

// Name: Colin Chu
// login ID: ckychu
/////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include "arrayfun.h"
#include "array-helpers.h"
#include "cs136-trace.h"

// see arrayfun.h for reference
int max_diff(const int a[], int len) {
    assert(a);
    assert(len > 0);
    if (len == 1) {
        return 0;
    }
    int min_so_far = a[0];
    int max_so_far = a[0];
    for (int i = 0; i < len; ++i) {
        min_so_far = (a[i] < min_so_far) ? a[i] : min_so_far;
        max_so_far = (a[i] > max_so_far) ? a[i] : max_so_far;
    }
    return (max_so_far - min_so_far);
}

// see arrayfun.h for reference
int select_k(int a[], int len, int k) {
    assert(a);
    assert(len > 0);
    assert(k < len);
    assert(k >= 0);
    merge_sort(a, len);
    return a[k];
}

// see arrayfun.h for reference
int greater_sum(int a[], int b[], int len) {
    assert(a);
    assert(b);
    assert(len > 0);
    int count = 0;
    int a_count = len - 1;
    int b_count = len - 1;
    merge_sort(a, len);
    merge_sort(b, len);
    while (a_count >= 0 && b_count >= 0) {
        if (a[a_count] > b[b_count]) {
            count += b_count + 1;
            a_count--;
        } else {
            b_count--;
        }
    }
    return count;
}
