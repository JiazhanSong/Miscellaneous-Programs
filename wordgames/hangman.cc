#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <iomanip>
#include <string>
using namespace std;



int main(int argc, char *argv[]) {
	if (argc != 2) {// checking if sufficient arguments are provided
		cerr << "usage: wordguess <filename>" << endl;
		return 0;
	}

	char* filename = argv[1];
	string secret;
	string guess;
	string hint;
	ifstream file(filename);

	if (file.fail()) { // checks if reading in the secret word from file was successful
		cerr << argv[1] << " cannot be opened" << endl;
		return 0;
	}

	file >> secret;
	int length = secret.length();

	// intro message	
	cout << endl << "-----------------------------------------------" << endl;
	cout << "Welcome to hangman. Guess the secret word!" << endl;
	cout << "Your word is " << secret.length() << " letters long." << endl;
	
	file >> ws; // extract leading whitespace until hint in secret file

	// prints any hints provided in secret word file
	if (getline(file, hint)) {
		cout << endl << "Hint: " << endl;
		cout << hint << endl;	
	}
	while (getline(file, hint)) {
		cout << hint << endl;
	}
	cout << endl << "Guess:" << endl;

	int attempts = 0;
	while (cin >> guess) { // loops through input
		if (length != guess.length()) {
			cout << endl << "invalid word length" << endl << endl;
		}
		else {
			attempts++;
			if (secret == guess) {
				cout << endl << "You guessed correctly in " << attempts << " attempt(s)!" << endl;
				return 0;
			}

			int matches = 0;
			cout << endl;
			for (int i = 0; i < length; i++) {
				if (secret[i] == guess[i]) {
					cout << secret[i];
					matches++;
				}
				else {
					cout << "_";
				}
			}
			cout << endl << matches << " letters match" << endl << endl;
		}
		cout << "Guess:" << endl;
	}
}
