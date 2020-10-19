#ifndef EXPENSE_H
#define EXPENSE_H

#include "Date.h"

class Expense {
    int expenseId;
    int userId;
    Date date;
    string item;
    string amount;

public:
    bool operator<(const Expense & expense);

    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDate();
    void setDateFromFile(string dateFromFile);
    void setItem(string item);
    void setAmount(string amount);

    int getExpenseId();
    int getUserId();
    string getDateOnString();
    Date & getDate();
    string getItem();
    string getAmount();
};

#endif // EXPENSE_H
