%{
//=====================================================================
//
//     parse.yy: mini-C プログラムの構文解析系生成用記述
//
//            コンパイラ演習  2004 (c) 平岡佑介, 石浦菜岐佐
//
//=====================================================================

// --------------------------------------------------------------------
// [Part-1] ヘッダやグローバル変数, 関数の宣言
// --------------------------------------------------------------------

#include "ast.h"
#include <cstdio>

extern int linenum;
extern std::FILE* yyin;

int yylex(void);
void yyerror(const char*);

Program* ast;
Program* build_program(Declaration_t* dd);

%}

// --------------------------------------------------------------------
// [Part-2] 構文木の各節点が返す値を格納する union
// --------------------------------------------------------------------

%union{
  char* string;
  int val;
  Expression* expression;
  Exp_variable* exp_variable;
  std::list<Expression*>* explist;
  Statement* statement;
  std::list<Statement*> * stlist;
  Variable* variable;
  Type type;
  Function* function;
  std::list<Variable*>* vars;
  Declaration_t* declaration_data;
}

// --------------------------------------------------------------------
// [Part-3] トークンの宣言
// --------------------------------------------------------------------

%token lex_KW_INT
%token lex_KW_CHAR
%token lex_KW_IF
%token lex_KW_ELSE
%token lex_KW_WHILE
%token lex_KW_RETURN

%token lex_PLUS lex_MINUS lex_STAR lex_SLASH lex_PERCENT
%token lex_AND
%token lex_EQ lex_EQEQ lex_NE lex_LT lex_GT lex_LE lex_GE
%token lex_COMMA lex_SEMICOLON
%token lex_LPAREN lex_RPAREN
%token lex_LBRACE lex_RBRACE
%token lex_LBRACK lex_RBRACK

%token <val> lex_INT lex_CHAR
%token <string> lex_ID

// --------------------------------------------------------------------
// [Part-4] 型の宣言
// --------------------------------------------------------------------

%type <expression> expression4
%type <exp_variable> exp_variable
%type <expression> expression3
%type <expression> expression2
%type <expression> expression
%type <expression> exp_function
%type <explist> explist
%type <statement> statement
%type <statement> st_assign
%type <statement> st_if
%type <statement> st_while
%type <statement> st_return
%type <statement> st_function
%type <statement> st_list
%type <stlist> stlist
%type <variable> variable_dcl
%type <type> type
%type <function> function_dcl
%type <vars> argument_dcllist
%type <vars> variable_dcllist
%type <declaration_data> dcllist

// --------------------------------------------------------------------
// [Part-5] 開始記号の宣言
// --------------------------------------------------------------------

%start program

%%
// --------------------------------------------------------------------
// [Part-6] 文法とアクションの記述
// --------------------------------------------------------------------

program
: dcllist
{
  ast = build_program($1);
}

dcllist
:
{
  $$ = new Declaration_t;
}
| dcllist variable_dcl lex_SEMICOLON
{
  $1->vars.push_back($2);
  $$ = $1;
}
| dcllist function_dcl
{
  $1->funclist.push_back($2);
  $$ = $1;
}

function_dcl
: type lex_ID lex_LPAREN argument_dcllist lex_RPAREN lex_LBRACE variable_dcllist st_list lex_RBRACE
{
  $$ = new Function($1, $2, *$4, *$7, $8);
  delete $4;
  delete $7;
}

argument_dcllist
:
{
  $$ = new std::list<Variable*>;
}
| variable_dcl
{
 $$ = new std::list<Variable*>;
 $$->push_back($1);
}
| argument_dcllist lex_COMMA variable_dcl
{
  $1->push_back($3);
  $$ = $1;
}


variable_dcllist
:
{
  $$ = new std::list<Variable*>;
}
| variable_dcllist variable_dcl lex_SEMICOLON
{
  $1->push_back($2);
  $$ = $1;
}

variable_dcl
: type lex_ID
{
  $$ = new Variable($1, $2);
}

type
: lex_KW_INT
{
  $$ = Type_INT;
}
| lex_KW_CHAR
{
  $$ = Type_CHAR;
}

statement
: st_assign {$$ = $1;}
| lex_LBRACE st_list lex_RBRACE {$$ = $2;}
| st_if {$$ = $1;}
| st_while {$$ = $1;}
| st_return {$$ = $1;}
| st_function {$$ = $1;}

st_assign
: exp_variable lex_EQ expression lex_SEMICOLON
{
  $$ = new St_assign($1, $3);
}

