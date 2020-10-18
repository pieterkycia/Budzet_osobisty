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
    static string convertFloatToString(float number);
    static string changeCommaToDot(string number);
};

#endif // AUXILIARYMETHODS_H
