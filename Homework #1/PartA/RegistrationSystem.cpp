#include <iostream>
#include <string>
using namespace std;

#include "RegistrationSystem.h"

/*
Constructor
The registration system is created by zero students
studentList initially does not contain any students
*/
RegistrationSystem::RegistrationSystem(){
   studentNo = 0;
   studentList = new Student[studentNo];
}

/*
Destructor
All students in registration system are deleted
*/
RegistrationSystem::~RegistrationSystem(){
    studentNo = 0;
    if (studentList){
        //avoid memory leak
        delete [] studentList;
        studentList = NULL;
    }
}

/*
addStudent
Add a new student to registration system with her/his student id, first name and last name
If the student is already in registration system, display warning message and do not add the student
If the student does not have a first name or last name, do not add the student
*/
void RegistrationSystem::addStudent( const int studentId, const string firstName, const string lastName ){
    //indicator for whether student already exists in registration system
    int flag = 0;
    for (int i = 0; i < studentNo;i++){
        if(studentId == studentList[i].getId())
            flag = 1;
    }

    //if the student already exists in registration system, display warning message and return
    if (flag)
        cout<<"Student "<<studentId << " already exists" << endl;

    //else if student does not have first name or last name, display warning message and return
    else if(firstName == "" || lastName ==""){
        cout<<"Student "<<studentId << " does not have a proper name" << endl;
    }

    //else, add student to registration system
    else{
        //create new student with desired id, first name and last name
        Student* newStudent = new Student(studentId,firstName,lastName);
        //copy existing studentList
        Student* temp = studentList;

        int index = 0; //index for the added student's position in studentList

        //recreate studentList with incremented size by 1
        studentList = new Student[studentNo+1];


        for (int i = 0; i < studentNo;i++){
            //if id of ith student is less than the given id, take one more for index
            //else do not change index
            if (studentId > temp[i].getId()){
                index = i+1;
            }
            //once studentId is less than the id of ith student, break from the loop
            else{
                break;
            }
        }

        //add student at the found index
        for (int i = 0; i<index;i++)
            studentList[i] = temp[i];
        studentList[index] = *newStudent;
        for (int i = index; i<studentNo;i++)
            studentList[i+1] = temp[i];
        //increase studentNo by 1
        studentNo++;

        //destroy copy of previous studentList, which is temp
        delete [] temp;//avoid memory leak
        temp = NULL;

        delete newStudent;
        newStudent = NULL;

        cout<<"Student "<<studentId << " has been added" << endl;
    }
}

/*
deleteStudent
Deletes student to registration system with given student id
If the student does not exist in registration system, displays warning message
*/
void RegistrationSystem::deleteStudent( const int studentId ){

    //indicator for whether student does not exist in registration system
    int index = -1;

    //find the index of given student if she/he is in registration system
    for (int i = 0; i < studentNo;i++){
        if (studentId == studentList[i].getId())
            index = i;
    }

    //if student does not exist in registration system, display warning message and return
    if (index == -1)
        cout<<"Student "<<studentId << " does not exist" << endl;
    //if student exists in registration system, delete student from registration system
    else{

        //copy of studentList
        Student* temp = studentList;
        //recreate studentList with decremented size by 1
        studentList = new Student[studentNo-1];

        //delete student by filling in studentList without the deleted student
        for (int i = 0; i<index;i++)
            studentList[i] = temp[i];
        for (int i = index+1; i<studentNo;i++)
            studentList[i-1] = temp[i];

        //decrement studentNo by 1
        studentNo--;
        //destroy temporary copy of previous studentList
        delete [] temp; //avoid memory leak
        temp = NULL;

        cout<<"Student "<<studentId << " has been deleted" << endl;
    }
}

/*
showStudent
Shows student with given student id
Displays warning message if student does not exist in registration system
*/

void RegistrationSystem::showStudent( const int studentId ){

    //indicator for whether student does not exist in registration system
    int index = -1;
    //get the index of student with desired student id
    for (int i = 0; i < studentNo;i++){
        if (studentList[i].getId() == studentId)
            index = i;
    }

    //if student does not exist in registration system, display warning message and return
    if(index == -1 )
        cout<<"Student "<<studentId << " does not exist" << endl;
    //if student exists in registration system, display info of student
    else{
        cout << "Student Id\tFirst Name\tLast Name"<<endl;
        cout << studentList[index] << endl;
    }
}

/*
showAllStudent
Shows all students inside registration system
Displays no student if the registration system is empty of students
*/
void RegistrationSystem::showAllStudents(){
    //if registration system does not have any students, display no student
    if (studentNo == 0)
        cout << "There are no students in the system"<<endl;

    //else, display all students inside studentList
    else{
    cout << "Student Id\tFirst Name\tLast Name"<<endl;

    for (int i = 0; i<studentNo;i++)
        cout << studentList[i] <<endl;
    }
}

