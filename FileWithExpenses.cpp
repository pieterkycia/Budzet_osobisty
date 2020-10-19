#include "FileWithExpenses.h"

vector <Expense> FileWithExpenses::loadExpensesLoggedUserFromFile(int loggedUserId) {
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;
    lastExpenseIdInFile = 0;

    if(xml.Load(FILE_NAME) == true) {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while (xml.FindElem("Expense")) {
            xml.IntoElem();
            xml.FindElem("expenseId");
            lastExpenseIdInFile = atoi(MCD_2PCSZ(xml.GetData()));
            expense.setExpenseId(lastExpenseIdInFile);
            xml.FindElem("userId");
            if (loggedUserId == atoi(MCD_2PCSZ(xml.GetData()))) {
                expense.setUserId(loggedUserId);
                xml.FindElem("date");
                expense.setDateFromFile(xml.GetData());
                xml.FindElem("item");
                expense.setItem(xml.GetData());
                xml.FindElem("amount");
                expense.setAmount(xml.GetData());
                expenses.push_back(expense);
                xml.OutOfElem();
            } else
                xml.OutOfElem();
        }
    }
    return expenses;
}

void FileWithExpenses::addExpenseToFile(Expense & expense) {
    CMarkup xml;

    if(xml.Load(FILE_NAME) == false) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    } else {
        if (xml.FindElem("Expenses")) {
        } else
            xml.AddElem("Expenses");
    }
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("expenseId", expense.getExpenseId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", expense.getDateOnString());
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", expense.getAmount());
    xml.Save(FILE_NAME);
    lastExpenseIdInFile++;
}

int FileWithExpenses::getLastExpenseIdInFile() {
    return lastExpenseIdInFile;
}
