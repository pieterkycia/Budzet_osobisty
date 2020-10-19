#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "Expense.h"
#include "FileWithExpenses.h"
#include <vector>

class ExpenseManager {
    const int LOGGED_USER_ID;
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;

    Expense setNewExpenseData();
    int getNewExpenseId();

public:
    ExpenseManager(string fileName, int loggedUserId): fileWithExpenses(fileName), LOGGED_USER_ID(loggedUserId) {
        expenses = fileWithExpenses.loadExpensesLoggedUserFromFile(LOGGED_USER_ID);
    };

    void addExpense();
    vector <Expense> selectExpensesByDate(Date & startingDate, Date & endingDate);
    void showSelectedExpenses(vector <Expense> & selectedExpenses);
    double sumOfSelectedExpenses(vector <Expense> & selectedExpenses);
};

#endif // EXPENSEMANAGER_H
