#ifndef REGISTRATIONSYSTEM_H_INCLUDED
#define REGISTRATIONSYSTEM_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#include "Student.h"

class RegistrationSystem {
public:
    RegistrationSystem();//constructor
    ~RegistrationSystem(); //destructor

    //public member functions
    void addStudent( const int studentId, const string firstName, const string lastName );
    void deleteStudent( const int studentId );

    //functions for courses
    void addCourse( const int studentId, const int courseId, const string courseName );
    void withdrawCourse( const int studentId, const int courseId );
    void cancelCourse( const int courseId );

    //display functions
    void showStudent( const int studentId ) const;
    void showCourse( const int courseId ) const;
    void showAllStudents() const;

private:
    //private data members
    Student* studentList;
    int studentNo;
};

#endif // REGISTRATIONSYSTEM_H_INCLUDED
