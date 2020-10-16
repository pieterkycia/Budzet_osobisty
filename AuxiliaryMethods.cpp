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

char AuxiliaryMethods::loadChar() {
    string text = "";
    char oneChar  = {0};
    while (true) {
        getline(cin, text);

        if (text.length() == 1) {
            oneChar = text[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return oneChar;
}
