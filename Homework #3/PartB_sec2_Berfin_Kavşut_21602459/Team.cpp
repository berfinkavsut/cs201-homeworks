#include "Team.h"

Team::Team(const string tname, const string tColor, const int tYear) {

    teamName = tname;
    teamColor = tColor;
    teamYear = tYear;

    head = new Node;
    playerCount = 0;
    head->next = NULL;

}

Team::Team (const Team &teamToCopy) {

    teamName = teamToCopy.teamName;
    teamColor = teamToCopy.teamColor;
    teamYear = teamToCopy.teamYear;
    playerCount = teamToCopy.playerCount;

   if (teamToCopy.head == NULL)
      head = NULL;
   else {

      head = new Node;
      head->p = teamToCopy.head->p;

      Node *ptr = head;

      for (Node *cur = teamToCopy.head->next; cur != NULL; cur = cur->next){
         ptr->next = new Node;
         ptr = ptr->next;
         ptr->p = cur->p;
      }
      ptr->next = NULL;
   }


}

Team::~Team() {

    teamName = "";
    teamColor = "";
    teamYear = 1800;

    if(head->next == NULL)
        return;

    Node* cur = head->next;
    for ( int i = 0; i < playerCount; i++ ) {
        delete cur;
        cur = cur -> next;
    }
    head->next = NULL;

    playerCount = 0;
}

void Team::operator=(const Team &right) {

   teamName = right.teamName;
   teamColor = right.teamColor;
   teamYear = right.teamYear;
   playerCount = right.playerCount;

   if (right.head == NULL)
      head = NULL;
   else {

      head = new Node;
      head->p = right.head->p;

      Node *ptr = head;

      for (Node *cur = right.head->next; cur != NULL; cur = cur->next){
         ptr->next = new Node;
         ptr = ptr->next;
         ptr->p = cur->p;
      }
      ptr->next = NULL;
   }
}

string Team::getTeamName() const {
    return teamName;
}
void Team::setTeamName(const string tName) {
    teamName = tName;
}

string Team::getTeamColor() const {
    return teamColor;
}
void Team::setTeamColor(const string tColor) {
    teamColor = tColor;
}

int Team::getTeamYear() const {
    return teamYear;
}
void Team::setTeamYear(const int tYear) {
    teamYear = tYear;
}


int Team::getTeamSize() const{
    return playerCount;
}

void Team::addPlayer (const string pName, const string pPosition){

    if (!findPlayer(pName)) {

        Node *cur = head;
        for ( int i = 0; i < playerCount; i++ ) {
            cur = cur->next;
        }

        cur->next = new Node;
        cur = cur->next;
        cur->next = NULL;
        cur->p.setPlayerName(pName);
        cur->p.setPlayerPosition(pPosition);

        playerCount++;

    }
    else
    {
        cout << "Player already exists in team!" << endl;
    }

}

void Team::removePlayer(const string pName) {

    Node* prev = head;
    Node* cur = head->next;

    for ( int i = 0; i < playerCount; i++ ) {

        if ( cur->p.getPlayerName() == pName ) {
            prev->next = cur->next;
            delete cur;
            playerCount--;
            return;
        }

        prev = cur;
        cur = cur->next;
    }

    cout << "There is no player with given player name!" << endl;
}

void Team::displayPlayers() const{

    if (head->next == NULL){
        cout << "--EMPTY--"<<endl;
    }

    Node *cur = head->next;
    for (int i = 0; i < playerCount; i++){
        cout << cur->p << endl;
        cur = cur->next;
    }

}

Team::Node* Team::findPlayer(const string playerName)const {

    if(head->next == NULL)
        return NULL;

    string pName;
    Node *cur = head->next;
    for (int i = 1; i <= playerCount; i++){
        pName = cur->p.getPlayerName();
        if( pName == playerName )
            return cur;
        cur = cur->next;
    }

    return NULL;
}


bool Team::existPlayer(const string playerName)const {

    if(head->next == NULL)
        return false;

    string pName;
    Node *cur = head->next;
    for (int i = 1; i <= playerCount; i++){
        pName = cur->p.getPlayerName();
        if( pName == playerName )
            return true;
        cur = cur->next;
    }
    return false;
}

string Team::getPosition(const string playerName)const {

    if(head->next == NULL)
        return "";

    string pName;
    Node *cur = head->next;
    for (int i = 1; i <= playerCount; i++){
        pName = cur->p.getPlayerName();
        if( pName == playerName )
            return cur->p.getPlayerPosition();
        cur = cur->next;
    }
    return "";
}


ostream& operator<<( ostream& out, const Team& tToDisplay ) {
    out << tToDisplay.teamName << ",\t"<< tToDisplay.teamColor << ",\t" << tToDisplay.teamYear;
    return out;
}


