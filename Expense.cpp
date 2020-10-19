#include "Expense.h"

bool Expense::operator<(const Expense & expense) {
    return (this -> date < expense.date);
}

void Expense::setExpenseId(int expenseId) {
    this -> expenseId = expenseId;
}

int Expense::getExpenseId() {
    return expenseId;
}
