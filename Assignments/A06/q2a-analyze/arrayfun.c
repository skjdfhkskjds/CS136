#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrayfun.h"

// see arrayfun.h for documentation

int max_diff(const int a[], int len) {
  assert(a);
  assert(len > 0);
  // note: if len == 1, returns 0
  int diff = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (abs(a[j] - a[i]) > diff) {
        diff = abs(a[j] - a[i]);
      }
    }
  }
  return diff;
} 

int select_k(int a[], int len, int k) {
  assert(a);
  assert(len > 0);
  assert(k < len);
  assert(k >= 0);
  // note: if k is 0, returns minimum value
  //       if k is len-1, returns maximum
  int min = a[0];
  for (int i = 1; i < len; ++i) {
    if (a[i] < min) {
      min = a[i];
    }
  }

  while (k) {
    int last_min = min;
    min = a[0];
    for (int i = 1; i < len; ++i) {
      if (a[i] > last_min && (a[i] < min || min <= last_min)) {
        min = a[i];
      }
    }
    --k;
  }
  return min;
}


int greater_sum(int a[], int b[], int len) {
  assert(a);
  assert(b);
  assert(len > 0);
  int sum = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len; ++j) {
      if (b[j] < a[i]) {
        ++sum;
      }
    }
  }
  return sum;
}

