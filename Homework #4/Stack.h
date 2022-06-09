#include "List.h"

class Stack {

public:

   // constructors and destructor:
   Stack();
   Stack(const Stack& aStack);
   ~Stack();

   // stack operations:
   bool isEmpty() const;

   bool push(char newItem);
   bool push(double newItem);

   bool pop();

   bool pop(char& stackTop);
   bool pop(double& stackTop);

   bool getTop(char& stackTop) const;
   bool getTop(double& stackTop) const;

private:

   List aList;  // list of stack items

};
