#ifndef SIMPLETEAM_H_INCLUDED
#define SIMPLETEAM_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class SimpleTeam {

public:

    SimpleTeam(const string tname = "",const string tColor = "", const int tYear = 1800);
    ~SimpleTeam ();
    SimpleTeam (const SimpleTeam &ttoCopy);
    void operator=(const SimpleTeam &right);

    string getTeamName() const;
    void setTeamName(const string tName);
    string getTeamColor() const;
    void setTeamColor(const string tColor);
    int getTeamYear() const;
    void setTeamYear(const int tYear);

private:

    string teamName;
    string teamColor;
    int teamYear;

friend ostream& operator<<( ostream& out, const SimpleTeam& tToDisplay );
};

#endif // SIMPLETEAM_H_INCLUDED
