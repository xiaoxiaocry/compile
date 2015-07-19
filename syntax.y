%{
 // #include <stdio.h>
  #include "lex.yy.c" 
  #include "transform.h"
  struct Node* head;
  int is_error = 0;
  char * err;
%}

%union{
   char* type_string;
   struct Node* type_Node;
}
%token <type_string> INT
%token <type_string> FLOAT ID TYPE RELOP  
%token ASSIGNOP OR AND  READ WRITE PLUS MINUS STAR DIV NOT LP RP LB RB DOT STRUCT IF ELSE WHILE RETURN SEMI LC RC COMMA

%type <type_Node> Program ExtDefList ExtDef Specifier StructSpecifier OptTag Tag VarDec ExtDecList FunDec VarList CompSt Args
%type <type_Node>  ParamDec StmtList Stmt DefList Def DecList Dec Exp 

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB DOT
%nonassoc STRUCT
%nonassoc READ
%nonassoc WRITE
%nonassoc IF
%nonassoc ELSE
%nonassoc WHILE
%nonassoc RETURN
%nonassoc SEMI
%nonassoc TYPE
%nonassoc ID
%nonassoc LC RC
%nonassoc COMMA
%%
Program : ExtDefList 			{$$=createNode("Program",@1.first_line,NULL);head=$$;be_lchild($$,$1);}
;
ExtDefList : ExtDef ExtDefList	 	{$$=createNode("ExtDefList",@1.first_line,NULL);be_lchild($$,$1);if($2->line!=0) be_rchild($1,$2);}
	| /* empty */			{$$=createNode("ExtDefList",0,NULL);}
;
ExtDef : Specifier ExtDecList SEMI 	{$$=createNode("ExtDef",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,$2);be_rchild($2,createNode("SEMI",0,NULL));}
	| Specifier SEMI		{$$=createNode("ExtDef",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("SEMI",0,NULL));}
	| Specifier FunDec CompSt 	{$$=createNode("ExtDef",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,$2);be_rchild($2,$3);}
	
;
ExtDecList : VarDec 			{$$=createNode("ExtDecList",@1.first_line,NULL);be_lchild($$,$1);}
	| VarDec COMMA ExtDecList 	{$$=createNode("ExtDecList",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("COMMA",0,NULL));be_rchild($1->rchild,$3);}
;
Specifier : TYPE 			{$$=createNode("Specifier",@1.first_line,NULL);be_lchild($$,createNode("TYPE",0,$1));}
	| StructSpecifier 		{$$=createNode("Specifier",@1.first_line,NULL);be_lchild($$,$1);}
;
StructSpecifier : STRUCT OptTag LC DefList RC {$$=createNode("StructSpecifier",@1.first_line,NULL);be_lchild($$,createNode("STRUCT",0,NULL));be_rchild($$->lchild,$2);be_rchild($2,createNode("LC",0,NULL));be_rchild($2->rchild,$4);be_rchild($4,createNode("RC",0,NULL));}
	| STRUCT Tag 			{$$=createNode("StructSpecifier",@1.first_line,NULL);be_lchild($$,createNode("STRUCT",0,NULL));be_rchild($$->lchild,$2);}

;
OptTag : ID 				{$$=createNode("OptTag",@1.first_line,NULL);be_lchild($$,createNode("ID",0,$1));}
	| /* empty */			{$$=createNode("OptTag",0,NULL);}
;
Tag : ID				{$$=createNode("Tag",@1.first_line,NULL);be_lchild($$,createNode("ID",0,$1));}
;
VarDec : ID 				{$$=createNode("VarDec",@1.first_line,NULL);be_lchild($$,createNode("ID",0,$1));}
	| VarDec LB INT RB 		{$$=createNode("VarDec",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("LB",0,NULL));be_rchild($1->rchild,createNode("INT",0,$3));be_rchild($1->rchild->rchild,createNode("RB",0,NULL));}
	| VarDec LB error RB   	{}
;
FunDec : ID LP VarList RP 		{$$=createNode("FunDec",@1.first_line,NULL);be_lchild($$,createNode("ID",0,$1));be_rchild($$->lchild,createNode("LP",0,NULL));be_rchild($$->lchild->rchild,$3);be_rchild($3,createNode("RP",0,NULL));}
	| ID LP RP 			{$$=createNode("FunDec",@1.first_line,NULL);be_lchild($$,createNode("ID",0,$1));be_rchild($$->lchild,createNode("LP",0,NULL));be_rchild($$->lchild->rchild,createNode("RP",0,NULL));}
	| ID error RP {}
	
;
VarList : ParamDec COMMA VarList 	{$$=createNode("VarList",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("COMMA",0,NULL));be_rchild($1->rchild,$3);}
	| ParamDec 			{$$=createNode("VarList",@1.first_line,NULL);be_lchild($$,$1);}
;
ParamDec : Specifier VarDec 		{$$=createNode("ParamDec",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,$2);}
;
CompSt : LC DefList StmtList RC 	{$$=createNode("CompSt",@1.first_line,NULL);be_lchild($$,createNode("LC",0,NULL));be_rchild($$->lchild,$2);be_rchild($2,$3);be_rchild($3,createNode("RC",0,NULL));}

	
;
StmtList : Stmt StmtList 		{$$=createNode("StmtList",@1.first_line,NULL);be_lchild($$,$1);if($2->line!=0) be_rchild($1,$2);}
	| /* empty */			{$$=createNode("StmtList",0,NULL);}
