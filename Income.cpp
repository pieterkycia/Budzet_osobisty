#include "Income.h"

bool Income::operator<(const Income & income) {
    return (this -> date < income.date);
}

void Income::setIncomeId(int incomeId) {
    this -> incomeId = incomeId;
}

void Income::setUserId(int userId) {
    this -> userId = userId;
}

void Income::setDate() {
    system("cls");
    char choice;
    while (true) {
        cout << "Data dzisiejsza? <t/n>: " << endl;
        choice = AuxiliaryMethods::loadChar();
        switch (choice) {
        case 't':
            date.setLocalDate();
            return;
        case 'n':
            date.setUserDate();
            return;
        default :
            cout << "Nie ma takiej opcji. Wpisz ponownie." << endl << endl;
        }
    }
}

void Income::setDateFromFile(string dateFromFile) {
date.checkDate(dateFromFile);
}

void Income::setItem(string item) {
    this -> item = item;
}

void Income::setAmount(string newAmount) {
    newAmount = AuxiliaryMethods::changeCommaToDot(newAmount);
    this -> amount = atof(newAmount.c_str());
}

int Income::getIncomeId() {
    return incomeId;
}

int Income::getUserId() {
    return userId;
}

string Income::getDate() {
    return date.convertDateToString();
}

string Income::getItem() {
    return item;
}

float Income::getAmount() {
    return amount;
}
