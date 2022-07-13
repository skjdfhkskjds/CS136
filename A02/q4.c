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
#include "equal.h"

// nth_root(a, n) returns the nth root of a.
// requires: n > 0
//           a has a real nth root (i.e. a cannot be negative if n is even)

double exponent(const double x, int n) {
    if (n == 0) {
        return 1;
    }
    if (x == 0 || x == 1) {
        return x;
    }

    double val = x;
    while (n > 1) {
        val *= x;
        n--;
    }
    return val;
}

double abs_val(double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

double nth_root(const double a, const int n) {
    if (a == 0 || a == 1) {
        return a;
    }

    double double_n = n;

    const double one_over_n = 1 / double_n;

    double x_k = a / n;
    double diff = abs_val(exponent(x_k, n) - a);

    while (!(is_almost_equal(diff, 0))) {
        double x_k1 = one_over_n * (((n - 1) * x_k) + (a / (exponent(x_k, (n - 1)))));
        x_k = x_k1;
        diff = abs_val(exponent(x_k, n) - a);
    }
    return x_k;
}

int main (void) {
    //exponent tests
    assert(exponent(1, 1) == 1);
    assert(exponent(3, 1) == 3);
    assert(exponent(3, 3) == 27);

    double result = nth_root(27.0, 3);
    assert(is_almost_equal(result, 3.0));
    assert(is_almost_equal(nth_root(16.0, 4), 2.0));
    assert(is_almost_equal(nth_root(16.0, 2), 4.0));
    assert(is_almost_equal(nth_root(1.0, 1), 1.0));
    assert(is_almost_equal(nth_root(0, 4), 0));
    assert(is_almost_equal(nth_root(16.0, 4), 2.0));
}