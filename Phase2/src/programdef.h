
#include <bits/stdc++.h>
using namespace std;

union Node{
	int num;
	char* lit;
	class UnaryExpr* unaryExpr;
	class DeclList* decls;
	class Prog* prog;
	class Variables* vars;
	class VarList* varList;
	class Variable* var;
	class Decl* decl;
	class Fields* fields;
	class MethodList* methods;
	class Field* field;
	class ExprList* exprList;
	class VarDecl* varDecl;
	class MethodCall* methodCall;
	class CalloutArg* calloutArg;
	class CalloutArgList* calloutArgList;
	class Statement* stmt;
	class Literal* literal;
	class Block* block;
	class StatementList* stmts;
	class ContinueStmt* continueStmt;
	class Params* params;
	class Expr* expr;
	class ForAssign* forAssign;
	class BinExpr* binExpr;
	class ReturnStmt* returnStmt;
	class EnclExpr* enclExpr;
	class Method* method;
	class AssignExpr* assignExpr;
	class IfStmt* ifStmt;
	class ForStmt* forStmt;
	class Location* location;
	class BreakStmt* breakStmt;
	class Param* param;


	Node()
	{
		lit = NULL;
		decls = NULL;
		decl = NULL;
		varDecl = NULL;
		varList = NULL;
		methods = NULL;
		methodCall = NULL;
		ifStmt = NULL;
		exprList = NULL;
		assignExpr = NULL;
		block = NULL;
		field = NULL;
		prog = NULL;
		var = NULL;
		calloutArg = NULL;
		calloutArgList = NULL;
		num = 0;
		param = NULL;
		stmt = NULL;
		method = NULL;
		breakStmt = NULL;
		literal = NULL;
		binExpr = NULL;
		vars = NULL;
		continueStmt = NULL;
		returnStmt = NULL;
		fields = NULL;
		location = NULL;
		enclExpr = NULL;
		forAssign = NULL;
		stmts = NULL;
		unaryExpr = NULL;
		forStmt = NULL;
		expr = NULL;
		params = NULL;
	}
	~Node(){}
};

typedef union Node YYSTYPE;

#define YYSTYPE_IS_DECLARED 1

class Visitor{
public:
	virtual int visit(class DeclList* e) {}
	virtual int visit(class MethodCall* e) {}
	virtual int visit(class Decl* e) {}
	virtual int visit(class Block* e) {}
	virtual int visit(class Field* e) {}
	virtual int visit(class Prog* e) {}
	virtual int visit(class Method* e) {}
	virtual int visit(class Expr* e) {}
	virtual int visit(class StatementList* e) {}
	virtual int visit(class ReturnStmt* e) {}
	virtual int visit(class VarDecl* e) {}
	virtual int visit(class Fields* e) {}
	virtual int visit(class CalloutArg* e) {}
	virtual int visit(class Variable* e) {}
	virtual int visit(class Variables* e) {}
	virtual int visit(class ForAssign* e) {}
	virtual int visit(class BreakStmt* e) {}
	virtual int visit(class Location* e) {}
	virtual int visit(class ExprList* e) {}
	virtual int visit(class BinExpr* e) {}
	virtual int visit(class Literal* e) {}
	virtual int visit(class UnaryExpr* e) {}
	virtual int visit(class EnclExpr* e) {}
	virtual int visit(class Param* e) {}
	virtual int visit(class ForStmt* e) {}
	virtual int visit(class CalloutArgList* e) {}
	virtual int visit(class MethodList* e) {}
	virtual int visit(class Params* e) {}
	virtual int visit(class AssignExpr* e) {}
	virtual int visit(class VarList* e) {}
	virtual int visit(class IfStmt* e) {}
	virtual int visit(class ContinueStmt* e) {}

};

