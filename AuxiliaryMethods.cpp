#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadLine() {
    string line = "";
    cin.sync();
    getline(cin, line);
    return line;
}

string AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
