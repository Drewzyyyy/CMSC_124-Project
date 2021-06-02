#pragma once
#include <string>
#include <unordered_map>

using namespace std;

/*
	Header file for variable storage methods
	
	Information: Unordered Map or Hash Table was used to store variables.
	Key and Value are both string, the value is only converted to int or string during calculations

	Methods		 - Description
	doesVarExist - Checks if the variable name exists in the hash table
	BEG			 - Performs BEG command (get variable name and store a value)
	PRINT		 - Performs PRINT command (get variable name or literal, then display the value)
	ASSIGN		 - Performs assignment (assign value to variable, check if variable names exist in the hash table, and solve if expression)
*/

class Storage
{
	unordered_map<string, string> variables;

	private:
		bool doesVarExist(string command);

	public:
		void BEG(string command);
		void PRINT(string command);
		void ASSIGN(string command);
};

