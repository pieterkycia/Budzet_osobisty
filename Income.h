#ifndef INCOME_H
#define INCOME_H

#include "GeneralItem.h"

class Income : public GeneralItem {
    int incomeId;

public:
    bool operator<(const Income & income);

    void setIncomeId(int incomeId);
    int getIncomeId();
};

#endif // INCOME_H
