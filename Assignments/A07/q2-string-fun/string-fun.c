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
#include <string.h>
#include "cs136-trace.h"
#include "string-fun.h"

const int lower_to_upper = 32;

// see .h
bool valid_password(const char *s)
{
    bool lowercase = false;
    bool uppercase = true;
    bool digit = false;
    bool special = false;

    if (strlen(s) < 8)
        return false;

    while (*s)
    {
        if (*s >= 'a' && *s <= 'z')
        {
            lowercase = true;
        }
        else if (*s >= 'A' && *s <= 'Z')
        {
            uppercase = true;
        }
        else if (*s >= '0' && *s <= '9')
        {
            digit = true;
        }
        else if (*s == ' ' || *s == '\n')
        {
            return false;
        }
        else if (*s >= 32 && *s <= 126)
        {
            special = true;
        }
        ++s;
    }

    if (lowercase && uppercase && digit && special)
    {
        return true;
    }
    return false;
}

// see .h
int count_words(const char *s)
{
    int count = 0;
    char prev = '\n';
    while (*s)
    {
        if (prev != '\n' && prev != ' ' && (*s == '\n' || *s == ' '))
        {
            count++;
        }
        prev = *s;
        ++s;
    }
    count++;
    return count;
}

// swap(a, b) swaps the values of a and b
// effects: modifies a and b
// time: O(1)
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// see .h
void reverse(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; ++i)
    {
        swap(s + i, s + (len - i - 1));
    }
}

// see .h
bool is_palindrome_black(const char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; ++i)
    {
        if (*(s + i) != *(s + (len - i - 1)))
        {
            return false;
        }
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////
// GOLD QUESTIONS
///////////////////////////////////////////////////////////////////////////////

// lower(c) returns c in lowercase if c is a letter
// time: O(1)
char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c += lower_to_upper;
    }
    return c;
}

// see .h
bool is_palindrome_gold(const char *s)
{
    int len = strlen(s);
    int j = len - 1;
    for (int i = 0; i < (len / 2) + 1; ++i)
    {
        char front = lower(*(s + i));
        char back = lower(*(s + j));
        if (front < 'a' || front > 'z')
        {
            continue;
        }
        else if (back < 'a' || back > 'z')
        {
            --i;
            --j;
            continue;
        }
        else if (front != back)
        {
            return false;
        }
        --j;
    }
    return true;
}

// reverse_word(start, end) reverses the word defined by the characters at the
// addresses pointed at by start and end
// effects: modifies start and end
// time: O(n)
void reverse_word(char *start, char *end)
{
    while (start < end)
    {
        swap(start, end);
        start++;
        end--;
    }
}

// see .h
void reverse_words(char *s)
{
    char *start = s;
    char *end = s;
    while (*end)
    {
        end++;
        if (*end == '\0')
        {
            reverse_word(start, end - 1);
        }
        else if (*end == ' ')
        {
            reverse_word(start, end - 1);
            start = end + 1;
        }
    }
}

// see .h
void sort_strings(char **aos, int len)
{
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (strcmp(*(aos + i), *(aos + j)) > 0)
            {
                char *temp = *(aos + i);
                *(aos + i) = *(aos + j);
                *(aos + j) = temp;
            }
        }
    }
}

// see .h
bool is_alphabetic(const char *s)
{
    char prev = *s;
    char prev_alpha = lower(*s);
    while (*s)
    {
        char c = lower(*s);
        if (c >= 'a' && c <= 'z' && (prev == '\n' || prev == ' '))
        {
            if (c <= prev_alpha)
            {
                return false;
            }
            prev_alpha = c;
        }
        prev = *s;
        ++s;
    }
    return true;
}

// see .h
int substring(const char *haystack, const char *needle)
{
    int index = 0;
    while (*haystack)
    {
        int i = 1;
        if (*needle == *haystack)
        {
            while (*(needle + i))
            {
                if (*(needle + i) != *(haystack + i))
                {
                    break;
                }
                ++i;
            }
            if (i == strlen(needle))
            {
                return index;
            }
        }
        ++haystack;
        ++index;
    }
    return -1;
}
