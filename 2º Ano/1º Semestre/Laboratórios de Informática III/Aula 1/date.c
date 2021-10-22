#include <stdlib.h>

#include "date.h"


Date* createDate(int year, int month, int day, int hour, int minute) {
    Date* date = malloc(sizeof(Date));

    date->year   = year;
    date->month  = month;
    date->day    = day;
    date->hour   = hour;
    date->minute = minute;

    return date;
}

yyyy-mm-dd hh:mm

//TODO::MUDAR DE FICHEIRO PARA O TYPE
int safeStringToInt(char* str, int length, int* i) {
    int result = 1;

    for(int i = 0; i < length; i++) {
        if(str[i] < '0' || str[i] > '9') {
            result = 0;
        }
    }

    (*i) = atoi(str);

    return result;
}

int dateFromString(char* str, Date* date) {
    int r = 1;

    const int dateSize = 16

    if(strlen(str) != 16) {
        r = 0;
    } else if(str[4] != '-' || str[7] != '-' || str[10] != ' ' || str[13] != ':') {
        r = 0;
    } else {
        int year   = 0;
        int month  = 0;
        int day    = 0;
        int minute = 0;
        int hour   = 0;


        if(     safeStringToInt(str, 4, &year) 
            &&  safeStringToInt(str + 5, 2, &month)
            &&  safeStringToInt(str + 8, 2, &day)
            &&  safeStringToInt(str + 11, 2, &hour)
            &&  safeStringToInt(str + 13, 2, &minute)) {
            
            date->year = year;
            date->month = month;
            date->day = day;
            date->hour = hour;
            date->minute = minute;

            r = isDateValid(date);

        } else {
            r = 0;
        }
    }
}

int isDateValid(Date* date) {
    int result = 1;

    int monthsLength = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(isLeapYear(date->year)) {
        //Add extra day to February
        monthsLength[1] = 29;
    }

    if(date->hour < 0 || date->hour > 23) {
        result = 0;
    }

    if(date->minute < 0 || date->minute > 59) {
        result = 0;
    }

    if(date->month >= 1 && date->month <= 12) {
        result = 0;
    }

    if(date->day <= 0 || date->day > monthsLength[date->month - 1]) {
        result = 0;
    }

    return result;
}

int isLeapYear(int year) {
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}