//=====================================================================
//
//     ast.cpp: mini-C プログラムの抽象構文木 (実装)
//
//            コンパイラ実習  2004 (c) 平岡佑介, 石浦菜岐佐
//
//=====================================================================

#include "ast.h"

//---------------------------------------------------------------------
//   Type_string の実装
//---------------------------------------------------------------------
std::string Type_string(Type t)
{
  switch (t)
  {
  case Type_INT:
    return "int";
  case Type_CHAR:
    return "char";
  default:
    return "UNDEF";
  }
}

//---------------------------------------------------------------------
//   Opeartor_string の実装
//---------------------------------------------------------------------
std::string Operator_string(Operator o)
{
  switch (o)
  {
  case Operator_PLUS:
    return "+";
  case Operator_MINUS:
    return "-";
  case Operator_MUL:
    return "*";
  case Operator_DIV:
    return "/";
  case Operator_MOD:
    return "%";
  case Operator_LT:
    return "<";
  case Operator_GT:
    return ">";
  case Operator_LE:
    return "<=";
  case Operator_GE:
    return ">=";
  case Operator_NE:
    return "!=";
  case Operator_EQ:
    return "==";
  default:
    return "???";
  }
}

static int tmp = 0;

//---------------------------------------------------------------------
//  tab(int)
//    インデントを行うための関数 (ast.cpp の中だけで用いる)
//    indent で指定された段数の 2 倍のスペースを返す
//---------------------------------------------------------------------
static std::string tab(int indent)
{
  std::string tab_ = "";
  for (int i = 0; i < indent; i++)
  {
    tab_ += "  ";
  }
  return tab_;
}

//---------------------------------------------------------------------
//   Exp_constant::print の実装
//---------------------------------------------------------------------
void Exp_constant::print(std::ostream &os) const
{
  switch (type())
  {
  case Type_INT:
    os << value();
    break;
  case Type_CHAR:
  {
    os << '\'';
    if (value() == '\n')
    {
      os << '\\';
      os << 'n';
    }
    else if (value() == '\t')
    {
      os << '\\';
      os << 't';
    }
    else if (value() == '\\')
    {
      os << '\\';
      os << '\\';
    }
    else
    {
      os << (char)value();
    }
    os << '\'';
    break;
  }
  default:
    assert(0);
  }
}

//------------------------------------------------------------------------
//   Exp_variable::print の 実装
//------------------------------------------------------------------------
void Exp_variable::print(std::ostream &os) const { os << name_; }

//------------------------------------------------------------------------
//   Exp_variable::run の 実装
//------------------------------------------------------------------------
int Exp_variable::run(map<string, Function *> &func, map<string, int> &gvar,
                      map<string, int> &lvar) const
{
  map<string, int>::const_iterator p;
  if ((p = lvar.find(name_)) != lvar.end())
  {
    return p->second;
  }
  if ((p = gvar.find(name_)) != gvar.end())
  {
    return p->second;
  }
  else
  {
    cerr << "undefined variable: " << name_ << endl;
    exit(1);
  }
}

//------------------------------------------------------------------------
//   Exp_operation1::print の 実装
//------------------------------------------------------------------------
void Exp_operation1::print(std::ostream &os) const
{
  os << Operator_string(operation());
  if (operand())
  {
    operand()->print(os);
  }
  else
  {
    os << "UNDEF";
  }
}

//------------------------------------------------------------------------
//  Exp_operation1::run の 実装
//------------------------------------------------------------------------
int Exp_operation1::run(map<string, Function *> &func, map<string, int> &gvar,
                        map<string, int> &lvar) const
{
  int v = operand()->run(func, gvar, lvar);

  if (operand_ == NULL)
  {
    cerr << "operand is NULL" << endl;
    exit(1);
  }

  switch (operation())
  {
  case Operator_PLUS:
    return v;
  case Operator_MINUS:
    return -v;
  default:
    cerr << "unknown operator" << endl;
    exit(1);
  }
}

