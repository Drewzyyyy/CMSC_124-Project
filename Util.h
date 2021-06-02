#pragma once
#include <string>

using namespace std;

/*
	Header file for function prototypes of utility functions
*/

int analyze_command(string command);	// Check and returns the command type
bool check_syntax(string command, int type);	// Check the syntax of the command type
bool isOperator(char c);	// Check if character is a mathematical operator (excluding '=')
bool isVar(string c);	// Check if string is in a variable name syntax
bool isDigit(string c);	// Check if string is in digit syntax

