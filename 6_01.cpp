#include "ast.h"
#include <iostream>

int main(void) {
  Expression *c1 = new Exp_constant(Type_INT, 7);
  Expression *c2 = new Exp_constant(Type_CHAR, 'x');
  std::map<std::string, Function *> func;
  std::map<std::string, int> gvar;
  std::map<std::string, int> lvar;
  std::cout << c1->run(func, gvar, lvar) << std::endl;
  return 0;
}
