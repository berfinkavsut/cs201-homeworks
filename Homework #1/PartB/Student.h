#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#include "Course.h"

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
    int  getCourseNo() const;
    string getCourseName(const int courseId) const;

    //set functions
    void setFirstName(const string);
    void setId(const int);
    void setLastName(const string);

    //additional to part A
    void addCourseToStudent( const int courseId, const string courseTitle);
    bool deleteCourse( const int courseId );
    void showCourses() const;
    bool hasCourse( const int courseId ) const;


private:
    //private data member
    int studentId;
    string firstName;
    string lastName;
    //additional to part A
    int courseNo;
    Course* courseList;

friend ostream& operator<<( ostream& , const Student& ); //overloaded output operator

};

#endif // STUDENT_H_INCLUDED
