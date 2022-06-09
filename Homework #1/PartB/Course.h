#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Course{
public:
    Course (const int cId= 0, const string cTitle= ""); //constructor
    Course (const Course& courseCopy); //copy constructor
    ~Course(); //destructor
    void operator = (const Course& right); //overloaded assignment operator

    //public member functions
    //get functions
    int getId() const;
    string getTitle() const;

    //set functions
    void setId(const int);
    void setTitle(const string);

private:
    //private data members
    int courseId;
    string courseTitle;

friend ostream& operator<<( ostream& , const Course& ); // overloaded output operator

};

#endif // COURSE_H_INCLUDED
