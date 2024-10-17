#include "ast.h"
#include <iostream>
#include <string>

int main(void) {
  string n = "a";
  Variable *f = new Variable(Type_INT, n);
  f->print(std::cout);
  return 0;
}