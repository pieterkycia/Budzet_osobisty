#ifndef GENERALITEM_H
#define GENERALITEM_H

#include "Date.h"

class GeneralItem {
protected:
    int userId;
    Date date;
    string item;
    string amount;

public:
    void setUserId(int userId);
    void setDate();
    void setDateFromFile(string dateFromFile);
    void setItem(string item);
    void setAmount(string amount);

    int getUserId();
    string getDateInString();
    Date & getDate();
    string getItem();
    string getAmount();
};

#endif // GENERALITEM_H
