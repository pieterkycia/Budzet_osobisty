#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "GeneralXmlFile.h"
#include "Income.h"
#include "Markup.h"
#include <iostream>
#include <vector>

using namespace std;

class FileWithIncomes : public GeneralXmlFile {
    int lastIncomeIdInFile;

public:
    FileWithIncomes(string fileName): GeneralXmlFile(fileName) {};

    vector <Income> loadIncomesLoggedUserFromFile(int loggedUserId);
    void addIncomeToFile(Income & income);
    int getLastIncomeIdInFile();
};

#endif // FILEWITHINCOMES_H
