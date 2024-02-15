/*
 * Usage: (1) $ flex file-scanner.lex
 *        (2) $ gcc lex.yy.c -lfl
 *        (3) $ ./a.out < file1.star
*/

KEYWORDS (integer|read|display|if|else|then|while|for|to)
RELATIONAL (​<|​<=|​>​|>=|​==|​#)
ASSIGNMENT (=|\+=|\-=|\*=|\/=)
ARITHMETIC [+\-\*/%]
DIGITS [0-9]
ID [a-zA-Z_][a-zA-Z0-9_]*
SYMBOLS [​(​)​{​}​,​;]

%%
[ \t\n]+ ;

{KEYWORDS} { printf("%s : KEYWORD\n", yytext); }

{ID} { printf("%s : IDENTIFIER\n", yytext); }

{DIGITS} { printf("%s : NUMBER\n", yytext); }

{RELATIONAL} { printf("%s : RELATIONAL OPERATOR\n", yytext); }

{ASSIGNMENT} { printf("%s : ASSIGNMENT OPERATOR\n", yytext); }

{ARITHMETIC} { printf("%s : ARITHMETIC OPERATOR\n", yytext); }

{SYMBOLS} { printf("%s : SYMBOLS\n", yytext); }

. ;
%%

int main(int argc, char *argv[]) {
    if(argc > 1) { 
        FILE *fp = fopen(argv[1], "r");
        if(fp) yyin = fp;
    }
    yylex();
    return 0;
}
