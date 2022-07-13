#include <stdbool.h>
#include "sequence.h"

// A module for working with sequences

// NOTE: each of the following requires that all pointers are not NULL


// sequence_add_one(seq) modifies seq by adding 1 to each item
// effects: modifies seq
void sequence_add_one(struct sequence *seq);


// sequence_build(n) returns a NEW sequence of length n
//   with the items 0, 1, ..., n-1
struct sequence *sequence_build(int n);


// sequence_map(fp, seq) applices fp to each item (eg., item_k = fp(item_k))
// effects: modifies seq
void sequence_map(int (* fp)( int ), struct sequence *seq);


// sequence_equal(seq1, seq2) determines if seq1 and seq2 are identical
bool sequence_equal(const struct sequence *seq1, const struct sequence *seq2);


// sequence_add_sum(seq) modifies seq so that each item (item_k) is the
//   sum of itself and all previous items (item_k = item_0 + ... item_k)
//   for example, the sequence (1,2,3)->(1,1+2,1+2+3)->(1,3,6)
// effects: modifies seq
void sequence_add_sum(struct sequence *seq);


// sequence_avg_and_variance(seq, &avg, &var) modifies avg and var
//   to store the average (mean) of all items
//   and the variance of all items.
//   The variance is calculated by summing over all items the difference
//   between the item and the average squared, divided by the number of items
//     sum [(item_k - avg)^2] / length
// notes:    uses simple integer arithmetic and division [rounds toward zero]
// requires: length(seq) > 0
// effects:  modifies *avg and *var
void sequence_avg_and_variance(const struct sequence *seq, int *avg, int *var);



// sequence_filter(fp, seq) removes all items from seq for which fp(item)
//   is false
// effects: modifies seq
void sequence_filter(bool (*fp)(int), struct sequence *seq);


// sequence_foldl(fp, base, seq) applies the foldl function (from Racket)
//   to the elements of seq, starting with the initial value of base.
//   in other words, fp(item_n-1, ... fp(item_1, fp(item_0, base)))
//   if seq is empty, it returns base
int sequence_foldl(int (*fp)(int, int), int base, const struct sequence *seq);
