#include <iostream>
#include <stdlib.h>
#include <string>
#include "Util.h"
#include "Storage.h"

using namespace std;

/*
	Program Description: This program serves as interpreter for a SNOL (Simple Number Only Language).
	It consists of three parts: Source, Utilities, and Storage
	Source: Serves as the main part of the program where the I/O part is done
	Utilities (Util.cpp) : Consists of utility functions where important parts involving syntax and grammar checking is done
	Storage (Storage.cpp) : Class file that deals with variable storage and manipulation

	Additional information:
		Command types:
			0 = Command unrecognized or invalid syntax
			1 = BEG command, for storing a value to a variable
			2 = PRINT command, for displaying the value of a variable
			3 = EXIT! command, for exiting the program
			4 = Calculation is done without storage, but syntax checking is important
			5 = Assignment is done to a variable
*/

int main() {
	string command;	// command stores the user input
	int type = 0;	// type stores the command type of the input
	Storage store;	// Object that performs variable
	cout << "The SNOL environment is now active, you may proceed with giving your commands." << endl;
	while (1) {
		cout << "\nCommand: ";
		getline(cin, command);
		type = analyze_command(command);	// Checks and returns the command type of the command
		switch (type) {
			case 0:
				/*
					analyze_command did not understand the command
					ERROR CHECKING HERE PLEASE
				*/
				break;
			case 1:
				// BEG Command
				if (check_syntax(command, type)) store.BEG(command);
				break;
			case 2:
				// PRINT Command
				if (check_syntax(command, type)) store.PRINT(command);
				break;
			case 3:
				cout << "\nInterpreter is now terminated..." << endl;
				return 0;
				break;
			case 4:
				/* 
				Already done syntax checking for this part, check if calculation will be possible
				else display error message
				if (check_syntax(command, type)) DO STUFF HERE;
				*/
				if (!check_syntax(command, type)) cout << "ERROR" << endl;
				break;
			case 5:
				// Assignment
				if (check_syntax(command, type)) store.ASSIGN(command);
				break;
		}
	}
}