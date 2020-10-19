#include "Budget.h"

void Budget::userRegister() {
    userManager.userRegister();
}

void Budget::userLogin() {
    userManager.userLogin();
    if (userLoggedIn() == true) {
        incomeManager = new IncomeManager("Incomes.xml", userManager.getLoggedUserId());
        expenseManager = new ExpenseManager("Expenses.xml", userManager.getLoggedUserId());
    }
}

void Budget::userLogout() {
    userManager.userLogout();
    delete incomeManager;
    delete expenseManager;
    incomeManager = NULL;
    expenseManager = NULL;
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

void Budget::addExpense() {
    expenseManager -> addExpense();
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
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z tego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

void Budget::showBalanceInThisMonth() {
    Date startingDate;
    Date endingDate;

    startingDate.setFirstDayInMonth();
    endingDate.setLastDayInMonth();

    showBalance(startingDate, endingDate);
}

void Budget::showBalanceInPreviousMonth() {
    Date startingDate;
    Date endingDate;

    startingDate.setPreviousMonth();
    startingDate.setFirstDayInMonth();
    endingDate.setPreviousMonth();
    endingDate.setLastDayInMonth();

    showBalance(startingDate, endingDate);
}

void Budget::showBalanceInSelectedPeriod() {
    Date startingDate;
    Date endingDate;

    startingDate.setUserDate();
    endingDate.setUserDate();
    if (endingDate <= startingDate) {
        cout << "Niepoprawny okres do wyswietlenia." << endl;
        system("pause");
        return;
    }
    showBalance(startingDate, endingDate);
}

void Budget::showBalance(Date & startingDate, Date & endingDate) {
    system("cls");
    vector <Income> selectedIncomes;
    vector <Expense> selectedExpenses;

    selectedIncomes = incomeManager -> selectIncomesByDate(startingDate, endingDate);
    cout << endl << " >>> PRZYCHODY <<<" << endl;
    cout << "----------------------" << endl;
    incomeManager -> showSelectedIncomes(selectedIncomes);
    selectedExpenses = expenseManager -> selectExpensesByDate(startingDate, endingDate);
    cout << endl << " >>> WYDATKI <<<" << endl;
    cout << "----------------------" << endl;
    expenseManager -> showSelectedExpenses(selectedExpenses);

    float sumOfIncomes = incomeManager -> sumOfSelectedIncomes(selectedIncomes);
    float sumOfExpenses = expenseManager -> sumOfSelectedExpenses(selectedExpenses);

    cout << endl << "Suma przychodow: " << sumOfIncomes << endl;
    cout << "Suma wydatkow: " << sumOfExpenses << endl;
    cout << "Bilans ogolny z tego okresu: " << sumOfIncomes - sumOfExpenses << endl << endl;
    system("pause");
}