class Interpreter:public Visitor{
public:
	Interpreter(){}
	int visit(class VarDecl* e);
	int visit(class Prog* e);
	int visit(class Variable* e);
	int visit(class CalloutArgList* e);
	int visit(class VarList* e);
	int visit(class Decl* e);
	int visit(class Fields* e);
	int visit(class StatementList* e);
	int visit(class ExprList* e);
	int visit(class Field* e);
	int visit(class DeclList* e);
	int visit(class Method* e);
	int visit(class CalloutArg* e);
	int visit(class Literal* e);
	int visit(class Params* e);
	int visit(class Location* e);
	int visit(class Variables* e);
	int visit(class MethodList* e);
	int visit(class Expr* e);
	int visit(class BinExpr* e);
	int visit(class MethodCall* e);
	int visit(class BreakStmt* e);
	int visit(class UnaryExpr* e);
	int visit(class Param* e);
	int visit(class EnclExpr* e);
	int visit(class ForAssign* e);
	int visit(class AssignExpr* e);
	int visit(class Block* e);
	int visit(class ContinueStmt* e);
	int visit(class IfStmt* e);
	int visit(class ForStmt* e);
	int visit(class ReturnStmt* e);
};

class BaseAst{
public:
	virtual int accept(Visitor* v){}
};

class DeclList: public BaseAst{
public:
	vector<class Decl*> decl_list;
	int count;
	DeclList(){count = 0;}
	void push_back(class Decl*);
	int accept(Visitor* v){ return v->visit(this); }

};


class Decl: public BaseAst{
public:
	string data_type;
	vector<class Field*> field_list;
	Decl(string, class Fields*);
	int accept(Visitor* v){ 
		return v->visit(this); }

};

class Fields: public BaseAst{
public:
	vector<class Field*> field_list;
	int count;
	Fields(){count = 0;}
	vector<class Field*> getFieldList();
	void push_back(class Field*);
	int accept(Visitor* v){ return v->visit(this); }

};

class Field: public BaseAst{
public:
	string type;
	string data_type;
	string name;
	int length;
	Field(string, string);
	Field(string, string, int);
	int accept(Visitor* v){ return v->visit(this); }

};


class VarList: public BaseAst{
public:
	vector<class VarDecl*> vars_list;
	int count;
	VarList(){count = 0;}
	void push_back(class VarDecl*);
	int accept(Visitor* v){ return v->visit(this); }

};

class Prog: public BaseAst{
public:
	class DeclList* decls;
	class MethodList* methods;

	Prog(class DeclList*,class MethodList*);
	int accept(Visitor* v){ return v->visit(this); }

};

class Variables: public BaseAst{
public:
	vector<class Variable*> var_list;
	int count;
	Variables(){count = 0;}
	void push_back(class Variable*);
	vector<class Variable*> getVarList();
	int accept(Visitor* v){ return v->visit(this); }

};

class Variable: public BaseAst{
public:
	string name;
	string data_type;
	Variable(string);
	int accept(Visitor* v){ return v->visit(this); }

};

class VarDecl: public BaseAst{
public:
	string data_type;
	vector<class Variable*> var_list;
	VarDecl(string, class Variables*);
	int accept(Visitor* v){ return v->visit(this); }

};
class MethodList:public BaseAst{
public:
	vector<class Method*> method_list;
	int count;
	MethodList(){count=0;}
	void push_back(class Method*);
	int accept(Visitor* v){ return v->visit(this); }

};

class Statement:public BaseAst{

};

class Method:public BaseAst{
public:
	string name;
	string return_type;
	class Params* params;
	class Block* block;

	Method(string, string, class Params*, class Block*);
	int accept(Visitor* v){ return v->visit(this); }

};

class Params:public BaseAst{
public:
	vector<class Param*> param_list;
	int count;
	Params(){count = 0;}
	void push_back(class Param*);
	int accept(Visitor* v){ return v->visit(this); }

};

class Param:public BaseAst{
public:
	string data_type;
	string name;
	Param(string, string);
	int accept(Visitor* v){ return v->visit(this); }

};

class CalloutArg:public BaseAst{
public:
	string type;
	string string_arg;
	class Expr* expr_arg;

	CalloutArg(string, string);
	CalloutArg(string, class Expr*);

	int accept(Visitor* v){ return v->visit(this); }

};

class CalloutArgList:public BaseAst{
public:
	vector<class CalloutArg*> callout_arg_list;
	int count;

