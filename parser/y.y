%{
#include <stdio.h>
int yylex();
void yyerror(const char *s);
%}

%union{
int num;
}

%token <num>NUMBER
%left '+' '-'
%left '*' '/'
%type <num>AE
%type <num>E

%%
AE:E { printf("The result is %d\n", $$); }
E: E '+' E { $$ = $1 + $3; }
E: E '-' E { $$ = $1 - $3; }
E: E '*' E { $$ = $1 * $3; }
E: E '/' E { $$ = $1 / $3; }
E: NUMBER { $$ = $1; }
%%

int main(void)
{
 yyparse();
 return 0;
}

void yyerror(const char *s)
{
 printf("Error: %s", s);
}
