%{
#include <stdio.h>
#include "y.tab.h"

int yylex();
void yyerror(const char *s);
%}

%%
[0-9]+ { yylval.num = atoi(yytext);
         return (NUMBER);}
\n { return 0; }
[ \t]+ ;
. { return (yytext[0]); }
%%
