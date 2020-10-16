#include "Budget.h"

void Budget::userRegister() {
    userManager.userRegister();
}

void Budget::userLogin() {
    userManager.userLogin();
}

void Budget::userLogout() {
    userManager.userLogout();
}

void Budget::changePassword() {
    userManager.changePassword();
}

void Budget::showAllUsers() {
    userManager.showAllUsers();
}

bool Budget::userLoggedIn() {
    if (userManager.getLoggedUserId() > 0)
        return true;
    else
        return false;
}

char Budget::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "3. Wyswietl wszystkich uzytkownikow" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

char Budget::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Zmien haslo" << endl;
    cout << "2. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

