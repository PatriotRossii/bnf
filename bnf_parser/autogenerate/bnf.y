%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);

%}

%token T_ID T_LITERAL T_ASS T_OR T_LEFT T_RIGHT T_NEWLINE
%left T_ASS T_OR
%start grammar

%%

grammar: rule
	| grammar rule
;

rule:
	nonterminal T_ASS cases 

cases: case_list T_NEWLINE
	| case_list T_OR cases

case_list: nonterminal
	| nonterminal case_list
	| terminal
	| terminal case_list

nonterminal:
	T_LEFT T_ID T_RIGHT

terminal:
	T_LITERAL

%%

int main() {
	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
