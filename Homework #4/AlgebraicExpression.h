// *************************************
// Header file AlgebraicExpression.h
// Global functions prototypes are here
// *************************************

#include <string>
#include <iostream>

using namespace std;

// It converts an infix expression exp to its equivalent prefix form.
string infix2prefix( const string exp );

// It evaluates a prefix expression.
double evaluatePrefix( const string exp );

string reverseString (const string str);
bool compare(char first, char second);
bool isOperator(char a);
bool isParenthesis(char a);
double translate(const char character);
