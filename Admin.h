#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Patient.h"

class Admin : public User {
public:
    Admin();
    void addPatient();
    void modifyPatientRecord();
    void viewAllAppointments();
    void showMenu() override;
};

#endif
