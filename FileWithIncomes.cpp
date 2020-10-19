#include "FileWithIncomes.h"

vector <Income> FileWithIncomes::loadIncomesLoggedUserFromFile(int loggedUserId) {
    Income income;
    vector <Income> incomes;
    CMarkup xml;
    lastIncomeIdInFile = 0;

    if(xml.Load(FILE_NAME) == true) {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while (xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("incomeId");
            lastIncomeIdInFile = atoi(MCD_2PCSZ(xml.GetData()));
            income.setIncomeId(lastIncomeIdInFile);
            xml.FindElem("userId");
            if (loggedUserId == atoi(MCD_2PCSZ(xml.GetData()))) {
                income.setUserId(loggedUserId);
                xml.FindElem("date");
                income.setDateFromFile(xml.GetData());
                xml.FindElem("item");
                income.setItem(xml.GetData());
                xml.FindElem("amount");
                income.setAmount(xml.GetData());
                incomes.push_back(income);
                xml.OutOfElem();
            } else
                xml.OutOfElem();
        }
    }
    return incomes;
}

void FileWithIncomes::addIncomeToFile(Income & income) {
    CMarkup xml;

    if(xml.Load(FILE_NAME) == false) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    } else {
        if (xml.FindElem("Incomes")) {
        } else
            xml.AddElem("Incomes");
    }
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", income.getIncomeId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", income.getDateInString());
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", income.getAmount());
    xml.Save(FILE_NAME);
    lastIncomeIdInFile++;
}

int FileWithIncomes::getLastIncomeIdInFile() {
    return lastIncomeIdInFile;
}
