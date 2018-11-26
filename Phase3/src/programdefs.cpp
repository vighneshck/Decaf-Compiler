#include <bits/stdc++.h>

using namespace std;
#include "programdef.h"

map < string, string > method_return_type;
map < string, string > var_type;
map < string, int > itable;


Field::Field(string type, string name){
	this->type = type;
	this->name = name;
}
Decl::Decl(string data_type, class Fields* fields){
	this->data_type = data_type;
	this->field_list = fields->getFieldList();
}

Prog::Prog(class DeclList* decls, class MethodList* methods){
	this->decls = decls;
	this->methods = methods;
}


VarDecl::VarDecl(string data_type, class Variables* variables){
	this->data_type = data_type;
	this->var_list = variables->getVarList();
}

Variable::Variable(string name) {
	this->name = name;
}
Method::Method(string name, string return_type, class Params* params, class Block* block){
	this->name = name;
	assert(return_type);
	this->return_type = return_type;
	this->params = params;
	this->block = block;
}
Field::Field(string type, string name, int length){
	this->type = type;
	assert(name);
	this->name = name;
	this->length = length;
}

CalloutArg::CalloutArg(string type, string arg){
	this->type = type;
	this->string_arg = arg;
}

Param::Param(string data_type, string name){
	this->data_type = data_type;
	this->name = name;
}

MethodCall::MethodCall(string type, string name, class CalloutArgList* args){
	this->args = args;
	this->type = type;
	assert(name);
	this->name = name;
}


Expr::Expr(string type, class Literal* literal){
	this->type = type;
	this->literal = literal;
}
IfStmt::IfStmt(string type, class Expr* expr, class Block* block1, class Block* block2){
	this->type = type;
	this->cond = cond;
	this->if_part = block1;
	this->else_part = block2;
}

MethodCall::MethodCall(string type, string name, class ExprList* expr_list){
	this->type = type;
	assert(name);
	this->name = name;
	this->expr_list = expr_list;
}
CalloutArg::CalloutArg(string type, class Expr* arg){
	this->type = type;
	this->expr_arg = arg;
}
Expr::Expr(string type, class EnclExpr* encl_expr){
	this->type = type;
	this->encl_expr = encl_expr;
}

Expr::Expr(string type, class Location* loc){
	this->type = type;
	this->loc = loc;
}

ForStmt::ForStmt(class ForAssign* initial, class Expr* end_cond, class Block* block){
	this->initial = initial;
	this->end_cond = end_cond;
	this->block = block;
}


Expr::Expr(string type, class MethodCall* method_call){
	this->type = type;
	this->method_call = method_call;
}


Location::Location(string type, string name){
	this->type = type;
	this->name = name;
}
Block::Block(class VarList* vars,class StatementList* stmts){
	this->vars = vars;
	this->stmts = stmts;
}

MethodCall::MethodCall(string type, string name){
	this->type = type;
	assert(name);
	this->name = name;
}


Literal::Literal(string type, char val){
	this->type = type;
	this->char_literal = val;
}

Literal::Literal(string type, bool val){
	this->type = type;
	this->bool_literal = val;
}

Location::Location(string data_type, string name, class Expr* expr){
	this->type = type;
	assert(name);
	this->name = name;
	this->expr = expr;
}
Expr::Expr(string type, class UnaryExpr* unary_expr){
	this->type = type;
	this->unary_expr = unary_expr;
}

Literal::Literal(string type, int val){
	this->type = type;
	this->int_literal = val;
}

IfStmt::IfStmt(string type,class Expr* cond,class Block* block){
	this->type = type;
	this->cond = cond;
	this->if_part = block;
}
BinExpr::BinExpr(class Expr* expr1, string oper, class Expr* expr2){
	this->expr1 = expr1;
	this->oper  = oper;
	this->expr2 = expr2;
}


EnclExpr::EnclExpr(class Expr* expr){
	this->expr = expr;
}

UnaryExpr::UnaryExpr(string oper, class Expr* expr){
	this->oper  = oper;
	this->expr = expr;
}
AssignExpr::AssignExpr(class Location* lhs, string oper, class Expr* rhs){
	this->lhs = lhs;
	this->oper = oper;
	this->rhs = rhs;
}
ReturnStmt::ReturnStmt(string type){
	this->type = type;
}
ForAssign::ForAssign(class Variable* var, class Expr* value){
	this->var = var;
	this->value = value;
}
Expr::Expr(string type, class BinExpr* bin_expr){
	this->type = type;
	this->bin_expr = bin_expr;
}

