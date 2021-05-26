#include <iostream>
#include <string>
#include <regex>
#include <unordered_map>
#include "Util.h"

using namespace std;

int main() {
	Menu(0);
	regex assignment("[A-Za-z][A-Za-z0-9]* *= *[0-9]+(\\.[0-9]+)? *((\\+|\\-|\\*|/|%) *([0-9]+)(\\.[0-9]+)?)*");
	regex calc("(([A-Za-z][A-Za-z0-9]*)|[0-9]+(\\.[0-9]+)?)( ?(\\+|\\-|\\*|\\/|%) *(([A-Za-z][A-Za-z0-9]*)|[0-9]+(\\.[0-9]+)?))+");
	regex beg("^(BEG) [A-Za-z][A-Za-z0-9]*");
	regex disp("^(PRINT) (([A-Za-z][A-Za-z0-9]*)|[0-9]*)");
	string cmd,var,target;
	unordered_map<string, int> vars;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (1) {
		cout << "\nCommand: ";
		getline(cin,cmd);
		if (regex_match(cmd,beg)) {
			cout << "BEG"<<endl;
		}
		else if (regex_match(cmd, disp)) {
			cout << "DISP" << endl;
		}
		else if (regex_match(cmd, assignment)) {
			cout << "ASSIGN" << endl;
		}
		else if (regex_match(cmd, calc)) {
			cout << "CALCULATION" << endl;
		}
		else {
			cout << "SNOL> Unknown command! Does not match any valid command of the language." << endl;
		}
	}
	return 0;
}