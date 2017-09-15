#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

int strtoint(string str) {
	stringstream ss(str);
	int num;
	ss >> num;
	return num;
}

int main(int argc, char *argv[]) {
	int total = strtoint(argv[argc - 1]);

	int arr[10];
	for (int i = 0; i < argc - 2; i++) {
		arr[i] = strtoint(argv[i + 1]);
	}

	bool possible = false;
	int indexnum;
	int indexnum2;
	int smallest;

	if (argc < 3) { // checking if sufficient arguments are provided
		cout << "Usage: change [denominations] [amount]" << endl;
		return 0;
	}

	for (int i = 0; i < argc - 3; ++i) { // sorting the array holding the denominations in ascending order
		smallest = i;
		for (int k = i + 1; k < argc - 2; ++k) {
			indexnum = arr[k];
			indexnum2 = arr[smallest];

			if (indexnum < indexnum2) {
				smallest = k;
			}
		}
		int hold = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = hold;
	}

	int change = total; // checking if it is possible
	for (int i = argc -3; i >= 0; --i) { // subtract possible change from total in descending order
		indexnum = arr[i];
		change = change % indexnum;
		if (change == 0) {
			possible = true;
			break;
		}
	}

	if (possible == true) { // printing result
		for (int i = argc - 3; i >= 0; --i) {
			indexnum = arr[i];
			int howMany = total / indexnum;
			total -= howMany * indexnum;
			if (howMany >= 1) {
				cout << howMany << " x " << indexnum << endl;
			}
		}
	}
	else {
		cout << "Impossible" << endl;
	}
}

