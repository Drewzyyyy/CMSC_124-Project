//  Created by Beatrice Totanes on 18/03/2021.
// The program expands a string or compresses a string depending on the user input and what action the user wants to perform.

#include <iostream>
#include <cctype>
#include <limits>

using namespace std;

// FUNCTION PROTOTYPES
void StringExpansion();
void StringCompression();
void ProgDescription();
int error(string input, unsigned long length, int type);

// MAIN FUNCTION
int main() {
    int c = 0;
    char choice;
    
    while (c == 0) {
        //Menu
        cout << "\nWelcome to this String Expansion/Compression program! Please choose an action to perform…\n";
        cout << "\t[P] Program Description\n";
        cout << "\t[E] String Expansion\n";
        cout << "\t[C] String Compression\n";
        cout << "\t[X] Exit\n";
        cout << "\nChoice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.clear();
        
        // toupper(char) Converts the letter that the user has entered into uppercase if it is in lowercase
        switch (toupper(choice)) {
            case 'X':
                c = 1;
                break;
            case 'P':
                ProgDescription(); // Goes to the function that explains briefly what the program does
                c = 0;
                break;
            case 'E':
                StringExpansion(); // Expands a string from user input
                c = 0;
                break;
            case 'C':
                StringCompression(); // Compresses a string from user input
                c = 0;
                break;
            default:
                c = 0;
                printf("Invalid input.\n"); //Prints message if user inputs a value other than 0 to 4
        }
        
    }
    return 0;
}

// FUNCTION DEFINITIONS-----

// 1. StringExpansion() - Expands a string that the user has entered; no parameters; no return value
void StringExpansion(){
    string input;
    string expanded;
    unsigned long length;
    int i, j = 0, k;
    char choice = 'N';
    int num = 0;
    
    do {
        
        do {
            // Gets string from user
            cout << "\nEnter string: ";
            getline(cin, input);
            
            // If the error checking function returns 1, then the expression entered by the user is invalid.
            if (error(input, input.length(), 0) == 1) {
                cout << "Invalid Input. Letters and numbers ONLY.\n";
            }
            // If the expression entered is invalid, it will ask the user to input an expression again.
        } while (error(input, input.length(), 0) == 1);
        
        cout << "Expanded: " << endl;
        length = input.length(); // Gets length of string inputted by user
        
        // Expands the string inputted by user
        for (i = 0; i < length; i++) {
            if (isdigit(input[i]) != 0) { // If input[i] is a number, then it will compute iyts value.
                num = num * 10 + (int)(input[i] - '0'); // Computes the value of a number
            }else {
                if (num == 0) { // If the num == 0, it will just print input[i]
                    cout << input[i];
                    j++;
                }else{
                    for (k = 0; k < num; k++) { //  Prints input[i] "num" times
                        cout << input[i];
                    }
                }
                num = 0; // sets num == 0 again
            }
        }
        
        int c = 0;
        while (c == 0) {
            cout << "\n\nDo you want to expand another string?\n";
            cout << "[Y] Yes\n";
            cout << "[N] No\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
            
            switch (toupper(choice)) {
                case 'Y':
                    c = 1;
                    break;
                case 'N':
                    c = 1;
                    break;
                default:
                    c = 0;
                    cout << "\tInvalid entry." << endl;
            }
        }
        
        
    } while (toupper(choice) == 'Y');
}

// 2. StringCompression() - Compresses a string that the user has entered; no parameters; no return value
void StringCompression(){
    string input;
    string compress;
    unsigned long length;
    int i;
    char choice = 'N';
    int num = 0;
    
    do {
        do {
            // Gets string from user
            cout << "\nEnter string: ";
            getline(cin, input);
            // If the error checking function returns 1, then the expression entered by the user is invalid.
            if (error(input, input.length(), 1) == 1) {
                cout << "Invalid Input. Letters ONLY.\n";
            }
            // If the expression entered is invalid, it will ask the user to input an expression again.
        } while (error(input, input.length(), 1) == 1);
        
        
        cout << "\nCompressed: ";
        length = input.length(); // Gets length of string inputted by user
        //Compresses the string inputted by user
        for (i = 0; i < length; i++) {
            num++; // Adds the number of times that a certain letter appears
            if (input[i] == input[i + 1]) { // Continues if the current and next letter are the same
                continue;
            }else{
                if (num == 1) { // If the instance of the letter is 1, then it only prints the letter.
                    cout << input[i];
                    num = 0;
                    continue;
                }
                // If the instance of the letter is > 1, then it will output the number of instances followed by the letter.
                cout << num;
                cout << input[i];
                num = 0;
            }
        }
        
        int c = 0;
        while (c == 0) {
            cout << "\n\nDo you want to compress another string?\n";
            cout << "[Y] Yes\n";
            cout << "[N] No\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
            
            switch (toupper(choice)) {
                case 'Y':
                    c = 1;
                    break;
                case 'N':
                    c = 1;
                    break;
                default:
                    c = 0;
                    cout << "\tInvalid entry." << endl;
            }
        }
        
        
    } while (toupper(choice) == 'Y');
}

// 3. ProgDescription() - no parameters; prints program description; returns nothing
void ProgDescription(){
    cout << "\nName: Beatrice Totanes\n";
    cout << "Student Number: 2019-08366\n";
    cout << "Program Development Duration: March 18, 2021 - March 19, 2021\n";
    cout << "\nBrief Description of Main Menu: \n";
    cout << "\t[String Expansion] - gets string and displays the expanded form\n";
    cout << "\t[String Compression] - gets string and displays the compressed form\n\n";
    cout << "\t[Exit] - exits the program\n\n";
    cout << "I hope you enjoy the program. I really worked hard for this. 2 years na lang, may sablay na, padayon!\n";
}

// 4. error()- for error checking; gets string, unsigned long, and int for parameters; returns 1 if there's an error in the input
int error(string input, unsigned long length, int type){ // returns 1 if there is an error/invalid
    int i;
    int status = 0;
    
    //type refers to if the input that will be checked for errors is from the string expansion or compression function
    if (type == 0) { // String Expansion Checking
        for (i = 0; i < length; i++) {
            if (input[length - 1] >= '0' && input[length - 1] <= '9') { // Checks if the last character of the input is a nos.
                status = 1; // signals an error
                break;
            }
            
            if ((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
                continue;
            }else{
                status = 1;
                break;
            }
        }
    }else{ // String Compression Checking
        for (i = 0; i < length; i++) {
            // Checks if all inputs are letters only
            if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
                continue;
            }else{
                status = 1;
                break;
            }
        }
    }
    
    if (status == 0) {
        return 0;
    }else return 1;
}
