#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include "User.h"
#include "Markup.h"
#include <vector>

class FileWithUsers {
    const string NAME_FILE;

public:
    FileWithUsers(string nameFile): NAME_FILE(nameFile) {};

    void addUserToFile(User user);
    vector <User> loadUserFromFile();
};


#endif // FILEWITHUSERS_H
