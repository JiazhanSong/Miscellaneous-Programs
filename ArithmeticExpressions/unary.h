#ifndef _UNARY_H
#define _UNDARY_H
#include "expression.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string>

class Unary : public Exp { // derived class
	string command;
	Exp *next;
public:
	Unary(string x, Exp *exp);
	~Unary();
	int evaluate();
	string prettyprint();
	void set(string varname, int input);
	void unset(string varname);
        Exp* copy();
};

#endif
