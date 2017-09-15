#include "binary.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string>

Binary::Binary(string x, Exp *l, Exp *r) : oper(x), leftexp(l), rightexp(r) {}

Binary::~Binary() {
	delete leftexp;
	delete rightexp;
}

int Binary::evaluate() {
	if (oper == "+") {
		return leftexp->evaluate() + rightexp->evaluate();
	}
	else if (oper == "-") {
		return leftexp->evaluate() - rightexp->evaluate();
	}
	else if (oper == "*") {
		return leftexp->evaluate() * rightexp->evaluate();
	}
	else {
		return leftexp->evaluate() / rightexp->evaluate();
	}
}
    
string Binary::prettyprint() {
	stringstream ss;
	ss << oper;
	return "(" + leftexp->prettyprint() + " " + ss.str() + " " + rightexp->prettyprint() + ")";
}
   
void Binary::set(string varname, int input) {
	leftexp->set(varname, input);
	rightexp->set(varname, input);
}

void Binary::unset(string varname) {
	leftexp->unset(varname);
	rightexp->unset(varname);
}

Exp* Binary::copy() {
	Binary *newbin = new Binary(oper, leftexp->copy(), rightexp->copy());
	return newbin;
}
