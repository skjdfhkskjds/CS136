/////////////////////////////////////////////////////////////////////////////
// SEASHELL_READONLY
/////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>

// max_diff(a, len) finds the maximum difference between two elements in a
// time: O(n)
int max_diff(const int a[], int len);


// select(a, len) finds the kth smallest value out of of a  (starting from 0,
//    e.g. k=0 selects the smallest, k=len-1 selects the largest)
// requires: a is a valid array with len elements
//           all elements of a are distinct
//           0 <= k < len
// effects: a might be modified
// time:     O(n log n)
int select_k(int a[], int len, int k);


// greater_sum(a, b, len) counts, for all 0 <= i < len how many elements of b
//   are less than element a[i].  The function returns the sum of these counts.
// example:
//  if  a = {5, 3, 1} and  b = {3, 2, 1} then greater_sum(a, b, 3) == 5
//    * count for a[0] == 3 (3, 2, and 1 are less than a[0])
//    * count for a[1] == 2 (2, amd 1, but not 3, are all less than a[1])
//    * count for a[2] == 0 (none of 3, 2, or 1 less less than a[2])
//     3 + 2 + 0 == 5
// requires: a and b are valid arrays with len elements
// effects: a, b might be modified
// time: O(n log n)
int greater_sum(int a[], int b[], int len);


