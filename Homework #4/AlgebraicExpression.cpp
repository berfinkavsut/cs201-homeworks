// *************************************
// Source file AlgebraicExpression.cpp
// Global functions are defined here
// *************************************

#include "AlgebraicExpression.h"
#include "Stack.h"

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

// It converts an infix expression exp to its equivalent prefix form.
// Pre-condition: string exp is a valid infix expression
string infix2prefix( const string exp ){

    //reverse expression
    string reverseExp = reverseString(exp);

    //convert string to char array
    int length = reverseExp.length();
    char reverseInfix[length+1];
    copy(reverseExp.begin(), reverseExp.end(), reverseInfix);
    reverseInfix[length] = '\0';

    //Stacks to use for implementation of infix2prefix conversion
    Stack prefix;
    Stack operators;

    for (int index = 0; index < length;index++){

        char infixChar = reverseInfix[index];

        //if infixChar is not operator, directly push to prefix stack
        if(!isOperator(infixChar) && !isParenthesis(infixChar))
            prefix.push(infixChar);
        //if it is operator
        else if(isOperator(infixChar)){

            //if there is no operator inside operators stack, directly push infixChar to operators stack
            if(operators.isEmpty()){
                operators.push(infixChar);
            }
            //else, check the top item/operator of operators stack for precedence
            else{

                //get operator at top
                char stackTop;
                operators.getTop(stackTop);

                //check precedence
                bool precedence = compare(infixChar,stackTop);

                //if infixChar has no less precedence over operator at top
                if (precedence)
                    operators.push(infixChar);

                //else, when infixChar has less precedence over operator at top
                else{
                    //continue until infixChar has no less precedence over operator at top
                    while(!precedence && !operators.isEmpty()){

                        //take operator and push to prefix stack
                        char temp;
                        operators.pop(temp);
                        prefix.push(temp);

                        //check precedence again
                        char stackTop2;
                        operators.getTop(stackTop2);
                        precedence = compare(infixChar,stackTop2);
                    }

                    //finally, push infixChar after checking for precedence
                    operators.push(infixChar);
                }
            }
        }

        //if infixChar is opening or closing parenthesis
        else if(isParenthesis(infixChar)){

            //if closing parenthesis, directly push to operators stack
            if(infixChar == ')'){
                operators.push(infixChar);
            }

            //else, infixChar is opening parenthesis
            else if (infixChar == '('){

                char temp;
                operators.getTop(temp);

                //get top item from operators stack until closing parenthesis
                while( temp != ')'){
                    operators.pop(temp);
                    prefix.push(temp);
                    operators.getTop(temp);
                }

                //pop/discard closing parenthesis
                operators.pop();
            }
        }
    }

    //take the rest of operators inside operators stack
    while(!operators.isEmpty()){
        char temp;
        operators.pop(temp);
        prefix.push(temp);
    }

    //convert prefix stack containing char items into string
    string prefixString = "";
    char temp;
    for (int i = 0; i < length && !prefix.isEmpty(); i++) {
        prefix.pop(temp);
        prefixString = prefixString + temp;
    }

    return prefixString;
}

// It evaluates a prefix expression.
// Pre-conditions:
// 1 - string exp is a valid prefix expression
// 2 - string exp has single digits (digits from 1 to 9)
// 3 - string exp has only these operators : * - / +
// 4 - string exp has parentheses "(" or ")" in addition to operators and digits
// 5 - no spaces between the digits and the operators
double evaluatePrefix( const string exp ){

    double result;

    //reverse prefix for convenience
    string reversePrefix = reverseString(exp);

    //convert string to char array
    int length = exp.length();
    char prefix[length+1];
    copy(reversePrefix.begin(), reversePrefix.end(), prefix);
    prefix[length] = '\0';

    //Stack operands to be used in evaluatePrefix implementation
    Stack operands;

    for (int index = 0; index < length; index++){

        char prefixChar = prefix[index];

        //if not operand, directly push to prefix stack
        if(!isOperator(prefixChar)){

            double operand;

            //convert char element to double
            operand = translate(prefixChar);
            operands.push(operand);
        }

        else if(isOperator(prefixChar)){

            double op1;
            double op2;
            double output;

            //take last two operands on top of operands stack
            operands.pop(op1);
            operands.pop(op2);

            //decide on operation type
            switch ( prefixChar )
            {
                case '+':
                    output = op1 + op2;
                    break;
                case '-':
                    output = op1 - op2;
                    break;
                case '*':
                    output = op1 * op2;
                    break;
                case '/':
                    if(op2 == 0)
                       return -10000.0;
                    output = op1 / op2;
                    break;
                default:
                    output = 0.0;
            }
            //push result to operands back
            operands.push(output);
        }
    }

    //take last item in operands, which is our result
    operands.pop(result);

    return result;

}

//reverses input string
string reverseString (const string str){

    int length = str.length();

    if (length == 1)
        return str;
    else
        return str.substr(length-1,length) + reverseString(str.substr(0,length-1));
}

//checks whether first does not have less precedence than second
//if first has less precedence, return false
//otherwise, return true
bool compare(char first, char second){

    if(first == '+' && second == '*')
        return false;
    if(first == '+' && second == '/')
        return false;
    if(first == '-' && second == '*')
        return false;
    if(first == '-' && second == '/')
        return false;
    return true;
}

//checks if operator or not
bool isOperator(char a){
    if(a == '*' || a == '/' || a == '+' || a == '-' )
        return true;
    return false;
}

//checks if parenthesis or not
bool isParenthesis(char a){
    if(a == '(' || a == ')' )
        return true;
    return false;
}

//converts char to double
//Pre-condition: character is a digit from 1 to 9
double translate(const char character){

    double digit;

    switch ( character )
    {
        case '1':
            digit = 1.0;
            break;
        case '2':
            digit = 2.0;
            break;
        case '3':
            digit = 3.0;
            break;
        case '4':
            digit = 4.0;
            break;
        case '5':
            digit = 5.0;
            break;
        case '6':
            digit = 6.0;
            break;
        case '7':
            digit = 7.0;
            break;
        case '8':
            digit = 8.0;
            break;
        case '9':
            digit = 9.0;
            break;
        default:
            digit = -1.0;
    }

    return digit;
}

