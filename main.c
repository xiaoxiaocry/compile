#include <stdio.h>
#include "syntax.tab.h"
extern struct Node* head;
extern int is_error;
int main (int argc,char** argv){
  if (argc <= 1)
      return 1;
  FILE* f = fopen (argv[1],"r");
  if(!f){
    perror(argv[1]);
    return 1;
  }
  yyrestart(f);
  yyparse(); 
  if(is_error==0){
	printTree(head,0);
	struct HashNode* Table[99];
	int k=0;
	for(;k<99;k++){
		Table[k]=NULL;
	}
	FILE *fp1=fopen("./test1.s","w");
	//struct InterCodes* codes1;
	//codes1=Translate_Program(Table,head);
	//Print_Codes(Translate_Program(Table,head),fp1);
	transform_codes(Translate_Program(Table,head),fp1);
	fclose(fp1);
 	//CreatTable(Table,head,0);
	//PrintHashTable(Table);
	//Op_Program(Table,head);
	}
  return 0;
}
