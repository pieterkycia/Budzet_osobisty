#ifndef BUDGET_H
#define BUDGET_H

#include "UserManager.h"

class Budget {
    UserManager userManager;

public:
    Budget(string nameFileWithUsers): userManager(nameFileWithUsers) {};

    bool userLoggedIn();

    void userRegister();
    void userLogin();
    void userLogout();
    void changePassword();
    void showAllUsers();

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
};

#endif // BUDGET_H

