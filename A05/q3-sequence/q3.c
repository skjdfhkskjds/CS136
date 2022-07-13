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

#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "sequence.h"

const int SEQUENCE_MAXLEN = 1024; // max sequence length constant

// see sequence.h
void sequence_init(struct sequence *seq) {
    assert(seq);
    struct sequence new = {0};
    new.maxlen = SEQUENCE_MAXLEN;
    *seq = new;
}

// see sequence.h
int sequence_length(const struct sequence *seq) {
    assert(seq);

    return seq->len;
}

// see sequence.h
int sequence_item_at(const struct sequence *seq, int pos) {
    assert(seq);
    assert(0 <= pos);
    assert(pos < seq->len);

    return seq->data[pos];
}

// see sequence.h
void sequence_insert_at(struct sequence *seq, int pos, int val) {
    assert(seq);
    assert(0 <= pos);
    assert(pos <= seq->len);
    assert(seq->len < SEQUENCE_MAXLEN);
    assert(seq->data);

    int new_len = seq->len + 1;
    for (int i = seq->len; i > (pos - 1); --i) {
        seq->data[i + 1] = seq->data[i];
    }
    seq->data[pos] = val;
    seq->len = new_len;
}

// see sequence.h
int sequence_remove_at(struct sequence *seq, int pos) {
    assert(seq);
    assert(0 <= pos);
    assert(pos < seq->len);
    assert(seq->data);

    int new_len = seq->len - 1;
    int removed = seq->data[pos];
    for (int i = pos; i < seq->len - 1; ++i) {
        seq->data[i] = seq->data[i + 1];
    }
    seq->len = new_len;
    return removed;
}

// see sequence.h
bool sequence_equiv(const struct sequence *seq1, const struct sequence *seq2) {
    assert(seq1);
    assert(seq2);
    assert(seq1->data);
    assert(seq2->data);

    if (seq1->len != seq2->len) {
        return false;
    }

    for (int i = 0; i < seq1->len; ++i) {
        
        if (seq1->data[i] != seq2->data[i]) {
            return false;
        }
    }
    return true;
}

// see sequence.h
void sequence_print(const struct sequence *seq) {
    assert(seq);

    // empty base case
    if (seq->len == 0) {
        printf("[empty]\n");
        return;
    }

    printf("[");
    for (int i = 0; i < seq->len - 1; ++i) {
        printf("%d,", seq->data[i]);
    }
    printf("%d]\n", seq->data[seq->len - 1]);
}

// clear_sequence(seq) clears all values of the sequence but maintains
//    the sequences original length
// effects: modifies seq
// requires: seq is not NULL
void clear_sequence(struct sequence *seq) {
    assert(seq);
    int before_len = seq->len;
    sequence_init(seq);
    seq->len = before_len;
}

// see sequence.h
void sequence_build(struct sequence *seq, int (*build_func)(int), int n) {
    assert(seq);
    assert(build_func);
    assert(0 <= n);
    assert(n <= SEQUENCE_MAXLEN);

    if (n == 0) {
        sequence_init(seq);
    }

    for (int i = 0; i < n; ++i) {
        seq->data[i] = build_func(i);
    }
    seq->len = n;
}

// see sequence.h
void sequence_filter(struct sequence *seq, bool (*filter_func)(int)) {
    assert(seq);
    assert(filter_func);

    int new_len = 0;
    for (int i = 0; i < seq->len; ++i) {
        if (filter_func(seq->data[i])) {
            seq->data[new_len] = seq->data[i];
            new_len++;
        }
    }
    seq->len = new_len;
}

// see sequence.h
void sequence_append(struct sequence *seq1, const struct sequence *seq2) {
    assert(seq1);
    assert(seq2);
    assert(seq1->len + seq2->len <= SEQUENCE_MAXLEN);
    assert(seq1 != seq2);
    
    int new_len = seq1->len + seq2->len;
    for (int i = 0; i < seq2->len; ++i) {
        seq1->data[i + seq1->len] = seq2->data[i];
    }
    seq1->len = new_len;
}

// member(a[], len, item) returns a bool indicating whether an item is in the 
//    provided array or not
// requires: all array elements are not NULL
//           array is of length len [NOT ASSERTED]
bool member(const int a[], int len, const int item) {
    assert(a);
    for (int i = 0; i < len; ++i) {
        if (item == a[i]) {
            return true;
        }
    }
    return false;
}

// see sequence.h
void sequence_remove_dups(struct sequence *seq) {
    assert(seq);
    struct sequence new = {0};
    int new_len = 0;

    for (int i = 0; i < seq->len; ++i) {
        if (!member(new.data, new_len, seq->data[i])) {
            new.data[new_len] = seq->data[i];
            new_len++;
        }
    }
    new.len = new_len;
    *seq = new;
}