ReturnStmt::ReturnStmt(string type, class Expr* expr){
	this->type = type;
	this->expr = expr;
}

int inccount(int count){
	return count + 1;
}

void VarList::push_back(class VarDecl* var){
	vars_list.push_back(var);
	count = inccount(count);
}

void Fields::push_back(class Field* var){
	field_list.push_back(var);
	count = inccount(count);
}

void Variables::push_back(class Variable* var){
	var_list.push_back(var);
	count = inccount(count);
}

void DeclList::push_back(class Decl* var){
	decl_list.push_back(var);
	count = inccount(count);
}
void ExprList::push_back(class Expr* var){
	expr_list.push_back(var);
	count = inccount(count);
}



void CalloutArgList::push_back(class CalloutArg* var){
	callout_arg_list.push_back(var);
	count = inccount(count);
}

void StatementList::push_back(class Statement* var){
	stmts.push_back(var);
	count = inccount(count);
}


void Params::push_back(class Param* var){
	param_list.push_back(var);
	count = inccount(count);
}
void MethodList::push_back(class Method* var){
	method_list.push_back(var);
	count = inccount(count);
}

vector<class Field*> Fields::getFieldList(){
	return field_list;
}

vector<class Variable*> Variables::getVarList(){
	return var_list;
}

void getExprType(class Expr* expr, string &type){

	if(expr->type == "mc")
		type = method_return_type[expr->method_call->name];

	else if(expr->type == "bin")
	{
		if(expr->bin_expr->oper == "+" || expr->bin_expr->oper == "-" || expr->bin_expr->oper == "*" || expr->bin_expr->oper == "/" || expr->bin_expr->oper == "%")
			type = "int";
		else
			type = "bool";
	}
	else if(expr->type == "lit")
	{
		type = expr->literal->type;
	}

	else if(expr->type == "loc")
		type = var_type[expr->loc->name];

	else if(expr->type == "unary")
	{
		if(expr->unary_expr->oper == "-")
			type = "int";
		else
			type = "bool";
	}

	else
		getExprType(expr->encl_expr->expr, type);
}

int Interpreter::visit(class DeclList* obj){
	Interpreter *it = new Interpreter();
	for(auto i:obj->decl_list)
	{
		i->accept(it);
	}
	return 0;
}



int Interpreter::visit(class Decl* obj){
	Interpreter *it = new Interpreter();
	for(auto i:obj->field_list)
	{
		i->data_type = obj->data_type;
		i->accept(it);
	}
	return 0;
}

int Interpreter::visit(class Prog* obj){
	Interpreter *it = new Interpreter();
	obj->decls->accept(it);
	obj->methods->accept(it);
	return 0;
}

int Interpreter::visit(class Field* obj){
	if(obj->type == " normal")
		itable[obj->name]=0;	
	else
		for(int i=0;i<obj->length;i++)
	    {
	      itable[to_string(i)+obj->name]=0;
	    }

	var_type[obj->name] = obj->data_type;
	return 0;
}

int Interpreter::visit(class VarList* obj){
	Interpreter *it = new Interpreter();
	for(auto i:obj->vars_list)
	{
		i->accept(it);
	}
	return 0;
}
int Interpreter::visit(class Fields* obj){
	Interpreter *it = new Interpreter();
	for(auto i:obj->field_list)
	{
		i->accept(it);
	}
	return 0;
}


int Interpreter::visit(class StatementList* obj){
	Interpreter *it = new Interpreter();
	for(auto i:obj->stmts)
	{
		i->accept(it);
	}
	return 0;
}

int Interpreter::visit(class Variable* obj){
	itable[obj->name]=0;
	var_type[obj->name] = obj->data_type;	
	return 0;
}

int Interpreter::visit(class Param* obj){
	return 0;
}
int Interpreter::visit(class MethodList* obj){
	Interpreter *it = new Interpreter();
	for(auto i:obj->method_list)
	{
		i->accept(it);
	}
	return 0;
}

