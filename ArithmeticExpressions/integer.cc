#include "integer.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string>

Integer::Integer(int x): val(x) {}

Integer::~Integer() {}

string Integer::prettyprint() {
	stringstream ss;
	ss << val;
	return ss.str();
}

Exp* Integer::copy() {
	Integer *newint = new Integer(val);
	return newint;
}

int Integer::evaluate() {
	return val;
}
