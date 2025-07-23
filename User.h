#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>
using namespace std;

class User {
protected:
    string name;
    string username;
    string password;
public:
    virtual void showMenu() = 0;
    virtual ~User() {}
};

#endif
