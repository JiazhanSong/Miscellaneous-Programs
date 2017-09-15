#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string>
#include "expression.h"
#include "integer.h"
#include "binary.h"
#include "unary.h"
#include "var.h"


// You will need to make changes to this file
int main () {
	string s;
	vector<Exp*> stack;

	// Read and construct expression object
	while (cin >> s) {
		istringstream ss(s);
		int n;
		if (ss >> n) {
			stack.push_back(new Integer(n));
		}
		else if (s == "NEG" || s == "ABS") {
			Exp *operand1 = stack.back();
                        stack.pop_back();
			stack.push_back(new Unary(s,operand1));
		}
		else if (s == "+" || s == "-" || s == "*" || s == "/") {
			Exp *operand2 = stack.back();
			stack.pop_back();
 
			Exp *operand1 = stack.back();
			stack.pop_back();
 
			stack.push_back(new Binary(s, operand1, operand2));

		}
		else if (s == "done") {
			string s = stack.back()->prettyprint();  
			cout << s << endl;
			break;
		}
		else {
			Var *expression = new Var(s);
			stack.push_back(expression);
		}
	}	

	// Command interpreter
	while (cin >> s) {
		if (s == "eval") {
			try {
				cout << stack.back()->evaluate() << endl;
			}
			catch(string varname) {
				cout << varname << " has no value." << endl;
			}
		}
		else if (s == "set") {
			string name;
			cin >> name;
			int value;
			cin >> value;
			stack.back()->set(name, value);
		}
		else if (s == "unset") {
			string name;
			cin >> name;
			stack.back()->unset(name);
		}
		else if (s == "print") {
			cout << stack.back()->prettyprint() << endl;
		}
		else if (s == "copy") {
			Exp *theCopy = stack.back()->copy();
			cout << theCopy->prettyprint() << endl;
			theCopy->set("x", 1);
			cout << theCopy->prettyprint() << endl;
			try {
				cout << theCopy->evaluate() << endl;
			}
			catch(string varname) {
                                cout << varname << " has no value." << endl;
                        }
			delete theCopy;
		}
	}
	delete stack.back();	
}
