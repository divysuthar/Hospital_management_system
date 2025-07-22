#include <bits/stdc++.h>
using namespace std;

class User
{
protected:
    string name, username, password;

public:
    virtual void showMenu() = 0;
    virtual ~User() {}
};

class Appointment
{
private:
    string patientID, doctorName, date, time;

public:
    static int totalAppointments;
    Appointment() {}
    Appointment(string pid, string doc, string d, string t)
    {
        patientID = pid, doctorName = doc, date = d, time = t;
        totalAppointments++;
    }
    void saveToFile()
    {
        ofstream out("data/appointments.txt", ios::app);
        out << patientID << "," << doctorName << "," << date << "," << time << endl;
        out.close();
    }
};
int Appointment::totalAppointments = 0;

class Patient : public User
{
private:
    string patientID;
    int age;
    string disease;

public:
    Patient() {}
    Patient(string pid, string n, int a, string d)
    {
        patientID = pid, age = a, disease = d;
        name = n;
    }
    void bookAppointment()
    {
        string docName, date, time;
        cout << "\nBooking Appointment\n";
        cout << "Doctor's Name: ";
        cin >> docName;
        cout << "Date (dd-mm-yyyy): ";
        cin >> date;
        cout << "Time (HH:MM): ";
        cin >> time;
        Appointment appt(patientID, docName, date, time);
        appt.saveToFile();
        cout << "Appointment booked successfully!\n";
    }
    void viewMedicalHistory()
    {
        string filePath = "data/patients/" + patientID + ".txt";
        ifstream in(filePath);
        if (!in)
        {
            cout << "No medical history found.\n";
            return;
        }
        cout << "\nMedical History for " << name << ":\n";
        string line;
        while (getline(in, line))
        {
            cout << line << endl;
        }
        in.close();
    }
    string getID() const
    {
        return patientID;
    }
    friend class Admin;
    void showMenu() override
    {
        int choice;
        do
        {
            cout << "\nPatient Menu for " << name << ":\n1. View Medical History\n2. Book Appointment\n0. Logout\nChoice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                viewMedicalHistory();
                break;
            case 2:
                bookAppointment();
                break;
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
        } while (choice != 0);
    }
};

class Doctor : public User
{
private:
    string specialization;

public:
    Doctor(string uname, string n, string pass, string spec)
    {
        username = uname;
        name = n;
        password = pass;
        specialization = spec;
    }
    void diagnosePatient()
    {
        string pid, notes;
        cout << "Enter Patient ID: ";
        cin >> pid;
        cout << "Diagnosis Notes: ";
        cin.ignore();
        getline(cin, notes);
        string filePath = "data/patients/" + pid + ".txt";
        ofstream out(filePath, ios::app);
        out << "Diagnosis by Dr. " << name << ": " << notes << endl;
        out.close();
        cout << "Notes saved.\n";
    }
    void showMenu() override
    {
        int choice;
        do
        {
            cout << "\nDoctor Menu for Dr. " << name << ":\n1. Diagnose Patient\n0. Logout\nChoice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                diagnosePatient();
                break;
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
        } while (choice != 0);
    }
};

class Admin : public User
{
public:
    Admin(string uname, string n, string pass)
    {
        username = uname;
        name = n;
        password = pass;
    }
    void addPatient()
    {
        string pid, pname, disease;
        int age;
        cout << "Enter Patient ID: ";
        cin >> pid;
        cout << "Name: ";
        cin >> pname;
        cout << "Age: ";
        cin >> age;
        cout << "Disease: ";
        cin >> disease;
        string filePath = "data/patients/" + pid + ".txt";
        ofstream out(filePath);
        out << "Patient: " << pname << ", Age: " << age << ", Disease: " << disease << endl;
        out.close();
        cout << "Patient added and file created.\n";
    }
    void viewAllAppointments()
    {
        ifstream in("data/appointments.txt");
        if (!in)
        {
            cout << "No appointments found.\n";
            return;
        }
        cout << "\nAll Appointments:\n";
        string line;
        while (getline(in, line))
        {
            cout << line << endl;
        }
        in.close();
    }
    void showMenu() override
    {
        int choice;
        do
        {
            cout << "\nAdmin Menu:\n1. Add Patient\n2. View All Appointments\n0. Logout\nChoice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                addPatient();
                break;
            case 2:
                viewAllAppointments();
                break;
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
        } while (choice != 0);
    }
};

int main()
{
}