/* Regex */

id      [a-zA-Z_][a-zA-Z0-9_\.]+
intlit	([0-9][0-9'_]*|0[xX][0-9a-fA-F_']+|0o[0-7_']+)[ulUL]*


%{
#include "intarith.h"
%}

%option reentrant
%option bison-bridge

%%

start	printf("Start command received\n");
stop	printf("Stop command received\n");
[ \t\r] { }
[\n]    printf("%d\t%s", yylineno++, yytext);

%%
/* Routines */

int yywrap(yyscan_t yyscanner)
{
    return 1;
}

