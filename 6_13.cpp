#include "ast.h"

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
    Exp_variable *i = new Exp_variable("i");
    Exp_variable *n = new Exp_variable("n");
    Exp_constant *one = new Exp_constant(Type_INT, 1);

    Expression *cond = new Exp_operation2(Operator_LE, i, n);

    list<Statement *> stmts;
    Statement *stmt1 = make_if();
    Exp_operation2 *asgn = new Exp_operation2(Operator_PLUS, i, one);
    Statement *stmt2 = new St_assign(i, asgn);
    stmts.push_back(stmt1);
    stmts.push_back(stmt2);

    Statement *body = new St_list(stmts);
    return new St_while(cond, body);
}

Function *make_function_asum()
{
    Type t = Type_INT;
    string n = "asum";

    list<Variable *> args;
    Variable *a1 = new Variable(Type_INT, "n");
    args.push_back(a1);

    list<Variable *> lvarlist;
    Variable *lv1 = new Variable(Type_INT, "s");
    Variable *lv2 = new Variable(Type_INT, "i");
    lvarlist.push_back(lv1);
    lvarlist.push_back(lv2);

    // s = 0;
    Exp_variable *ev1 = new Exp_variable("s");
    Exp_constant *c1 = new Exp_constant(Type_INT, 0);
    St_assign *sa1 = new St_assign(ev1, c1);
    // i = - n;
    Exp_variable *ev2 = new Exp_variable("i");
    Exp_variable *ev3 = new Exp_variable("n");
    Exp_operation1 *eo1 = new Exp_operation1(Operator_MINUS, ev3);
    St_assign *sa2 = new St_assign(ev2, eo1);
    // while
    Statement *sw = make_while();
    // return s;
    St_return *sr = new St_return(ev1);

    list<Statement *> list;
    list.push_back(sa1);
    list.push_back(sa2);
    list.push_back(sw);
    list.push_back(sr);

    St_list *st_list = new St_list(list);
    Function *f = new Function(t, n, args, lvarlist, st_list);
    return f;
}

Function *make_function_main()
{
    // local variables
    list<Variable *> lvarlist;
    Variable *lv1 = new Variable(Type_INT, "a"); // int a;
    lvarlist.push_back(lv1);

    // g = 3;
    Exp_variable *ev1 = new Exp_variable("g");         // g
    Exp_constant *ec1 = new Exp_constant(Type_INT, 3); // 3
    St_assign *sa1 = new St_assign(ev1, ec1);          // g = 3;

    // a = asum(g);
    Exp_variable *ev2 = new Exp_variable("a"); // a
    list<Expression *> args;
    args.push_back(ev1);
    Exp_function *ef1 = new Exp_function("asum", args); // asum(g)
    St_assign *sa2 = new St_assign(ev2, ef1);           // a = asum(g);

    // putint(a);
    list<Expression *> args2; // args for putint
    args2.push_back(ev2);
    St_function *sf1 = new St_function("putint", args2); // putint(a);

    list<Statement *> statements;
    statements.push_back(sa1); // push "g = 3;"
    statements.push_back(sa2); // push "a = asum(g);"
    statements.push_back(sf1); // push "putint(a);"
    St_list *st_list = new St_list(statements);

    // args for main but its empty
    list<Variable *> main_args;

    Function *main = new Function(Type_INT, "main", main_args, lvarlist, st_list);
    return main;
}

int main()
{
    // プログラムの抽象構文木
    std::list<Variable *> gvar;
    std::list<Function *> func;
    gvar.push_back(new Variable(Type_INT, "g"));
    func.push_back(make_function_asum());
    Program *p = new Program(gvar, func, make_function_main());

    // 実行
    p->run();
}