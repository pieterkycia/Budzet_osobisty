#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include "GeneralXmlFile.h"
#include "Expense.h"
#include "Markup.h"
#include <iostream>
#include <vector>

using namespace std;

class FileWithExpenses : public GeneralXmlFile {
    int lastExpenseIdInFile;

public:
    FileWithExpenses(string fileName): GeneralXmlFile(fileName) {};

    vector <Expense> loadExpensesLoggedUserFromFile(int loggedUserId);
    void addExpenseToFile(Expense & expense);
    int getLastExpenseIdInFile();
};

#endif // FILEWITHEXPENSES_H
