#include <iostream>
#include <string>
using namespace std;

#include "Student.h"

/*
Constructor
Student is constructed with student's id, first name and last name
Student is constructed with an empty  list of courses
This constructor is also operating as default constructor by its default arguments in "Student.h"
*/
Student::Student(const int studentId, const string firstName, const string lastName){
    setId(studentId);
    setFirstName(firstName);
    setLastName(lastName);
    courseNo = 0;
    courseList = new Course[courseNo];
}


/*
Copy Constructor
Student is copied with its student id, first name
last name, course number and list of courses
*/
Student::Student(const Student& studentCopy){
    studentId = studentCopy.studentId;
    firstName = studentCopy.firstName;
    lastName = studentCopy.lastName;
    courseNo = studentCopy.courseNo;
    //deep copy
    delete [] courseList; //avoid memory leak
    courseList = NULL;
    //copy list of courses
    courseList = new Course[courseNo];
    for (int i = 0; i<courseNo;i++){
            courseList[i] = studentCopy.courseList[i];
    }
}

/*
Destructor
Set id to 0, clear first name and last name
Set courseNo to 0 and empty the list of courses
*/
Student::~Student(){
    studentId = 0;
    firstName = "";
    lastName = "";
    courseNo = 0;
    delete [] courseList;
    courseList = NULL;
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
        courseNo = right.courseNo;
        //deep copy
        delete [] courseList; // avoid memory leak
        courseList = NULL;
        //create copy of list of courses for assignment
        courseList = new Course[courseNo];
        for (int i = 0; i<courseNo;i++)
            courseList[i] = right.courseList[i];
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

/*
getCourseNo
Returns courseNo
*/
int Student::getCourseNo() const{
    return courseNo;
}

/*
getCourseName
Returns the course name with specified course id
*/
string Student::getCourseName(const int courseId) const{
    string courseName = "";
    //find the courseName by checking its course id
    for (int i = 0; i<courseNo;i++){
        if(courseList[i].getId() == courseId){
            courseName = courseList[i].getTitle();
            return courseName;
        }
    }
    return courseName;
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
addCourseToStudent
Adds the course with desired course id and title to student's list of courses
*/
void Student::addCourseToStudent( const int courseId, const string courseTitle){
    //indicator for whether course with given course id is student's list of courses or not
    int flag = 0;
    for (int i = 0; i < courseNo;i++){
        if(courseId == courseList[i].getId())
            flag = 1;
    }

    //if the course in not in student's list of courses, display warning message
    if (flag)
        cout << "Student " << studentId <<" is already enrolled in course " << courseId << endl;

    //else, add course to student's list of courses
    else{

        //create new course with specified id and title
        Course* newCourse = new Course(courseId,courseTitle);
        //copy courseList of Student object with size incremented by 1
        Course* temp = courseList;
        courseList = new Course[courseNo+1];

        //deep copy of the previous list of courses into the new list of courses
        for (int i = 0; i < courseNo;i++){
           courseList[i] = temp[i];
        }
        //add new course to courseList, unsorted list of courses
        courseList[courseNo] = *newCourse;
        //increment courseNo by 1
        courseNo++;

        delete newCourse; //avoid memory leak
        newCourse = NULL;
        delete [] temp; //avoid memory leak
        temp = NULL;

        cout<<"Course "<< courseId << " has been added to student " << studentId<<endl;
    }
}

/*
deleteCourse
Deletes the course with desired course id from student's list of courses
Returns true if delete operation is successful, false if unsuccessful
*/
bool Student::deleteCourse( const int courseId ){
    //indicator for whether student is already enrolled in the course or not
    int index = -1;
    for (int i = 0; i < courseNo;i++){
        if(courseId == courseList[i].getId())
            index = i;
    }

    //if student is not enrolled in the list of course, return false
    //delete operation is unsuccessful
    if (index == -1)
        return false;

    //
    else{

        //create new course with specified id and title
        Course* temp = courseList;
        //copy courseList of Student object with size decremented by 1
        courseList = new Course[courseNo-1];

        //deep copy of the previous list of courses into the new list of courses
        for (int i = 0; i<index;i++)
            courseList[i] = temp[i];
        for (int i = index+1; i<courseNo;i++)
            courseList[i-1] = temp[i];

        //decrement courseNo by 1
        courseNo--;

        delete [] temp; // avoid memory leak
        temp = NULL;

        return true;
    }
}

/*
hasCourse
Returns true if course with specified courseId is in list of courses
Returns false if not in list of courses
*/
bool Student::hasCourse( const int courseId ) const{
    for (int i = 0; i < courseNo ; i++){
        if(courseList[i].getId() == courseId)
            return true;
    }
    return false;
}

/*
showCourses
Displays student's list of courses
Displays nothing if list of courses is empty
*/
void Student::showCourses() const{
    if(courseNo>0){
    cout << "\tCourse id\tCourse name"<<endl;
    for (int i = 0; i<courseNo;i++)
        cout <<"\t" << courseList[i] <<endl;
    }
}


/*
Overloaded Output Operator
Returns student info to be displayed
List of courses are displayed after student id, first name and last name
*/
ostream& operator<<( ostream& out, const Student& sToDisplay ) {
    out << sToDisplay.studentId << "\t\t"<< sToDisplay.firstName;
    out << "\t\t" << sToDisplay.lastName;

    if(sToDisplay.courseNo>0){
        out << "\n\tCourse id\tCourse name"<<"\n";
        for (int i = 0; i<sToDisplay.courseNo;i++)
            out <<"\t" << sToDisplay.courseList[i] <<"\n";
    }
    return out;
}

