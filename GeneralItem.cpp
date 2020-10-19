#include "GeneralItem.h"

void GeneralItem::setUserId(int userId) {
    this -> userId = userId;
}

void GeneralItem::setDate() {
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

void GeneralItem::setDateFromFile(string dateFromFile) {
    date.checkDate(dateFromFile);
}

void GeneralItem::setItem(string item) {
    this -> item = item;
}

void GeneralItem::setAmount(string amount) {

    this -> amount = AuxiliaryMethods::changeCommaToDot(amount);
}

int GeneralItem::getUserId() {
    return userId;
}

string GeneralItem::getDateInString() {
    return date.convertDateToString();
}

Date & GeneralItem::getDate() {
    return date;
}

string GeneralItem::getItem() {
    return item;
}

string GeneralItem::getAmount() {
    return amount;
}