//------------------------------------------------------------------------
//   Exp_operation2::print の 実装
//------------------------------------------------------------------------
void Exp_operation2::print(std::ostream &os) const
{
  if (operand1())
  {
    operand1()->print(os);
  }
  else
  {
    os << "UNDEF";
  }

  os << " " + Operator_string(operation()) + " ";

  if (operand2())
  {
    operand2()->print(os);
  }
  else
  {
    os << "UNDEF";
  }
}

//------------------------------------------------------------------------
//   Exp_operation2::run の 実装
//------------------------------------------------------------------------
int Exp_operation2::run(map<string, Function *> &func, map<string, int> &gvar,
                        map<string, int> &lvar) const
{
  if (operand1_ == NULL)
  {
    cerr << "operand1 is NULL" << endl;
    exit(1);
  }

  int o1 = operand1_->run(func, gvar, lvar);

  if (operand2_ == NULL)
  {
    cerr << "operand2 is NULL" << endl;
    exit(1);
  }

  int o2 = operand2_->run(func, gvar, lvar);

  switch (operation_)
  {
  case Operator_PLUS:
    return o1 + o2;
  case Operator_MINUS:
    return o1 - o2;
  case Operator_MUL:
    return o1 * o2;
  case Operator_DIV:
    return o1 / o2;
  case Operator_MOD:
    return o1 % o2;
  case Operator_LT:
    return o1 < o2;
  case Operator_GT:
    return o1 > o2;
  case Operator_LE:
    return o1 <= o2;
  case Operator_GE:
    return o1 >= o2;
  case Operator_NE:
    return o1 != o2;
  case Operator_EQ:
    return o1 == o2;
  default:
    cerr << "unknown operator" << endl;
    exit(1);
  }
}

//------------------------------------------------------------------------
//   Exp_function::~Exp_function() の 実装
//------------------------------------------------------------------------
Exp_function::~Exp_function()
{
  for (list<Expression *>::const_iterator it = args_.begin(); it != args_.end();
       it++)
  {
    delete *it;
  }
}

//------------------------------------------------------------------------
//   Exp_function::print() の 実装
//------------------------------------------------------------------------
void Exp_function::print(ostream &os) const
{
  os << name_ << "(";
  for (list<Expression *>::const_iterator it = args_.begin(); it != args_.end();
       it++)
  {
    (*it)->print(os);
    if (it != --args_.end())
    {
      os << ", ";
    }
  }
  os << ")";
}

//------------------------------------------------------------------------
//   Exp_function::run() の 実装
//------------------------------------------------------------------------
int Exp_function::run(map<string, Function *> &func, map<string, int> &gvar,
                      map<string, int> &lvar) const
{
  // push each arg value to i_args
  list<int> i_args;
  for (list<Expression *>::const_iterator it = args_.begin(); it != args_.end();
       it++)
  {
    int val = (*it)->run(func, gvar, lvar);
    i_args.push_back(val);
  }

  map<string, Function *>::const_iterator p;

  if (name_ == "getint")
  {
    int i;
    cin >> i;
    return i;
  }
  else if (name_ == "getchar")
  {
    char c;
    cin >> c;
    return c;
  }
  else if (name_ == "putint")
  {
    int i = i_args.front();
    cout << i;
    return 0;
  }
  else if (name_ == "putchar")
  {
    char c = i_args.front();
    cout << c;
    return 0;
  }
  else
  {
    if ((p = func.find(name_)) != func.end())
    {
      Function *f = p->second;
      return f->run(func, gvar, i_args);
    }
    else
    {
      cerr << "undefined function: " << name_ << endl;
      exit(1);
    }
  }
}

//------------------------------------------------------------------------
//   St_assign::print() の 実装
//------------------------------------------------------------------------
void St_assign::print(ostream &os, int indent) const
{
  os << tab(indent);
  if (lhs())
  {
    lhs()->print(os);
  }
  else
  {
    os << "UNDEF";
  }
  os << " = ";

  if (rhs())
  {
    rhs()->print(os);
  }
  else
  {
    os << "UNDEF";
  }
  os << ";" << endl;
}

