#include "UserManager.h"

User UserManager::setNewUserData() {
    User user;

    cout << endl << "Podaj imie: ";
    string name = AuxiliaryMethods::loadLine();
    name = AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(name);
    user.setName(name);
    cout << "Podaj nazwisko: ";
    string surname = AuxiliaryMethods::loadLine();
    surname = AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(surname);
    user.setSurname(surname);

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
    system("pause");
}

void UserManager::userLogin() {
    string login = "";
    string password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {

            for (int ileProb = 3; ileProb > 0; ileProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << ileProb << ": ";
                password = AuxiliaryMethods::loadLine();
                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowano." << endl;
                    loggedUserId = users[i].getUserId();
                    system("pause");
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
}

void UserManager::userLogout() {
    cout << endl << "Wylogowano." << endl;
    loggedUserId = 0;
    system("pause");
}

void UserManager::changePassword() {
    string newpassword = "";
    cout << endl << "Podaj nowe haslo: ";
    newpassword = AuxiliaryMethods::loadLine();

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUserId() == loggedUserId) {
            users[i].setPassword(newpassword);
            fileWithUsers.changeUserPasswordInFile(users[i]);
            cout << endl << "Haslo zostalo zmienione" << endl;
            system("pause");
            return;
        }
    }
}

int UserManager::getLoggedUserId() {
    return loggedUserId;
}
