#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "Income.h"
#include "Markup.h"
#include <iostream>
#include <vector>

using namespace std;

class FileWithIncomes {
const string FILE_NAME;
int lastIncomeIdInFile;


public:
    FileWithIncomes(string fileName): FILE_NAME(fileName){};

    vector <Income> loadIncomesLoggedUserFromFile(int loggedUserId);

    int getLastIncomeIdInFile();
};


#endif // FILEWITHINCOMES_H
