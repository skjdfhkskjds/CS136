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

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "cs136-trace.h"
#include "wordle.h"

const int upper_to_lower = 'a' - 'A';

// upper(c) returns c in uppercase if c is a letter
// time: O(1)
char upper(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        c -= upper_to_lower;
    }
    return c;
}

// char_search(secret, c) returns the index of c if c is in secret and -1
// otherwise
// time: O(n)
int char_search(const char *secret, const char c)
{
    int len = strlen(secret);
    for (int i = 0; i < len; ++i)
    {
        if (*(secret + i) == c)
        {
            return i;
        }
    }
    return -1;
}

// see wordle.h
bool evaluate_guess(const char *secret, const char *guess, char *result)
{
    int len = strlen(secret);
    char *verify = result;
    assert(len == strlen(guess));
    for (int i = 0; i < len; ++i)
    {
        int index = char_search(secret, *(guess + i));
        if (*(guess + i) == *(secret + i))
        {
            *result = upper(*(guess + i));
        }
        else if (index != -1)
        {
            *result = *(guess + i);
        }
        else
        {
            *result = '.';
        }
        ++result;
    }
    *result = '\0';
    while (*verify)
    {
        if (*verify < 'A' || *verify > 'Z')
        {
            return false;
        }
        ++verify;
    }
    return true;
}

// see wordle.h
int find_in_list(const char *guess, char *word_list[], int num_words)
{
    int low = 0;
    int high = num_words - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int equal = strcmp(word_list[mid], guess);
        if (equal == 0)
        {
            return mid;
        }
        else if (equal < 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// char_index(c) returns the index of c in an alphabet array and -1 if c
// is not a letter
// time: O(1)
int char_index(char c)
{
    int i = c;
    if (c >= 'a' && c <= 'z')
    {
        return (i - 'a');
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return (i - 'A');
    }
    return -1;
}

// see wordle.h
void available_letters(char *guesses[], char *results[], int num_guesses,
                       char *alphabet)
{
    assert(num_guesses >= 0);
    for (int n = 0; n < 26; n++)
    {
        if (alphabet[n] == '\0')
        {
            alphabet[n] = n + 'a';
        }
    }
    for (int i = 0; i < num_guesses; ++i)
    {
        char *j = results[i];
        char *k = guesses[i];
        while (*j)
        {
            int index = char_index(*j);
            if (index == -1)
            {
                index = char_index(*k);
                alphabet[index] = '.';
            }
            else
            {
                alphabet[index] = upper(*j);
            }
            ++j;
            ++k;
        }
    }
}

// contains_char(s, c) returns true if s contains c and false otherwise
// time: O(n)
bool contains_char(const char *s, const char c)
{
    while (*s)
    {
        if (*s == c)
        {
            return true;
        }
        ++s;
    }
    return false;
}

// check_guess(guess, result, next_guess) returns true if the guess follows
// the rules defined by a hard_guess and false otherwise
// requires: guess, result and next_guess are all the same length
// time: O(n^2)
bool check_guess(char *guess, char *result, const char *next_guess)
{
    int i = 0;
    while (*(next_guess + i))
    {
        char next = *(next_guess + i);
        char r = *(result + i);
        if (next == r && (r < 'A' || r > 'Z'))
        {
            return false;
        }
        else if (r == '.' && (contains_char(next_guess, *(guess + i))))
        {
            return false;
        }
        else if (r >= 'A' && r <= 'Z' && r != upper(next))
        {
            return false;
        }
        else if ((r >= 'a' && r <= 'z') && (!contains_char(next_guess, r)))
        {
            return false;
        }
        ++i;
    }
    return true;
}

// see wordle.h
bool valid_hard_guess(char *guesses[], char *results[], int num_guesses,
                      const char *next_guess)
{
    for (int i = 0; i < num_guesses; ++i)
    {
        if (!check_guess(guesses[i], results[i], next_guess))
        {
            return false;
        }
    }
    return true;
}

// see wordle.h
int find_solution(char *guesses[], char *results[], int num_guesses,
                  char *word_list[], int num_words,
                  char *solutions[], int max_solutions)
{
    int num_solutions = 0;
    for (int i = 0; i < num_words && num_solutions < max_solutions; ++i)
    {
        if (valid_hard_guess(guesses, results, num_guesses, word_list[i]))
        {
            solutions[num_solutions] = word_list[i];
            num_solutions++;
        }
    }
    return num_solutions;
}
