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

#include <stdio.h>
#include <assert.h>
#include "sequence.h"
#include "seq-tools.h"



void sequence_add_one(struct sequence *seq) {
    assert(seq != NULL);
    int length = sequence_length(seq);
    for (int i = 0; i < length; i++) {
        int new = sequence_item_at(seq, i) + 1;
        sequence_remove_at(seq, i);
        sequence_insert_at(seq, i, new);
    }
}


struct sequence *sequence_build(int n) {
    struct sequence *seq = sequence_create();
    for (int i = 0; i < n; i++) {
        sequence_insert_at(seq, i, i);
    }
    return seq;
}


void sequence_map(int (*fp)(int), struct sequence *seq) {
    assert(seq != NULL);
    assert(fp != NULL);
    int length = sequence_length(seq);
    for (int i = 0; i < length; i++) {
        int new = fp(sequence_item_at(seq, i));
        sequence_remove_at(seq, i);
        sequence_insert_at(seq, i, new);
    }
}


/******************************************************************************
// DO NOT REMOVE THIS COMMENT BLOCK

These two geese are named "Black" and "Gold".
They are here to ensure your black & gold code is sufficiently separated
to avoid any "contamination" if you give/receive help on a black question.



                                       ___
                                   ,-""   `.
                                 ,'  _   e )`-._
                                /  ,' `-._<.===-'
                               /  /
                              /  ;
                  _          /   ;
     (`._    _.-"" ""--..__,'    |
     <_  `-""                     \
      <`-                          :
       (__   <__.                  ;
         `-.   '-.__.      _.'    /
            \      `-.__,-'    _,'
             `._    ,    /__,-'
                ""._\__,'< <____
                     | |  `----.`.
                     | |        \ `.
                     ; |___      \-``
                     \   --<
                      `.`.<
                 hjw    `-'


    
    

                                                            _...--.
                                            _____......----'     .'
                                      _..-''                   .'
                                    .'                       ./
                            _.--._.'                       .' |
                         .-'                           .-.'  /
                       .'   _.-.                     .  \   '
                     .'  .'   .'    _    .-.        / `./  :
                   .'  .'   .'  .--' `.  |  \  |`. |     .'
                _.'  .'   .' `.'       `-'   \ / |.'   .'
             _.'  .-'   .'     `-.            `      .'
           .'   .'    .'          `-.._ _ _ _ .-.    :
          /    /o _.-'     LGB       .--'   .'   \   |
        .'-.__..-'                  /..    .`    / .'
      .'   . '                       /.'/.'     /  |
     `---'                                   _.'   '
                                           /.'    .'
                                            /.'/.'


    
    
source: https://ascii.co.uk/art/goose    
******************************************************************************/


bool sequence_equal(const struct sequence *seq1, const struct sequence *seq2) {
    assert(seq1 != NULL);
    assert(seq2 != NULL);
    if (sequence_length(seq1) != sequence_length(seq2)) {
        return false;
    }
    int length = sequence_length(seq1);
    for (int i = 0; i < length; i++) {
        if (sequence_item_at(seq1, i) != sequence_item_at(seq2, i)) {
            return false;
        }
    }
  return true;
}


void sequence_add_sum(struct sequence *seq) {
    assert(seq != NULL);
    int sum = 0;
    int length = sequence_length(seq);
    for (int i = 0; i < length; i++) {
        int new = sequence_item_at(seq, i) + sum;
        sum += sequence_item_at(seq, i);
        sequence_remove_at(seq, i);
        sequence_insert_at(seq, i, new);
    }
}

int square(int x) {
    return x * x;
}

void sequence_avg_and_variance(const struct sequence *seq, 
                               int *avg, int *var) {
    assert(seq != NULL);
    assert(avg != NULL);
    assert(var != NULL);
    assert(sequence_length(seq) > 0);
    int sum = 0;
    int length = sequence_length(seq);
    for (int i = 0; i < length; i++) {
        sum += sequence_item_at(seq, i);
    }
    *avg = (sum / length);
    int var_sum = 0;
    for (int i = 0; i < length; i++) {
        var_sum += square(sequence_item_at(seq, i) - *avg);
    }
    *var = (var_sum / length);
}

void sequence_mutate(struct sequence *old, struct sequence *new) {
    int length = sequence_length(new);
    sequence_clear(old);
    for (int i = 0; i < length; i++) {
        sequence_insert_at(old, i, sequence_item_at(new, i));
    }
}

void sequence_filter(bool (*fp)(int), struct sequence *seq) {
    assert(seq != NULL);
    assert(fp != NULL);
    struct sequence *new = sequence_create();
    int length = sequence_length(seq);
    for (int i = 0; i < length; i++) {
        if (fp(sequence_item_at(seq, i))) {
            sequence_insert_at(new, sequence_length(new), sequence_item_at(seq, i));
        }
    }
    sequence_mutate(seq, new);
}


int sequence_foldl(int (*fp)(int, int), int base, 
                   const struct sequence *seq) {
    assert(fp != NULL);
    assert(seq != NULL);
    int length = sequence_length(seq);
    if (length == 0) {
        return base;
    }

    int result = fp(sequence_item_at(seq, 0), base);
    for (int i = 1; i < length; i++) {
        result = fp(sequence_item_at(seq, i), result);
    }
    return result;
}