int Interpreter::visit(class Method* obj){
	Interpreter *it = new Interpreter();

	obj->params->accept(it);
	obj->block->accept(it);
	method_return_type[obj->name] = obj->return_type;
	return 0;
}

int Interpreter::visit(class Params* obj){
	Interpreter *it = new Interpreter();
	for(auto i:obj->param_list)
	{
		i->accept(it);
	}
	return 0;
}

int Interpreter::visit(class VarDecl* obj){
	Interpreter *it = new Interpreter();
	for(auto i:obj->var_list)
	{
		i->data_type = obj->data_type;
		i->accept(it);
	}
	return 0;
}

int Interpreter::visit(class CalloutArg* obj){
	Interpreter *it = new Interpreter();

	if(obj->type == "expr")
		obj->expr_arg->accept(it);
	return 0;
}

int Interpreter::visit(class CalloutArgList* obj){
	Interpreter *it = new Interpreter();
	for(auto i:obj->callout_arg_list)
	{
		i->accept(it);
	}
	return 0;
}

int Interpreter::visit(class ExprList* obj){
	Interpreter *it = new Interpreter();
	for(auto i:obj->expr_list)
	{
		i->accept(it);
	}
	return 0;
}
int Interpreter::visit(class Expr* obj){
	Interpreter *it = new Interpreter();

	if(obj->type == "loc")
		return obj->loc->accept(it);
	else if(obj->type == "unary")
		return obj->unary_expr->accept(it);
	else if(obj->type == "lit")
		return obj->literal->accept(it);
	else if(obj->type == "mc")
		return obj->method_call->accept(it);
	else if(obj->type == "bin")
		return obj->bin_expr->accept(it);
	else
		return obj->encl_expr->accept(it);
}

int Interpreter::visit(class MethodCall* obj){
	Interpreter *it = new Interpreter();

	if(obj->type == "normal")
	{
		obj->expr_list->accept(it);
	}
	else
	{
		obj->args->accept(it);
	}
	return 0;
}


int Interpreter::visit(class Block* obj){
	Interpreter *it = new Interpreter();
	obj->vars->accept(it);
	obj->stmts->accept(it);
	return 0;
}

int Interpreter::visit(class Literal* obj){
	if(obj->type == "int")
		return obj->int_literal;
	else if(obj->type == "char")
		return obj->char_literal;
	else
		return obj->bool_literal;
}

int Interpreter::visit(class Location* obj){
	Interpreter *it = new Interpreter();

	if(obj->type == "normal")
		return itable[obj->name];
	else
		return itable[to_string(obj->expr->accept(it))+obj->name];
}


int Interpreter::visit(class Variables* obj){
	Interpreter *it = new Interpreter();
	for(auto i:obj->var_list)
	{
		i->accept(it);
	}
	return 0;
}
int Interpreter::visit(class UnaryExpr* obj){
	Interpreter *it = new Interpreter();
	if(obj->oper == "-")
		return -obj->expr->accept(it);
	else if(obj->oper == "!")
	{
		string type = "";
		getExprType(obj->expr, type);
		if(type != "bool")
		{
			cout << "Error: Non-boolean NOT operand!\n";
			return -1;
		}
		return !obj->expr->accept(it);
	}
	else
	{
		cout<<"Error: Unsupported unary operator!" << obj->oper << "\n";
		return -1;
	}
}
int Interpreter::visit(class BinExpr* obj){
	Interpreter *it = new Interpreter();

	string type1 = "", type2 = "";
	getExprType(obj->expr1, type1);
	getExprType(obj->expr2, type2);

	if(type1 != type2){
		cout << "Error: Binary operands have different data types\n";
		return -1;
	}	
	if(obj->oper == "+" && type1 == "int")
		return obj->expr1->accept(it) + obj->expr2->accept(it);

	else if(obj->oper == "*" && type1 == "int")
		return obj->expr1->accept(it) * obj->expr2->accept(it);


	else if(obj->oper == "/" && type1 == "int")
		return obj->expr1->accept(it) / obj->expr2->accept(it);
	else if(obj->oper == ">" && type1 == "int")
		return obj->expr1->accept(it) > obj->expr2->accept(it);

	else if(obj->oper == "-" && type1 == "int")
		return obj->expr1->accept(it) - obj->expr2->accept(it);

	else if(obj->oper == "<" && type1 == "int")
		return obj->expr1->accept(it) < obj->expr2->accept(it);
	else if(obj->oper == "<=" && type1 == "int")
		return obj->expr1->accept(it) <= obj->expr2->accept(it);


	else if(obj->oper == "!=")
		return obj->expr1->accept(it) != obj->expr2->accept(it);

	else if(obj->oper == ">=" && type1 == "int")
		return obj->expr1->accept(it) >= obj->expr2->accept(it);

	else if(obj->oper == "==")
		return obj->expr1->accept(it) == obj->expr2->accept(it);

	else if(obj->oper == "&&" && type1 == "bool")
		return obj->expr1->accept(it) && obj->expr2->accept(it);
	else if(obj->oper == "||"  && type1 == "bool")
		return obj->expr1->accept(it) || obj->expr2->accept(it);


	else if(obj->oper == "%" && type1 == "int")
		return obj->expr1->accept(it) % obj->expr2->accept(it);

	else
	{
		cout <<"Error: Invalid operand datatypes or invalid operator\n";
		return -1;
	}

}


