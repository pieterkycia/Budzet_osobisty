#ifndef INCOME_H
#define INCOME_H

#include "Date.h"

class Income {
    int incomeId;
    int userId;
    Date date;
    string item;
    string amount;

public:

    bool operator<(const Income & income);

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate();
    void setDateFromFile(string dateFromFile);
    void setItem(string item);
    void setAmount(string amount);

    int getIncomeId();
    int getUserId();
    string getDateOnString();
    Date & getDate();
    string getItem();
    string getAmount();
};

#endif // INCOME_H
