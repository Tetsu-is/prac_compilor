#include "ast.h"
#include <iostream>

Statement *make_if()
{
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

Statement *make_while()
{
  // // int i;
  // Exp_variable *i = new Exp_variable("i");
  // // int n;
  // Exp_variable *n = new Exp_variable("n");
  // // int s;
  // // Exp_variable *s = new Exp_variable("s");

  // // cond: i <= n
  // Expression *cond = new Exp_operation2(Operator_LE, i, n);

  // list<Statement *> stmts;
  // Statement *stmt1 = make_if();

  // // i = i + 1;
  // Exp_operation2 *asgn = new Exp_operation2(Operator_PLUS, i, i);
  // Statement *stmt2 = new St_assign(i, asgn);
  // stmts.push_back(stmt1);
  // stmts.push_back(stmt2);

  // Statement *body = new St_list(stmts);
  // return new St_while(cond, body);
  Expression *ii = new Exp_variable("i");
  Expression *n = new Exp_variable("n");
  Expression *cond = new Exp_operation2(Operator_LE, ii, n);

  Statement *ifst = make_if();

  // i = i + 1;
  Exp_variable *i = new Exp_variable("i");
  Exp_constant *c = new Exp_constant(Type_INT, 1);
  // i + 1
  Exp_operation2 *rhs = new Exp_operation2(Operator_PLUS, i, c);
  St_assign *asgn = new St_assign(i, rhs);

  list<Statement *> stmts;
  stmts.push_back(ifst);
  stmts.push_back(asgn);

  Statement *body = new St_list(stmts);
  return new St_while(cond, body);
}

int main(void)
{
  Statement *s = make_while();

  map<string, Function *> func;
  map<string, int> gvar;
  map<string, int> lvar;
  lvar["i"] = -3;
  lvar["n"] = 3;
  lvar["s"] = 0;
  Return_t rd = s->run(func, gvar, lvar);
  cout << "i = " << lvar["i"] << endl;
  cout << "n = " << lvar["n"] << endl;
  cout << "s = " << lvar["s"] << endl;
  return 0;
}
