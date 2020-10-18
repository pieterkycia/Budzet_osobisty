#include <iostream>
#include "Budget.h"

using namespace std;

int main() {
    Budget budget("users.xml");
    char choice;

    while (true) {
        if (budget.userLoggedIn() == false) {
            choice = budget.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                budget.userRegister();
                break;
            case '2':
                budget.userLogin();
                break;
            case '3':
                budget.showAllUsers();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = budget.selectOptionFromUserMenu();
            switch (choice) {
            case '1':
                budget.addIncome();
                break;
            case '3':
                budget.showBalanceInThisMonth();
                break;
            case '4':
                budget.showBalanceInPreviousMonth();
                break;
            case '5':
                budget.showBalanceInSelectedPeriod();
                break;
            case '6':
                budget.changePassword();
                break;
            case '7':
                budget.userLogout();
                break;
            case '8':
                budget.showAllIncomes();
                break;
            default :
                cout << "Nie ma takiej opcji w menu" << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
