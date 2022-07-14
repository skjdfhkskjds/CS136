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

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "sstack.h"

struct sstack
{
    int len;
    int maxlen;
    char **data;
};

// see .h
struct sstack *sstack_create(void)
{
    struct sstack *ss = malloc(sizeof(struct sstack));
    ss->len = 0;
    ss->maxlen = 1;
    ss->data = malloc(ss->maxlen * sizeof(char *));
    return ss;
}

// see .h
bool sstack_is_empty(const struct sstack *ss)
{
    assert(ss);
    return ss->len == 0;
}

// see .h
const char *sstack_top(const struct sstack *ss)
{
    assert(ss);
    assert(ss->len);
    return ss->data[ss->len - 1];
}

// see .h
char *sstack_pop(struct sstack *ss)
{
    assert(ss);
    assert(ss->len);
    ss->len -= 1;
    if (ss->len * 4 == ss->maxlen)
    {
        ss->data = realloc(ss->data, (ss->maxlen / 2) * sizeof(char *));
        ss->maxlen /= 2;
    }
    return ss->data[ss->len];
}

// see .h
void sstack_push(const char *str, struct sstack *ss)
{
    assert(ss);
    if (ss->len == ss->maxlen)
    {
        ss->maxlen *= 2;
        ss->data = realloc(ss->data, ss->maxlen * sizeof(char *));
    }
    char *item = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(item, str);
    ss->data[ss->len] = item;
    ss->len += 1;
}

// see .h
void sstack_destroy(struct sstack *ss)
{
    for (int i = 0; i < ss->len; ++i)
    {
        free(ss->data[i]);
    }
    free(ss->data);
    free(ss);
}

// see .h
void sstack_status(const struct sstack *ss)
{
    printf("status: %d/%d\n", ss->len, ss->maxlen);
}
