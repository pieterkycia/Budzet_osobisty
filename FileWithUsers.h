#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include "User.h"
#include "Markup.h"
#include <vector>

class FileWithUsers {
    const string FILE_NAME;

public:
    FileWithUsers(string fileName): FILE_NAME(fileName) {};

    void addUserToFile(User & user);
    void changeUserPasswordInFile(User & user);
    vector <User> loadUserFromFile();
};


#endif // FILEWITHUSERS_H