st_list
: stlist
{
  $$ = new St_list(*$1);
  delete $1;
}

stlist
:
{
  $$ = new std::list<Statement*>;
}
| stlist statement
{
  $1->push_back($2);
  $$ = $1;
}

st_if
: lex_KW_IF lex_LPAREN expression lex_RPAREN statement
{
  $$ = new St_if($3, $5, NULL);
}
| lex_KW_IF lex_LPAREN expression lex_RPAREN statement lex_KW_ELSE statement 
{
  $$ = new St_if($3, $5, $7);
}

st_while
: lex_KW_WHILE lex_LPAREN expression lex_RPAREN statement
{
  $$ = new St_while($3, $5);
}

st_return
: lex_KW_RETURN expression lex_SEMICOLON
{
  $$ = new St_return($2);
}

st_function
: lex_ID lex_LPAREN explist lex_RPAREN lex_SEMICOLON
{
  $$ = new St_function($1, *$3);
}

expression4
: lex_INT
{
  $$ = new Exp_constant(Type_INT, $1);
}
| lex_CHAR
{
  $$ = new Exp_constant(Type_CHAR, $1);
}
| exp_variable
{
  $$ = $1;
}
| lex_LPAREN expression lex_RPAREN
{
  $$ = $2;
}
| exp_function
{
  $$ = $1;
}

exp_function
: lex_ID lex_LPAREN explist lex_RPAREN
{
  $$ = new Exp_function($1, *$3);
  delete $3;
}

explist
:
{
  $$ = new std::list<Expression*>;
}
| expression
{
  $$ = new std::list<Expression*>;
  $$->push_back($1);
}
| explist lex_COMMA expression
{
  $1->push_back($3);
  $$ = $1;
}

exp_variable
: lex_ID
{
  $$ = new Exp_variable($1);
}

expression3
: expression4
{
  $$ = $1;
}
| expression3 lex_STAR expression4
{
  $$ = new Exp_operation2(Operator_MUL, $1, $3);
}
| expression3 lex_SLASH expression4
{
  $$ = new Exp_operation2(Operator_DIV, $1, $3);
}
| expression3 lex_PERCENT expression4
{
  $$ = new Exp_operation2(Operator_MOD, $1, $3);
}

expression2
: expression3
{
  $$ = $1;
}
| lex_PLUS expression3
{
  $$ = new Exp_operation1(Operator_PLUS, $2);
}
| lex_MINUS expression3
{
  $$ = new Exp_operation1(Operator_MINUS, $2);
}
| expression2 lex_PLUS expression3
{
  $$ = new Exp_operation2(Operator_PLUS, $1, $3);
}
| expression2 lex_MINUS expression3
{
  $$ = new Exp_operation2(Operator_MINUS, $1, $3);
}

expression
: expression2
{
  $$ = $1;
}
| expression lex_LT expression2
{
  $$ = new Exp_operation2(Operator_LT, $1, $3);
}
| expression lex_GT expression2
{
  $$ = new Exp_operation2(Operator_GT, $1, $3);
}
| expression lex_LE expression2
{
  $$ = new Exp_operation2(Operator_LE, $1, $3);
}
| expression lex_GE expression2
{
  $$ = new Exp_operation2(Operator_GE, $1, $3);
}
| expression lex_EQEQ expression2
{
  $$ = new Exp_operation2(Operator_EQ, $1, $3);
}
| expression lex_NE expression2
{
  $$ = new Exp_operation2(Operator_NE, $1, $3);
}

%%
// --------------------------------------------------------------------
// [Part-7] 関数本体の記述
// --------------------------------------------------------------------

int main(int argc, char *argv[])
{
  if(std::FILE* fp = std::fopen(argv[1], "r"))
  {
    linenum = 1;  // lex の行番号を 1 に初期設定
    yyin = fp;    // lex のファイルポインタをセット
    yyparse();    // 構文解析関数を呼び出す
    ast->run();
  }
  else {
    printf("ファイル '%s' が開けません\n", argv[1]);
  }
}

Program* build_program(Declaration_t* dd)
{
  std::list<Function*> flist;
  Function* mainf;

  // ddのfunclistリスト中の関数のうち、"main"という名前の
  // ものはmainfにセットし、それ以外はリストflistに入れる
  std::list<Function*>::iterator f;
  for (f = dd->funclist.begin(); f != dd->funclist.end(); f++) {
    if ((*f)->name() == "main") { mainf = *f; }
    else { flist.push_back(*f); }
  }

  return new Program(dd->vars, flist, mainf);
}