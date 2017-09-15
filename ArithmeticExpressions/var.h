#ifndef _VAR_H
#define _VAR_H
#include "expression.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string>

class Var : public Exp { // derived class
	string name;
	int val;
	bool ifset;
public:
	Var(string x);
	~Var();
	void set(string varname, int input);
	void unset(string varname);
	int evaluate();
	string prettyprint();
	Exp* copy();
};

#endif
