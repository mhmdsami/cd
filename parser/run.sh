yacc -d y.y
flex scanner.lex
gcc lex.yy.c y.tab.c -lfl -o parser.out
./parser.out