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
    cout << "3. Wyswietl z tego miesiaca" << endl;
    cout << "---------------------------" << endl;
    cout << "4. Zmien haslo" << endl;
    cout << "5. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

void Budget::showBalanceInThisMonth() {
    vector <Income> selectedIncomes;
    Date startingDate;
    Date endingDate;

    startingDate.setFirstDayInMonth();
    endingDate.setLastDayInMonth();

    selectedIncomes = incomeManager -> selectedIncomes(startingDate, endingDate);
    incomeManager -> showSelectedIncomes(selectedIncomes);
    cout << incomeManager -> sumOfSelectedIncomes(selectedIncomes) << endl;
    system("pause");
}

void Budget::showBalanceInPreviousMonth() {
    vector <Income> selectedIncomes;
    Date startingDate;
    Date endingDate;

    startingDate.setPreviousMonth();
    startingDate.setFirstDayInMonth();
    endingDate.setPreviousMonth();
    endingDate.setLastDayInMonth();

    selectedIncomes = incomeManager -> selectedIncomes(startingDate, endingDate);
    incomeManager -> showSelectedIncomes(selectedIncomes);
    cout << incomeManager -> sumOfSelectedIncomes(selectedIncomes) << endl;
    system("pause");
}

void Budget::showBalanceInSelectedPeriod() {
    vector <Income> selectedIncomes;
    Date startingDate;
    Date endingDate;

    startingDate.setUserDate();
    endingDate.setUserDate();
    if (endingDate <= startingDate) {
        cout << "Niepoprawny okres do wyswietlenia." << endl;
        system("pause");
        return;
    }

    selectedIncomes = incomeManager -> selectedIncomes(startingDate, endingDate);
    incomeManager -> showSelectedIncomes(selectedIncomes);
    cout << incomeManager -> sumOfSelectedIncomes(selectedIncomes) << endl;
    system("pause");
}

