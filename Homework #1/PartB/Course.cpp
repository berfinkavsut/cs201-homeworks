#include <iostream>
#include <string>
using namespace std;

#include "Course.h"

/*
Constructor
Course is constructed with course id and course title
This constructor is also operating as default constructor by its default arguments in "Course.h"
*/
Course::Course(const int courseId, const string courseTitle){
    setId(courseId);
    setTitle(courseTitle);
}

/*
Copy Constructor
Course is copied with course id and course title
*/
Course::Course(const Course& courseCopy){
    courseId = courseCopy.courseId;
    courseTitle = courseCopy.courseTitle;
}


/*
Destructor
Sets course id to 0 and clears course title
*/
Course::~Course(){
    courseId = 0;
    courseTitle = "";
}

/*
Overloaded Assignment Operator
Assigns Course object with the rvalue of assignment operator
Takes the course id and course title
*/
void Course::operator = (const Course& right){
    if ( &right != this ) {
        courseId = right.courseId;
        courseTitle = right.courseTitle;
    }
}

//get functions

/*
getId
Returns courseId
*/
int Course::getId() const{
    return courseId;
}

/*
getTitle
Returns courseTitle
*/
string Course::getTitle() const{
    return courseTitle;
}

//set functions

/*
setId
Sets courseId
*/
void Course::setId(const int myId){
    courseId = myId;
}

/*
setTitle
Sets courseTitle
*/
void Course::setTitle(const string myTitle){
    courseTitle = myTitle;
}

/*
Overloaded Output Operator
Returns course info to be displayed
*/
ostream& operator<<( ostream& out, const Course& cToDisplay ) {
    out << cToDisplay.courseId << "\t\t"<< cToDisplay.courseTitle;
    return out;
}
