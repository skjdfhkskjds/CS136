/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS (v2)

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
//
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff, which you do not have to mention)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from and/or collaborated with: None

// Name: Colin Chu
// login ID: ckychu
/////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "set.h"
#include "array-helpers.h"
#include "cs136-trace.h"
/**************************************
 * DO NOT CHANGE THIS VALUE.  FOR REAL*
 *************************************/       
const int SET_MAX = 1000;


// see .h
void set_init(struct set *s) {
  assert(s);
  s->count = 0;
}


// see .h
int set_count(const struct set *s) {
  assert(s);
  return s->count;
}

// see .h
bool set_member(const struct set *s, int item) {
    if (s->count == 0) {
        return false;
    }
    int high = s->count - 1;
    int low = 0;
    while (low <= high) {
        int mid = (high + low) / 2;
        //trace_int(s->data[mid]);
        if (s->data[mid] == item) {
            return true;
        } else if (s->data[mid] < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

// see .h
void set_add(struct set *s, int item) {
    if (set_member(s, item)) {
        return;
    }
    assert(s->count + 1 < SET_MAX);
    int pos = 0;
    for (int i = 0; i < s->count; ++i) {
        if (s->data[i] > item) {
            pos = i;
        }
    }
    for (int i = s->count - 1; i > pos; --i) {
        s->data[i + 1] = s->data[i];
    }
    s->data[pos] = item;
    s->count = s->count + 1;
}

// see .h
void set_remove(struct set *s, int item) {
    if (!set_member(s, item)) {
        return;
    }
    if (item == s->data[s->count - 1]) {
        s->data[s->count - 1] = 0;
        s->count = s->count - 1;
        return;
    }
    for (int i = 0; i < s->count - 1; ++i) {
        if (item > s->data[i]) {
            continue;
        } else {
            s->data[i] = s->data[i + 1];
        }
    }
    s->count = s->count - 1;
}


// see .h
void set_union(struct set *dest, const struct set *a, const struct set *b) {
    assert(dest != a);
    assert(dest != b);
    for (int i = 0; i < a->count; ++i) {
        dest->data[i] = a->data[i];
    }
    dest->count = a->count;
    for (int i = 0; i < b->count; ++i) {
        if (set_member(dest, b->data[i])) {
            continue;
        }
        assert(dest + i + a->count);
        dest->data[i + a->count] = b->data[i];
        dest->count = dest->count + 1;
    }
    merge_sort(dest->data, dest->count);
}

// see .h
void set_intersect(struct set *dest, const struct set *a, const struct set *b) {
    assert(dest != a);
    assert(dest != b);
    dest->count = 0;
    int a_count = 0;
    int b_count = 0;
    while (a_count <= a->count && b_count <= b->count) {
        if (a->data[a_count] == b->data[b_count]) {
            dest->data[dest->count] = a->data[a->count];
            dest->count = dest->count + 1;
            a_count++;
            b_count++;
        } else if (a->data[a_count] > b->data[b_count]) {
            b_count++;
        } else {
            a_count++;
        }
    }
}

// see .h
void array_to_set(struct set *dest, const int src[], int len) {
    assert(0 < len);
    assert(len <= SET_MAX);
    for (int i = 0; i < len; ++i) {
        dest->data[i] = src[i];
    }
    merge_sort(dest->data, len);
    int prev = dest->data[0];
    int count = 1;
    for (int i = 1; i < len; ++i) {
        if (dest->data[i] != prev) {
        dest->data[count] = dest->data[i];
        prev = dest->data[i];
        count++;
        }
    }
    dest->count = count;
}

// see .h
void set_print(const struct set *s) {
    printf("{");
    for (int i = 0; i < s->count - 1; ++i) {
        printf("%d, ", s->data[i]);
    }
    printf("%d}\n", s->data[s->count - 1]);
}
