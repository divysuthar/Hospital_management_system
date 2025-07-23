#include "Patient.h"
using namespace std;

Patient::Patient()
{
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Patient ID: ";
    getline(cin, patientID);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Disease: ";
    cin.ignore();
    getline(cin, disease);
}

void Patient::bookAppointment()
{
    string date, time;
    cout << "Enter Appointment Date (DD/MM/YYYY): ";
    getline(cin, date);
    cout << "Enter Time (HH:MM): ";
    getline(cin, time);

    ofstream file("data/appointments.txt", ios::app);
    file << patientID << "," << name << "," << date << "," << time << "\n";
    file.close();

    cout << "Appointment booked successfully!\n";
}

void Patient::viewMedicalHistory()
{
    ifstream file("data/patients/" + patientID + ".txt");
    string line;
    cout << "--- Medical History ---\n";
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

void Patient::showMenu()
{
    int choice;
    do
    {
        cout << "\nPatient Menu:\n";
        cout << "1. Book Appointment\n2. View Medical History\n3. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            bookAppointment();
            break;
        case 2:
            viewMedicalHistory();
            break;
        }
    } while (choice != 3);
}
