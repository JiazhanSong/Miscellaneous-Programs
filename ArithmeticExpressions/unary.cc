#include "unary.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string>

Unary::Unary(string x, Exp *exp) : command(x), next(exp) {}

Unary::~Unary() {
	delete next;
}

int Unary::evaluate() {
	if (command == "NEG") {
		return -(next->evaluate());
	}
	else {
		int val = next->evaluate();
		if (val < 0) {
			return -val;
		}
		return val;
	}    	
}

string Unary::prettyprint() {
	if (command == "ABS") {
		return "|" + next->prettyprint() + "|";
	}
	else {
		return "-" + next->prettyprint();
	}
}

void Unary::set(string varname, int input) {
	next->set(varname, input);
}

void Unary::unset(string varname) {
	next->unset(varname);
}

Exp* Unary::copy() {
	Unary *newun = new Unary(command, next->copy());
	return newun;
}

