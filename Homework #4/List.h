// *************************************
// Header file List.h for the ADT list
// Pointer-based implementation.
// *************************************

class List{

public:

   // constructors and destructor:
   List();                  // default constructor
   List(const List& aList); // copy constructor
   ~List();                 // destructor

   // list operations:
   bool isEmpty() const;
   int getLength() const;

   bool retrieve(int index, char& dataItem) const;
   bool retrieve(int index, double& dataItem) const;

   bool insert(int index, char newItem);
   bool insert(int index, double newItem);

   bool remove(int index);

private:

   //a node on the list
   struct ListNode{
      char item; // char data item on the list
      double item2;  // double data item on the list
      ListNode *next;    // pointer to next node
   };

   int       size;  // number of items in list
   ListNode *head;  // pointer to linked list of items
   ListNode *find(int index) const; // Returns a pointer to the index-th node in the linked list
}; //end List class




