#include "Budget.h"

void Budget::userRegister() {
    userManager.userRegister();
}

void Budget::userLogin() {
    userManager.userLogin();
    if (userLoggedIn() == true)
        incomeManager = new IncomeManager("Incomes.xml", userManager.getLoggedUserId());
}

void Budget::userLogout() {
    userManager.userLogout();
    delete incomeManager;
    incomeManager = NULL;
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

void Budget::addIncome() {
    incomeManager -> addIncome();
}

void Budget::showAllIncomes() {
    incomeManager -> showAllIncomes();
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
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Wyswietl przychody" << endl;
    cout << "---------------------------" << endl;
    cout << "3. Zmien haslo" << endl;
    cout << "4. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

