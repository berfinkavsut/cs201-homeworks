#include "CompleteReg.h"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

CompleteReg::CompleteReg() {
    head = new Node;
    teamCount = 0;
    head->next = NULL;
}

CompleteReg::~CompleteReg() {

    if(head->next == NULL)
        return;

    Node* cur = head->next;
    for ( int i = 0; i < teamCount; i++ ) {
        delete cur;
        cur = cur -> next; // next item

    }
    head->next = NULL;
    teamCount = 0;
}

CompleteReg::CompleteReg( const CompleteReg &systemToCopy ){

   teamCount = systemToCopy.teamCount;

   if (systemToCopy.head == NULL)
      head = NULL;
   else {

      head = new Node;
      head->t = systemToCopy.head->t;

      Node *ptr = head;

      for (Node *cur = systemToCopy.head->next; cur != NULL; cur = cur->next){
         ptr->next = new Node;
         ptr = ptr->next;
         ptr->t = cur->t;
      }
      ptr->next = NULL;
   }
}

CompleteReg& CompleteReg::operator=( const CompleteReg &right ){

   teamCount = right.teamCount;

   if (right.head == NULL)
      head = NULL;
   else {

      head = new Node;
      head->t = right.head->t;

      Node *ptr = head;

      for (Node *cur = right.head->next; cur != NULL; cur = cur->next){
         ptr->next = new Node;
         ptr = ptr->next;
         ptr->t = cur->t;
      }
      ptr->next = NULL;
   }
}

Team& CompleteReg::operator[]( const int index ){};

void CompleteReg::displayTeam( const string tName ) const{
    Node* ptr = findTeam(tName);
    if(!ptr){
        cout << ptr->t <<endl;
        cout << "--EMPTY--" <<endl;
    }
    else{
        cout << ptr->t <<endl;
        ptr->t.displayPlayers();
    }
}

void CompleteReg::addTeam ( const string tName, const string tColor, const int tYear ){


    if(tYear < 1800 || tYear > 2000){
        cout << "Team year is not between 1800 and 2000!" << endl;
        return;
    }

    if (!findTeam(tName)) {

        Node *cur = head;
        for ( int i = 0; i < teamCount; i++ ) {
            cur = cur->next;
        }

        cur->next = new Node;
        cur = cur->next;


        cur->t.setTeamName(tName);
        cur->t.setTeamColor(tColor);
        cur->t.setTeamYear(tYear);

        cur->next = NULL;

        teamCount++;
    }
    else{
        cout << "Team already exists in registration system!" << endl;
    }
}

void CompleteReg::removeTeam(const string teamName) {

    Node *prev = head;
    Node* cur = head->next;

    for ( int i = 0; i < teamCount; i++ ) {

        if ( cur->t.getTeamName() == teamName ) {
            prev->next = cur->next;
            delete cur;
            teamCount--;
            return;
        }

        prev = cur;
        cur = cur->next;
    }

    cout << "There is no team with given team name!" << endl;
}

void CompleteReg::displayAllTeams() const{

    if (head->next == NULL)
        cout << "--EMPTY--"<<endl;

    Node *cur = head->next;
    for (int i = 0; i < teamCount; i++){
        cout << "Team " << cur->t << endl;
        cur->t.displayPlayers();
        cur = cur->next;
    }

}

CompleteReg::Node* CompleteReg::findTeam(const string teamName) const {

    string str = teamName;
    transform(str.begin(), str.end(),str.begin(), ::toupper);

    if(head->next == NULL)
        return NULL;

    string tName;

    Node *cur = head->next;
    for (int i = 1; i <= teamCount; i++){

        tName = cur->t.getTeamName();
        transform(tName.begin(), tName.end(),tName.begin(), ::toupper);

        if( tName == str )
            return cur;
        cur = cur->next;
    }
    return NULL;

}

int CompleteReg::getSize() const{
    return teamCount;
}

void CompleteReg::addPlayer( const string tName, const string pName, const string pPosition ){
    Node* ptr = findTeam(tName);
    if(!ptr){
        cout << "Team does not exist!" <<endl;
    }
    else{
        ptr->t.addPlayer(pName, pPosition);
    }
}


void CompleteReg::displayPlayer( const string playerName ) const {

    bool flag = false;

    if(head->next!=NULL) {

        cout << playerName << endl;

        Node* cur = head->next;
        for (int i = 0; i<teamCount;i++){
            if(cur->t.existPlayer(playerName)){
                cout << cur->t.getPosition(playerName)<<",\t";
                cout << cur->t << endl;
                flag = true;
            }
            cur = cur->next;
        }
    }
    if(!flag)
        cout << "--EMPTY--" << endl;
}


void CompleteReg::removePlayer( const string tName, const string pName ){
    Node* ptr = findTeam(tName);
    if(!ptr){
        cout << "Team does not exist!" <<endl;
    }
    else{
        ptr->t.removePlayer(pName);
    }
}


