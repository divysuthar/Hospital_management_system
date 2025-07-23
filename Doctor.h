#ifndef DOCTOR_H
#define DOCTOR_H

#include "User.h"
#include <iostream>
using namespace std;

class Doctor : public User
{
private:
    string specialization;

public:
    Doctor();
    void diagnosePatient();
    void showMenu() override;
};

#endif
