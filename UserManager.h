#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "AuxiliaryMethods.h"
#include <vector>

class UserManager {
    vector <User> users;
    bool loginExist(string login);
    int getNewUserId();

public:
    User setNewUserData();

    void userRegister();
    void showAllUsers();
};



#endif // USERMANAGER_H
