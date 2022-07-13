// This module provides a variety of array functions
// (that are not very cohesive)

// SEASHELL_READONLY

// For all of these functions:
//   * you must NOT define your own local arrays
//   * do not assume anything about the length of the array
//     (other than it is positive)

struct stats {
  int min;
  int max;
  double median;
  double mean;
  double variance;
};

// The following applies to all functions:
// requires: all array parameters are valid (not NULL)
//           all array length parameters (e.g., len) are > 0
//           all arrays are of the specified length [not asserted]

/////////////////////////////////////////////////////////////////////////////
// BLACK QUESTION

// add_max(a, len) modifies the elements of a so that the value of the 
//   largest element of a is added to each.
// examples: {1, 3, 6} => {7, 9, 12}
//           {1, 0, -1} => {2, 1, 0}
// effects: modifies a
void add_max(int a[], int len);


/////////////////////////////////////////////////////////////////////////////
// GOLD QUESTIONS


// partial_sums(a, len) modifies the elements of a so that each
//   element a[i] is equal to the sum of all elements in the original
//   array a[0]...a[i]
// examples: {1, 3, 6} => {1, 4, 10}
//           {1, 0, -1} => {1, 1, 0}
// effects: modifies a
void partial_sums(int a[], int len);


// even_before_odd(a, len) modifies a so that all the even numbers appear
//   before all of the odd numbers, preserving the original order of
//   even and odd numbers
// examples: {1, 2, 3, 4} => {2, 4, 1, 3}
//                           {2, 4, 3, 1} <- INCORRECT
//                           {4, 2, 1, 3} <- INCORRECT
//                           {4, 2, 3, 1} <- INCORRECT
//           {4, 3, 5, 0} => {4, 0, 3, 5}
// effects: modifies a [by rearranging the elements of a]
void even_before_odd(int a[], int len);


// get_statistics(a, len, s) modifies s to reflect statistics on elements of a
// notes: you may rearrange the elements of a if you wish
//        if there are an even number of elements, the median
//          is the average of the two middle elements (hence, the double type)
//        see the assignment text for calculating variance correctly
// example: {1, 3, 6} = {1, 6, 3.0, 3.33, 6.33}
// requires: len > 1
// effects: may modify a [by rearranging the elements of a]
//          modifies *s
void get_statistics(int a[], int len, struct stats *s);
