#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Player{
public:

    Player(const string pName = "", const string pPosition="");
    string getPlayerName() const;
    void setPlayerName(const string pName);
    string getPlayerPosition() const;
    void setPlayerPosition(const string pPosition);

private:

    string playerName;
    string playerPosition;

friend ostream& operator<<( ostream& out, const Player& pToDisplay );

};

#endif // PLAYER_H_INCLUDED
