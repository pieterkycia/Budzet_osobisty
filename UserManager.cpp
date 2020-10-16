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
    fileWithUsers.addUserToFile(user);
    cout << endl << "Dodano nowego uzytkownika." << endl;
}

void UserManager::userLogin() {
    string login = "";
    string password = "";

    if (!users.empty()) {
        cout << endl << "Podaj login: ";
        login = AuxiliaryMethods::loadLine();
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getLogin() == login) {

                for (int j = 3; j > 0; j--) {
                    cout << endl << "Podaj haslo. Pozostalo prob: " << j << ": ";
                    password = AuxiliaryMethods::loadLine();
                    if (users[i].getPassword() == password) {
                        cout << endl << "Zalogowano." << endl;
                        loggedUserId = users[i].getUserId();
                        return;
                    }
                }
                cout << endl << "Wprowadzono 3 razy bledne haslo." << endl;
                system("pause");
                return;
            }
        }
        cout << endl << "Nie ma uzytkownika z takim loginem " << endl;
        system("pause");
    } else {
        cout << endl << "Nie ma zapisanych uzytkownikow." << endl;
        system("pause");
    }
}

void UserManager::userLogout() {
    cout << endl << "Wylogowano." << endl;
    loggedUserId = 0;
    system("pause");
}

void UserManager::showAllUsers() {
    if (!users.empty()) {
        for (int i = 0; i < users.size(); i++) {
            cout << endl;
            cout << "UserId:      " << users[i].getUserId() << endl;
            cout << "Name:        " << users[i].getName() << endl;
            cout << "Surname:     " << users[i].getSurname() << endl;
            cout << "Login:       " << users[i].getLogin() << endl;
            cout << "Password:    " << users[i].getPassword() << endl;
        }
    } else {
        cout << endl << "Nie ma zapisanych uzytkownikow." << endl;
        system("pause");
    }
}

int UserManager::getLoggedUserId() {
return loggedUserId;
}
