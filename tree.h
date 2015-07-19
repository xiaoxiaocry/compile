#include <stdlib.h>

struct Node{
	char* content;
	char* name;
	struct Node* lchild;
	struct Node* rchild;
	int line;
	int bl;
};

struct HashNode{
  char* type;
  char* name;
  char* kind;
  struct HashNode* Func;
  struct Size* arraysize;
  struct HashNode* next;
};
struct Args_TYPE{
	char *type;
	struct Args_TYPE* next;
};
struct Size{
  int size;
  struct Size* next;
  struct Size* prev;
};

struct Exp_TYPE{
	char* type;
	int array_dem;
	int line;
	int is_num;
	char* id;
};

struct Node* createNode(char* n,int l,char* c);

void be_lchild(struct Node *f,struct Node *s);
void be_rchild(struct Node *f,struct Node *s);

void printTree(struct Node* head,int n);
void CreatTable(struct HashNode* HashTable[],struct Node *head,int n);

void Op_ExtDefList(struct HashNode* HashTable[],struct Node *head);
void Op_ExtDef(struct HashNode* HashTable[],struct Node *head);
void Op_ExtDecList(struct HashNode* HashTable[],struct Node *head);
void Op_Specifier(struct HashNode* HashTable[],struct Node *head);
void Op_StructSpecifier(struct HashNode* HashTable[],struct Node *head);
char* Op_OptTag(struct HashNode* HashTable[],struct Node *head);
char* Op_Tag(struct HashNode* HashTable[],struct Node *head);
char* Op_VarDec(struct HashNode* HashTable[],struct Node *head);
char* Op_FunDec(struct HashNode* HashTable[],struct Node *head);
void Op_VarList(struct HashNode* HashTable[],struct Node *head);
void Op_ParameDec(struct HashNode* HashTable[],struct Node *head);
void Op_StmtList(struct HashNode* HashTable[],struct Node *head,char* s,int* sline);
void Op_CompSt(struct HashNode* HashTable[],struct Node *head,char* s,int* sline);
void Op_Stmt(struct HashNode* HashTable[],struct Node *head,char* s,int* sline);
void Op_DefList(struct HashNode* HashTable[],struct Node *head);
void Op_DecList(struct HashNode* HashTable[],struct Node *head);
void Op_Def(struct HashNode* HashTable[],struct Node *head);
void Op_Dec(struct HashNode* HashTable[],struct Node *head);
struct Exp_TYPE* Op_Exp(struct HashNode* HashTable[],struct Node *head);
struct Args_TYPE* Op_Args(struct HashNode* HashTable[],struct Node *head);


int is_exist(struct HashNode* HashTable[],char * name);
int is_exist_in_Func(struct HashNode* FuncNode,char* name);
void PrintHashTable(struct HashNode* HashTable[]);
int hash(char *name);;
