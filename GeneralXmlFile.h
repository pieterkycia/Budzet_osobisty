#ifndef GENERALXMLFILE_H
#define GENERALXMLFILE_H

#include <iostream>

using namespace std;

class GeneralXmlFile {
protected:
    const string FILE_NAME;

public:
    GeneralXmlFile(string fileName): FILE_NAME(fileName) {};
};
#endif // GENERALXMLFILE_H
