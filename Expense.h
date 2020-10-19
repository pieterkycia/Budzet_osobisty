#ifndef EXPENSE_H
#define EXPENSE_H

#include "GeneralItem.h"

class Expense : public GeneralItem {
    int expenseId;

public:
    bool operator<(const Expense & expense);

    void setExpenseId(int expenseId);
    int getExpenseId();
};

#endif // EXPENSE_H
