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

#include "cs136-trace.h"
#include "expt.h"

// see expt.h for reference
double fast_expt(double x, int n) {
    assert(n >= 0);
    int result = 0;
    if (n == 1) {
        return x;
    } else if (n % 2 == 0) {
        result = fast_expt(x * x, n / 2);
    } else {
        result = x * fast_expt(x * x, (n - 1) / 2);
    }
  return result;
}