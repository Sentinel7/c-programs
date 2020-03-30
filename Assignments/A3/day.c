/* day.c
   CSC 111 - Fall 2019 - Assignment 3

   B. Bird - 08/14/2019

   Jason Thomo - V00949336 - 08/25/2019
*/

#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    if (year % 4 != 0)
        return 0;
    else if (year % 100 != 0)
        return 1;
    else if (year % 400 != 0)
        return 0;
    else
        return 1;
}

int lastDay(int day, int month, int year) {
    int lastDay;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        lastDay = 30;
    else if (month == 2)
        if (isLeapYear(year) == 1)
            lastDay = 29;
        else
            lastDay = 28;
    else
        lastDay = 31;

    return lastDay;
}

int dayOfWeek(int day, int month, int year) {
    int monthTable[] = {0, 1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
    int runningTotal = ((year % 100) / 4) + day + monthTable[month];
    if (isLeapYear(year) == 1 && (month == 1 || month == 2))
        runningTotal--;
    int value = (((year / 100) % 4) * 2);
    runningTotal -= value;
    runningTotal += year % 100;
    runningTotal += 12;
    runningTotal = runningTotal % 7;
    return runningTotal;
}

int main(int argc, char** argv){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT
       rename the variables, change their type or move the declarations. */

    int year = 2019;
    int month = 9;
    int day = 30;

    /* END OF INPUT DATA */
    /* Implement your solution below this line */
    /* (you may also add new functions above main() if needed) */

    char *daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    if (year > 10000 || year < 1) {
        printf("Error: Invalid year");
        return 0;
    } else if (month > 12 || month < 1) {
        printf("Error: Invalid month");
        return 0;
    } else if (day > lastDay(day, month, year) || day <= 0) {
        printf("Error: Invalid day");
        return 0;
    } else {
        printf("%d/%d/%d: %s", year, month, day, daysOfWeek[dayOfWeek(day, month, year)]);
    }

    return 0;
}