#include "ExpenseManager.h"

void ExpenseManager::addExpense() {
    Expense expense;

    expense = setNewExpenseData();
    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);
    cout << "Dodano wydatek." << endl;
    system("pause");
}

Expense ExpenseManager::setNewExpenseData() {
    Expense expense;

    expense.setDate();
    cout << "Podaj nazwe wydatku: ";
    expense.setItem(AuxiliaryMethods::loadLine());
    cout << "Podaj wysokosc wydatku: ";
    expense.setAmount(AuxiliaryMethods::loadLine());
    expense.setExpenseId(getNewExpenseId());
    expense.setUserId(LOGGED_USER_ID);
    return expense;
}

int ExpenseManager::getNewExpenseId() {
    return fileWithExpenses.getLastExpenseIdInFile() + 1;
}

void ExpenseManager::showSelectedExpenses(vector <Expense> & selectedExpenses) {
    if (!selectedExpenses.empty()) {
        for (int i = 0; i < selectedExpenses.size(); i++) {
            cout << endl;
            cout << "Data:      " << selectedExpenses[i].getDateInString() << endl;
            cout << "Nazwa:     " << selectedExpenses[i].getItem() << endl;
            cout << "Kwota:     " << selectedExpenses[i].getAmount() << endl;
        }
    } else {
        cout << endl << "Brak wydatkow." << endl;
    }
}

vector <Expense> ExpenseManager::selectExpensesByDate(Date & startingDate, Date & endingDate) {
    vector <Expense> selectedExpenses;

    for (int i = 0; i < expenses.size(); i++) {
        if (expenses[i].getDate() >= startingDate && expenses[i].getDate() <= endingDate) {
            selectedExpenses.push_back(expenses[i]);
        }
    }
    sort(selectedExpenses.begin(),selectedExpenses.end());
    return selectedExpenses;
}

double ExpenseManager::sumOfSelectedExpenses(vector <Expense> & selectedExpenses) {
    double sum = 0;

    for (int i = 0; i < selectedExpenses.size(); i++) {
        sum += atof((selectedExpenses[i].getAmount()).c_str());
    }
    return sum;
}
