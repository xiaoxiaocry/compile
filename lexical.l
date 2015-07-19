%{
#include "syntax.tab.h"
#include <string.h>
extern  int is_error;
//int lines=1;
int yycolumn = 1;

#define YY_USER_ACTION \
yylloc.first_line = yylloc.last_line = yylineno; \
yylloc.first_column = yycolumn; \
yylloc.last_column = yycolumn + yyleng - 1; \
yycolumn += yyleng;
%}
%option yylineno
digit [0-9]
letter [_a-zA-Z]
%%
; {return SEMI;}
, {return COMMA;}
= {return ASSIGNOP;}
>|<|>=|<=|==|!= {yylval.type_string=(char *)malloc(strlen(yytext));strcpy(yylval.type_string,yytext);return RELOP;}
\+ {return PLUS;}
- {return MINUS;}
\* {return STAR;}
\/ {return DIV;}
&& {return AND;}
\|\| {return OR;}
\. {return DOT;}
! {return NOT;}
\( {return LP;}
\) {return RP;}
\[ {return LB;}
\] {return RB;}
\{ {return LC;}
\} {return RC;}
struct {return STRUCT;}
return {return RETURN;}
read {return READ;}
write {return WRITE;}
if {return IF;}
else {return ELSE;}
while {return WHILE;}
int {yylval.type_string="INT";return TYPE;}
float {yylval.type_string="FLOAT";return TYPE;}
([1-9]{digit}*)|0 {yylval.type_string=(char *)malloc(strlen(yytext));strcpy(yylval.type_string,yytext);return INT;}
((([1-9]{digit}*)|0)?(\.){digit}+)|(((([1-9]{digit}*)|0)?(\.)?{digit}+)e[\+\-]?([1-9]{digit}*)|0) {yylval.type_string=(char *)malloc(strlen(yytext));strcpy(yylval.type_string,yytext);return FLOAT;}
{letter}({digit}|{letter})* {yylval.type_string=(char *)malloc(strlen(yytext));strcpy(yylval.type_string,yytext);return ID;}
\  {}
\n {yycolumn=1;}
. {printf("Error type A at Line %d: Mysterious characters \'%s\'\n",yylineno,yytext);is_error=1;}
%%
/*int main (int argc,char** argv){
  if(argc>1){
    if(!(yyin=fopen(argv[1],"r"))){
      perror(argv[1]);
      return 1;
    }
  }
  while(yylex()!=0);
  return 0;
}*/
