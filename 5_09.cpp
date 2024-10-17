#include "ast.h"
#include <iostream>

Statement *make_if() {
  Exp_variable *s = new Exp_variable("s");
  Exp_variable *i = new Exp_variable("i");

  // cond 部の木の生成
  Operator op = Operator_LT;
  Exp_variable *ex1 = i;
  Exp_constant *ex2 = new Exp_constant(Type_INT, 0);
  Expression *cond = new Exp_operation2(op, ex1, ex2);

  // then 部の木の生成
  Exp_variable *lhs1 = s;
  Exp_operation2 *rhs1 = new Exp_operation2(Operator_MINUS, s, i);
  Statement *then = new St_assign(lhs1, rhs1);

  // else 部の木の生成
  Exp_variable *lhs2 = s;
  Exp_operation2 *rhs2 = new Exp_operation2(Operator_PLUS, s, i);
  Statement *els = new St_assign(lhs2, rhs2);

  return new St_if(cond, then, els);
}

Statement *make_while() {
  Exp_variable *i = new Exp_variable("i");
  Exp_variable *n = new Exp_variable("n");
  Exp_variable *s = new Exp_variable("s");

  Expression *cond = new Exp_operation2(Operator_LE, i, n);

  list<Statement *> stmts;
  Statement *stmt1 = make_if();
  Exp_operation2 *asgn = new Exp_operation2(Operator_PLUS, s, i);
  Statement *stmt2 = new St_assign(s, asgn);
  stmts.push_back(stmt1);
  stmts.push_back(stmt2);

  Statement *body = new St_list(stmts);
  return new St_while(cond, body);
}

int main(void) {
  Statement *maked_if = make_if();
  Statement *s = make_while();
  s->print(std::cout, 0);
  return 0;
}
