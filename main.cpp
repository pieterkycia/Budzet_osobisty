#include <iostream>
#include "UserManager.h"

using namespace std;

int main() {
    UserManager userManager("users.xml");
    userManager.showAllUsers();
    while (1) {
        userManager.userRegister();
        userManager.showAllUsers();
    }
    return 0;
}
