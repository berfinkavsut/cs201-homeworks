#ifndef COMPLETEREG_H_INCLUDED
#define COMPLETEREG_H_INCLUDED

#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

#include "Team.h"

class CompleteReg {
public:

    CompleteReg();
    ~CompleteReg ();
    CompleteReg ( const CompleteReg &systemToCopy );
    CompleteReg& operator=( const CompleteReg &right );
    Team& operator[]( const int index );

    void addTeam( const string tName, const string tColor, const int tyear );
    void removeTeam( string teamName );
    void displayAllTeams() const;

    void addPlayer( const string tName, const string pName, const string pPosition );
    void removePlayer( const string teamName, const string playerName );
    void displayTeam( const string teamName ) const;
    void displayPlayer( const string playerName ) const ;

    int getSize() const;

private:
    struct Node {
        Team t;
        Node* next;
    };

    Node *head;
    int teamCount;
    Node* findTeam(string teamName) const;
};

#endif // COMPLETEREG_H_INCLUDED
