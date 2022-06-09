#include "SimpleTeam.h"

SimpleTeam::SimpleTeam(const string tname, const string tColor, const int tYear) {
    teamName = tname;
    teamColor = tColor;
    teamYear = tYear;
}

SimpleTeam::SimpleTeam (const SimpleTeam &teamToCopy) {
    teamName = teamToCopy.teamName;
}

SimpleTeam::~SimpleTeam() {
}

void SimpleTeam::operator=(const SimpleTeam &right) {
    teamName = right.teamName;
}

string SimpleTeam::getTeamName() const {
    return teamName;
}
void SimpleTeam::setTeamName(const string tName) {
    teamName = tName;
}

string SimpleTeam::getTeamColor() const {
    return teamColor;
}
void SimpleTeam::setTeamColor(const string tColor) {
    teamColor = tColor;
}

int SimpleTeam::getTeamYear() const {
    return teamYear;
}
void SimpleTeam::setTeamYear(const int tYear) {
    teamYear = tYear;
}

ostream& operator<<( ostream& out, const SimpleTeam& tToDisplay ) {
    out << tToDisplay.teamName << ",\t"<< tToDisplay.teamColor << ",\t" << tToDisplay.teamYear;
    return out;
}


