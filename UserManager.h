#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"
#include <vector>

class UserManager {
    vector <User> users;
    FileWithUsers fileWithUsers;

    bool loginExist(string login);
    int getNewUserId();

public:
    UserManager(string nameFile): fileWithUsers(nameFile) {};

    User setNewUserData();

    void userRegister();
    void showAllUsers();
};



#endif // USERMANAGER_H
