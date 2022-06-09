// *************************************
// Driver file for AlgebraicExpression.h
// Global functions of AlgebraicExpression.h are tested here
// *************************************


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#include "AlgebraicExpression.h"

int main() {

    string infix;
    string prefix;
    string expectedPrefix;
    double infixAnswer;
    double prefixAnswer;

    //Check if infix2prefix function works or not
    cout << "----------------infix2prefix----------------" << endl;
    cout << "\n";

    infix = "K+L-M*N+(O+P)*W/U/V*T+Q";
    expectedPrefix = "++-+KL*MN*//*+OPWUVTQ";
    prefix = infix2prefix(infix);
    cout << "infix : " << infix << endl;
    cout << "expected prefix : " << expectedPrefix << endl;
    cout << "computed prefix : " << prefix << endl;
    cout << "\n";

    infix = "(A+B)*(C+D)/E";
    expectedPrefix = "/*+AB+CDE";
    prefix =  infix2prefix(infix);
    cout << "infix : " << infix << endl;
    cout << "expected prefix : " << expectedPrefix << endl;
    cout << "computed prefix : " << prefix << endl;
    cout << "\n";

    infix = "(((A+B)*C)-((D-E)*(F+G)))";
    expectedPrefix = "-*+ABC*-DE+FG";
    prefix = infix2prefix(infix);
    cout << "infix : " << infix << endl;
    cout << "expected prefix : " << expectedPrefix << endl;
    cout << "computed prefix : " << prefix << endl;
    cout << "\n";

    infix = "1-5/(6-1*4)";
    expectedPrefix = "-1/5-6*14";
    prefix = infix2prefix(infix);
    cout << "infix : " << infix << endl;
    cout << "expected prefix : " << expectedPrefix << endl;
    cout << "computed prefix : " << prefix << endl;
    cout << "\n";

    //Check if evaluatePrefix function works or not
    //infix answers are computed by calculator
    cout << "----------------evaluatePrefix----------------" << endl;
    cout << "\n";

    infix = "1+2-3*4+(5+6)*1/2/3*6+7";
    prefix = infix2prefix(infix);
    infixAnswer = 9;
    prefixAnswer = evaluatePrefix(infix2prefix(infix));
    cout << "infix  : " << infix << endl;
    cout << "prefix : " << prefix << endl;
    cout << "infix answer  : " << infixAnswer << endl;
    cout << "prefix answer : " << prefixAnswer << endl;
    cout << "\n";

    infix = "(8+9)*(1-1)/4";
    prefix = infix2prefix(infix);
    infixAnswer = 0;
    prefixAnswer = evaluatePrefix(infix2prefix(infix));
    cout << "infix  : " << infix << endl;
    cout << "prefix : " << prefix << endl;
    cout << "infix answer  : " << infixAnswer << endl;
    cout << "prefix answer : " << prefixAnswer << endl;
    cout << "\n";

    infix = "(((2+3)*4)-((1-5)*(3+4)))";
    prefix = infix2prefix(infix);
    infixAnswer = 48;
    prefixAnswer = evaluatePrefix(infix2prefix(infix));
    cout << "infix  : " << infix << endl;
    cout << "prefix : " << prefix << endl;
    cout << "infix answer  : " << infixAnswer << endl;
    cout << "prefix answer : " << prefixAnswer << endl;
    cout << "\n";

    infix = "1-5/(6-1*4)";
    prefix = infix2prefix(infix);
    infixAnswer = -1.5;
    prefixAnswer = evaluatePrefix(infix2prefix(infix));
    cout << "infix  : " << infix << endl;
    cout << "prefix : " << prefix << endl;
    cout << "infix answer  : " << infixAnswer << endl;
    cout << "prefix answer : " << prefixAnswer << endl;
    cout << "\n";

    infix = "1-5/(6-6*1)";
    prefix = infix2prefix(infix);
    prefixAnswer = evaluatePrefix(infix2prefix(infix));
    cout << "Check for the case of ( number / 0 )!" << endl;
    cout << "When ( number / 0 ) occurs, evaluatePrefix returns -10000 as an indicator!" << endl;
    cout << "infix  : " << infix  << endl;
    cout << "prefix : " << prefix << endl;
    cout << "infix answer  : not defined!" << endl;
    cout << "prefix answer : " << prefixAnswer << endl;
    cout << "\n";

    return 0;
}
