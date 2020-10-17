#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include "Income.h"
#include <vector>

class IncomeManager {
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    Date startingDateToShowBalance;
    Date endingDateToShowBalance;

    Income setNewIncomeData();
    int getNewIncomeId();

public:
    IncomeManager(int loggedUserId): LOGGED_USER_ID(loggedUserId) {};

    void addIncome();
    void showAllIncomes();
};


#endif // INCOMEMANAGER_H
