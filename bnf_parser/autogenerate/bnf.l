%option noyywrap

%{

#include <stdio.h>

#define YY_DECL int yylex()

#include "bnf.tab.h"

%}

%%

[ \t]		;	// ignore all whitespace
[a-z][a-z0-9]*		{ return T_ID; }
\n			{ return T_NEWLINE; }
"::="		{ return T_ASS; }
"|"			{ return T_OR; }
"<"			{ return T_LEFT; }
">"			{ return T_RIGHT; }
