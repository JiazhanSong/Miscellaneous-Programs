#ifndef _BINARY_H
#define _BINARY_H
#include "expression.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string>

class Binary : public Exp { // derived class
	string oper;
	Exp *leftexp;
	Exp *rightexp;
public:
	Binary(string x, Exp *l, Exp *r);
	~Binary();
	int evaluate();
	string prettyprint();
	void set(string varname, int input);
	void unset(string varname);        
	Exp* copy();
};

#endif
