#include "Storage.h"
#include "Util.h"
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

/*
	Performs variable storage, and manipulation

	Rundown:
	Line - Name			: Description
	20	 - doesVarExist : Checks if the is already assigned
	25	 - BEG			: Performs BEG command (get variable name and store a value)
	36	 - PRINT		: Performs PRINT command (get variable name or literal, then display the value)
	43	 - ASSIGN		: Performs assignment (assign value to variable, check if variable names exist in the hash table, and solve if expression)
*/

bool Storage::doesVarExist(string command) {
	if (variables.find(command) == variables.end()) return 0;	// Variable not assigned yet
	else return 1;
}

void Storage::BEG(string command) {
	string temp = command.erase(0, 4);	// Remove "BEG "
	string store;
	cout << "SNOL> Please enter value for [" << temp << "]: ";
	cin >> store;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (isDigit(store)) variables[temp] = store;
	else cout << "ERROR" << endl; // DISPLAY APPROPRIATE ERROR COMMAND
}

void Storage::PRINT(string command) {
	string temp = command.erase(0, 6);	// Remove "PRINT  "
	if (doesVarExist(temp)) cout << "SNOL> [" << temp << "] = " << variables.at(temp) << endl;
	else if(isDigit(temp)) cout << "SNOL> [" << temp << "] = " << temp << endl;
	else cout << "SNOL> Error! [" << temp << "] is not defined!" << endl;
}

void Storage::ASSIGN(string command) {
	string temp, expr, var;
	bool isFloat = false;
	// Perform expression evaluation similar to in syntax checking, break down expression part by part
	for (int i = 0; i < command.length(); i++) {
		if (isOperator(command[i])) {	// Current operator is an operator
			if (isVar(temp)) {	// Is part in variable syntax
				if(doesVarExist(temp)) expr += variables.at(temp) + command[i];	// Add variable value and operator to the string
				else {
					cout << "SNOL> Error! [" << temp << "] is not defined!" << endl;
					return;
				}
			}
			else {
				if (command[i] == '.') isFloat = true;
				expr += temp + command[i];	// Add digit and operator to the string
			}
			temp.erase();
		}
		else if (command[i] == ' ') continue;	// Ignore spaces
		else if (command[i] == '=') {
			var += temp;	// Get variable name
			temp.erase();
		}
		else temp += command[i];	// Add character to part to be assessed
	}

	// Same as above, but for the last part before end of string
	if (isVar(temp)) {
		if (doesVarExist(temp)) expr += variables.at(temp);	// Add variable value and operator to the string
		else {
			cout << "SNOL> Error! [" << temp << "] is not defined!" << endl;
			return;
		}
	}
	else expr += temp;
	temp.erase();
	command.erase();
	cout << "EXPR = " << expr << endl; // For checking only removable
	//cout << "Expression: " << expr << endl;
	/* Insert code here for solution to the expr
		Guides: Access to the expression only: expr
				Access to the variable name: var
				All spaces were removed
				Do operations
				Remember: MODULUS NEEDS TO BE ONLY FOR INT

		If possible create other methods for the INFIX->POSTFIX and Calculation
		variables[var] = value of expr; // To store the value to expr to the hash table
	*/
}
