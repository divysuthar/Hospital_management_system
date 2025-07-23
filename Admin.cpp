#include "Admin.h"
#include <iostream>
#include <fstream>
using namespace std;

Admin::Admin() {
    cout << "Enter Admin Username: ";
    cin.ignore();
    getline(cin, username);
    password = "admin";  // demo
}

void Admin::addPatient() {
    Patient p;
    ofstream file("data/patients/" + p.patientID + ".txt");
    file << "Name: " << p.name << "\nAge: " << p.age << "\nDisease: " << p.disease << "\n";
    file.close();
    cout << "Patient record created successfully.\n";
}

void Admin::modifyPatientRecord() {
    string id;
    cout << "Enter Patient ID to Modify: ";
    getline(cin, id);
    ofstream file("data/patients/" + id + ".txt", ios::app);
    string entry;
    cout << "Enter note to add to record: ";
    getline(cin, entry);
    file << "Admin Note: " << entry << "\n";
    file.close();
    cout << "Record updated.\n";
}

void Admin::viewAllAppointments() {
    ifstream file("data/appointments.txt");
    string line;
    cout << "--- All Appointments ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void Admin::showMenu() {
    int choice;
    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add New Patient\n2. Modify Patient Record\n3. View All Appointments\n4. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: addPatient(); break;
            case 2: modifyPatientRecord(); break;
            case 3: viewAllAppointments(); break;
        }
    } while (choice != 4);
}
