#include "Expense.h"

bool Expense::operator<(const Expense & expense) {
    return (this -> date < expense.date);
}

void Expense::setExpenseId(int expenseId) {
    this -> expenseId = expenseId;
}

void Expense::setUserId(int userId) {
    this -> userId = userId;
}

void Expense::setDate() {
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

void Expense::setDateFromFile(string dateFromFile) {
    date.checkDate(dateFromFile);
}

void Expense::setItem(string item) {
    this -> item = item;
}

void Expense::setAmount(string amount) {

    this -> amount = AuxiliaryMethods::changeCommaToDot(amount);
}

int Expense::getExpenseId() {
    return expenseId;
}

int Expense::getUserId() {
    return userId;
}

string Expense::getDateOnString() {
    return date.convertDateToString();
}

Date & Expense::getDate() {
    return date;
}

string Expense::getItem() {
    return item;
}

string Expense::getAmount() {
    return amount;
}
