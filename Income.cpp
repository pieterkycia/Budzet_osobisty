#include "Income.h"

bool Income::operator<(const Income & income) {
    return (this -> date < income.date);
}

void Income::setIncomeId(int incomeId) {
    this -> incomeId = incomeId;
}

int Income::getIncomeId() {
    return incomeId;
}
