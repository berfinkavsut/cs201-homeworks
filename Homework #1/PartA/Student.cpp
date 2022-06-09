#include <iostream>
#include <string>
using namespace std;

#include "Student.h"

/*
Constructor
Student is constructed by student's id, first name and last name
This constructor is also operating as default constructor by its default arguments in "Student.h"
*/
Student::Student(const int studentId, const string firstName, const string lastName){
    setId(studentId);
    setFirstName(firstName);
    setLastName(lastName);
}

/*
Copy Constructor
Student is copied with its student id, first name and last name
*/
Student::Student(const Student& studentCopy){
    studentId = studentCopy.studentId;
    firstName = studentCopy.firstName;
    lastName = studentCopy.lastName;
}

/*
Destructor
Set id to 0, clear first name and last name
*/
Student::~Student(){
    studentId = 0;
    firstName = "";
    lastName = "";
}

/*
Overloaded Assignment Operator
Assigns Student object with the rvalue of assignment operator
Takes the student id, first name and last name of the rvalue
*/
void Student::operator = (const Student& right){
    if ( &right != this ) {
        studentId = right.studentId;
        firstName = right.firstName;
        lastName = right.lastName;
    }
}

//get functions

/*
getId
Returns studentId
*/
int Student::getId() const{
    return studentId;
}

/*
getFirstName
Returns firstName
*/
string Student::getFirstName() const{
    return firstName;
}

/*
getLastName
Returns lastName
*/
string Student::getLastName() const{
    return lastName;
}

//set functions

/*
setId
Sets studentId
*/
void Student::setId(const int myId){
    studentId = myId;
}

/*
setFirstName
Sets firstName
*/
void Student::setFirstName(const string myFirstName){
    firstName = myFirstName;
}

/*
setLastName
Sets lastName
*/
void Student::setLastName(const string myLastName){
    lastName = myLastName;
}

/*
Overloaded Output Operator
Returns student info to be displayed
*/
ostream& operator<<( ostream& out, const Student& sToDisplay ) {
    out << sToDisplay.studentId << "\t\t"<< sToDisplay.firstName;
    out << "\t\t" << sToDisplay.lastName;
    return out;
}
