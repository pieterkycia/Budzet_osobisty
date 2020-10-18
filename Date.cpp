#include "Date.h"

int Date::daysInMonth() {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if (leapYear() == true)
            return 29;
        else
            return 28;
    }
}

bool Date::leapYear() {
    if((year % 4 == 0 && year % 100 !=0) || (year % 4 == 0 && year % 400 == 0 && year % 100 == 0))
        return true;
    else
        return false;
}

bool Date::setDay(int newDay) {
    if (newDay >= 1 && newDay <= daysInMonth()) {
        day = newDay;
        return true;
    } else {
        return false;
    }
}

bool Date::setMonth(int newMonth) {
    if (newMonth >= 1 && newMonth <= 12) {
        month = newMonth;
        return true;
    } else {
        return false;
    }
}

bool Date::setYear(int newYear) {
    if (newYear >= 2000 && newYear < 10000) {
        year = newYear;
        return true;
    } else {
        return false;
    }
}

bool Date::operator<(const Date & newDate) {
    if (this -> year < newDate.year)
        return true;
    else if (this -> year == newDate.year) {
        if (this -> month < newDate.month)
            return true;
        else if (this -> month == newDate.month) {
            if (this -> day < newDate.day)
                return true;
            else
                return false;
        } else
            return false;
    } else
        return false;
}

bool Date::operator<=(const Date & newDate) {
    if (this -> year < newDate.year)
        return true;
    else if (this -> year == newDate.year) {
        if (this -> month < newDate.month)
            return true;
        else if (this -> month == newDate.month) {
            if (this -> day <= newDate.day)
                return true;
            else
                return false;
        } else
            return false;
    } else
        return false;
}

bool Date::operator>=(const Date & newDate) {
    if (this -> year > newDate.year)
        return true;
    else if (this -> year == newDate.year) {
        if (this -> month > newDate.month)
            return true;
        else if (this -> month == newDate.month) {
            if (this -> day >= newDate.day)
                return true;
            else
                return false;
        } else
            return false;
    } else
        return false;
}

void Date::setLocalDate() {
    time_t czas;
    struct tm * date;
    time(& czas);
    date = localtime(& czas);
    year = date -> tm_year + 1900;
    month = date -> tm_mon + 1;
    day = date -> tm_mday;
}

void Date::setUserDate() {
    string userDate = "";
    do {
        cout << "Podaj date w postaci rrrr-mm-dd: ";
        userDate = AuxiliaryMethods::loadLine();
    } while (checkDate(userDate) == false);
}

bool Date::checkDate(string date) {
    string line = "";
    int choice = 0;
    if (date.length() < 8 || date.length() > 10) {
        cout << "Niepoprawna data." << endl;
        return false;
    }
    for (int i = 0; i <= date.length(); i++) {
        if (date[i] != '-' && date[i] != '\0') {
            line += date[i];
        } else {
            switch (choice) {
            case 0:
                if (this -> setYear(atoi(line.c_str())) == false) {
                    cout << "Niepoprawna data." << endl;
                    return false;
                }
                break;
            case 1:
                if (this -> setMonth(atoi(line.c_str())) == false) {
                    cout << "Niepoprawna data." << endl;
                    return false;
                }
                break;
            case 2:
                if (this -> setDay(atoi(line.c_str())) == false) {
                    cout << "Niepoprawna data." << endl;
                    return false;
                }
                break;
            }
            line = "";
            choice++;
        }
    }
    return true;
}

void Date::setFirstDayInMonth() {
    day = 1;
}
void Date::setLastDayInMonth() {
    day = daysInMonth();
}

void Date::setPreviousMonth() {
    if (month == 1) {
        if (year == 2000) {
        } else {
            year = year - 1;
            month = 12;
        }
    } else
        month = month - 1;
}

string Date::convertDateToString() {
    string convertedDate = "";
    string yearToString = "";
    string monthToString = "";
    string dayToString = "";

    if (day < 10)
        dayToString = "0" + AuxiliaryMethods::convertIntToString(day);
    else
        dayToString = AuxiliaryMethods::convertIntToString(day);
    if (month < 10)
        monthToString = "0" + AuxiliaryMethods::convertIntToString(month);
    else
        monthToString = AuxiliaryMethods::convertIntToString(month);
    yearToString = AuxiliaryMethods::convertIntToString(year);

    convertedDate = yearToString + "-" + monthToString + "-" + dayToString;
    return convertedDate;
}

