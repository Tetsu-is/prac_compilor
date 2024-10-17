#include "ast.h"
#include <iostream>

int main(void) {
  Exp_variable *var = new Exp_variable("s");
  Statement *s = new St_return(var);
  s->print(std::cout, 0);
  return 0;
}
