// This module provides a variety of array functions
// (that are not very cohesive)

// SEASHELL_READONLY

// For all of these functions:
//   * you cannot mutate any of the arrays
//   * you must NOT define your own local arrays
//   * do not assume anything about the length of the array
//     (other than it is positive)

// The following applies to all functions:
// requires: all array parameters are valid (not NULL)
//           all array length parameters (e.g., len) are > 0
//           all arrays are of the specified length [not asserted]

/////////////////////////////////////////////////////////////////////////////
// BLACK QUESTION


// even_odd(a, len, even, odd) sets *even/*odd to be the number of even/odd
//    integers in a
// examples: {1, 3, 6} => *even: 1, *odd: 2
//           {2, 4, 6} => *even: 3, *odd: 0
// effects: modifies *even, *odd
void even_odd(const int a[], int len, int *even, int *odd);


/////////////////////////////////////////////////////////////////////////////
// GOLD QUESTIONS

// most_freq(a, len) returns the most frequent element in a
// note: if there is a tie (more than one element is the most frequent)
//       it returns the most frequent element that occurs first in the array
// examples: {1, 3, 6} => 1
//           {1, 3, 3} => 3
int most_freq(const int a[], int len);


// longest_arith_prog(a, len) computes the length of the longest consectutive
//   arithmetic progression found in a
// notes: an arithmetic progression is a sequence of integers where the
//          distance between every pair of consecutive integers is the same
//        or in other words: in the form: a, a + b, a + 2*b, a + 3*b, ...
//        so the following are all arithmetic progressions:
//        (7), (1, 3), (10, 14, 18), (3, 3, 3), (9, 7, 5)
//        arrays of length 1 or 2 are always arithmetic progressions
// examples: {2, 7, 4, 1} => 3 [(7, 4, 1) is the longest with length 3]
//           {1, 3, 6} => 2 [(1, 3) and (3, 6) are both length 2]
int longest_arith_prog(const int a[], int len);


// largest_sum_of_n(a, len, n) computes the largest sum of n consecutive
//   integers found in a
// examples: for the array a = {1, 3, 6} (len = 3)
//           largest_sum_of_n(a, 3, 1) => 6
//           largest_sum_of_n(a, 3, 2) => 9
//           largest_sum_of_n(a, 3, 3) => 10
// requires: 1 <= n <= len
int largest_sum_of_n(const int a[], int len, int n);
