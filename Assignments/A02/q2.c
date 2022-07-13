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

// Use these strings in your solutions:
// "Warning: positive overflow detected for a = %d, b = %d!\n"
// "Warning: negative overflow detected for a = %d, b = %d!\n"

void print_message(int a, int b, int error) {
    if (error == INT_MAX) {
        printf("Warning: positive overflow detected for a = %d, b = %d!\n", a, b);
    }
    else {
        printf("Warning: negative overflow detected for a = %d, b = %d!\n", a, b);
    }
}

int saturation_add(int a, int b) {
    if (a > 0 && b > 0 && (a > INT_MAX - b || b > INT_MAX - a)) {
        print_message(a, b, INT_MAX);
        return INT_MAX;
    }
    else if (a < 0 && b < 0 && (a < INT_MIN - b || b < INT_MIN - a)) {
        print_message(a, b, INT_MIN);
        return INT_MIN;
    }
    return (a + b);
}

int saturation_sub(int a, int b) {
    if (a > 0 && b < 0 && a > INT_MAX + b ) {
        print_message(a, b, INT_MAX);
        return INT_MAX;
    }
    else if (a < 0 && b > 0 && a < INT_MIN + b) {
        print_message(a, b, INT_MIN);
        return INT_MIN;
    }
    return (a - b);
}

// int up_div(int a, int b) {
//     int result = a / b;
//     if (result < 0) {
//         return (result - 1);
//     }
//     return (result + 1);
// }

int saturation_mult(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    
    if (a > 0 && b > 0 && (a > INT_MAX / b || b > INT_MAX / a)) {
        print_message(a, b, INT_MAX);
        return INT_MAX;
    }
    else if (a < 0 && b < 0 && (a < INT_MAX / b || b < INT_MAX / a)) {
        print_message(a, b, INT_MAX);
        return INT_MAX;
    }
    //catches INT_MIN / -1 = INT_MAX + 1
    else if ((a == -1 && b > 0) || (b == -1 && a > 0)) {
        return (a * b);
    } 
    else if (a > 0 && b < 0 && (a > INT_MIN / b || b < INT_MIN / a)) {
        print_message(a, b, INT_MIN);
        return INT_MIN;
    }
    else if (a < 0 && b > 0 && (a < INT_MIN / b || b > INT_MIN / a)) {
        print_message(a, b, INT_MIN);
        return INT_MIN;
    }
    return (a * b);
}

int main(void) {
    //add tests
    assert(saturation_add(2, 2) == 4);
    assert(saturation_add(INT_MAX, 1) == INT_MAX);
    assert(saturation_add(INT_MIN, -1) == INT_MIN);
    assert(saturation_add(INT_MIN + 1, INT_MIN) == INT_MIN);
    assert(saturation_add(-1, INT_MIN) == INT_MIN);  
    assert(saturation_add(-1, -3) == -4);

    //sub tests
    assert(saturation_sub(5, 1) == 4);
    assert(saturation_sub(INT_MIN, 1) == INT_MIN);
    assert(saturation_sub(-1, INT_MIN) == INT_MAX);
    assert(saturation_sub(1, INT_MIN) == INT_MAX);
    assert(saturation_sub(INT_MAX, -1) == INT_MAX);
    assert(saturation_sub(-1, -1) == 0);
    assert(saturation_sub(-1, 1) == -2);

    //multiplication tests
    assert(saturation_mult(2, 2) == 4);
    assert(saturation_mult(2, INT_MAX) == INT_MAX);
    assert(saturation_mult(INT_MAX, 2) == INT_MAX);
    assert(saturation_mult(-2, INT_MIN) == INT_MAX);
    assert(saturation_mult(-1, INT_MIN) == INT_MAX);
    assert(saturation_mult(-2, INT_MAX) == INT_MIN);
    assert(saturation_mult(-1, INT_MAX) == (INT_MIN + 1));
    assert(saturation_mult(2, INT_MIN) == INT_MIN);
    assert(saturation_mult(INT_MIN, 2) == INT_MIN);
    assert(saturation_mult(-2, -2) == 4);
    assert(saturation_mult(-2, 2) == -4);
    assert(saturation_mult(2, -2) == -4);
}
