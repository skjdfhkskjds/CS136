// SEASHELL_READONLY

// A module that provides the Set ADT

#include <stdbool.h>

extern const int SET_MAX; // 1000

struct set {
  int count;
  int data[1000];
};

// All of the following functions require that set pointer is not NULL

// Unless otherwise stated, the n for efficiency is the count of the set
// (Technically n <= 1000 but we are ignoring this limit for the runtime analysis)

// set_init(s) initializes s as an empty set (count = 0)
// effects: s will be (re)initialized
// time: O(1)
void set_init(struct set *s);


// set_count(s) returns the number of unique elements in s
// time: O(1)
int set_count(const struct set *s);


// set_member(s, item) returns true if item is an element of s, false otherwise
// time: O(log n)
bool set_member(const struct set *s, int item);

// set_add(s, item) adds item to set s
// requires: s will not contain more than SET_MAX items after insert
// effects: set may be modified
// time: O(n) 
void set_add(struct set *s, int item);

// set_remove(s, item) removes item from set s, if it is present
// effects: set may be modified
// time: O(n)
void set_remove(struct set *s, int item);

// set_union(dest, a, b) mutates set dest to be the union of a and b
//  (in other words, items will be members of dest if and only if
//   they are members of either a OR b).
// requires: dest is neither a nor b
//           dest will not contain more than SET_MAX items after union
// effects: dest will be overwritten with new contents
// time: O(n log n) where n is the combined counts of a and b
void set_union(struct set *dest, const struct set *a, const struct set *b);

// set_intersect(dest, a, b) mutates set dest to be the intersection of a and b
//  (in other words, items will be members of test if and only if
//  they are members of both a AND b).
// requires: dest is neither a nor b
// effects: dest will be overwritten with new contents
// time: O(n) where n is the combined counts of a and b
void set_intersect(struct set *dest, const struct set *a, const struct set *b);

// array_to_set(dest, src, len) mutates set dest to contain the elements of
//  the array src
// requires: src has length >= len [not asserted]
//           0 < len <= SET_MAX
// effects: dest will be overwritten with new contents
// time: O(n log n) where n is the length of array src
void array_to_set(struct set *dest, const int src[], int len);

// set_print(s) prints the elements of s inside braces e.g. {1, 2, 3}
//  followed by a newline
// effects: outputs text
// time: O(n)
void set_print(const struct set *s);
