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

#include <stdio.h>
#include "lame-robot.h"

// print_line() prints dashed lines and a line return
// effects: produces output
void print_line(void) {
  printf("---------------------------------------------\n");
}

int run_robot(char move, int dist) {
    if (move == 'f') {
        robot_forward(dist);
        robot_status();
    }
    else if (move == 'l') {
        robot_left();
        robot_status();
    }
    else if (move == 'r') {
        robot_right();
        robot_status();
    }
    else if (move == 'd') {
        robot_drop();
        robot_status();
    }
    else if (move == 'p') {
        robot_pickup();
        robot_status();
    }
    else if (move == 't') {
        robot_reset();
        robot_status();
    }
    else if (move == 's') {
        robot_status();
    }
    else {
        return 0;
    }
    print_line();
    return 1;
}

int main(void) {
    char in = 0;
    while (scanf(" %c", &in) == 1) {
        int dist = -1;
        if (in == 'f') {
            if (scanf("%d", &dist) != 1) {
                return 0;
            }
        }
        if (run_robot(in, dist) == 0) {
            return 0;
        }
    }
}