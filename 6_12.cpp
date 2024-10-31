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

int main()
{
    // Function* function_asum = make_function_asum(); // 前回の演習で作成したもの
    // std::map<std::string, Function*> func;
    // std::map<std::string, int> gvar;
    // std::list<int> i_arglist;
    // i_arglist.push_back(3);
    // int r = function_asum->run(func, gvar, i_arglist);
    // std::cout << r << std::endl;

    std::list<Expression *> arglist;
    arglist.push_back(new Exp_constant(Type_INT, 5));
    Expression *exp_function_asum = new Exp_function("asum", arglist);
    std::map<std::string, Function *> func;
    std::map<std::string, int> gvar;
    std::map<std::string, int> lvar;
    func["asum"] = make_function_asum();
    int asum5 = exp_function_asum->run(func, gvar, lvar);
    std::cout << "asum(5) = " << asum5 << std::endl;
    return 0;
}