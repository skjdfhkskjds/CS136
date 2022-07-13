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
#include "mutable-fun.h"


/////////////////////////////////////////////////////////////////////////////
// BLACK QUESTION


// see mutable-fun.h
void add_max(int a[], int len) {
    assert(len > 0);
    assert(a);
    int max = 0;
    for (int i = 0; i < len; ++i) {
        max = (a[i] > max) ? a[i] : max;
    }

    for (int i = 0; i < len; ++i) {
        a[i] += max;
    }
}


/////////////////////////////////////////////////////////////////////////////
// GOLD QUESTIONS


// see mutable-fun.h
void partial_sums(int a[], int len) {
    assert(len > 0);
    assert(a);
    int partial_sum = 0;
    for (int i = 0; i < len; ++i) {
        int temp = a[i];
        a[i] += partial_sum;
        partial_sum += temp;
    }
}

// send_to_back(a[], len, pos) sends the element at pos to the back of a[]
// effects: modifies a[]
// requires: all elements in a[] are not NULL
//           0 <= pos < len
//           len > 0
//           a[] is of length len [NOT ASSERTED]
void send_to_back(int a[], int len, const int pos) {
    assert(len > 0);
    assert(a);
    int last = a[pos];
    for (int i = pos; i < len - 1; ++i) {
        a[i] = a[i + 1];
    }
    a[len - 1] = last;
}

// see mutable-fun.h
void even_before_odd(int a[], int len) {
    assert(len > 0);
    assert(a);
    int j = 0; //keeps track of "real" index
    for (int i = 0; i < len; ++i) {
        if ((a[j] % 2) != 0) {
            send_to_back(a, len, j);
            j--;
        }
        j++;
    }
}

// square(n) squares n
double square(double n) {
    return n * n;
}

// swap(a, b) swaps the values of a and b
// requires: a and b are not NULL
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// quick_sort(a[], first, last) sorts the array a
void quick_sort(int a[], int first, int last) {
    
	if (last <= first) return;
	
	int pivot = a[first];
	int pos = last;

	for (int i = last; i > first; --i) {
		if (a[i] > pivot) {
			swap(&a[pos], &a[i]);
			--pos;
		}
	}
	swap(&a[first], &a[pos]);
	quick_sort(a, first, pos - 1);
	quick_sort(a, pos + 1, last);
}

// sort(a[], len) wrapper function for quick_sort
// requires: all values in a are not NULL
void sort(int a[], int len) {
    assert(a);
	quick_sort(a, 0, len - 1);
}

// see mutable-fun.h
void get_statistics(int a[], int len, struct stats *s) {
    assert(len > 1);
    assert(s);
    assert(a);

    int min_so_far = a[0];
    int max_so_far = a[0];
    double sum = 0;
    double var_sum = 0;
    
    //gets the median
    sort(a, len);
    if (len % 2 == 0) {
        double mid = (a[(len / 2) - 1] + a[len / 2]);
        s->median = mid / 2;
    } else {
         s->median = a[len / 2];
    }

    for (int i = 0; i < len; ++i) {
        min_so_far = (a[i] < min_so_far) ? a[i] : min_so_far;
        max_so_far = (a[i] > max_so_far) ? a[i] : max_so_far;
        sum += a[i];
    }

    s->mean = (sum / len);
    for (int i = 0; i < len; ++i) {
        var_sum += square(a[i] - s->mean);
    }
    s->variance = var_sum / (len - 1);
    s->max = max_so_far;
    s->min = min_so_far;
}
