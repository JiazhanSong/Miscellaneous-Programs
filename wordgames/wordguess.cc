#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

int validcheck(string word) { // checking if a word is valid
	if (word.length() != 5) {
		return 1;
	}
	for (int i = 0; i < 5-1; i++) {
		for (int k = i+1; k < 5; k++) {
			if (word[i] == word[k]) {
				return 1;
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {// checking if sufficient arguments are provided
		cerr << "usage: wordguess <filename>" << endl;
		return 0;
	}

	char* filename = argv[1];
	string secret;
	string guess;
	ifstream file(filename);

	if (file.fail()) { // checks if reading in the secret word from file was successful
		cerr << argv[1] << " cannot be opened" << endl;
		return 0;
	}

	file >> secret;

	if (validcheck(secret) == 1) { // checks the validity of secret word
		cerr << "the secret word is invalid" << endl;
		return 0;
	}

	while (cin >> guess) { // loops through input
		if (validcheck(guess) == 1) {
			cout << "invalid guess" << endl;
		}
		else {
			if (secret == guess) {
				cout << "you guessed correctly!" << endl;
				return 0;
			}

			int matches = 0;
			for (int i = 0; i < 5; i++) {
				for (int k = 0; k < 5; k++) {
					if (guess[i] == secret[k]) {
						matches++;
					}
				}
			}
			cout << matches << " letters match" << endl;
		}
	}
}
