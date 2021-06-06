#pragma once
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int precedence(char value);
string infixToPostfix(stack <char> stack, string infix);

