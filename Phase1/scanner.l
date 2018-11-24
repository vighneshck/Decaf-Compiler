%{
#include <bits/stdc++.h>
#include "parser.tab.hpp"
#define YY_DECL extern "C" int yylex()
using namespace std;
int line_no = 0;
%}
letter	[A-Za-z]
delim	[ \t]+
digit	[0-9]
alpha	[A-Za-z0-9]
char [ -~]
character   \'{char}\'
string (\\n|\\t|\\'|\\\\|\\\"|[^\\"'])
hex_digit [0-9a-fA-F]
%%
"class" { return CLASS; }
"void" { return VOID;}
"boolean" { return DTYPE;}
"int" { return DTYPE;}
"return" { return RETURN;}
"for" { return FOR;}
"if" { return IF;}
"else" { return ELSE;}
"continue" { return CONTINUE;}
"break" { return BREAK;}
"true" { return BOOL;}
"false" { return BOOL;}
"callout" { return CALLOUT;}
"=" { return EQ; }
"+=" { return ADDEQ; }
"-=" { return SUBEQ; }
"!" { return NOT; }
"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"%" { return MOD; }
"<" { return LT; }
">" { return GT; }
"<=" { return LE; }
">=" { return GE; }
"==" { return EQUAL; }
"!=" { return NOT_EQUAL; }
"&&" { return COND_AND; }
"||" { return COND_OR; }
"," { return COMMA; }
"{" { return OB; }
"}" { return CB; }
"[" { return OSB; }
"]" { return CSB; }
"(" { return OP; }
")" { return CP; }
";" { return SC; }
"0x"{hex_digit}+ { return INTEGER;}
{digit}+ { return INT_LIT;}
{letter}{alpha}* { return ID;}
{character} { return CHAR; }
\"{string}*\" { return STRING; }
{delim} 
"//".*
\n { ++line_no; }
%%