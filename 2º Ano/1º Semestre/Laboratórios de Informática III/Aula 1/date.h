#ifndef _DATE_H_
#define _DATE_H_

typedef struct date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
} Date;


Date* createDate(int,int,int,int,int);

int isDateValid(Date*);

int isLeapYear(int);
#endif