//------------------------------------------------------------------------
//   St_assign::run() の 実装
//------------------------------------------------------------------------
Return_t St_assign::run(map<string, Function *> &func, map<string, int> &gvar,
                        map<string, int> &lvar) const
{
  assert(lhs());
  assert(rhs());
  int i_rhs = rhs()->run(func, gvar, lvar);

  map<string, int>::iterator p;
  if ((p = lvar.find(lhs()->name())) != lvar.end())
  {
    p->second = i_rhs;
  }
  else if ((p = gvar.find(lhs()->name())) != gvar.end())
  {
    p->second = i_rhs;
  }
  else
  {
    cerr << "undefined variable: " << lhs()->name() << endl;
    exit(1);
  }

  return Return_t(false, 0);
}

//------------------------------------------------------------------------
//   St_list::print() の 実装
//------------------------------------------------------------------------
void St_list::print(ostream &os, int indent) const
{
  for (list<Statement *>::const_iterator it = statements_.begin();
       it != statements_.end(); it++)
  {
    (*it)->print(os, indent);
  }
}

//------------------------------------------------------------------------
//   St_list::run() の 実装
//------------------------------------------------------------------------
Return_t St_list::run(map<string, Function *> &func, map<string, int> &gvar,
                      map<string, int> &lvar) const
{
  for (list<Statement *>::const_iterator it = statements_.begin(); it != statements_.end(); it++)
  {
    assert(*it);
    Return_t rd = (*it)->run(func, gvar, lvar);
    if (rd.val_is_returned)
      return rd;
  }
  return Return_t(false, 0);
}

//------------------------------------------------------------------------
//   St_if::print() の 実装
//------------------------------------------------------------------------
void St_if::print(ostream &os, int indent) const
{
  os << tab(indent) << "if (";
  if (condition())
  {
    condition()->print(os);
  }
  else
  {
    os << "UNDEF";
  }
  os << ") {" << endl;
  if (then_part())
  {
    then_part()->print(os, indent + 1);
  }
  else
  {
    os << "UNDEF";
  }
  os << tab(indent) << "}" << endl;
  if (else_part())
  {
    os << tab(indent) << "else {" << endl;
    else_part()->print(os, indent + 1);
    os << tab(indent) << "}" << endl;
  }
}

//------------------------------------------------------------------------
//   St_if::run() の 実装
//------------------------------------------------------------------------
Return_t St_if::run(map<string, Function *> &func, map<string, int> &gvar,
                    map<string, int> &lvar) const
{
  assert(condition() != NULL);

  int is_condition_true = condition()->run(func, gvar, lvar);

  if (is_condition_true != 0)
  {
    if (then_part() == NULL)
    {
      return Return_t(false, 0);
    }
    return then_part()->run(func, gvar, lvar);
  }
  else
  {
    if (else_part() == NULL)
    {
      return Return_t(false, 0);
    }
    return else_part()->run(func, gvar, lvar);
  }
  return Return_t(false, 0);
}

//------------------------------------------------------------------------
//   St_while::print() の 実装
//------------------------------------------------------------------------
void St_while::print(ostream &os, int indent) const
{
  os << tab(indent) << "while (";
  if (condition())
  {
    condition()->print(os);
  }
  else
  {
    os << "UNDEF";
  }
  os << ") {" << endl;
  if (body())
  {
    body()->print(os, indent + 1);
  }
  else
  {
    os << "UNDEF";
  }
  os << tab(indent) << "}" << endl;
}

//------------------------------------------------------------------------
//   St_while::run() の 実装
//------------------------------------------------------------------------
Return_t St_while::run(map<string, Function *> &func, map<string, int> &gvar,
                       map<string, int> &lvar) const
{

  assert(condition() != NULL);

  while (condition()->run(func, gvar, lvar) != 0)
  {
    if (body() == NULL)
    {
      return Return_t(false, 0);
    }
    Return_t rd = body()->run(func, gvar, lvar);
    if (rd.val_is_returned)
      return rd;
  }
  return Return_t(false, 0);
}

