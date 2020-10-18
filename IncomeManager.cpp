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

void IncomeManager::showAllIncomes() {
    if (!incomes.empty()) {
        for (int i = 0; i < incomes.size(); i++) {
            cout << endl;
            cout << "incomeId:     " << incomes[i].getIncomeId() << endl;
            cout << "userId:       " << incomes[i].getUserId() << endl;
            cout << "date:         " << incomes[i].getDate() << endl;
            cout << "item:         " << incomes[i].getItem() << endl;
            cout << "amount:       " << incomes[i].getAmount() << endl;
        }
    } else {
        cout << endl << "Nie ma zapisanych przychodow." << endl;
    }
    system("pause");
}

int IncomeManager::getNewIncomeId() {
    return fileWithIncomes.getLastIncomeIdInFile() + 1;
}
