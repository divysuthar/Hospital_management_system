#include<bits/stdc++.h>
#include "User.h"
#include "Patient.h"
#include "Doctor.h"
#include "Admin.h"

using namespace std;

void loginMenu() {
    int choice;
    cout << "\n--- Hospital Management System ---\n";
    cout << "1. Patient\n2. Doctor\n3. Admin\n4. Exit\nChoice: ";
    cin >> choice;

    User* user = NULL;

    switch (choice) {
        case 1:
            user = new Patient();
            break;
        case 2:
            user = new Doctor();
            break;
        case 3:
            user = new Admin();
            break;
        case 4:
            cout << "Goodbye!\n";
            return;
        default:
            cout << "Invalid choice\n";
            return;
    }

    user->showMenu();
    delete user;
}

int main() {
    while (true) {
        loginMenu();
    }
    return 0;
}
