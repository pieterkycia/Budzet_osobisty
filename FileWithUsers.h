#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include "GeneralXmlFile.h"
#include "User.h"
#include "Markup.h"
#include <vector>

class FileWithUsers : public GeneralXmlFile {
public:
    FileWithUsers(string fileName): GeneralXmlFile(fileName) {};

    void addUserToFile(User & user);
    void changeUserPasswordInFile(User & user);
    vector <User> loadUserFromFile();
};

#endif // FILEWITHUSERS_H
