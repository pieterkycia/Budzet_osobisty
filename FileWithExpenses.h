#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include "Expense.h"
#include "Markup.h"
#include <iostream>
#include <vector>

using namespace std;

class FileWithExpenses {
    const string FILE_NAME;
    int lastExpenseIdInFile;

public:
    FileWithExpenses(string fileName): FILE_NAME(fileName) {};

    vector <Expense> loadExpensesLoggedUserFromFile(int loggedUserId);
    void addExpenseToFile(Expense & expense);
    int getLastExpenseIdInFile();
};

#endif // FILEWITHEXPENSES_H