	CalloutArgList(){count = 0;}
	void push_back(class CalloutArg*);
	int accept(Visitor* v){ return v->visit(this); }

};

class ExprList:public BaseAst{
public:
	vector<class Expr*> expr_list;
	int count;

	ExprList(){count = 0;}
	void push_back(class Expr*);
	int accept(Visitor* v){ return v->visit(this); }

};

class MethodCall:public Statement{
public:
	string type, name;
	class ExprList* expr_list;
	class CalloutArgList* args;

	MethodCall(string, string, class ExprList*);
	MethodCall(string, string);
	MethodCall(string, string, class CalloutArgList*);
	int accept(Visitor* v){ return v->visit(this); }

};

class StatementList:public BaseAst{
public:
	vector<class Statement*> stmts;
	int count;
	StatementList(){count=0;}
	void push_back(class Statement*);
	int accept(Visitor* v){ return v->visit(this); }

};

class Block:public Statement{
public:
	class VarList* vars;
	class StatementList* stmts;

	Block(class VarList*, class StatementList*);
	int accept(Visitor* v){ return v->visit(this); }

}; 

class Expr:public BaseAst{
public:
	string type;
	class Location* loc;
	class MethodCall* method_call;
	class Literal* literal;
	class BinExpr* bin_expr;
	class UnaryExpr* unary_expr;
	class EnclExpr* encl_expr;

	Expr(string, class Location*);
	Expr(string, class MethodCall*);
	Expr(string, class Literal*);
	Expr(string, class BinExpr*);
	Expr(string, class UnaryExpr*);
	Expr(string, class EnclExpr*);

	int accept(Visitor* v){ return v->visit(this); }

};

/* ID or ID[expr] */
class Location: public BaseAst {
public:
	string type;
	string name;
	class Expr* expr;
	Location(string, string);
	Location(string, string, class Expr*);
	int accept(Visitor* v){ return v->visit(this); }

};

class Literal:public BaseAst{
public:
	string type;
	int int_literal;
	char char_literal;
	bool bool_literal;

	Literal(string, int);
	Literal(string, char);
	Literal(string, bool);
};

class BinExpr:public BaseAst{
public:
	class Expr* expr1;
	class Expr* expr2;
	string oper;
	BinExpr(class Expr*, string, class Expr*);
	int accept(Visitor* v){ return v->visit(this); }

};

class UnaryExpr:public BaseAst{
public:
	class Expr* expr;
	string oper;
	UnaryExpr(string, class Expr*);
	int accept(Visitor* v){ return v->visit(this); }

};

class EnclExpr:public BaseAst{
public:
	class Expr* expr;
	EnclExpr(class Expr*);
	int accept(Visitor* v){ return v->visit(this); }

};


class ReturnStmt : public Statement{
public:
	string type;
	class Expr* expr;

	ReturnStmt(string);
	ReturnStmt(string, class Expr*);
	int accept(Visitor* v){ return v->visit(this); }

};
class ForAssign: public BaseAst{
public:
	class Variable* var;
	class Expr* value;

	ForAssign(class Variable*, class Expr*);
	int accept(Visitor* v){ return v->visit(this); }

};

class IfStmt:public Statement{
public:
	string type;
	class Expr* cond;
	class Block *if_part, *else_part;
	IfStmt(string,class Expr*,class Block*);
	IfStmt(string,class Expr*,class Block*,class Block*);
	int accept(Visitor* v){ return v->visit(this); }

};
class AssignExpr: public Statement{
public:
  class Location* lhs;
  string oper;
  class Expr* rhs;
  AssignExpr(class Location*, string, class Expr*);
  int accept(Visitor* v){ return v->visit(this); }
 
};

class ForStmt:public Statement{
public:
	class ForAssign* initial;
	class Expr* end_cond;
	class Block* block;
	ForStmt(class ForAssign*,class Expr*,class Block*);
	int accept(Visitor* v){ return v->visit(this); }

};
class BreakStmt : public Statement{
public:
	BreakStmt(){}
	int accept(Visitor* v){ return v->visit(this); }

};


class ContinueStmt : public Statement{
public:
	ContinueStmt(){}
	int accept(Visitor* v){ return v->visit(this); }

};
