#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Operand_* Operand;


struct Array{
	char* name;
	struct Size* s;
};
struct Operand_{
	enum{VARIABLE,CONSTANT,ADDRESS,TEMP,LABEL,ARRAY,OP,CALL}kind;
	union{
		int var_no;//temp,constant
		char* value;
		struct Array* array;
	}u;
};

struct InterCode{
	enum{ASSIGN,ADD,SUB,MUL,DV,FUNCTION,PARAM,LAB,RETURNN,GOTO,DEC,ARG,If,READD,WRITEE,ASL,ASR}kind;
	union{
		struct {Operand right,left;} assign;//assign,dec
		struct {Operand result,op1,op2;}binop;
		Operand dirop;//return
		struct {Operand temp1,op,temp2,label;}If;
		//char* func;//function
		//char* name;//param
	}u;
};
struct InterCodes{struct InterCode code;struct InterCodes* prev,*next;};





int is_param(char* s);

struct Operand_* new_temp();
struct Operand_* new_label();

struct InterCodes* Translate_ExtDefList(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_ExtDef(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_ExtDecList(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_Specifier(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_StructSpecifier(struct HashNode* HashTable[],struct Node *head);
char* Translate_OptTag(struct HashNode* HashTable[],struct Node *head);
char* Translate_Tag(struct HashNode* HashTable[],struct Node *head);
struct Operand_* Translate_VarDec(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_FunDec(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_VarList(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_ParameDec(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_StmtList(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_CompSt(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_Stmt(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_DefList(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_DecList(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_Def(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_Dec(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_Exp(struct HashNode* HashTable[],struct Node *head,Operand place,int a);
struct InterCodes* Translate_Array(struct HashNode* HashTable[],struct Node *head,Operand place,struct Array* Array,int* sum,int v,struct InterCodes* tcode);
//struct InterCodes* Translate_Array_Exp(Operand place,struct Size *s);
struct InterCodes* Translate_Args(struct HashNode* HashTable[],struct Node *head);
struct InterCodes* Translate_Cond(struct Node *head,Operand label_true,Operand label_false,struct HashNode* HashTable[]);
int SearchArrayList(struct Array* array);


void Print_Codes(struct InterCodes* codes1,FILE *fp1);

struct InterCodes* combine_code(struct InterCodes* temp1,struct InterCodes* temp2);
