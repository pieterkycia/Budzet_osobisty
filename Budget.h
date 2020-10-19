#ifndef BUDGET_H
#define BUDGET_H

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include <iomanip>

class Budget {
    UserManager userManager;
    IncomeManager * incomeManager;
    ExpenseManager * expenseManager;

public:
    Budget(string nameFileWithUsers): userManager(nameFileWithUsers) {
        incomeManager = NULL;
        expenseManager = NULL;
    };

    bool userLoggedIn();

    void userRegister();
    void userLogin();
    void userLogout();
    void changePassword();
    void showAllUsers();

    void addIncome();
    void addExpense();
    void showBalanceInThisMonth();
    void showBalanceInPreviousMonth();
    void showBalanceInSelectedPeriod();
    void showBalance(Date & startingDate, Date & endingDate);

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
};

#endif // BUDGET_H

