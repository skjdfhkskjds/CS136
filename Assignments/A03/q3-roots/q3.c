/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// Name: Colin Chu
// login ID: ckychu
/////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

double abs_val(double n) {
    if (n < 0) {
        return -n;
    }
    return n;
}


// bisection(f, lo, hi, tolerance) uses the bisection method to find a root
//   of f that exists between lo and hi such that |f(root)| <= tolerance
// requires: tolerance > 0
//           lo < hi
//           f(lo) * f(hi) < 0
//           f is "continuous" between lo and hi
double bisection(double (*f)(double), double lo, double hi, double tolerance) {
    assert(tolerance > 0);
    assert(lo < hi);
    assert(f(lo) * f(hi) < 0);

    double mid = (lo + hi) / 2;
    while (abs_val(f(mid)) > tolerance) {
        if ((f(lo) < 0) && (f(mid) < 0)) {
            lo = mid;
            mid = (lo + hi) / 2;
        }
        else if (f(lo) < 0) {
            hi = mid;
            mid = (lo + hi) / 2;
        }
        else if ((f(lo) >= 0) && (f(mid) < 0)) {
            hi = mid;
            mid = (lo + hi) / 2; 
        }
        else {
            lo = mid;
            mid = (lo + hi) / 2;
        }
    }
    return mid;
}


// poly_with_root_sqrt2(x) calculates x^2 - 2
double poly_with_root_sqrt2(double x) {
  return x * x - 2;
}


int main(void) {
  double root = bisection(poly_with_root_sqrt2, 1, 2, 0.00001);
  assert(root >= 1.41400 && root <= 1.41499);
}
