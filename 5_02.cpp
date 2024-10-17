#include "ast.h"
#include <iostream>

int main(void) {
  Expression *c1 = new Exp_variable("n");
  c1->print(std::cout);
  std::cout << std::endl;
  return 0;
}