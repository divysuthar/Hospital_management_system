#include "Doctor.h"
#include <fstream>

Doctor::Doctor() {
    cout << "Enter Doctor Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Specialization: ";
    getline(cin, specialization);
}

void Doctor::diagnosePatient() {
    string id, diagnosis;
    cout << "Enter Patient ID: ";
    getline(cin, id);
    cout << "Enter Diagnosis Notes: ";
    getline(cin, diagnosis);

    ofstream file("data/patients/" + id + ".txt", ios::app);
    file << "Doctor: " << name << "\nDiagnosis: " << diagnosis << "\n\n";
    file.close();

    cout << "Diagnosis saved to medical history.\n";
}

void Doctor::showMenu() {
    int choice;
    do {
        cout << "\nDoctor Menu:\n";
        cout << "1. Diagnose Patient\n2. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) diagnosePatient();
    } while (choice != 2);
}
