#ifndef _INTEGER_H
#define _INTEGER_H
#include "expression.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string>

class Integer : public Exp { // derived class
	int val;
public:
	Integer(int x);
	~Integer();
	string prettyprint();
	int evaluate();
	Exp* copy();
};

#endif
