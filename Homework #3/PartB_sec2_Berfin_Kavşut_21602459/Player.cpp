
#include "Player.h"

Player::Player(const string pName, const string pPosition){
    playerName = pName;
    playerPosition = pPosition;
}

string Player::getPlayerName() const{
    return playerName;
}
void Player::setPlayerName(const string pName){
    playerName = pName;
}
string Player::getPlayerPosition() const{
    return playerPosition;
}
void Player::setPlayerPosition(const string pPosition){
    playerPosition = pPosition;
}

ostream& operator<<( ostream& out, const Player& pToDisplay ) {
    out << pToDisplay.playerName << ",\t"<< pToDisplay.playerPosition;
    return out;
}
