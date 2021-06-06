#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>
#include "Calculation.h"

using namespace std;

int precedence(char value){
    if ( value == '*' || value == '/' || value == '%'){
        return 2;
    }
    else if (value == '+' || value == '-'){
        return 1;
    }
    else return -1;
}

string infixToPostfix(stack <char> stack, string infix){
    string postfix;

    for(int i = 0; i < infix.length(); i++){ //reading the string per char
        if ((isdigit(infix[i])) || (infix[i] == '.')) {
            postfix += infix[i];
            if (infix[i + 1] == '.') continue;
            else if (!isdigit(infix[i + 1])) postfix += " ";
        }
        else if (infix[i] == ' '){
            continue;
        }
        else if (infix[i] == '('){
            stack.push(infix[i]);
        }
        else if (infix[i] == ')'){
            while ((stack.top() != '(') && (!stack.empty())){
                char temp = stack.top();
                postfix += temp;
                postfix += " ";
                stack.pop();
            }
            if(stack.top() == '('){
                stack.pop();
            }
        }
        else{ // if the current infix[i] is operator
            if (stack.empty()){
                stack.push(infix[i]);
            }
            else {
                if (precedence(infix[i]) > precedence(stack.top())){
                    stack.push(infix[i]);
                }
                else if(precedence(infix[i]) == precedence(stack.top())){
                    postfix += stack.top();
                    postfix += " ";
                    stack.pop();
                    stack.push(infix[i]);
                }
                else{
                    while ((!stack.empty()) && (precedence(infix[i]) < precedence(stack.top()))){
                        postfix += stack.top();
                        postfix += " ";
                        stack.pop();
                    }
                    stack.push(infix[i]);
                }
            }
        } 
    }
    while(!stack.empty()){
        postfix += stack.top();
        postfix += " ";
        stack.pop();
    }
    return postfix;
}

 //int evaluatePostfix(string postfixExpr){
 //    stack <int> operand;

 //    for (int i = 0; i < postfixExpr.length(); ++i){
 //    }
 //}
