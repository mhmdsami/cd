/* 
 * Example Scanner: 
 * Description: Count the number of characters and the number of lines 
 *              from standard input
 * Usage: (1) $ flex sample2.lex
 *        (2) $ gcc lex.yy.c -lfl
 *        (3) $ ./a.out
 *            stdin> whatever you like
 *	      stdin> Ctrl-D
 * Example from http://alumni.cs.ucr.edu/~lgao/teaching/flex/sample2.lex
 * This is a basic example for flex program
 */

	int num_lines = 0, num_chars = 0;

%%
\n	++num_lines; ++num_chars;
.	++num_chars;
%%

int main()
{
  yylex();
  printf("# of lines = %d, # of chars = %d\n", num_lines, num_chars);
}
