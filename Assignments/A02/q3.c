/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// Name: Colin Chu
// login ID: ckychu
/////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

/////////////////////////////////////////////////////////////////////////////
// PROVIDED FUNCTION and CONSTANTS (DO NOT CHANGE)

// print_header(year, month) prints the calendar "header"
//   for the given year/month
// notes: if month is invalid, no month line is printed
//        header is aligned for 4-digit years
// effects: produces output
void print_header(const int year, const int month)
{
    if (month == 1)
    {
        printf("====January %d====\n", year);
    }
    else if (month == 2)
    {
        printf("===February %d====\n", year);
    }
    else if (month == 3)
    {
        printf("=====March %d=====\n", year);
    }
    else if (month == 4)
    {
        printf("=====April %d=====\n", year);
    }
    else if (month == 5)
    {
        printf("======May %d======\n", year);
    }
    else if (month == 6)
    {
        printf("=====June %d======\n", year);
    }
    else if (month == 7)
    {
        printf("=====July %d======\n", year);
    }
    else if (month == 8)
    {
        printf("====August %d=====\n", year);
    }
    else if (month == 9)
    {
        printf("===September %d===\n", year);
    }
    else if (month == 10)
    {
        printf("====October %d====\n", year);
    }
    else if (month == 11)
    {
        printf("===November %d====\n", year);
    }
    else if (month == 12)
    {
        printf("===December %d====\n", year);
    }
    printf("Su Mo Tu We Th Fr Sa\n");
}

// you may use these constants in your code if you wish
// it is not a requirement, but it is strongly recommended
// you may not change their values

const int SUNDAY = 0;
const int base_year = 1589;
const int base_year_jan_1 = SUNDAY;
const int max_year = 2999;
/////////////////////////////////////////////////////////////////////////////

const int thirty_month = 0;
const int thirty_one_month = 1;

int month_type(int month) {
    if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
        return thirty_month;
    }
    else if (month != 2) {
        return thirty_one_month;
    }
    return month;
}

bool leap_year(int year) {
    if ((year % 400) == 0) {
        return 1;
    }
    else if ((year % 100) == 0) {
        return 0;
    }
    else if ((year % 4) == 0) {
        return 1;
    }
    return 0;
}

bool valid_date(int year, int month, int day) {
    if (year < base_year || year > max_year) {
        return 0;
    }
    if (day <= 28) {
        return 1;
    }
    else if (day <= 30 && (month_type(month) == 0)) {
        return 1;
    }
    else if (day <= 31 && (month_type(month) == 1)) {
        return 1;
    }
    else if (day == 29 && month == 2 && leap_year(year)) {
        return 1;
    }
    return 0;
}

int days_in_month(int month, int year) {
    if (month_type(month) == 0) {
        return 30;
    }
    else if (month_type(month) == 1) {
        return 31;
    }
    else if (month == 2 && leap_year(year)) {
        return 29;
    }
    return 28;
}

int format_month(int month) {
    month %= 12;
    if (month == 0) {
        return 12;
    }
    return month;
}

int day_of_the_week(int year, int month, int day) {
    assert(valid_date(year, month, day));

    int day_so_far = base_year_jan_1;
    int month_so_far = 1;
    int year_so_far = base_year;

    while (year_so_far <= year) {
        if (year_so_far == year && month_so_far == month) {
            break;
        }

        day_so_far = (days_in_month(month_so_far, year_so_far) + day_so_far) % 7;

        if (month_so_far == 12) {
            month_so_far = 1;
            year_so_far++;
            continue;
        }
        month_so_far++;
    }

    day_so_far = (day_so_far + (day - 1)) % 7;
    return day_so_far;
}

void print_day(int day, int day_of_week) {
    if (day == 32) {
        printf("   ");
        return;
    }
    else if (day < 10) {
        if (day_of_week == 6) {
            printf("%2d\n", day);
            return;
        }
        printf("%2d ", day);
    }
    else if (day_of_week == 6) {
        printf("%2d\n", day);
        return;
    }
    else {
        printf("%2d ", day);
    }
}

void print_calendar(int year, int month) {
    assert(valid_date(year, month, 1));

    const int empty_day = 32;

    int start_day = day_of_the_week(year, month, 1);
    int day_of_week = 0;
    int day_so_far = 1;

    print_header(year, month);

    while (day_of_week < start_day) {
        print_day(empty_day, day_of_week);
        day_of_week++;
    }

    for (; day_so_far <= days_in_month(month, year); day_so_far++) {
        //prints last day of month
        if (day_so_far == days_in_month(month, year) && day_of_week != 6) {
            printf("%2d\n", day_so_far);
            break;
        }
        print_day(day_so_far, day_of_week);
        day_of_week = (day_of_week + 1) % 7;
    }
}

void assertion_tests(void) {
    // Due date is a valid date and a Thursday
    assert(valid_date(2021, 1, 28));
    assert(day_of_the_week(2021, 1, 28) == 4);

    // Add your own assertion-based tests below
}

///////////////////////////////////////////////////////
// You do not need to modify the rest of the program //
///////////////////////////////////////////////////////

int main(void)
{
    assertion_tests();
    while (1)
    {
        int year = read_int();
        int month = read_int();
        if (month == READ_INT_FAIL)
        {
            break;
        }
        print_calendar(year, month);
    }
}