#include <iostream>
#include "UserManager.h"

using namespace std;

int main() {
    UserManager userManager("users.xml");
    userManager.showAllUsers();
    while (1) {
        userManager.userLogin();
        userManager.userRegister();
        userManager.userLogout();
        userManager.showAllUsers();
    }
    return 0;
}
