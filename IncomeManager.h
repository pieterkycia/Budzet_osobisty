#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include "Income.h"
#include "FileWithIncomes.h"
#include <vector>

class IncomeManager {
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    //Date startingDateToShowBalance;
    //Date endingDateToShowBalance;
    FileWithIncomes fileWithIncomes;

    Income setNewIncomeData();
    int getNewIncomeId();

public:
    IncomeManager(string fileName, int loggedUserId): fileWithIncomes(fileName), LOGGED_USER_ID(loggedUserId) {
        incomes = fileWithIncomes.loadIncomesLoggedUserFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    vector <Income> selectedIncomes(Date & startingDate, Date & endingDate);
    void showAllIncomes();
    void showSelectedIncomes(vector <Income> & selectedIncomes);
    float sumOfSelectedIncomes(vector <Income> & selectedIncomes);
};


#endif // INCOMEMANAGER_H
