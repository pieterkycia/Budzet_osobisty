#include "IncomeManager.h"

void IncomeManager::addIncome() {
    Income income;

    income = setNewIncomeData();
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);
    cout << "Dodano przychod." << endl;
    system("pause");
}

Income IncomeManager::setNewIncomeData() {
    Income income;

    income.setDate();
    cout << "Podaj nazwe przychodu: ";
    income.setItem(AuxiliaryMethods::loadLine());
    cout << "Podaj wysokosc przychodu: ";
    income.setAmount(AuxiliaryMethods::loadLine());
    income.setIncomeId(getNewIncomeId());
    income.setUserId(LOGGED_USER_ID);
    return income;
}

void IncomeManager::showSelectedIncomes(vector <Income> & selectedIncomes) {
    if (!selectedIncomes.empty()) {
        for (int i = 0; i < selectedIncomes.size(); i++) {
            cout << endl;
            cout << "incomeId:     " << selectedIncomes[i].getIncomeId() << endl;
            cout << "userId:       " << selectedIncomes[i].getUserId() << endl;
            cout << "date:         " << selectedIncomes[i].getDateOnString() << endl;
            cout << "item:         " << selectedIncomes[i].getItem() << endl;
            cout << "amount:       " << selectedIncomes[i].getAmount() << endl;
        }
    } else {
        cout << endl << "Nie ma zapisanych przychodow." << endl;
    }
}

int IncomeManager::getNewIncomeId() {
    return fileWithIncomes.getLastIncomeIdInFile() + 1;
}

vector <Income> IncomeManager::selectIncomesByDate(Date & startingDate, Date & endingDate) {
    vector <Income> selectedIncomes;

    for (int i = 0; i < incomes.size(); i++) {
        if (incomes[i].getDate() >= startingDate && incomes[i].getDate() <= endingDate) {
            selectedIncomes.push_back(incomes[i]);
        }
    }
    sort(selectedIncomes.begin(),selectedIncomes.end());
    return selectedIncomes;
}

float IncomeManager::sumOfSelectedIncomes(vector <Income> & selectedIncomes) {
    float sum = 0;

    for (int i = 0; i < selectedIncomes.size(); i++) {
        sum += atof((selectedIncomes[i].getAmount()).c_str());
    }
    return sum;
}