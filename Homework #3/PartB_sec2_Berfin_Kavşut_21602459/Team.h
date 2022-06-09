#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include <iostream>
#include <string>

#include "Player.h"

using namespace std;

class Team {

public:

    Team(const string tname = "",const string tColor = "", const int tYear = 1800);
    ~Team ();
    Team (const Team &ttoCopy);
    void operator=(const Team &right);


    string getTeamName() const;
    void setTeamName(const string tName);
    string getTeamColor() const;
    void setTeamColor(const string tColor);
    int getTeamYear() const;
    void setTeamYear(const int tYear);

    void addPlayer(const string pName, const string pPosition);
    void removePlayer (const string pName);
    void displayPlayers() const;
    bool existPlayer(const string playerName)const;
    int getTeamSize() const;
    string getPosition(const string playerName)const;

private:

    string teamName;
    string teamColor;
    int teamYear;

    struct Node {
        Player p;
        Node* next;
    };

    Node *head;
    int playerCount;
    Node* findPlayer(const string playerName) const;


friend ostream& operator<<( ostream& out, const Team& tToDisplay );
};




#endif // TEAM_H_INCLUDED