int Interpreter::visit(class EnclExpr* obj){
	Interpreter *it = new Interpreter();
	return obj->expr->accept(it);
}


int Interpreter::visit(class ForAssign* obj){
	Interpreter *it = new Interpreter();
	itable[obj->var->name] = obj->value->accept(it);
	return 0;
}

int Interpreter::visit(class IfStmt* obj){
	Interpreter *it = new Interpreter();

	string type = "";
	getExprType(obj->cond, type);
	if(type != "bool")
	{
		cout << "Error: Missing boolean expression for if\n";
		return -1;
	}

	if(obj->type == "normal")
	{
		if(obj->cond->accept(it))
			obj->if_part->accept(it);
	}
	else
	{
		if(obj->cond->accept(it))
			obj->if_part->accept(it);
		else 
			obj->else_part->accept(it);
	}
	return 0;
}

int Interpreter::visit(class AssignExpr* obj){
	Interpreter *it = new Interpreter();
	string type = "";

	getExprType(obj->rhs, type);
	
	if(obj->lhs->type == "normal")
	{
		if(itable.find(obj->lhs->name)==itable.end())
		{
			cout<<"Error: "<<obj->lhs->name<<" not defined\n";
			return -1;
		}
		else
		{
			if(var_type[obj->lhs->name] != type)
			{
				cout << obj->lhs << " and " << obj->rhs <<" different in AssignExpr!\n";
				return -1;
			}
			if(obj->oper == "=")
				itable[obj->lhs->name] = obj->rhs->accept(it);
			else if(obj->oper == "-=")
				itable[obj->lhs->name] -= obj->rhs->accept(it);
			else if(obj->oper == "+=")
				itable[obj->lhs->name] += obj->rhs->accept(it);
		}
	}
	else if(obj->lhs->type == "arr")
	{
		int cur = obj->lhs->expr->accept(it);
		if(itable.find(to_string(cur)+obj->lhs->name)==itable.end())
		{
			cout<<"Error: "<<obj->lhs->name<<"["<<cur<<"] not defined\n";
			return -1;
		}
		else
		{
			if(var_type[obj->lhs->name] != type)
			{
				cout << obj->lhs << " and " << obj->rhs <<" different in AssignExpr!\n";
				return -1;
			}
			itable[to_string(cur)+obj->lhs->name] = obj->rhs->accept(it);
		}
	}
	return 0;
}
int Interpreter::visit(class ContinueStmt* obj){
	return 0;
}


int Interpreter::visit(class ForStmt* obj){
	Interpreter *it = new Interpreter();
	obj->initial->accept(it);
	while(itable[obj->initial->var->name] <= obj->end_cond->accept(it))
	{
		obj->block->accept(it);
		itable[obj->initial->var->name] += 1;
	}
	return 0;
}

int Interpreter::visit(class ReturnStmt* obj){
	Interpreter *it = new Interpreter();
	
	if(obj->type == "normal")
		return 0;
	else if(obj->type == "expr")
		return obj->expr->accept(it);
}
int Interpreter::visit(class BreakStmt* obj){
	return 0;
}
