#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"
#include <vector>

class UserManager {
    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    bool loginExist(string login);
    int getNewUserId();

public:
    UserManager(string nameFile): fileWithUsers(nameFile) {
        loggedUserId = 0;
        users = fileWithUsers.loadUserFromFile();
    };

    User setNewUserData();

    void userRegister();
    void userLogin();
    void userLogout();
    void changePassword();
    void showAllUsers();

    int getLoggedUserId();
};



#endif // USERMANAGER_H
