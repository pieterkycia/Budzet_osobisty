#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include "Income.h"
#include "FileWithIncomes.h"
#include <vector>

class IncomeManager {
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;

    Income setNewIncomeData();
    int getNewIncomeId();

public:
    IncomeManager(string fileName, int loggedUserId): fileWithIncomes(fileName), LOGGED_USER_ID(loggedUserId) {
        incomes = fileWithIncomes.loadIncomesLoggedUserFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    vector <Income> selectIncomesByDate(Date & startingDate, Date & endingDate);
    void showSelectedIncomes(vector <Income> & selectedIncomes);
    double sumOfSelectedIncomes(vector <Income> & selectedIncomes);
};

#endif // INCOMEMANAGER_H
