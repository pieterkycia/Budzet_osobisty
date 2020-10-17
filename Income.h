#ifndef INCOME_H
#define INCOME_H

#include "Date.h"

class Income {
    int incomeId;
    int userId;
    Date date;
    string item;
    float amount;

public:

    bool operator<(const Income & income);

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate();
    void setItem(string item);
    void setAmount(float amount);

    int getIncomeId();
    int getUserId();
    string getDate();
    string getItem();
    float getAmount();
};

#endif // INCOME_H
