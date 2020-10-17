#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class AuxiliaryMethods {
public:
    static string loadLine();
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string text);
    static char loadChar();
    static string convertIntToString(int number);
};
#endif // AUXILIARYMETHODS_H
