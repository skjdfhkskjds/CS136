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

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "minesweeper.h"

//////////////////////////////////////
// DO NOT CHANGE THESE CONSTANTS:
const char UNREVEALED = ' ' ;
const char REVEALED[9] = "012345678";
const char FLAG = 'F';
const char MINE = '*';
//////////////////////////////////////

// is_valid(b) terminates program (with assert) if b is not a valid board
// note: length of board cannot be determined, so width * height = length is 
//       not asserted
//       the validity of the values in board cannot be asserted, as the length 
//       of the board is unknown
//       the uniqueness of coordinates of mines cannot be asserted, as a 
//       member style verification requires another array to store previously 
//       viewed positions, but variable length based array declarations are 
//       prohibited
// requires: b is not NULL
void is_valid(const struct ms_board *b) {
    assert(b);
    assert(b->width > 0);
    assert(b->height > 0);
    assert(b->mines);
    for (int i = 0; i < b->num_mines; ++i) {
        assert(b->mines[i].x <= b->width);
        assert(b->mines[i].y <= b->height);
    }
}

// calculate(x, y, w) returns the array position of any given (x, y) 
//      coordinates on a board of width w
int calculate(int x, int y, int w) {
    return (((y - 1) * w) + (x - 1));
}

// see minesweeper.h
bool flag(struct ms_board *b, int x, int y) {
    is_valid(b);
    assert(1 <= x);
    assert(x <= b->width);
    assert(1 <= y);
    assert(y <= b->height);
    
    int pos = calculate(x, y, b->width);
    char cur_state = b->board[pos];
    if (cur_state == UNREVEALED) {
        b->board[pos] = FLAG;
        return true;
    } else if (cur_state == FLAG) {
        b->board[pos] = UNREVEALED;
        return true;
    }
    return false;
}

// is_mine(b, x, y) returns true if a given position is a mine and false 
//      otherwise
// requires: b is not NULL
bool is_mine(const struct ms_board *b, int x, int y) {
    for (int i = 0; i < b->num_mines; ++i) {
        if (b->mines[i].x == x && b->mines[i].y == y) {
            return true;
        }
    }
    return false;
}

// revealed(state) returns true if the given state is revealed and false 
//      otherwise
bool revealed(char state) {
    for (int i = 0; i < 9; ++i) {
        if (state == REVEALED[i]) {
            return true;
        }
    }
    return false;
}

// see minesweeper.h
bool reveal(struct ms_board *b, int x, int y) {
    is_valid(b);
    assert(1 <= x);
    assert(x <= b->width);
    assert(1 <= y);
    assert(y <= b->height);

    int pos = calculate(x, y, b->width);
    char cur_state = b->board[pos];
    if (cur_state == UNREVEALED) {
        if (is_mine(b, x, y)) {
            b->board[pos] = MINE;
            return true;
        }
    } else {
        return false;
    }

    int adj_mines = 0;
    int adj_len = 8;
    struct posn adjacents[] = {{x - 1, y - 1}, {x, y - 1}, {x + 1, y - 1},
                               {x - 1, y}, {x + 1, y},
                               {x - 1, y + 1}, {x, y + 1}, {x + 1, y + 1}};
    for (int i = 0; i < adj_len; ++i) {
        int a_x = adjacents[i].x;
        int a_y = adjacents[i].y;  
        if (a_x > b->width || a_x < 1 || a_y > b->height || a_y < 1) {
            // skip if out of bounds
            continue;
        }
        if (is_mine(b, a_x, a_y)) {
            adj_mines++;
        }
    }
    b->board[pos] = REVEALED[adj_mines];
    if (adj_mines == 0) {
        for (int i = 0; i < adj_len; ++i) {
            int a_x = adjacents[i].x;
            int a_y = adjacents[i].y;
            if (a_x > b->width || a_x < 1 || a_y > b->height || a_y < 1) {
                // skip if out of bounds
                continue;
            }
            reveal(b, a_x, a_y);
        }
    }
    return true;
}

// see minesweeper.h
bool game_won(const struct ms_board *b) {
    is_valid(b);
    for (int i = 0; i < b->height; ++i) {
        for (int j = 0; j < b->width; ++j) {
            int pos = calculate(j + 1, i + 1, b->width);
            char cur_state = b->board[pos];
            if (is_mine(b, j + 1, i + 1)) {
                if (cur_state != UNREVEALED && cur_state != FLAG) {
                    return false;
                } else {
                    continue;
                }
            } else if (!revealed(cur_state)) {
                return false;
            }
        }
    }
    return true;
}

// see minesweeper.h
bool game_lost(const struct ms_board *b) {
    is_valid(b);
    for (int i = 0; i < b->num_mines; ++i) {
        int x = b->mines[i].x;
        int y = b->mines[i].y;
        int pos = calculate(x, y, b->width);
        if (b->board[pos] == MINE) {
            return true;
        }
    }
    return false;
}

