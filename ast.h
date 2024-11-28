//=====================================================================
//
//     ast.h: mini-C プログラムの抽象構文木 (ヘッダ)
//
//            コンパイラ実習  2004 (c) 平岡佑介, 石浦菜岐佐
//
//=====================================================================

#ifndef INCLUDE_AST_H_
#define INCLUDE_AST_H_

#include <assert.h>
#include <iostream>
#include <list>
#include <map>
#include <string>

class Function;
class Variable;

struct Return_t
{
  bool val_is_returned; // return文が実行されたか
  int return_val;       // return文の返り値
  Return_t() : val_is_returned(false), return_val(0) {}
  Return_t(bool r, int v) : val_is_returned(r), return_val(v) {}
};

struct Declaration_t
{
  std::list<Variable *> vars;
  std::list<Function *> funclist;
};

using namespace std;

//---------------------------------------------------------------------
//   Type
//   型 (int か char) を表す列挙型
//---------------------------------------------------------------------
enum Type
{
  Type_INT,
  Type_CHAR
};

//---------------------------------------------------------------------
// Type_string
// Type の表示用文字列
//---------------------------------------------------------------------
string Type_string(Type t);

//---------------------------------------------------------------------
//  Operator
//  演算子を表す列挙型
//---------------------------------------------------------------------
enum Operator
{
  Operator_PLUS,  // +
  Operator_MINUS, // -
  Operator_MUL,   // *
  Operator_DIV,   // /
  Operator_MOD,   // %

  Operator_LT, // <
  Operator_GT, // >
  Operator_LE, // <=
  Operator_GE, // >=
  Operator_NE, // !=
  Operator_EQ, // ==
};

// static int tmp = 0;

//---------------------------------------------------------------------
//  Operator_string
//  Operator の表示用文字列
//---------------------------------------------------------------------
string Operator_string(Operator o);

//---------------------------------------------------------------------
//  class Expression
//  「式」の抽象基底
//---------------------------------------------------------------------
class Expression
{
private:
  Expression(const Expression &);
  Expression &operator=(const Expression &);

public:
  Expression() {}
  virtual ~Expression() {}
  virtual void print(ostream &os) const = 0;
  virtual int run(map<string, Function *> &func, // 関数表
                  map<string, int> &gvar,        // グローバル変数表
                  map<string, int> &lvar         // ローカル夠数表
  ) const = 0;
};

//---------------------------------------------------------------------
//  class Exp_constant
//  式中の定数を表す
//---------------------------------------------------------------------
class Exp_constant : public Expression
{
private:
  Type type_;
  int value_;

public:
  Exp_constant(Type t, int i) : type_(t), value_(i) {}
  ~Exp_constant() {}
  const int value() const { return value_; }
  const Type type() const { return type_; }
  void print(ostream &os) const;
  int run(map<string, Function *> &func, map<string, int> &gvar,
          map<string, int> &lvar) const
  {
    return value_;
  }
};

// ---------------------------------------------------------------------
// class Exp_variable
// 式中の変数を表す
// --------------------------------------------------------------------
class Exp_variable : public Expression
{
private:
  string name_;

public:
  Exp_variable(const string &n) : name_(n) {}
  ~Exp_variable() {}
  const string &name() const { return name_; }
  void print(ostream &os) const;
  int run(map<string, Function *> &func, map<string, int> &gvar,
          map<string, int> &lvar) const;
};

// ---------------------------------------------------------------------
// class Exp_operation1
// オペランドを1つだけ取る演算
// --------------------------------------------------------------------
class Exp_operation1 : public Expression
{
private:
  Operator operation_;
  Expression *operand_;

public:
  Exp_operation1(Operator op, Expression *ex) : operation_(op), operand_(ex) {}
  ~Exp_operation1() { delete operand_; }
  Operator operation() const { return operation_; }
  const Expression *operand() const { return operand_; }
  void print(ostream &os) const;
  int run(map<string, Function *> &func, map<string, int> &gvar,
          map<string, int> &lvar) const;
};

