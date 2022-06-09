// **************************************
// Implementation file ListA.cpp for the ADT list
// Pointer-based implementation
// *****************************************

#include "List.h"  //header file
#include <iostream>
#include <cstddef> // for NULL

using namespace std;

List::List() : size(0), head(NULL) {}

List::List(const List& aList): size(aList.size){
   if (aList.head == NULL)
      head = NULL;  // original list is empty
   else {
      // copy first node
      head = new ListNode;
      head->item = aList.head->item;
      head->item2 = aList.head->item2;
      // copy rest of list
      ListNode *newPtr = head;  // new list ptr

      for (ListNode *origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next){
         newPtr->next = new ListNode;
         newPtr = newPtr->next;
         newPtr->item = origPtr->item;
         newPtr->item2 = origPtr->item2;
      }
      newPtr->next = NULL;
   }
}  // end copy constructor

List::~List(){
   while (!isEmpty())
      remove(1);
} // end destructor



bool List::isEmpty() const{
   return (size == 0);
}

int List::getLength() const{
   return size;
}

List::ListNode *List::find(int index) const{

   if ( (index < 1) || (index > getLength()) )
      return NULL;

   else{ // count from the beginning of the list
      ListNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }
}  // end find

bool List::retrieve(int index, char& dataItem) const {

   if ((index < 1) || (index > getLength()))
      return false;

   // get pointer to node, then data in node
   ListNode *cur = find(index);
   dataItem = cur->item;

   return true;

} // end retrieve


bool List::retrieve(int index, double& dataItem) const {

   if ((index < 1) || (index > getLength()))
      return false;

   // get pointer to node, then data in node
   ListNode *cur = find(index);
   dataItem = cur->item2;

   return true;

} // end retrieve



bool List::insert(int index, char newItem) {

   int newLength = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   ListNode *newPtr = new ListNode;
   size = newLength;
   newPtr->item = newItem;

   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      ListNode *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;

} // end insert


bool List::insert(int index, double newItem) {

   int newLength = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   ListNode *newPtr = new ListNode;
   size = newLength;
   newPtr->item2 = newItem;

   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      ListNode *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;

} // end insert

bool List::remove(int index) {

   ListNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   --size;

   if (index == 1){
      cur = head;
      head = head->next;
   }
   else{
      ListNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;

   return true;

}  // end remove
