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

int main(void)
{
  Statement *s = make_if();
  map<string, Function *> func;
  map<string, int> gvar;
  map<string, int> lvar;
  // 真の場合
  lvar["i"] = -5;
  lvar["s"] = 10;
  Return_t rd1 = s->run(func, gvar, lvar);
  cout << "s = " << lvar["s"] << endl;

  // 偽の場合
  lvar["i"] = 7;
  lvar["s"] = 10;
  Return_t rd2 = s->run(func, gvar, lvar);
  cout << "s = " << lvar["s"] << endl;
  return 0;
}