//------------------------------------------------------------------------
//   St_return::print() の 実装
//------------------------------------------------------------------------
void St_return::print(ostream &os, int indent) const
{
  os << tab(indent) << "return ";
  if (value())
  {
    value()->print(os);
  }
  else
  {
    os << "UNDEF";
  }
  os << ";" << endl;
}

//------------------------------------------------------------------------
//   St_return::run() の 実装
//------------------------------------------------------------------------
Return_t St_return::run(map<string, Function *> &func, map<string, int> &gvar,
                        map<string, int> &lvar) const
{
  assert(value());
  int rv = value()->run(func, gvar, lvar);
  return Return_t(true, rv);
}

//------------------------------------------------------------------------
//   St_function::print() の 実装
//------------------------------------------------------------------------
void St_function::print(ostream &os, int indent) const
{
  os << tab(indent);
  function_.print(os);
  os << ";" << endl;
}

//------------------------------------------------------------------------
//   St_function::run() の 実装
//------------------------------------------------------------------------
Return_t St_function::run(map<string, Function *> &func, map<string, int> &gvar,
                          map<string, int> &lvar) const
{
  function_.run(func, gvar, lvar);
  return Return_t(false, 0);
}

//------------------------------------------------------------------------
//   Variable::print() の 実装
//------------------------------------------------------------------------
void Variable::print(ostream &os) const
{
  os << Type_string(type_) << " " << name_;
}

//------------------------------------------------------------------------
//   Function::print() の 実装
//------------------------------------------------------------------------
void Function::print(ostream &os) const
{
  os << Type_string(type_) << " " << name_ << "(";
  for (list<Variable *>::const_iterator it = args_.begin(); it != args_.end();
       it++)
  {
    (*it)->print(os);
    if (next(it) != args_.end())
    {
      os << ", ";
    }
  }
  os << ")" << endl;

  os << "{" << endl;

  // print local variables
  for (list<Variable *>::const_iterator it = lvarlist_.begin();
       it != lvarlist_.end(); it++)
  {
    os << tab(1);
    (*it)->print(os);
    os << ";" << endl;
  }

  // os << endl;

  // print body
  body_->print(os, 1);

  os << "}" << endl;
}

//------------------------------------------------------------------------
//   Function::runの実装
//------------------------------------------------------------------------
int Function::run(map<string, Function *> &func, map<string, int> &gvar,
                  list<int> &i_args) const
{
  // 引数の名前と値をローカル変数表に登録する
  map<string, int> lvar;

  auto i = args().begin();
  auto j = i_args.begin();
  
  for (;i != args().end() && j != i_args.end(); ++i, ++j)
  {
    lvar[(*i)->name()] = *j;
  }

  // ローカル変数をローカル変数表に登録
  for (list<Variable *>::const_iterator it = lvarlist().begin(); it != lvarlist().end(); it++)
  {
    lvar[(*it)->name()] = 0;
  }

  Return_t rd = body()->run(func, gvar, lvar);

  return rd.return_val;
}

//------------------------------------------------------------------------
//  Program::print() の 実装
//------------------------------------------------------------------------
void Program::print(ostream &os) const
{
  // print global variables
  for (list<Variable *>::const_iterator it = varlist_.begin();
       it != varlist_.end(); it++)
  {
    (*it)->print(os);
    os << ";" << endl;
  }

  os << endl;
  os << endl;

  // print functions
  for (list<Function *>::const_iterator it = funclist_.begin();
       it != funclist_.end(); it++)
  {
    (*it)->print(os);
  }

  os << endl;

  // print main function
  main_->print(os);
}

//------------------------------------------------------------------------
//  Program::run() の 実装
//------------------------------------------------------------------------
int Program::run(map<string, Function *> &func, map<string, int> &gvar, list<int> &i_args) const
{
  list<Variable *> gvar;

  for(auto i = varlist()->begin(); i != varlist()->end(); i++)
  {
    gvar[(*i)->name()] =  
  }
}