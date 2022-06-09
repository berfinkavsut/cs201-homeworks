#include "Stack.h"     // list operations

// default constructor
Stack::Stack(){}

// copy constructor
Stack::Stack(const Stack& aStack): aList(aStack.aList){}

// destructor
Stack::~Stack() {}

bool Stack::isEmpty() const {
   return aList.isEmpty();
}

bool Stack::getTop(char& stackTop) const {
   return aList.retrieve(1, stackTop);
}

bool Stack::getTop(double& stackTop) const {
   return aList.retrieve(1, stackTop);
}

bool Stack::push(char newItem){
     return aList.insert(1, newItem);
}

bool Stack::push(double newItem){
     return aList.insert(1, newItem);
}

bool Stack::pop() {
    return aList.remove(1);
}

bool Stack::pop(char& stackTop) {
   if (aList.retrieve(1, stackTop)) //first retrieve
      return aList.remove(1); //then, delete
   else
      return false;
}

bool Stack::pop(double& stackTop) {
   if (aList.retrieve(1, stackTop)) //first retrieve
      return aList.remove(1); //then, delete
   else
      return false;
}


