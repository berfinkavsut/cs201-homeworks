#ifndef REGISTRATIONSYSTEM_H_INCLUDED
#define REGISTRATIONSYSTEM_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#include "Student.h"

class RegistrationSystem {
public:
    RegistrationSystem(); //constructor
    ~RegistrationSystem(); //destructor

    //public member functions
    void addStudent( const int studentId, const string firstName, const string lastName );
    void deleteStudent( const int studentId );
    void showStudent( const int studentId );
    void showAllStudents();

private:
    //private data members
    Student* studentList;
    int studentNo;
};

#endif // REGISTRATIONSYSTEM_H_INCLUDED