;
Stmt : Exp SEMI 			{$$=createNode("Stmt",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("SEMI",0,NULL));}
	| CompSt			{$$=createNode("Stmt",@1.first_line,NULL);be_lchild($$,$1);}
	| RETURN Exp SEMI 		{$$=createNode("Stmt",@1.first_line,NULL);be_lchild($$,createNode("RETURN",@1.first_line,NULL));be_rchild($$->lchild,$2);be_rchild($2,createNode("SEMI",0,NULL));}
	| IF LP Exp RP Stmt 		{$$=createNode("Stmt",@1.first_line,NULL);be_lchild($$,createNode("IF",0,NULL));be_rchild($$->lchild,createNode("LP",0,NULL));be_rchild($$->lchild->rchild,$3);be_rchild($3,createNode("RP",0,NULL));be_rchild($3->rchild,$5);}
	| IF LP Exp RP Stmt ELSE Stmt 	{$$=createNode("Stmt",@1.first_line,NULL);be_lchild($$,createNode("IF",0,NULL));be_rchild($$->lchild,createNode("LP",0,NULL));be_rchild($$->lchild->rchild,$3);be_rchild($3,createNode("RP",0,NULL));be_rchild($3->rchild,$5);be_rchild($5,createNode("ELSE",0,NULL));be_rchild($5->rchild,$7);}
	| WHILE LP Exp RP Stmt 		{$$=createNode("Stmt",@1.first_line,NULL);be_lchild($$,createNode("WHILE",0,NULL));be_rchild($$->lchild,createNode("LP",0,NULL));be_rchild($$->lchild->rchild,$3);be_rchild($3,createNode("RP",0,NULL));be_rchild($3->rchild,$5);}
	| Exp error SEMI  {}
	| RETURN error SEMI {}
;
DefList : Def DefList 			{$$=createNode("DefList",@1.first_line,NULL);be_lchild($$,$1);if($2->line!=0) be_rchild($1,$2);}

	| /* empty */			{$$=createNode("DefList",0,NULL);}
;
Def : Specifier DecList SEMI 		{$$=createNode("Def",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,$2);be_rchild($2,createNode("SEMI",0,NULL));}
	|Specifier DecList error SEMI {}
	
;
DecList : Dec 				{$$=createNode("DecList",@1.first_line,NULL);be_lchild($$,$1);}
	| Dec COMMA DecList 		{$$=createNode("DecList",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("COMMA",0,NULL));be_rchild($1->rchild,$3);}
;
Dec : VarDec 				{$$=createNode("Dec",@1.first_line,NULL);be_lchild($$,$1);}
	| VarDec ASSIGNOP Exp 		{$$=createNode("Dec",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("ASSIGNOP",0,NULL));be_rchild($1->rchild,$3);}
;
Exp : Exp ASSIGNOP Exp 			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("ASSIGNOP",0,NULL));be_rchild($1->rchild,$3);}
	| Exp AND Exp 			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("AND",0,NULL));be_rchild($1->rchild,$3);}
	| Exp OR Exp			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("OR",0,NULL));be_rchild($1->rchild,$3);}
	| Exp RELOP Exp 		{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("RELOP",0,$2));be_rchild($1->rchild,$3);}
	| Exp PLUS Exp 			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("PLUS",0,NULL));be_rchild($1->rchild,$3);}
	| Exp MINUS Exp 		{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("MINUS",0,NULL));be_rchild($1->rchild,$3);}
	| Exp STAR Exp 			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("STAR",0,NULL));be_rchild($1->rchild,$3);}
	| Exp DIV Exp 			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("DIV",0,NULL));be_rchild($1->rchild,$3);}
	| LP Exp RP 			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,createNode("LP",0,NULL));be_rchild($$->lchild,$2);be_rchild($2,createNode("RP",0,NULL));}
	| MINUS Exp 			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,createNode("MINUS",0,NULL));be_rchild($$->lchild,$2);}
	| NOT Exp 			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,createNode("NOT",0,NULL));be_rchild($$->lchild,$2);}
	| READ LP RP  			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,createNode("READ",0,NULL));be_rchild($$->lchild,createNode("LP",0,NULL));be_rchild($$->lchild->rchild,createNode("RP",0,NULL));}
	| WRITE LP Exp RP		{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,createNode("WRITE",0,NULL));be_rchild($$->lchild,createNode("LP",0,NULL));be_rchild($$->lchild->rchild,$3);be_rchild($$->lchild->rchild->rchild,createNode("RP",0,NULL));}
	| ID LP Args RP 		{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,createNode("ID",0,$1));be_rchild($$->lchild,createNode("LP",0,NULL));be_rchild($$->lchild->rchild,$3);be_rchild($3,createNode("RP",0,NULL));}
	| ID LP RP  			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,createNode("ID",0,$1));be_rchild($$->lchild,createNode("LP",0,NULL));be_rchild($$->lchild->rchild,createNode("RP",0,NULL));}
	| Exp LB Exp RB 		{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("LB",0,NULL));be_rchild($1->rchild,$3);be_rchild($3,createNode("RB",0,NULL));}
	| Exp DOT ID 			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("DOT",0,NULL));be_rchild($1->rchild,createNode("ID",0,$3));}
	| ID 				{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,createNode("ID",0,$1));}
	| INT 				{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,createNode("INT",0,$1));}
	| FLOAT 			{$$=createNode("Exp",@1.first_line,NULL);be_lchild($$,createNode("FLOAT",0,$1));}
	| Exp LB error RB	{yyerror("Missing \"]\";");}
	| ID LP error RP {}
;

Args : Exp COMMA Args			{$$=createNode("Args",@1.first_line,NULL);be_lchild($$,$1);be_rchild($1,createNode("COMMA",0,NULL));be_rchild($1->rchild,$3);}
	| Exp				{$$=createNode("Args",@1.first_line,NULL);be_lchild($$,$1);}
;
%%
yyerror(char* msg) {
is_error=1;
fprintf(stderr, "Error type B at Line %d: %s\n",yylineno,msg);
}


