#include "var.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string>

Var::Var(string x): name(x), val(0), ifset(false) {}

Var::~Var() {}

string Var::prettyprint() {
        if (ifset) {
		return to_string(val);
	}
	return name;
}

void Var::set(string varname, int input) {
	if (varname == name) {
		val = input;
		ifset = true;
	}
}

void Var::unset(string varname) {
	ifset = false;
}

Exp* Var::copy() {
	Var *newvar = new Var(name);
	if (ifset) {
		newvar->set(name, val);
	}
	return newvar;
}

int Var::evaluate() {
	if (ifset) {
		return val;
	}
	else {
		throw name;
	}
}
