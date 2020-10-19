#ifndef BUDGET_H
#define BUDGET_H

#include "UserManager.h"
#include "IncomeManager.h"

class Budget {
    UserManager userManager;
    IncomeManager * incomeManager;

public:
    Budget(string nameFileWithUsers): userManager(nameFileWithUsers) {
        incomeManager = NULL;
    };

    bool userLoggedIn();

    void userRegister();
    void userLogin();
    void userLogout();
    void changePassword();
    void showAllUsers();

    void addIncome();
    void showBalanceInThisMonth();
    void showBalanceInPreviousMonth();
    void showBalanceInSelectedPeriod();
    void showBalance(Date & startingDate, Date & endingDate);

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
};

#endif // BUDGET_H

