#include "UserManager.h"

User UserManager::setNewUserData() {
    User user;

    cout << endl << "Podaj imie: ";
    string name = AuxiliaryMethods::loadLine();
    user.setName(AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(name));
    cout << "Podaj nazwisko: ";
    string surname = AuxiliaryMethods::loadLine();
    user.setSurname(AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(surname));

    do {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    } while (loginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::loadLine());
    user.setUserId(getNewUserId());

    return user;
}

bool UserManager::loginExist(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << "Podany login jest zajety." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

void UserManager::userRegister() {
    User user;

    user = setNewUserData();
    users.push_back(user);
    cout << endl << "Dodano nowego uzytkownika." << endl;
}

void UserManager::showAllUsers() {
    for (int i = 0; i < users.size(); i++) {
        cout << endl;
        cout << "UserId:      " << users[i].getUserId() << endl;
        cout << "Name:        " << users[i].getName() << endl;
        cout << "Surname:     " << users[i].getSurname() << endl;
        cout << "Login:       " << users[i].getLogin() << endl;
        cout << "Password:    " << users[i].getPassword() << endl;
    }
}