// ---------------------------------------------------------------------
// class Exp_operation1
// オペランドを2つだけ取る演算
// --------------------------------------------------------------------
class Exp_operation2 : public Expression
{
private:
  Operator operation_;
  Expression *operand1_;
  Expression *operand2_;

public:
  Exp_operation2(Operator op, Expression *ex1, Expression *ex2)
      : operation_(op), operand1_(ex1), operand2_(ex2) {}
  ~Exp_operation2()
  {
    delete operand1_;
    delete operand2_;
  }
  Operator operation() const { return operation_; }
  const Expression *operand1() const { return operand1_; }
  const Expression *operand2() const { return operand2_; }
  void print(ostream &os) const;
  int run(map<string, Function *> &func, map<string, int> &gvar,
          map<string, int> &lvar) const;
};

// ---------------------------------------------------------------------
// class Exp_function
// 関数式を表す
// --------------------------------------------------------------------
class Exp_function : public Expression
{
private:
  string name_;
  list<Expression *> args_;

public:
  Exp_function(const string &nm, const list<Expression *> &args)
      : name_(nm), args_(args) {}
  ~Exp_function();
  const string &name() const { return name_; }
  const list<Expression *> &args() const { return args_; }
  void print(ostream &os) const;
  int run(map<string, Function *> &func, map<string, int> &gvar,
          map<string, int> &lvar) const;
};

//--------------------------------------------------------------------
//  class Statement
// 「文」の抽象基底
//---------------------------------------------------------------------
class Statement
{
public:
  Statement() {}                                             // Constructor
  virtual ~Statement() {}                                    // Destructor
  virtual void print(ostream &os, int indent = 0) const = 0; // Print
  virtual Return_t run(map<string, Function *> &func, map<string, int> &gvar,
                       map<string, int> &lvar) const = 0;

private:
  Statement(const Statement &);            // Copy constructor is forbidden
  Statement &operator=(const Statement &); // Assignment is forbidden
};

//---------------------------------------------------------------------
//  class St_assign
//  代入文の抽象基底
//---------------------------------------------------------------------
class St_assign : public Statement
{
private:
  Exp_variable *lhs_; // left-hand side
  Expression *rhs_;   // right-hand side
public:
  St_assign(Exp_variable *lexp, Expression *rexp)
      : lhs_(lexp), rhs_(rexp) {} // Constructor
  ~St_assign()
  {
    delete lhs_;
    delete rhs_;
  } // Destructor deltete child nodes
  const Exp_variable *lhs() const { return lhs_; }
  const Expression *rhs() const { return rhs_; }
  void print(ostream &os, int indent = 0) const; // Print
  Return_t run(map<string, Function *> &func, map<string, int> &gvar,
               map<string, int> &lvar) const;
};

//---------------------------------------------------------------------
//  class St_list
//  分の並びの抽象基底
//---------------------------------------------------------------------
class St_list : public Statement
{
private:
  list<Statement *> statements_;

public:
  St_list(const list<Statement *> &li) : statements_(li) {}
  ~St_list()
  {
    for (list<Statement *>::const_iterator it = statements_.begin();
         it != statements_.end(); it++)
    {
      delete *it;
    }
  }
  const list<Statement *> &statements() const { return statements_; }
  void print(ostream &os, int indent = 0) const;
  Return_t run(map<string, Function *> &func, map<string, int> &gvar,
               map<string, int> &lvar) const;
};

//---------------------------------------------------------------------
//  class St_if
//  if文の抽象基底
//---------------------------------------------------------------------
class St_if : public Statement
{
private:
  Expression *cond_;
  Statement *then_;
  Statement *else_;

public:
  St_if(Expression *cond, Statement *then, Statement *els)
      : cond_(cond), then_(then), else_(els) {}
  ~St_if()
  {
    delete cond_;
    delete then_;
    delete else_;
  }
  const Expression *condition() const { return cond_; }
  const Statement *then_part() const { return then_; }
  const Statement *else_part() const { return else_; }
  void print(ostream &os, int indent = 0) const;
  Return_t run(map<string, Function *> &func, map<string, int> &gvar,
               map<string, int> &lvar) const;
};

