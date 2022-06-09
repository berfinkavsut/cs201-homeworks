#include "SimpleReg.h"

SimpleReg::SimpleReg() {
    head = new Node;
    teamCount = 0;
    head->next = NULL;
}

SimpleReg::~SimpleReg() {

    if(head->next == NULL)
        return;

    Node* cur = head->next;
    for ( int i = 0; i < teamCount; i++ ) {
        delete cur;
        cur = cur -> next; // next item

    }
    cout << "destruct  yeah!" << endl;

    head->next = NULL;
}

void SimpleReg::addTeam ( const string tName, const string tColor, const int tYear ){

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
        cur->next = NULL;
        cur->t.setTeamName(tName);
        cur->t.setTeamColor(tColor);
        cur->t.setTeamYear(tYear);

        teamCount++;

	return;
    }
    else{
    
    	cout << "Team already exists in registration system!" << endl;
    }
}

void SimpleReg::removeTeam(const string teamName) {

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

void SimpleReg::displayAllTeams() const{

    if (head->next == NULL)
        cout << "--EMPTY--"<<endl;

    Node *cur = head->next;
    for (int i = 0; i < teamCount; i++){
        cout << "Team " << cur->t << endl;
        cur = cur->next;
    }

}

SimpleReg::Node* SimpleReg::findTeam(const string teamName) const {

    if(head->next == NULL)
        return NULL;

    string tName;
    Node *cur = head->next;
    for (int i = 1; i <= teamCount; i++){
        tName = cur->t.getTeamName();
        if( tName == teamName )
            return cur;
        cur = cur->next;
    }

    return NULL;

}

int SimpleReg::getSize() const{
    return teamCount;

}


