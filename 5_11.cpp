#include "ast.h"
#include <iostream>

int main(void) {
  string name = "putint";
  list<Expression *> args;
  Exp_variable *arg = new Exp_variable("a");
  args.push_back(arg);
  St_function *f = new St_function(name, args);
  f->print(std::cout, 0);
  return 0;
}