Statement *make_if(void);

//---------------------------------------------------------------------
//  class St_while
//  while文の抽象基底
//---------------------------------------------------------------------
class St_while : public Statement
{
private:
  Expression *cond_;
  Statement *body_;

public:
  St_while(Expression *cond, Statement *body) : cond_(cond), body_(body) {}
  ~St_while()
  {
    delete cond_;
    delete body_;
  }
  const Expression *condition() const { return cond_; }
  const Statement *body() const { return body_; }
  void print(ostream &os, int indent = 0) const;
  Return_t run(map<string, Function *> &func, map<string, int> &gvar,
               map<string, int> &lvar) const;
};

Statement *make_while(void);

//---------------------------------------------------------------------
//  class St_return
//  return文の抽象基底
//---------------------------------------------------------------------
class St_return : public Statement
{
private:
  Expression *value_;

public:
  St_return(Expression *value) : value_(value) {}
  ~St_return() { delete value_; }
  const Expression *value() const { return value_; }
  void print(ostream &os, int indent = 0) const;
  Return_t run(map<string, Function *> &func, map<string, int> &gvar,
               map<string, int> &lvar) const;
};

//---------------------------------------------------------------------
//  class St_function
//---------------------------------------------------------------------
class St_function : public Statement
{
private:
  Exp_function function_; // Exp_function を包含
public:
  // 実装は function_のメソッドを呼び出すだけ
  St_function(const string &name, const list<Expression *> &args)
      : function_(name, args) {}
  ~St_function() {}
  const string &name() const { return function_.name(); }
  const list<Expression *> &args() const { return function_.args(); }
  void print(ostream &os, int indent = 0) const;
  Return_t run(map<string, Function *> &func, map<string, int> &gvar,
               map<string, int> &lvar) const;
};

//---------------------------------------------------------------------
// class Variable
//--------------------------------------------------------------------
class Variable
{
private:
  Type type_;
  string name_;

public:
  Variable(Type t, const string &n) : type_(t), name_(n) {}
  ~Variable() {}
  Type type() const { return type_; }
  const string &name() const { return name_; }
  void print(ostream &os) const;
};

//---------------------------------------------------------------------
// class Function
//--------------------------------------------------------------------
class Function
{
private:
  Type type_;
  string name_;
  list<Variable *> args_;
  list<Variable *> lvarlist_;
  Statement *body_;

public:
  Function(Type type, const string &name, const list<Variable *> &args,
           const list<Variable *> &lvarlist, Statement *body)
      : type_(type), name_(name), args_(args), lvarlist_(lvarlist),
        body_(body) {}
  ~Function();
  Type type() const { return type_; }
  const string &name() const { return name_; }
  const list<Variable *> &args() const { return args_; }
  const list<Variable *> &lvarlist() const { return lvarlist_; }
  const Statement *body() const { return body_; }
  void print(ostream &os) const;
  int run(map<string, Function *> &func, map<string, int> &gvar,
          list<int> &i_args) const;
};

//---------------------------------------------------------------------
// class Program
//--------------------------------------------------------------------
class Program
{
private:
  list<Variable *> varlist_;
  list<Function *> funclist_;
  Function *main_;

public:
  Program(const list<Variable *> &varlist, const list<Function *> &funclist,
          Function *main)
      : varlist_(varlist), funclist_(funclist), main_(main) {}
  ~Program();
  const list<Variable *> &varlist() const { return varlist_; }
  const list<Function *> &funclist() const { return funclist_; }
  const Function *main() const { return main_; }
  void print(ostream &os) const;
  int run() const;
};

#endif // ifndef INCLUDE_AST_H_