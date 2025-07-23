#ifndef PATIENT_H
#define PATIENT_H

#include "User.h"
#include<bits/stdc++.h>

class Admin;

class Patient : public User {
private:
    string patientID;
    int age;
    string disease;
public:
    Patient();
    void bookAppointment();
    void viewMedicalHistory();
    void showMenu() override;
    friend class Admin;
};

#endif
