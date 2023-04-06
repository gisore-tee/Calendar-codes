#include <stdio.h>

// function to determine if a year is a leap year or not
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

// function to get the number of days in a given month
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[month - 1];
}

// function to get the day of the week of the first day of a given month
int getFirstDayOfWeek(int month, int year) {
    // The Zeller's congruence algorithm is used to get the day of the week
    int q = 1; // day of the month
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (q + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return h;
}

// function to print the calendar for a given month and year
void printCalendar(int month, int year) {
    int i, firstDayOfWeek, daysInMonth;
    char *monthNames[] = {"January", "February", "March", "April", "May", "June", "July",
                          "August", "September", "October", "November", "December"};
    daysInMonth = getDaysInMonth(month, year);
    firstDayOfWeek = getFirstDayOfWeek(month, year);

    // print the calendar header
    printf("\n%s %d\n", monthNames[month - 1], year);
    printf("Su Mo Tu We Th Fr Sa\n");

    // print the days of the month
    for (i = 0; i < firstDayOfWeek; i++) {
        printf("   ");
    }
    for (i = 1; i <= daysInMonth; i++) {
        printf("%2d ", i);
        if ((i + firstDayOfWeek) % 7 == 0) {
            printf("\n");
        }
    }
    if ((i + firstDayOfWeek - 1) % 7 != 0) {
        printf("\n");
    }
}

int main() {
    int month, year;
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);
    printCalendar(month, year);
    return 0;
}
