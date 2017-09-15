#ifndef _EXPRESSION_H
#define _EXPRESSION_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string>

using namespace std;

class Exp {
 public:
    virtual string prettyprint();
    virtual void set(string varname, int input);
    virtual void unset(string varname);
    virtual int evaluate();
    virtual Exp* copy();
    virtual ~Exp();
};

#endif
