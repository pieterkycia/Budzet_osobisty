#ifndef DATE_H
#define DATE_H

#include "AuxiliaryMethods.h"
#include <iostream>
#include <time.h>

class Date {
    int day;
    int month;
    int year;

    int daysInMonth();
    bool leapYear();
    bool setDay(int day);
    bool setMonth(int month);
    bool setYear(int year);

public:
    Date() {
        setLocalDate();
    };

    bool operator<(const Date & newDate);
    bool operator<=(const Date & newDate);
    bool operator>=(const Date & newDate);

    void setLocalDate();
    void setUserDate();
    bool checkDate(string date);

    void setFirstDayInMonth();
    void setLastDayInMonth();
    void setPreviousMonth();

    string convertDateToString();
};

#endif // DATE_H
