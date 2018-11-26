%{
#include <bits/stdc++.h>
#include "programdef.h"
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
"boolean" { yylval.lit = strdup(yytext); return TYPE;}
"int" { yylval.lit = strdup(yytext); return TYPE;}
"return" { return RETURN;}
"for" { return FOR;}
"if" { return IF;}
"else" { return ELSE;}
"continue" { return CONTINUE;}
"break" { return BREAK;}
"true" { yylval.lit = strdup(yytext); return BOOLEAN;}
"false" { yylval.lit = strdup(yytext); return BOOLEAN;}
"callout" { return CALLOUT;}
"=" { yylval.lit = strdup(yytext);return EQ; }
"+=" { yylval.lit = strdup(yytext);return ADDEQ; }
"-=" { yylval.lit = strdup(yytext);return SUBEQ; }
"!" { yylval.lit = strdup(yytext); return NOT; }
"+" { yylval.lit = strdup(yytext); return ADD; }
"-" { yylval.lit = strdup(yytext); return SUB; }
"*" { yylval.lit = strdup(yytext); return MUL; }
"/" { yylval.lit = strdup(yytext); return DIV; }
"%" { yylval.lit = strdup(yytext); return MOD; }
"<" { yylval.lit = strdup(yytext); return LT; }
">" { yylval.lit = strdup(yytext); return GT; }
"<=" { yylval.lit = strdup(yytext);return LE; }
">=" { yylval.lit = strdup(yytext);return GE; }
"==" { yylval.lit = strdup(yytext);return EQUAL; }
"!=" { yylval.lit = strdup(yytext);return NOT_EQUAL; }
"&&" { yylval.lit = strdup(yytext);return COND_AND; }
"||" { yylval.lit = strdup(yytext);return COND_OR; }
"," { return COMMA; }
"{" { return OB; }
"}" { return CB; }
"[" { return OSB; }
"]" { return CSB; }
"(" { return OP; }
")" { return CP; }
";" { return SC; }
"0x"{hex_digit}+ { return INT_LIT;}
{digit}+ { return INT_LIT;}
{letter}{alpha}* { yylval.lit = strdup(yytext); return ID;}
{character} { yylval.lit = strdup(yytext); return CHAR; }
\"{string}*\" { yylval.lit = strdup(yytext); return STRING; }
{delim} 
"//".*
\n { ++line_no; }
%%