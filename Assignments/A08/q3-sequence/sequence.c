/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with: None

// Name: Colin Chu
// login ID: ckychu
/////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "sequence.h"
#include "cs136-trace.h"

struct sequence
{
    int len;
    int maxlen;
    char **data;
};

// see sequence.h
struct sequence *sequence_create(void)
{
    struct sequence *seq = malloc(sizeof(struct sequence));
    seq->len = 0;
    seq->maxlen = 1;
    seq->data = malloc(seq->maxlen * sizeof(char *));
    return seq;
}

// see sequence.h
void sequence_destroy(struct sequence *seq)
{
    for (int i = 0; i < seq->len; ++i)
    {
        free(seq->data[i]);
    }
    free(seq->data);
    free(seq);
}

// see sequence.h
int sequence_length(const struct sequence *seq)
{
    assert(seq);
    return seq->len;
}

// see sequence.h
const char *sequence_item_at(const struct sequence *seq, int pos)
{
    assert(seq);
    assert(0 <= pos);
    assert(pos < seq->len);
    return seq->data[pos];
}

// see sequence.h
void sequence_insert_at(struct sequence *seq, int pos, const char *s)
{
    assert(seq);
    assert(0 <= pos);
    assert(pos <= seq->len);
    if (seq->len == seq->maxlen)
    {
        seq->maxlen *= 2;
        seq->data = realloc(seq->data, seq->maxlen * sizeof(char *));
        printf("expanded\n");
    }
    char *item = malloc((strlen(s) + 1) * sizeof(char));
    strcpy(item, s);
    for (int i = seq->len; i > pos; --i)
    {
        seq->data[i] = seq->data[i - 1];
    }
    seq->data[pos] = item;
    seq->len += 1;
}

// see sequence.h
void sequence_remove_at(struct sequence *seq, int pos)
{
    assert(seq);
    assert(0 <= pos);
    assert(pos < seq->len);
    seq->len -= 1;
    //free(seq->data[pos]);
    for (int i = pos; i < seq->len - 1; ++i)
    {
        seq->data[i] = seq->data[i + 1];
    }
    if (seq->len * 4 == seq->maxlen)
    {
        seq->data = realloc(seq->data, (seq->maxlen / 2) * sizeof(char *));
        seq->maxlen /= 2;
    }
}

// see sequence.h
bool sequence_equiv(const struct sequence *seq1, const struct sequence *seq2)
{
    assert(seq1);
    assert(seq2);
    assert(seq1->data);
    assert(seq2->data);
    if (seq1->len != seq2->len)
        return false;

    for (int i = 0; i < seq1->len; ++i)
    {
        if (strcmp(seq1->data[i], seq2->data[i]) != 0)
        {
            return false;
        }
    }
    return true;
}

// see sequence.h
void sequence_print(const struct sequence *seq)
{
    assert(seq);
    // empty base case
    if (seq->len == 0)
    {
        printf("[empty]\n");
        return;
    }

    printf("[");
    for (int i = 0; i < seq->len; ++i)
    {
        if (i)
        {
            printf(",");
        }
        printf("%s", seq->data[i]);
    }
    printf("]\n");
}

// see sequence.h
void sequence_filter(struct sequence *seq, bool (*f)(const char *))
{
    assert(seq);
    assert(f);

    int new_len = 0;
    for (int i = 0; i < seq->len; ++i)
    {
        if (f(seq->data[i]))
        {
            char *item = malloc((strlen(seq->data[i]) + 1) * sizeof(char));
            strcpy(item, seq->data[i]);
            seq->data[new_len] = item;
            new_len++;
        }
        else
        {
            //free(seq->data[i]);
        }
    }
    seq->len = new_len;
    if (seq->len * 4 == seq->maxlen)
    {
        seq->data = realloc(seq->data, (seq->maxlen / 2) * sizeof(char *));
        seq->maxlen /= 2;
    }
}

// see sequence.h
void sequence_append(struct sequence *seq1, const struct sequence *seq2)
{
    assert(seq1);
    assert(seq2);
    assert(seq1 != seq2);

    if ((seq1->len + seq2->len) >= seq1->maxlen)
    {
        seq1->maxlen = seq1->len + seq2->len;
        seq1->data = realloc(seq1->data, seq1->maxlen * sizeof(char *));
    }
    for (int i = 0; i < seq2->len; ++i)
    {
        char *item = malloc((strlen(seq2->data[i]) + 1) * sizeof(char));
        strcpy(item, seq2->data[i]);
        seq1->data[seq1->len] = item;
        seq1->len += 1;
    }
}

// see sequence.h
void sequence_remove_dups(struct sequence *seq)
{
    assert(seq);
    for (int i = 0; i < seq->len; ++i)
    {
        int new_len = i + 1;
        for (int j = new_len; j < seq->len; ++j)
        {
            if (strcmp(seq->data[j], seq->data[i]) != 0)
            {
                seq->data[new_len] = seq->data[j];
                ++new_len;
            }
            else
            {
                //free(seq->data[j]);
            }
        }
        seq->len = new_len;
    }
    if (seq->len * 4 == seq->maxlen)
    {
        seq->data = realloc(seq->data, (seq->maxlen / 2) * sizeof(char *));
        seq->maxlen /= 2;
    }
}