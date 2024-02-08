/*
 * Usage: (1) $ flex scanner.lex
 *        (2) $ gcc lex.yy.c -lfl
 *        (3) $ ./a.out < file1.star
*/

KEYWORDS (integer|read|display|if|else|then|while|for|to)
RELATIONAL (​<|​<=|​>​|>=|​==|​#)
ARITHMETIC [+\-\*/%]
DIGITS [0-9]
SYMBOLS [​(​)​{​}​,​;]

%%
[ \n] ;

{KEYWORDS} {
    printf("%s : KEYWORD\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("%s : IDENTIFIER\n", yytext);
}

{DIGITS} {
    printf("%s : NUMBER\n", yytext);
}

{RELATIONAL} {
    printf("%s : RELATIONAL OPERATOR\n", yytext);
}

= {
    printf("%s : ASSIGNMENT OPERATOR\n", yytext);
}

{ARITHMETIC} {
    printf("%s : ARITHMETIC OPERATOR\n", yytext);
}

{SYMBOLS} {
    printf("%s : SYMBOLS\n", yytext);
}

. ;
%%

int main() {
    yylex();
    return 0;
}
