#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    //public member functions
    Student (const int sId= 0, const string sFirstName= "",const string sLastName= ""); //constructor
    Student (const Student& studentCopy); //copy constructor
    ~Student(); //destructor
    void operator = (const Student& right); //overloaded assignment operator

    //get functions
    int getId() const;
    string getFirstName() const;
    string getLastName() const;

    //set functions
    void setFirstName(const string);
    void setId(const int);
    void setLastName(const string);

private:
    //private data members
    int studentId;
    string firstName;
    string lastName;

friend ostream& operator<<( ostream& , const Student& ); //overloaded output operator
};

#endif // STUDENT_H_INCLUDED
