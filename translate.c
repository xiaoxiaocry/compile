
#include "translate.h"







int count_temp=0;
int count_label=0;
struct Array* paramlist[99];
int paramnum=0;
struct Array* arraylist[99];
int arraynum=0;
int is_param(char* s){
	int i;
	for(i=0;i<paramnum;i++){
		if(strcmp(s,paramlist[i]->name)==0)
			return 1;
	}
	return 0;
}







struct Operand_* new_temp(){
	struct Operand_* temp = (struct Operand_*)malloc(sizeof(struct Operand_));
	temp->kind=TEMP;
	temp->u.var_no=count_temp++;

	return temp;
}
struct Operand_* new_label(){
	struct Operand_* label = (struct Operand_*)malloc(sizeof(struct Operand_));
	label->kind=LABEL;
	label->u.var_no=count_label++;
	
	return label;
}

	




void Print_Codes(struct InterCodes* codes1,FILE *fp1){
	if(codes1==NULL)
		exit(0);
	else{
		struct InterCode ic=codes1->code;
		if(ic.kind==ASSIGN){
			struct Operand_* temp1=ic.u.assign.left;
			struct Operand_* temp2=ic.u.assign.right;
			if(temp1->kind==TEMP){
				printf("%s%d","t",temp1->u.var_no);
				fprintf(fp1,"%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				printf("%s%d","#",temp1->u.var_no);
				fprintf(fp1,"%s%d","#",temp1->u.var_no);
			}
			if(temp1->kind==ADDRESS){
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);

			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
			printf(" := ");
			fprintf(fp1," := ");
			if(temp2->kind==TEMP){
				printf("%s%d","t",temp2->u.var_no);
				fprintf(fp1,"%s%d","t",temp2->u.var_no);
			}
			if(temp2->kind==VARIABLE){
				printf("%s",temp2->u.value);
				fprintf(fp1,"%s",temp2->u.value);
			}
			if(temp2->kind==CONSTANT){
				printf("%s%d","#",temp2->u.var_no);
				fprintf(fp1,"%s%d","#",temp2->u.var_no);
			}
			if(temp2->kind==ADDRESS){
				printf("*t%d",temp2->u.var_no);
				fprintf(fp1,"*t%d",temp2->u.var_no);
			}
			if(temp2->kind==CALL){
				printf("CALL %s",temp2->u.value);
				fprintf(fp1,"CALL %s",temp2->u.value);
			}
			if(temp2->kind==ARRAY){
				printf("&%s",temp2->u.value);
				fprintf(fp1,"&%s",temp2->u.value);
			}
		}
		if(ic.kind==ASL){
			struct Operand_* temp1=ic.u.assign.left;
			struct Operand_* temp2=ic.u.assign.right;
			if(temp1->kind==TEMP){
				printf("*%s%d","t",temp1->u.var_no);
				fprintf(fp1,"*%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				printf("*%s",temp1->u.value);
				fprintf(fp1,"*%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				printf("%s%d","#",temp1->u.var_no);
				fprintf(fp1,"%s%d","#",temp1->u.var_no);
			}
			if(temp1->kind==ADDRESS){
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);

			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
			printf(" := ");
			fprintf(fp1," := ");
			if(temp2->kind==TEMP){
				printf("%s%d","t",temp2->u.var_no);
				fprintf(fp1,"%s%d","t",temp2->u.var_no);
			}
			if(temp2->kind==VARIABLE){
				printf("%s",temp2->u.value);
				fprintf(fp1,"%s",temp2->u.value);
			}
			if(temp2->kind==CONSTANT){
				printf("%s%d","#",temp2->u.var_no);
				fprintf(fp1,"%s%d","#",temp2->u.var_no);
			}
			if(temp2->kind==ADDRESS){
				printf("*t%d",temp2->u.var_no);
				fprintf(fp1,"*t%d",temp2->u.var_no);
			}
			if(temp2->kind==CALL){
				printf("CALL %s",temp2->u.value);
				fprintf(fp1,"CALL %s",temp2->u.value);
			}
			if(temp2->kind==ARRAY){
				printf("&%s",temp2->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
		}
		if(ic.kind==ASR){
			struct Operand_* temp1=ic.u.assign.left;
			struct Operand_* temp2=ic.u.assign.right;
			if(temp1->kind==TEMP){
				printf("%s%d","t",temp1->u.var_no);
				fprintf(fp1,"%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				printf("%s%d","#",temp1->u.var_no);
				fprintf(fp1,"%s%d","#",temp1->u.var_no);
			}
			if(temp1->kind==ADDRESS){
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);

			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
			printf(" := ");
			fprintf(fp1," := ");
			if(temp2->kind==TEMP){
				printf("*%s%d","t",temp2->u.var_no);
				fprintf(fp1,"*%s%d","t",temp2->u.var_no);
			}
			if(temp2->kind==VARIABLE){
				printf("*%s",temp2->u.value);
				fprintf(fp1,"*%s",temp2->u.value);
			}
			if(temp2->kind==CONSTANT){
				printf("%s%d","#",temp2->u.var_no);
				fprintf(fp1,"%s%d","#",temp2->u.var_no);
			}
			if(temp2->kind==ADDRESS){
				printf("*t%d",temp2->u.var_no);
				fprintf(fp1,"*t%d",temp2->u.var_no);
			}
			if(temp2->kind==CALL){
				printf("CALL %s",temp2->u.value);
				fprintf(fp1,"CALL %s",temp2->u.value);
			}
			if(temp2->kind==ARRAY){
				printf("&%s",temp2->u.value);
				fprintf(fp1,"&%s",temp2->u.value);
			}
		}
		if(ic.kind==ADD){
			struct Operand_* temp1=ic.u.binop.op1;
			struct Operand_* temp2=ic.u.binop.op2;
			struct Operand_* temp0=ic.u.binop.result;
			if(temp0->kind==TEMP){
				printf("%s%d","t",temp0->u.var_no);
				fprintf(fp1,"%s%d","t",temp0->u.var_no);
			}
			if(temp0->kind==VARIABLE){
				printf("%s",temp0->u.value);
				fprintf(fp1,"%s",temp0->u.value);
			}
			if(temp0->kind==CONSTANT){
				printf("%s%d","#",temp0->u.var_no);
				fprintf(fp1,"%s%d","#",temp0->u.var_no);
			}
			if(temp0->kind==ADDRESS){
				printf("*t%d",temp0->u.var_no);
				fprintf(fp1,"*t%d",temp0->u.var_no);
			}
			if(temp0->kind==ARRAY){
				printf("&%s",temp0->u.value);
				fprintf(fp1,"&%s",temp0->u.value);
			}
			printf(" := ");
			fprintf(fp1," := ");
			if(temp1->kind==TEMP){
				printf("%s%d","t",temp1->u.var_no);
				fprintf(fp1,"%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				printf("%s%d","#",temp1->u.var_no);
				fprintf(fp1,"%s%d","#",temp1->u.var_no);
			}
			if(temp1->kind==ADDRESS){
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);
			}
			if(temp1->kind==CALL){
				printf("CALL %s",temp1->u.value);
				fprintf(fp1,"CALL %s",temp1->u.value);
			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
			printf(" + ");
			fprintf(fp1," + ");
			if(temp2->kind==TEMP){
				printf("%s%d","t",temp2->u.var_no);
				fprintf(fp1,"%s%d","t",temp2->u.var_no);
			}
			if(temp2->kind==VARIABLE){
				printf("%s",temp2->u.value);
				fprintf(fp1,"%s",temp2->u.value);
			}
			if(temp2->kind==CONSTANT){
				printf("%s%d","#",temp2->u.var_no);
				fprintf(fp1,"%s%d","#",temp2->u.var_no);
			}
			if(temp2->kind==ADDRESS){
				printf("*t%d",temp2->u.var_no);
				fprintf(fp1,"*t%d",temp2->u.var_no);
			}
			if(temp2->kind==CALL){
				printf("CALL %s",temp2->u.value);
				fprintf(fp1,"CALL %s",temp2->u.value);
			}
			if(temp2->kind==ARRAY){
				printf("&%s",temp2->u.value);
				fprintf(fp1,"&%s",temp2->u.value);
			}
		}
		if(ic.kind==SUB){
			struct Operand_* temp1=ic.u.binop.op1;
			struct Operand_* temp2=ic.u.binop.op2;
			struct Operand_* temp0=ic.u.binop.result;
			if(temp0->kind==TEMP){
				printf("%s%d","t",temp0->u.var_no);
				fprintf(fp1,"%s%d","t",temp0->u.var_no);
			}
			if(temp0->kind==VARIABLE){
				printf("%s",temp0->u.value);
				fprintf(fp1,"%s",temp0->u.value);
			}
			if(temp0->kind==CONSTANT){
				printf("%s%d","#",temp0->u.var_no);
				fprintf(fp1,"%s%d","#",temp0->u.var_no);
			}
			if(temp0->kind==ADDRESS){
				printf("*t%d",temp0->u.var_no);
				fprintf(fp1,"*t%d",temp0->u.var_no);
			}
			if(temp0->kind==ARRAY){
				printf("&%s",temp0->u.value);
				fprintf(fp1,"&%s",temp0->u.value);
			}
			printf(" := ");
			fprintf(fp1," := ");
			if(temp1->kind==TEMP){
				printf("%s%d","t",temp1->u.var_no);
				fprintf(fp1,"%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				printf("%s%d","#",temp1->u.var_no);
				fprintf(fp1,"%s%d","#",temp1->u.var_no);
			}
			if(temp1->kind==ADDRESS){
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);
			}
			if(temp1->kind==CALL){
				printf("CALL %s",temp1->u.value);
				fprintf(fp1,"CALL %s",temp1->u.value);
			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
			printf(" - ");
			fprintf(fp1," - ");
			if(temp2->kind==TEMP){
				printf("%s%d","t",temp2->u.var_no);
				fprintf(fp1,"%s%d","t",temp2->u.var_no);
			}
			if(temp2->kind==VARIABLE){
				printf("%s",temp2->u.value);
				fprintf(fp1,"%s",temp2->u.value);
			}
			if(temp2->kind==CONSTANT){
				printf("%s%d","#",temp2->u.var_no);
				fprintf(fp1,"%s%d","#",temp2->u.var_no);
			}
			if(temp2->kind==ADDRESS){
				printf("*t%d",temp2->u.var_no);
				fprintf(fp1,"*t%d",temp2->u.var_no);
			}
			if(temp2->kind==CALL){
				printf("CALL %s",temp2->u.value);
				fprintf(fp1,"CALL %s",temp2->u.value);
			}
			if(temp2->kind==ARRAY){
				printf("&%s",temp2->u.value);
				fprintf(fp1,"&%s",temp2->u.value);
			}
		}
		if(ic.kind==MUL){
			struct Operand_* temp1=ic.u.binop.op1;
			struct Operand_* temp2=ic.u.binop.op2;
			struct Operand_* temp0=ic.u.binop.result;
			if(temp0->kind==TEMP){
				printf("%s%d","t",temp0->u.var_no);
				fprintf(fp1,"%s%d","t",temp0->u.var_no);
			}
			if(temp0->kind==VARIABLE){
				printf("%s",temp0->u.value);
				fprintf(fp1,"%s",temp0->u.value);
			}
			if(temp0->kind==CONSTANT){
				printf("%s%d","#",temp0->u.var_no);
				fprintf(fp1,"%s%d","#",temp0->u.var_no);
			}
			if(temp0->kind==ADDRESS){
				printf("*t%d",temp0->u.var_no);
				fprintf(fp1,"*t%d",temp0->u.var_no);
			}
			if(temp0->kind==ARRAY){
				printf("&%s",temp0->u.value);
				fprintf(fp1,"&%s",temp0->u.value);
			}
			printf(" := ");
			fprintf(fp1," := ");
			if(temp1->kind==TEMP){
				printf("%s%d","t",temp1->u.var_no);
				fprintf(fp1,"%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				printf("%s%d","#",temp1->u.var_no);
				fprintf(fp1,"%s%d","#",temp1->u.var_no);
			}
			if(temp1->kind==ADDRESS){
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);
			}
			if(temp1->kind==CALL){
				printf("CALL %s",temp1->u.value);
				fprintf(fp1,"CALL %s",temp1->u.value);
			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
			printf(" * ");
			fprintf(fp1," * ");
			if(temp2->kind==TEMP){
				printf("%s%d","t",temp2->u.var_no);
				fprintf(fp1,"%s%d","t",temp2->u.var_no);
			}
			if(temp2->kind==VARIABLE){
				printf("%s",temp2->u.value);
				fprintf(fp1,"%s",temp2->u.value);
			}
			if(temp2->kind==CONSTANT){
				printf("%s%d","#",temp2->u.var_no);
				fprintf(fp1,"%s%d","#",temp2->u.var_no);
			}
			if(temp2->kind==ADDRESS){
				printf("*t%d",temp2->u.var_no);
				fprintf(fp1,"*t%d",temp2->u.var_no);
			}
			if(temp2->kind==CALL){
				printf("CALL %s",temp2->u.value);
				fprintf(fp1,"CALL %s",temp2->u.value);
			}
			if(temp2->kind==ARRAY){
				printf("&%s",temp2->u.value);
				fprintf(fp1,"&%s",temp2->u.value);
			}
		}
		if(ic.kind==DV){
			struct Operand_* temp1=ic.u.binop.op1;
			struct Operand_* temp2=ic.u.binop.op2;
			struct Operand_* temp0=ic.u.binop.result;
			if(temp0->kind==TEMP){
				printf("%s%d","t",temp0->u.var_no);
				fprintf(fp1,"%s%d","t",temp0->u.var_no);
			}
			if(temp0->kind==VARIABLE){
				printf("%s",temp0->u.value);
				fprintf(fp1,"%s",temp0->u.value);
			}
			if(temp0->kind==CONSTANT){
				printf("%s%d","#",temp0->u.var_no);
				fprintf(fp1,"%s%d","#",temp0->u.var_no);
			}
			if(temp0->kind==ADDRESS){
				printf("*t%d",temp0->u.var_no);
				fprintf(fp1,"*t%d",temp0->u.var_no);
			}
			if(temp0->kind==ARRAY){
				printf("&%s",temp0->u.value);
				fprintf(fp1,"&%s",temp0->u.value);
			}
			printf(" := ");
			fprintf(fp1," := ");
			if(temp1->kind==TEMP){
				printf("%s%d","t",temp1->u.var_no);
				fprintf(fp1,"%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				printf("%s%d","#",temp1->u.var_no);
				fprintf(fp1,"%s%d","#",temp1->u.var_no);
			}
			if(temp1->kind==ADDRESS){
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);
			}
			if(temp1->kind==CALL){
				printf("CALL %s",temp1->u.value);
				fprintf(fp1,"CALL %s",temp1->u.value);
			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
			printf(" / ");
			fprintf(fp1," / ");
			if(temp2->kind==TEMP){
				printf("%s%d","t",temp2->u.var_no);
				fprintf(fp1,"%s%d","t",temp2->u.var_no);
			}
			if(temp2->kind==VARIABLE){
				printf("%s",temp2->u.value);
				fprintf(fp1,"%s",temp2->u.value);
			}
			if(temp2->kind==CONSTANT){
				printf("%s%d","#",temp2->u.var_no);
				fprintf(fp1,"%s%d","#",temp2->u.var_no);
			}
			if(temp2->kind==ADDRESS){
				printf("*t%d",temp2->u.var_no);
				fprintf(fp1,"*t%d",temp2->u.var_no);
			}
			if(temp2->kind==CALL){
				printf("CALL %s",temp2->u.value);
				fprintf(fp1,"CALL %s",temp2->u.value);
			}
			if(temp2->kind==ARRAY){
				printf("&%s",temp2->u.value);
				fprintf(fp1,"&%s",temp2->u.value);
			}
		}
		if(ic.kind==READD){
			struct Operand_* temp1;
			temp1=ic.u.dirop;
			printf("READ ");
			fprintf(fp1,"READ ");
			if(temp1->kind==TEMP){
				printf("%s%d","t",temp1->u.var_no);
				fprintf(fp1,"%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				printf("%s%d","#",temp1->u.var_no);
				fprintf(fp1,"%s%d","#",temp1->u.var_no);
			}
			if(temp1->kind==ADDRESS){
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);
			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
		}
		if(ic.kind==WRITEE){
			struct Operand_* temp1;
			temp1=ic.u.dirop;
			printf("WRITE ");
			fprintf(fp1,"WRITE ");
			if(temp1->kind==TEMP){
				printf("%s%d","t",temp1->u.var_no);
				fprintf(fp1,"%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				printf("%s%d","#",temp1->u.var_no);
				fprintf(fp1,"%s%d","#",temp1->u.var_no);
			}
			if(temp1->kind==ADDRESS){
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);
			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
		}
		if(ic.kind==FUNCTION){
			struct Operand_* temp1;
			temp1=ic.u.dirop;
			printf("FUNCTION ");
			fprintf(fp1,"FUNCTION ");
			printf("%s :",temp1->u.value);
			fprintf(fp1,"%s :",temp1->u.value);
		}
		if(ic.kind==PARAM){
			struct Operand_* temp1;
			temp1=ic.u.dirop;
			printf("PARAM ");
			fprintf(fp1,"PARAM ");
			if(temp1->kind==VARIABLE){
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			else{
				printf("%s",temp1->u.array->name);
				fprintf(fp1,"%s",temp1->u.array->name);
			}
		}
		if(ic.kind==LAB){
			struct Operand_* temp1;
			temp1=ic.u.dirop;
			printf("LABEL label");
			fprintf(fp1,"LABEL label");
			printf("%d :",temp1->u.var_no);
			fprintf(fp1,"%d :",temp1->u.var_no);
		}
		if(ic.kind==RETURNN){
			struct Operand_* temp1;
			temp1=ic.u.dirop;
			printf("RETURN ");
			fprintf(fp1,"RETURN ");
			if(temp1->kind==TEMP){
				//printf("1\n");
				printf("%s%d","t",temp1->u.var_no);
				fprintf(fp1,"%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				//printf("2\n");
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				//printf("3\n");
				printf("%s","#");
				fprintf(fp1,"%s","#");
				printf("%d",temp1->u.var_no);
				fprintf(fp1,"%d",temp1->u.var_no);
			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
			if(temp1->kind==ADDRESS){
				//printf("4\n");
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);
			}
			if(temp1->kind==CALL){
				//printf("5\n");
				printf("CALL %s",temp1->u.value);
				fprintf(fp1,"CALL %s",temp1->u.value);
			}
		}
		if(ic.kind==GOTO){
			struct Operand_* temp1;
			temp1=ic.u.dirop;
			printf("GOTO label");
			fprintf(fp1,"GOTO label");
			printf("%d",temp1->u.var_no);
			fprintf(fp1,"%d",temp1->u.var_no);
			
		}
		if(ic.kind==DEC){
			struct Operand_* temp1=ic.u.assign.left;
			struct Operand_* temp2=ic.u.assign.right;
			printf("DEC  ");
			fprintf(fp1,"DEC  ");
			printf("%s ",temp1->u.value);
			fprintf(fp1,"%s ",temp1->u.value);
			printf("%d",temp2->u.var_no);
			fprintf(fp1,"%d",temp2->u.var_no);
		}
		if(ic.kind==ARG){
			struct Operand_* temp1=ic.u.dirop;
			printf("ARG ");
			fprintf(fp1,"ARG ");
			if(temp1->kind==TEMP){
				printf("%s%d","t",temp1->u.var_no);
				fprintf(fp1,"%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				printf("%s%d","#",temp1->u.var_no);
				fprintf(fp1,"%s%d","#",temp1->u.var_no);
			}
			if(temp1->kind==ADDRESS){
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);
			}
			if(temp1->kind==CALL){
				printf("CALL %s",temp1->u.value);
				fprintf(fp1,"CALL %s",temp1->u.value);
			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
			
		}
		if(ic.kind==If){
			struct Operand_* temp1=ic.u.If.temp1;
			struct Operand_* temp2=ic.u.If.op;
			struct Operand_* temp3=ic.u.If.temp2;
			struct Operand_* temp4=ic.u.If.label;
			printf("IF ");
			fprintf(fp1,"IF ");
			if(temp1->kind==TEMP){
				printf("%s%d","t",temp1->u.var_no);
				fprintf(fp1,"%s%d","t",temp1->u.var_no);
			}
			if(temp1->kind==VARIABLE){
				printf("%s",temp1->u.value);
				fprintf(fp1,"%s",temp1->u.value);
			}
			if(temp1->kind==CONSTANT){
				printf("%s%d","#",temp1->u.var_no);
				fprintf(fp1,"%s%d","#",temp1->u.var_no);
			}
			if(temp1->kind==ADDRESS){
				printf("*t%d",temp1->u.var_no);
				fprintf(fp1,"*t%d",temp1->u.var_no);
			}
			if(temp1->kind==CALL){
				printf("CALL %s",temp1->u.value);
				fprintf(fp1,"CALL %s",temp1->u.value);
			}
			if(temp1->kind==ARRAY){
				printf("&%s",temp1->u.value);
				fprintf(fp1,"&%s",temp1->u.value);
			}
			printf(" %s ",temp2->u.value);
			fprintf(fp1," %s ",temp2->u.value);
			if(temp3->kind==TEMP){
				printf("%s%d","t",temp3->u.var_no);
				fprintf(fp1,"%s%d","t",temp3->u.var_no);
			}
			if(temp3->kind==VARIABLE){
				printf("%s",temp3->u.value);
				fprintf(fp1,"%s",temp3->u.value);
			}
			if(temp3->kind==CONSTANT){
				printf("%s%d","#",temp3->u.var_no);
				fprintf(fp1,"%s%d","#",temp3->u.var_no);
			}
			if(temp3->kind==ADDRESS){
				printf("*t%d",temp3->u.var_no);
				fprintf(fp1,"*t%d",temp3->u.var_no);
			}
			if(temp3->kind==CALL){
				printf("CALL %s",temp3->u.value);
				fprintf(fp1,"CALL %s",temp3->u.value);
			}
			if(temp3->kind==ARRAY){
				printf("&%s",temp3->u.value);
				fprintf(fp1,"&%s",temp3->u.value);
			}
			printf(" GOTO label");
			fprintf(fp1," GOTO label");
			printf("%d",temp4->u.var_no);
			fprintf(fp1,"%d",temp4->u.var_no);
		}
		printf("\n");
		fprintf(fp1,"\n");
		Print_Codes(codes1->next,fp1);
	}
}

struct InterCodes* combine_code(struct InterCodes* temp1,struct InterCodes* temp2){
	if(temp1==NULL)
		return temp2;
	else if(temp2==NULL)
		return temp1;
	else{
		struct InterCodes*  temp3=temp1;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp2;
		temp2->prev=temp1;
		return temp3;
	}
}

struct InterCodes* Translate_Program(struct HashNode* HashTable[],struct Node *head){
	printf("program\n");
	printf("%s\n",head->name);

	count_temp=0;
	count_label=0;
	int i;

	paramnum=0;

	arraynum=0;
	for(i=0;i<100;i++){
		paramlist[i]=NULL;
		arraylist[i]=NULL;
	}
	return Translate_ExtDefList(HashTable,head->lchild);
	
}

struct InterCodes* Translate_ExtDefList(struct HashNode* HashTable[],struct Node *head){
	printf("ExtDefList\n");
	
	if(head==NULL)return NULL;
	printf("%s\n",head->name);
	struct InterCodes*  temp1=Translate_ExtDef(HashTable,head->lchild);
	struct InterCodes*  temp2=Translate_ExtDefList(HashTable,head->lchild->rchild);
	struct InterCodes*  temp3=combine_code(temp1,temp2);
	
	return temp3;
	
}
struct InterCodes* Translate_ExtDef(struct HashNode* HashTable[],struct Node *head){
	printf("ExtDef\n");
	printf("%s\n",head->name);
	if(strcmp(head->lchild->rchild->name,"ExtDecList")==0){
		Translate_Specifier(HashTable,head->lchild);
		Translate_ExtDecList(HashTable,head->lchild->rchild);
		return NULL;
		
	}
	else if(strcmp(head->lchild->rchild->name,"SEMI")==0){
		Translate_Specifier(HashTable,head->lchild);
		return NULL;
	}
	else if(strcmp(head->lchild->rchild->name,"FunDec")==0){
		
		Translate_Specifier(HashTable,head->lchild);
		struct InterCodes*  temp1=Translate_FunDec(HashTable,head->lchild->rchild);
		struct InterCodes*  temp2=Translate_CompSt(HashTable,head->lchild->rchild->rchild);
		temp1=combine_code(temp1,temp2);
		return temp1;
		
		
		
	}
}

struct InterCodes* Translate_ExtDecList(struct HashNode* HashTable[],struct Node *head){
	printf("ExtDecList\n");
	printf("%s\n",head->name);
	if(head->lchild->rchild==NULL){
		Translate_VarDec(HashTable,head->lchild);
		return NULL;
	}
	else if(strcmp(head->lchild->rchild->name,"COMMA")==0){
		Translate_VarDec(HashTable,head->lchild);
		Translate_ExtDecList(HashTable,head->lchild->rchild->rchild);
		//struct InterCodes*  temp3=combine_code(temp1,temp2);
		
		return NULL;
	}
}
		


struct InterCodes* Translate_Specifier(struct HashNode* HashTable[],struct Node *head){
	printf("Specifier\n");
	printf("%s\n",head->name);
	if(strcmp(head->lchild->name,"TYPE")==0)
		return NULL;
	else if(strcmp(head->lchild->name,"StructSpecifier")==0){//we don't have any structure
		printf("Cannot translate:Code contains variables or parameters of structure type.\n");
		Translate_StructSpecifier(HashTable,head->lchild);
		exit(0);
	}
}

struct InterCodes* Translate_StructSpecifier(struct HashNode* HashTable[],struct Node *head){//no struct
	printf("structspecifier\n");
	printf("%s\n",head->name);
	return NULL;
	//printf("Cannot translate:Code contains variables or parameters of structure type.\n");
	/*if(strcmp(head->lchild->rchild->name,"OptTag")==0){
		struct InterCodes*  temp1=Translate_OptTag(HashTable,head->lchild->rchild);
		struct InterCodes*  temp2=Translate_DefList(HashTable,head->lchild->rchild->rchild->rchild);
		temp1=combine(temp1,temp2);
		return temp1;
	}
	else {
		return Translate_Tag(HashTable,head->lchild->rchild);
	}	*/	
}

char* Translate_OptTag(struct HashNode* HashTable[],struct Node *head){//no struct
	printf("OptTag\n");
	if(head==NULL)return NULL;
	printf("%s\n",head->name);
	return head->lchild->content;
}

char* Translate_Tag(struct HashNode* HashTable[],struct Node *head){	
	printf("Tag\n");
	printf("%s\n",head->name);
	return head->lchild->content;
}

struct Operand_* Translate_VarDec(struct HashNode* HashTable[],struct Node *head){
	printf("VarDec\n");
	printf("%s\n",head->name);
	if(strcmp(head->lchild->name,"ID")==0){
		struct Operand_* temp=(struct Operand_* )malloc(sizeof(struct Operand_));
		temp->kind=VARIABLE;
		temp->u.value=head->lchild->content;
		/*struct InterCodes* temp = (struct InterCodes* )malloc(sizeof(struct InterCodes));
		temp->code.kind=PARAM;
		temp->code.u.dirop.kind=VARIABLE;
		temp->code.u.dirop.u.value=head->lchild->content;
		temp->next=NULL;
		temp->prev=NULL;
		paramlist[paramnum++]=head->lchild->content;*/
		
		return temp;
	}
	else{
		struct Operand_* temp=Translate_VarDec(HashTable,head->lchild);
		
		if(temp->kind==VARIABLE){
			struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
			temp1->kind=ARRAY;
			temp1->u.array=(struct Array*)malloc(sizeof(struct Array));
			temp1->u.array->name=temp->u.value;
			temp1->u.array->s=(struct Size*)malloc(sizeof(struct Size));
			temp1->u.array->s->size=atoi(head->lchild->rchild->rchild->content);
			temp1->u.array->s->next=NULL;
			temp1->u.array->s->prev=NULL;
			return temp1;
		}
		else{
			struct Size* t=temp->u.array->s;
			if(t->next!=NULL)
				t=t->next;
			struct Size* tt=(struct Size*)malloc(sizeof(struct Size));
			tt->size=atoi(head->lchild->rchild->rchild->content);
			tt->next=NULL;
			tt->prev=t;
			t->next=tt;			
			return temp;
		}
		
	}
}

struct InterCodes* Translate_FunDec(struct HashNode* HashTable[],struct Node *head){
	printf("FunDec\n");
	printf("%s\n",head->name);
	struct InterCodes* temp=(struct InterCodes* )malloc(sizeof(struct InterCodes));
	temp->code.kind=FUNCTION;
	temp->code.u.dirop=(struct Operand_*)malloc(sizeof(struct Operand_));
	temp->code.u.dirop->kind=VARIABLE;
	temp->code.u.dirop->u.value=head->lchild->content;
	temp->prev=NULL;
	temp->next=NULL;
	
	if(strcmp(head->lchild->rchild->rchild->name,"RP")!=0){
		struct InterCodes* temp1=Translate_VarList(HashTable,head->lchild->rchild->rchild);
		temp->next=temp1;
		temp1->prev=temp;
		return temp;
	}
	else{
		return temp;
	}
}

struct InterCodes* Translate_VarList(struct HashNode* HashTable[],struct Node *head){
	printf("VarList\n");
	printf("%s\n",head->name);
	if(head->lchild->rchild==NULL){
		return Translate_ParameDec(HashTable,head->lchild);	
	}
	else{
		struct InterCodes* temp1=Translate_ParameDec(HashTable,head->lchild);
		struct InterCodes* temp2=Translate_VarList(HashTable,head->lchild->rchild->rchild);
		temp1=combine_code(temp1,temp2);
		return temp1;
	}
}

struct InterCodes* Translate_ParameDec(struct HashNode* HashTable[],struct Node *head){
	printf("ParameDec\n");
	printf("%s\n",head->name);
	Translate_Specifier(HashTable,head->lchild);
	struct Operand_* temp=Translate_VarDec(HashTable,head->lchild->rchild);
	struct InterCodes* temp1=(struct InterCodes* )malloc(sizeof(struct InterCodes));
	
	if(temp->kind==ARRAY){
		int i=0;
		for(i=0;i<paramnum;i++){
			if(strcmp(temp->u.array->name,paramlist[i]->name)==0)
			{	paramlist[i]=temp->u.array;break;}
		}
		if(i==paramnum)
			paramlist[paramnum++]=temp->u.array;

		
	}
	temp1->code.kind=PARAM;
	temp1->code.u.dirop=temp;
	temp1->next=NULL;
	temp1->prev=NULL;
	return temp1;
	
}

struct InterCodes* Translate_CompSt(struct HashNode* HashTable[],struct Node *head){
	printf("CompSt\n");
	printf("%s\n",head->name);
	struct InterCodes* temp1=Translate_DefList(HashTable,head->lchild->rchild);
	struct InterCodes* temp2=Translate_StmtList(HashTable,head->lchild->rchild->rchild);
	temp1=combine_code(temp1,temp2);
	return temp1;
}

struct InterCodes* Translate_StmtList(struct HashNode* HashTable[],struct Node *head){
	printf("stmtList\n");
	//printf("1\n");
	if(head==NULL)return NULL;
	printf("%s\n",head->name);
	
	struct InterCodes* temp1=Translate_Stmt(HashTable,head->lchild);
	struct InterCodes* temp2;
	if(head->lchild!=NULL)
	temp2=Translate_StmtList(HashTable,head->lchild->rchild);
	else
	temp2=NULL;
	temp1=combine_code(temp1,temp2);
	return temp1;
}

struct InterCodes* Translate_Stmt(struct HashNode* HashTable[],struct Node *head){
	printf("Stmt\n");
	if(head==NULL)return NULL;
	printf("%s\n",head->name);
	if(head->lchild->rchild==NULL)
		return Translate_CompSt(HashTable,head->lchild);
	else if(strcmp(head->lchild->rchild->name,"SEMI")==0){
		return Translate_Exp(HashTable,head->lchild,NULL,0);
	}
	else if(strcmp(head->lchild->name,"RETURN")==0){//Maybe I can directly return the id followed if right;
		
		if(head->lchild->rchild->lchild->rchild==NULL){
			/*struct InterCodes* t=temp1;
			while(t->next!=NULL)//find the last node
				t=t->next;
			t=t->prev;
			t->next->prev=NULL;
			free(t->next);*/
			struct InterCodes* temp2=(struct InterCodes* )malloc(sizeof(struct InterCodes));
			temp2->code.kind=RETURNN;
			temp2->code.u.dirop=(struct Operand_*)malloc(sizeof(struct Operand_));
			if(strcmp(head->lchild->rchild->lchild->name,"ID")==0){
				temp2->code.u.dirop->kind=VARIABLE;
				temp2->code.u.dirop->u.value=head->lchild->rchild->lchild->content;
			}
			else{
				temp2->code.u.dirop->kind=CONSTANT;
				temp2->code.u.dirop->u.var_no=atoi(head->lchild->rchild->lchild->content);
			}
			temp2->next=NULL;
			temp2->prev=NULL;
			//temp1=combine_code(temp1,temp2);
			return temp2;
		}
		else{
			struct Operand_* place = new_temp();
			struct InterCodes* temp1=Translate_Exp(HashTable,head->lchild->rchild,place,0);
			struct InterCodes* temp2=(struct InterCodes* )malloc(sizeof(struct InterCodes));
			temp2->code.kind=RETURNN;
			temp2->code.u.dirop=place;
			temp2->next=NULL;
			temp2->prev=NULL;
			temp1=combine_code(temp1,temp2);
			return temp1;
		}
				
		
	}
	else if(strcmp(head->lchild->name,"WHILE")==0){
		struct Operand_* label1 = new_label();
		struct Operand_* label2 = new_label();
		struct Operand_* label3 = new_label();

		struct Node* p=head->lchild->rchild->rchild;

		struct InterCodes* temp2=Translate_Cond(p,label2,label3,HashTable);
		struct InterCodes* temp4=Translate_Stmt(HashTable,p->rchild->rchild);
		
		struct InterCodes* temp1=(struct InterCodes* )malloc(sizeof(struct InterCodes));
		struct InterCodes* temp3=(struct InterCodes* )malloc(sizeof(struct InterCodes));
		struct InterCodes* temp5=(struct InterCodes* )malloc(sizeof(struct InterCodes));
		struct InterCodes* temp6=(struct InterCodes* )malloc(sizeof(struct InterCodes));

		temp1->code.kind=LAB;
		temp1->code.u.dirop=label1;
		temp1->next=NULL;
		temp1->prev=NULL;

		temp3->code.kind=LAB;
		temp3->code.u.dirop=label2;
		temp3->next=NULL;
		temp3->prev=NULL;

		temp5->code.kind=GOTO;
		temp5->code.u.dirop=label1;
		temp5->next=NULL;
		temp5->prev=NULL;

		temp6->code.kind=LAB;
		temp6->code.u.dirop=label3;
		temp6->next=NULL;
		temp6->prev=NULL;

		temp1=combine_code(temp1,temp2);
		temp1=combine_code(temp1,temp3);
		temp1=combine_code(temp1,temp4);
		temp1=combine_code(temp1,temp5);
		temp1=combine_code(temp1,temp6);

		return temp1;
	}
	else if(head->lchild->rchild->rchild->rchild->rchild->rchild==NULL){//if
		struct Operand_* label1 = new_label();
		struct Operand_* label2 = new_label();

		struct Node* p=head->lchild->rchild->rchild;
		struct InterCodes* temp1=Translate_Cond(p,label1,label2,HashTable);
		struct InterCodes* temp2=Translate_Stmt(HashTable,p->rchild->rchild);

		struct InterCodes* temp3=(struct InterCodes* )malloc(sizeof(struct InterCodes));
		struct InterCodes* temp4=(struct InterCodes* )malloc(sizeof(struct InterCodes));
		
		temp3->code.kind=LAB;
		temp3->code.u.dirop=label1;
		temp3->next=NULL;
		temp3->prev=NULL;

		temp4->code.kind=LAB;
		temp4->code.u.dirop=label2;
		temp4->next=NULL;
		temp4->prev=NULL;

		temp1=combine_code(temp1,temp3);
		temp1=combine_code(temp1,temp2);
		temp1=combine_code(temp1,temp4);

		return temp1;

	}
	else{//if else
		struct Operand_* label1 = new_label();
		struct Operand_* label2 = new_label();
		struct Operand_* label3 = new_label();
		
		struct Node* p=head->lchild->rchild->rchild;
		struct InterCodes* temp1=Translate_Cond(p,label1,label2,HashTable);
		p=p->rchild->rchild;
		struct InterCodes* temp3=Translate_Stmt(HashTable,p);
		p=p->rchild->rchild;
		struct InterCodes* temp6=Translate_Stmt(HashTable,p);

		struct InterCodes* temp2=(struct InterCodes* )malloc(sizeof(struct InterCodes));
		struct InterCodes* temp4=(struct InterCodes* )malloc(sizeof(struct InterCodes));
		struct InterCodes* temp5=(struct InterCodes* )malloc(sizeof(struct InterCodes));
		struct InterCodes* temp7=(struct InterCodes* )malloc(sizeof(struct InterCodes));

		temp2->code.kind=LAB;
		temp2->code.u.dirop=label1;
		temp2->next=NULL;
		temp2->prev=NULL;

		temp4->code.kind=LAB;
		temp4->code.u.dirop=label2;
		temp4->next=NULL;
		temp4->prev=NULL;
		
		temp5->code.kind=GOTO;
		temp5->code.u.dirop=label3;
		temp5->next=NULL;
		temp5->prev=NULL;
		
		temp7->code.kind=LAB;
		temp7->code.u.dirop=label3;
		temp7->next=NULL;
		temp7->prev=NULL;
		
		struct InterCodes* t=temp3;
		if(t!=NULL)
			while(t->next!=NULL)
				t=t->next;
		if(t!=NULL&&t->code.kind==RETURNN){
			temp1=combine_code(temp1,temp2);
			temp1=combine_code(temp1,temp3);
			temp1=combine_code(temp1,temp4);
			temp1=combine_code(temp1,temp6);
		}
		else{
			temp1=combine_code(temp1,temp2);
			temp1=combine_code(temp1,temp3);
			temp1=combine_code(temp1,temp5);
			temp1=combine_code(temp1,temp4);
			temp1=combine_code(temp1,temp6);
			temp1=combine_code(temp1,temp7);
		}
		return temp1;
	}
}


struct InterCodes* Translate_DefList(struct HashNode* HashTable[],struct Node *head){
	printf("DefList\n");
	if(head==NULL)return NULL;
	printf("%s\n",head->name);
	
	struct InterCodes* temp1=Translate_Def(HashTable,head->lchild);
	if(head->lchild!=NULL){
		struct InterCodes* temp2=Translate_DefList(HashTable,head->lchild->rchild);
		temp1=combine_code(temp1,temp2);
	}
	
	return temp1;
}

struct InterCodes* Translate_Def(struct HashNode* HashTable[],struct Node *head){
	printf("Def\n");
	if(head==NULL)return NULL;
	printf("%s\n",head->name);
	Translate_Specifier(HashTable,head->lchild);
	struct InterCodes* temp1=Translate_DecList(HashTable,head->lchild->rchild);
	return temp1;
}

struct InterCodes* Translate_DecList(struct HashNode* HashTable[],struct Node *head){
	printf("DecList\n");
	printf("%s\n",head->name);
	struct InterCodes* temp1=Translate_Dec(HashTable,head->lchild);
	if(head->lchild->rchild!=NULL){
		
	//else{
	//	struct InterCodes* temp1=Translate_Dec(HashTable,head->lchild);
		struct InterCodes* temp2=Translate_DecList(HashTable,head->lchild->rchild->rchild);	
		temp1=combine_code(temp1,temp2);
	}
	return temp1;
}

struct InterCodes* Translate_Dec(struct HashNode* HashTable[],struct Node *head){
	printf("Dec\n");
	printf("%s\n",head->name);
	struct InterCodes* temp1=NULL;
	struct Operand_* temp=Translate_VarDec(HashTable,head->lchild);
	if(temp->kind==ARRAY){
		arraylist[arraynum++]=temp->u.array;
		int i=4;
		struct Size* p=temp->u.array->s;
		while(p!=NULL){ 
			i=i*p->size;
			p=p->next;
		}
		temp1=(struct InterCodes* )malloc(sizeof(struct InterCodes));
		temp1->code.kind=DEC;
		temp1->code.u.assign.right=(struct Operand_* )malloc(sizeof(struct Operand_));
		temp1->code.u.assign.left=(struct Operand_* )malloc(sizeof(struct Operand_));
		temp1->code.u.assign.left->kind=VARIABLE;
		temp1->code.u.assign.left->u.value=temp->u.array->name;
		temp1->code.u.assign.right->kind=CONSTANT;
		temp1->code.u.assign.right->u.var_no=i;
		temp1->next=NULL;
		temp1->prev=NULL;
		return temp1;
		
	}
	if(head->lchild->rchild!=NULL){	
		//Translate_VarDec(HashTable,head->lchild);
		struct Operand_* place=(struct Operand_*)malloc(sizeof(struct Operand_));
		place->kind=VARIABLE;
		place->u.value=temp->u.value;
	//	printf("%s\n",place->u.value);
		temp1=Translate_Exp(HashTable,head->lchild->rchild->rchild,place,0);
		return temp1;
	}
	return temp1;
}

struct InterCodes* Translate_Exp(struct HashNode* HashTable[],struct Node *head,Operand place,int a){
	printf("%s\n",head->name);
	if(strcmp(head->lchild->name,"Exp")==0){
		struct Node* p = head->lchild;
		if(strcmp(p->rchild->name,"ASSIGNOP")==0){
			struct InterCodes* codes1;
			if(p->lchild->rchild==NULL){
				struct Operand_ *temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=VARIABLE;
				temp2->u.value=p->lchild->content;
				codes1=Translate_Exp(HashTable,p->rchild->rchild,temp2,0);
				return codes1;
			}
			else{
				struct Operand_ *temp2=new_temp();
				struct InterCodes* codes2=Translate_Exp(HashTable,p->rchild->rchild,temp2,0);
				codes1=Translate_Exp(HashTable,p,temp2,1);
				return combine_code(codes2,codes1);
			}
		}
				if(strcmp(head->lchild->rchild->name,"LB")==0){
					int i=0;
					int bl=-1;
					struct Array *array=(struct Array*)malloc(sizeof(struct Array)); 
					char *arrayID;
					struct Node *q=head;
					while(strcmp(q->name,"ID")!=0){
						q=q->lchild;
					}
					arrayID=q->content;
					for(i=0;i<arraynum;i++){
						if(strcmp(arraylist[i]->name,arrayID)==0){
							array=arraylist[i];
							bl=0;
						}
					}
					for(i=0;i<paramnum;i++){
						if(strcmp(paramlist[i]->name,arrayID)==0){
							array=paramlist[i];
							bl=1;
						}
					}
					if(bl==0){
						struct InterCodes* codes1;
						struct Operand_* temp1=new_temp();
						struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_*));
						temp2->kind=CONSTANT;
						temp2->u.var_no=4;
						int cc=0;
						codes1=Translate_Array(HashTable,p,temp1,array,&cc,0,NULL);
						struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
						struct InterCode* ic1=(struct InterCode*)malloc(sizeof(struct InterCode));
						ic1->kind=MUL;
						ic1->u.binop.result=temp1;
						ic1->u.binop.op1=temp1;
						ic1->u.binop.op2=temp2;
						codes2->code=*ic1;
						codes2->next=NULL;
						struct Operand_* temp3=(struct Operand_*)malloc(sizeof(struct Operand_*));
						temp3->kind=ARRAY;
						temp3->u.value=array->name;
						printf("%s\n",array->name);
						struct InterCodes* codes3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
						struct InterCode* ic2=(struct InterCode*)malloc(sizeof(struct InterCode));
						ic2->kind=ADD;
						ic2->u.binop.result=temp1;
						ic2->u.binop.op1=temp3;
						ic2->u.binop.op2=temp1;
						codes3->code=*ic2;
						codes3->next=NULL;
						//temp1->kind=ADDRESS;
						struct InterCodes* codes4=(struct InterCodes*)malloc(sizeof(struct InterCodes));
						struct InterCode* ic3=(struct InterCode*)malloc(sizeof(struct InterCode));
						if(a==0){
							ic3->kind=ASR;
							ic3->u.assign.left=place;
							ic3->u.assign.right=temp1;
						}
						else{
							ic3->kind=ASL;
							ic3->u.assign.left=temp1;
							place->kind=TEMP;
							ic3->u.assign.right=place;
						}
						codes4->code=*ic3;
						codes4->next=NULL;
						return combine_code(codes1,combine_code(codes2,combine_code(codes3,codes4)));
					}
					if(bl==1){
						struct InterCodes* codes1;
						struct Operand_* temp1=new_temp();
						struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_*));
						temp2->kind=CONSTANT;
						temp2->u.var_no=4;
						int aa=0;
						codes1=Translate_Array(HashTable,p,temp1,array,&aa,0,NULL);
						struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
						struct InterCode* ic1=(struct InterCode*)malloc(sizeof(struct InterCode));
						ic1->kind=MUL;
						ic1->u.binop.result=temp1;
						ic1->u.binop.op1=temp1;
						ic1->u.binop.op2=temp2;
						codes2->code=*ic1;
						codes2->next=NULL;
						struct Operand_* temp3=(struct Operand_*)malloc(sizeof(struct Operand_*));
						temp3->kind=VARIABLE;
						temp3->u.value=array->name;
						printf("%s\n",array->name);
						struct InterCodes* codes3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
						struct InterCode* ic2=(struct InterCode*)malloc(sizeof(struct InterCode));
						ic2->kind=ADD;
						ic2->u.binop.result=temp1;
						ic2->u.binop.op1=temp3;
						ic2->u.binop.op2=temp1;
						codes3->code=*ic2;
						codes3->next=NULL;
						//temp1->kind=ADDRESS;
						struct InterCodes* codes4=(struct InterCodes*)malloc(sizeof(struct InterCodes));
						struct InterCode* ic3=(struct InterCode*)malloc(sizeof(struct InterCode));
						ic3->kind=ASSIGN;
						if(a==0){
							ic3->kind=ASR;
							ic3->u.assign.left=place;
							ic3->u.assign.right=temp1;
						}
						else{
							ic3->kind=ASL;
							ic3->u.assign.left=temp1;
							place->kind=TEMP;
							ic3->u.assign.right=place;
						}
						codes4->code=*ic3;
						codes4->next=NULL;
						return combine_code(codes1,combine_code(codes2,combine_code(codes3,codes4)));	
					}
				}
		if(strcmp(p->rchild->name,"PLUS")==0){
			int a=1;
			if(strcmp(p->lchild->name,"ID")==0&&p->lchild->rchild==NULL)
				a=a*2;
			if(strcmp(p->lchild->name,"INT")==0)
				a=a*3;
			if(strcmp(p->rchild->rchild->lchild->name,"ID")==0&&p->rchild->rchild->lchild->rchild==NULL)
				a=a*5;
			if(strcmp(p->rchild->rchild->lchild->name,"INT")==0)
				a=a*7;
			if(a==1){
				struct Operand_* temp1=new_temp();
				struct Operand_* temp2=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2;
				struct InterCodes* codes3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				codes2=Translate_Exp(HashTable,p->rchild->rchild,temp2,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=ADD;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes3->code=*ic;
				codes3->next=NULL;
				return combine_code(combine_code(codes1,codes2),codes3);
			}
			if(a==2){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p->rchild->rchild,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=VARIABLE;
				temp2->u.value=p->lchild->content;
				ic->kind=ADD;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp2;
				ic->u.binop.op2=temp1;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==3){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p->rchild->rchild,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp2->u.var_no=atoi(p->lchild->content);
				ic->kind=ADD;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==5){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				ic->kind=ADD;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==7){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				ic->kind=ADD;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==10){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=VARIABLE;
				temp1->u.value=p->lchild->content;
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=ADD;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==14){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=VARIABLE;
				temp1->u.value=p->lchild->content;
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=ADD;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==15){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp1->u.var_no=atoi(p->lchild->content);
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=ADD;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp2;
				ic->u.binop.op2=temp1;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==21){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp1->u.var_no=atoi(p->lchild->content);
				temp2->kind=CONSTANT;
				num=(char*)malloc(1024);
				dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=ADD;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}						
		}
		if(strcmp(p->rchild->name,"MINUS")==0){
			int a=1;
			if(strcmp(p->lchild->name,"ID")==0&&p->lchild->rchild==NULL)
				a=a*2;
			if(strcmp(p->lchild->name,"INT")==0)
				a=a*3;
			if(strcmp(p->rchild->rchild->lchild->name,"ID")==0&&p->rchild->rchild->lchild->rchild==NULL)
				a=a*5;
			if(strcmp(p->rchild->rchild->lchild->name,"INT")==0)
				a=a*7;
			if(a==1){
				struct Operand_* temp1=new_temp();
				struct Operand_* temp2=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2;
				struct InterCodes* codes3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				codes2=Translate_Exp(HashTable,p->rchild->rchild,temp2,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=SUB;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes3->code=*ic;
				codes3->next=NULL;
				return combine_code(combine_code(codes1,codes2),codes3);
			}
			if(a==2){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p->rchild->rchild,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=VARIABLE;
				temp2->u.value=p->lchild->content;
				ic->kind=SUB;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp2;
				ic->u.binop.op2=temp1;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==3){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p->rchild->rchild,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp2->u.var_no=atoi(p->lchild->content);
				ic->kind=SUB;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp2;
				ic->u.binop.op2=temp1;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==5){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				ic->kind=SUB;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==7){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				ic->kind=SUB;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==10){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=VARIABLE;
				temp1->u.value=p->lchild->content;
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=SUB;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==14){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=VARIABLE;
				temp1->u.value=p->lchild->content;
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=SUB;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==15){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp1->u.var_no=atoi(p->lchild->content);
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=SUB;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==21){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp1->u.var_no=atoi(p->lchild->content);
				temp2->kind=CONSTANT;
				num=(char*)malloc(1024);
				dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=SUB;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
		}
		if(strcmp(p->rchild->name,"STAR")==0){
			int a=1;
			if(strcmp(p->lchild->name,"ID")==0&&p->lchild->rchild==NULL)
				a=a*2;
			if(strcmp(p->lchild->name,"INT")==0)
				a=a*3;
			if(strcmp(p->rchild->rchild->lchild->name,"ID")==0&&p->rchild->rchild->lchild->rchild==NULL)
				a=a*5;
			if(strcmp(p->rchild->rchild->lchild->name,"INT")==0)
				a=a*7;
			if(a==1){
				struct Operand_* temp1=new_temp();
				struct Operand_* temp2=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2;
				struct InterCodes* codes3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				codes2=Translate_Exp(HashTable,p->rchild->rchild,temp2,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=MUL;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes3->code=*ic;
				codes3->next=NULL;
				return combine_code(combine_code(codes1,codes2),codes3);
			}
			if(a==2){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p->rchild->rchild,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=VARIABLE;
				temp2->u.value=p->lchild->content;
				ic->kind=MUL;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp2;
				ic->u.binop.op2=temp1;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==3){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p->rchild->rchild,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp2->u.var_no=atoi(p->lchild->content);
				ic->kind=MUL;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==5){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				ic->kind=MUL;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==7){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				ic->kind=MUL;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==10){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=VARIABLE;
				temp1->u.value=p->lchild->content;
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=MUL;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==14){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=VARIABLE;
				temp1->u.value=p->lchild->content;
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=MUL;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==15){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp1->u.var_no=atoi(p->lchild->content);
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=MUL;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp2;
				ic->u.binop.op2=temp1;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==21){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp1->u.var_no=atoi(p->lchild->content);
				temp2->kind=CONSTANT;
				num=(char*)malloc(1024);
				dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=MUL;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
		}
		if(strcmp(p->rchild->name,"DIV")==0){
			int a=1;
			if(strcmp(p->lchild->name,"ID")==0&&p->lchild->rchild==NULL)
				a=a*2;
			if(strcmp(p->lchild->name,"INT")==0)
				a=a*3;
			if(strcmp(p->rchild->rchild->lchild->name,"ID")==0&&p->rchild->rchild->lchild->rchild==NULL)
				a=a*5;
			if(strcmp(p->rchild->rchild->lchild->name,"INT")==0)
				a=a*7;
			if(a==1){
				struct Operand_* temp1=new_temp();
				struct Operand_* temp2=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2;
				struct InterCodes* codes3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				codes2=Translate_Exp(HashTable,p->rchild->rchild,temp2,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=DV;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes3->code=*ic;
				codes3->next=NULL;
				return combine_code(combine_code(codes1,codes2),codes3);
			}
			if(a==2){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p->rchild->rchild,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=VARIABLE;
				temp2->u.value=p->lchild->content;
				ic->kind=DV;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp2;
				ic->u.binop.op2=temp1;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==3){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p->rchild->rchild,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp2->u.var_no=atoi(p->lchild->content);
				ic->kind=DV;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp2;
				ic->u.binop.op2=temp1;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==5){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				ic->kind=DV;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==7){
				struct Operand_* temp1=new_temp();
				struct InterCodes* codes1;
				struct InterCodes* codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1=Translate_Exp(HashTable,p,temp1,0);
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				ic->kind=DV;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				codes2->code=*ic;
				codes2->next=NULL;
				return combine_code(codes1,codes2);
			}
			if(a==10){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=VARIABLE;
				temp1->u.value=p->lchild->content;
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=DV;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==14){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=VARIABLE;
				temp1->u.value=p->lchild->content;
				temp2->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=DV;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==15){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp1->u.var_no=atoi(p->lchild->content);
				temp2->kind=VARIABLE;
				temp2->u.value=p->rchild->rchild->lchild->content;
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=DV;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
			if(a==21){
				struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=CONSTANT;
				char* num=(char*)malloc(1024);
				char* dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->lchild->content));
				temp1->u.var_no=atoi(p->lchild->content);
				temp2->kind=CONSTANT;
				num=(char*)malloc(1024);
				dest=(char*)malloc(1024);
				strcpy(dest,"#");
				strcpy(num,strcat(dest,p->rchild->rchild->lchild->content));
				temp2->u.var_no=atoi(p->rchild->rchild->lchild->content);
				struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=DV;
				ic->u.binop.result=place;
				ic->u.binop.op1=temp1;
				ic->u.binop.op2=temp2;
				struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
			}
		}
		if(strcmp(p->rchild->name,"AND")==0||strcmp(p->rchild->name,"OR")==0||strcmp(p->rchild->name,"RELOP")==0){
			struct Operand_* label1=new_label();
			struct Operand_* label2=new_label();
			struct InterCodes* codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			struct InterCodes* codes2;
			struct InterCodes* codes3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			struct InterCodes* codes4=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			struct InterCodes* codes5=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			struct InterCode* ic1=(struct InterCode*)malloc(sizeof(struct InterCode));
			struct InterCode* ic2=(struct InterCode*)malloc(sizeof(struct InterCode));
			struct InterCode* ic3=(struct InterCode*)malloc(sizeof(struct InterCode));
			struct InterCode* ic4=(struct InterCode*)malloc(sizeof(struct InterCode));
			struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
			struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
			temp1->kind=CONSTANT;
			temp1->u.value="#0";
			ic1->kind=ASSIGN;
			ic1->u.assign.right=place;
			ic1->u.assign.left=temp1;
			codes1->code=*ic1;
			codes1->next=NULL;
			codes2=Translate_Cond(head,label1,label2,HashTable);
			ic2->kind=LAB;
			ic2->u.dirop=label1;
			ic3->kind=ASSIGN;
			temp2->kind=CONSTANT;
			temp2->u.value="#1";
			ic3->u.assign.right=place;
			ic3->u.assign.left=temp2;
			ic4->kind=LAB;
			ic4->u.dirop=label2;
			codes3->code=*ic2;
			codes3->next=NULL;
			codes4->code=*ic3;
			codes4->next=NULL;
			codes5->code=*ic4;
			codes5->next=NULL;
			codes3=combine_code(codes3,codes4);
			codes3=combine_code(codes3,codes5);
			return combine_code(combine_code(codes1,codes2),codes3);
		}
		if(strcmp(p->rchild->name,"LB")==0){
			
		}
	}
	else{
		if(strcmp(head->lchild->name,"INT")==0){
			char* num=(char*)malloc(1024);
			char* dest=(char*)malloc(1024);
			strcpy(dest,"#");
			strcpy(num,strcat(dest,head->lchild->content));
			struct Operand_ *temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
			temp1->kind=CONSTANT;
			temp1->u.var_no=atoi(head->lchild->content);
			struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
			ic->kind=ASSIGN;
			ic->u.assign.right=temp1;
			ic->u.assign.left=place;
			struct InterCodes* codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			codes1->code=*ic;
			codes1->next=NULL;
			return codes1;
		}
		if(strcmp(head->lchild->name,"ID")==0){
			if(head->lchild->rchild==NULL){
				struct Operand_ *temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
				temp1->kind=VARIABLE;
				temp1->u.value=head->lchild->content;
				struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
				ic->kind=ASSIGN;
				ic->u.assign.right=temp1;
				ic->u.assign.left=place;
				struct InterCodes* codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				codes1->code=*ic;
				codes1->next=NULL;
				return codes1;
				
			}
			else if(strcmp(head->lchild->rchild->name,"LP")==0){
				if(strcmp(head->lchild->rchild->rchild->name,"Args")==0){
					struct InterCodes* codes2;
					codes2=Translate_Args(HashTable,head->lchild->rchild->rchild);
					struct InterCodes* codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
					struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
					struct Operand_ *temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
					struct Operand_ *temp2=new_temp();
					temp1->kind=CALL;
					temp1->u.value=head->lchild->content;
					ic->kind=ASSIGN;
					ic->u.assign.right=temp1;
					if(place!=NULL)
						ic->u.assign.left=place;
					else
						ic->u.assign.left=temp2;
					codes1->code=*ic;
					codes1->next=NULL;
					return combine_code(codes2,codes1);
				}
				else{
					struct InterCodes* codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
					struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
					struct Operand_ *temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
					struct Operand_ *temp2=new_temp();
					temp1->kind=CALL;
					temp1->u.value=head->lchild->content;
					ic->kind=ASSIGN;
					ic->u.assign.right=temp1;
					if(place!=NULL)
						ic->u.assign.left=place;
					else
						ic->u.assign.left=temp2;
					codes1->code=*ic;
					codes1->next=NULL;
					return codes1;	
				}
			}
		}
		if(strcmp(head->lchild->name,"MINUS")==0){
			struct Operand_ *temp1=new_temp();
			struct InterCodes *codes1;
			struct InterCodes *codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			codes1=Translate_Exp(HashTable,head->lchild->rchild,temp1,0);
			struct Operand_ *temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
			temp2->kind=CONSTANT;
			temp2->u.var_no=0;
			struct InterCode* ic=(struct InterCode*)malloc(sizeof(struct InterCode));
			ic->kind=SUB;
			ic->u.binop.result=place;
			ic->u.binop.op1=temp2;
			ic->u.binop.op2=temp1;
			codes2->code=*ic;
			codes2->next=NULL;
			return combine_code(codes1,codes2);
		}
		if(strcmp(head->lchild->name,"NOT")==0){
			struct Operand_* label1=new_label();
			struct Operand_* label2=new_label();
			struct InterCodes* codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			struct InterCodes* codes2;
			struct InterCodes* codes3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			struct InterCodes* codes4=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			struct InterCodes* codes5=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			struct InterCode* ic1=(struct InterCode*)malloc(sizeof(struct InterCode));
			struct InterCode* ic2=(struct InterCode*)malloc(sizeof(struct InterCode));
			struct InterCode* ic3=(struct InterCode*)malloc(sizeof(struct InterCode));
			struct InterCode* ic4=(struct InterCode*)malloc(sizeof(struct InterCode));
			struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
			struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
			temp1->kind=CONSTANT;
			temp1->u.value="#0";
			ic1->kind=ASSIGN;
			ic1->u.assign.right=place;
			ic1->u.assign.left=temp1;
			codes1->code=*ic1;
			codes1->next=NULL;
			codes2=Translate_Cond(head,label1,label2,HashTable);
			ic2->kind=LAB;
			ic2->u.dirop=label1;
			ic3->kind=ASSIGN;
			temp2->kind=CONSTANT;
			temp2->u.value="#1";
			ic3->u.assign.right=place;
			ic3->u.assign.left=temp2;
			ic4->kind=LAB;
			ic4->u.dirop=label2;
			codes3->code=*ic2;
			codes3->next=NULL;
			codes4->code=*ic3;
			codes4->next=NULL;
			codes5->code=*ic4;
			codes5->next=NULL;
			codes3=combine_code(codes3,codes4);
			codes3=combine_code(codes3,codes5);
			return combine_code(combine_code(codes1,codes2),codes3);
		}
		if(strcmp(head->lchild->name,"LP")==0){
			struct InterCodes *codes1;
			codes1=Translate_Exp(HashTable,head->lchild->rchild,place,0);
			return codes1;
		}
		if(strcmp(head->lchild->name,"READ")==0){
			struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
			ic->kind=READD;
			ic->u.dirop=place;
			codes1->code=*ic;
			codes1->next=NULL;
			return codes1;			
		}
		if(strcmp(head->lchild->name,"WRITE")==0){
			struct InterCodes *codes1;
			struct InterCodes *codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
			struct Operand_ *temp1=new_temp();
			codes1=Translate_Exp(HashTable,head->lchild->rchild->rchild,temp1,0);
			struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
			ic->kind=WRITEE;
			ic->u.dirop=temp1;
			codes2->code=*ic;
			codes2->next=NULL;
			return combine_code(codes1,codes2);
		}
	}

	
}
struct InterCodes* Translate_Array(struct HashNode* HashTable[],struct Node *head,Operand place,struct Array* array,int* sum,int v,struct InterCodes* tcode){
		if(strcmp(head->name,"ID")!=0){
			if(tcode==NULL){
				tcode=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				tcode->code.kind=-1;
			}
				
			struct InterCodes* code1=Translate_Array(HashTable,head->lchild,place,array,sum,v+1,tcode);
			if(strcmp(head->rchild->rchild->lchild->name,"INT")==0){
				
				int i;
				int u=1;
				struct Size* a=array->s;
				while(a->next!=NULL)
					a=a->next;
				for(i=0;i<v;i++){
					u=u*a->size;
					a=a->prev;
				}
				u=u*atoi(head->rchild->rchild->lchild->content);
				*sum=*sum+u;
				
			}
			else{	
				
				
								
				
				int i;
				int u=1;
				struct Size* a=array->s;
				struct InterCodes* code2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
				while(a->next!=NULL)
					a=a->next;
				for(i=0;i<v;i++){
					u=u*a->size;
					a=a->next;
				}
				Operand temp1=new_temp();
				Operand temp2;
				if(strcmp(head->rchild->rchild->lchild->name,"ID")==0){
					temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
					temp2->kind=VARIABLE;
					temp2->u.value=head->rchild->rchild->lchild->content;
				}
				else{
					temp2=new_temp();
					struct InterCodes* code0=Translate_Exp(HashTable,head->rchild->rchild,temp2,0);
					struct InterCodes* tcode1;
					if(tcode->code.kind!=-1)
						tcode1=combine_code(tcode,code0);
					else
						tcode1=code0;
					*tcode = *tcode1;
				}
				Operand temp3=(struct Operand_*)malloc(sizeof(struct Operand_));
				
				temp3->kind=CONSTANT;
				temp3->u.var_no=u;
				code2->code.kind=MUL;
				code2->code.u.binop.op1=temp2;
				code2->code.u.binop.op2=temp3;
				code2->code.u.binop.result=temp1;
				code2->next=NULL;
				code1=combine_code(code1,code2);
				
			}
			
			if(v==0){
				if(code1!=NULL){
					struct InterCodes* c=code1;
					if(c->next==NULL){
						//Operand temp4=new_temp();
						struct InterCodes* code3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
						code3->code.kind=ADD;
						code3->code.u.binop.result=place;
						code3->code.u.binop.op1=(Operand)malloc(sizeof(struct Operand_));
						code3->code.u.binop.op1->kind=CONSTANT;
						code3->code.u.binop.op1->u.var_no=*sum;
						code3->code.u.binop.op2=c->code.u.binop.result;
						code3->next=NULL;
						code1=combine_code(code1,code3);
						if(tcode->code.kind!=-1)
						code1=combine_code(tcode,code1);
						return code1;
					}
					else{
						Operand temp4=new_temp();
						struct InterCodes* code3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
						code3->next=NULL;
						code3->code.kind=ADD;
						code3->code.u.binop.result=temp4;
						code3->code.u.binop.op1=c->code.u.binop.result;
						c=c->next;
						code3->code.u.binop.op2=c->code.u.binop.result;
						while(c->next!=NULL){
							c=c->next;
							Operand temp5=new_temp();
							struct InterCodes* code4=(struct InterCodes*)malloc(sizeof(struct InterCodes));
							code4->next=NULL;
							code4->code.kind=ADD;
							code4->code.u.binop.result=temp5;
							code4->code.u.binop.op1=temp4;
							code4->code.u.binop.op2=c->code.u.binop.result;
							temp4=temp5;
							combine_code(code3,code4);
						}
						if(*sum!=0){
						struct InterCodes* code5=(struct InterCodes*)malloc(sizeof(struct InterCodes));
						code5->code.kind=ADD;
						code5->code.u.binop.result=temp4;
						code5->code.u.binop.op1=(Operand)malloc(sizeof(struct Operand_));
						code5->code.u.binop.op1->kind=CONSTANT;
						code5->code.u.binop.op1->u.var_no=*sum;
						code5->code.u.binop.op2=c->code.u.binop.result;
						code5->next=NULL;
						code3=combine_code(code3,code5);
						}
						code1=combine_code(code1,code3);
						if(tcode->code.kind!=-1)
						code1=combine_code(tcode,code1);
					}
				}
				else{
					struct InterCodes* code3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
					code3->code.kind=ASSIGN;
					code3->code.u.assign.right=(Operand)malloc(sizeof(struct Operand_));
					code3->code.u.assign.left=place;
					code3->code.u.assign.right->kind=CONSTANT;
					code3->code.u.assign.right->u.var_no=*sum;
					code3->next=NULL;
					

					code1=combine_code(code1,code3);
				}
			}
			return code1;			
		}
		else
			return NULL;	
}
/*struct InterCodes* Translate_Array_Exp(Operand place,struct Size *s){
	struct InterCodes *codes1=(struct InterCodes*)malloc(sizeof(struct InterCodes));
	struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
	if(s==NULL)
		return NULL;
	if(s->next!=NULL){
		struct Operand_* temp1=(struct Operand_*)malloc(sizeof(struct Operand_*));
		temp1->kind=CONSTANT;
		temp1->u.var_no=s->size;
		ic->kind=MUL;
		ic->u.binop.result=place;
		ic->u.binop.op1=place;
		ic->u.binop.op2=temp1;
		codes1->code=*ic;
		codes1->next=NULL;
		return combine_code(codes1,Translate_Array_Exp(place,s->next));
	}
	else
		return NULL;
}*/
struct InterCodes* Translate_Args(struct HashNode* HashTable[],struct Node *head){
		if(head->lchild->rchild!=NULL){
		struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_*));
		struct InterCodes *codes1;
		struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
		struct InterCodes *codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
		if(strcmp(head->lchild->lchild->name,"ID")==0&&head->lchild->lchild->rchild==NULL){
			int i=0;
			int bl=0;
			for(i=0;i<arraynum;i++){
				if(strcmp(arraylist[i]->name,head->lchild->lchild->content)==0){
					bl=1;
				}
			}
			for(i=0;i<paramnum;i++){
				if(strcmp(paramlist[i]->name,head->lchild->lchild->content)==0){
					bl=1;
				}
			}
			if(bl==0){
				temp2->kind=VARIABLE;
				temp2->u.value=head->lchild->lchild->content;
			}
			if(bl==1){
				temp2->kind=ARRAY;
				temp2->u.value=head->lchild->lchild->content;
			}
			ic->kind=ARG;
			ic->u.dirop=temp2;
			codes2->code=*ic;
			codes2->next=NULL;
			struct InterCodes *codes3;
			codes3=Translate_Args(HashTable,head->lchild->rchild->rchild);
			return combine_code(codes2,codes3);
		}
		if(strcmp(head->lchild->lchild->name,"INT")==0&&head->lchild->lchild->rchild==NULL){
			temp2->kind=CONSTANT;
			temp2->u.var_no=atoi(head->lchild->lchild->content);
			ic->kind=ARG;
			ic->u.dirop=temp2;
			codes2->code=*ic;
			codes2->next=NULL;
			struct InterCodes *codes3;
			codes3=Translate_Args(HashTable,head->lchild->rchild->rchild);
			return combine_code(codes2,codes3);
		}
			struct Operand_ * temp1=new_temp();
			codes1=Translate_Exp(HashTable,head->lchild,temp1,0);
			ic->kind=ARG;
			ic->u.dirop=temp1;
			codes2->code=*ic;
			codes2->next=NULL;
			struct InterCodes *codes3;
			codes3=Translate_Args(HashTable,head->lchild->rchild->rchild);
			return combine_code(combine_code(codes1,codes2),codes3);
	}
	else{
		struct InterCodes *codes2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
		struct InterCode *ic=(struct InterCode*)malloc(sizeof(struct InterCode));
		struct Operand_* temp2=(struct Operand_*)malloc(sizeof(struct Operand_*));
		if(strcmp(head->lchild->lchild->name,"ID")==0&&head->lchild->lchild->rchild==NULL){
			int i=0;
			int bl=0;
			for(i=0;i<arraynum;i++){
				if(strcmp(arraylist[i]->name,head->lchild->lchild->content)==0){
					bl=1;
				}
			}
			for(i=0;i<paramnum;i++){
				if(strcmp(paramlist[i]->name,head->lchild->lchild->content)==0){
					bl=1;
				}
			}
			if(bl==0){
				temp2->kind=VARIABLE;
				temp2->u.value=head->lchild->lchild->content;
			}
			if(bl==1){
				temp2->kind=ARRAY;
				temp2->u.value=head->lchild->lchild->content;
			}
			ic->kind=ARG;
			ic->u.dirop=temp2;
			codes2->code=*ic;
			codes2->next=NULL;
			return codes2;
		}
		if(strcmp(head->lchild->lchild->name,"INT")==0&&head->lchild->lchild->rchild==NULL){
			temp2->kind=CONSTANT;
			temp2->u.var_no=atoi(head->lchild->lchild->content);
			ic->kind=ARG;
			ic->u.dirop=temp2;
			codes2->code=*ic;
			codes2->next=NULL;
			return codes2;
		}
		struct Operand_ * temp1=new_temp();
		struct InterCodes *codes1;
		codes1=Translate_Exp(HashTable,head->lchild,temp1,0);
		ic->kind=ARG;
		ic->u.dirop=temp1;
		codes2->code=*ic;
		codes2->next=NULL;
		return combine_code(codes1,codes2);
	}
}

struct InterCodes* Translate_Cond(struct Node *head,Operand label_true,Operand label_false,struct HashNode* HashTable[]){
		printf("%s\n",head->name);
	if(head->lchild->rchild==NULL){
		Operand t1=new_temp();
		struct InterCodes* temp1=Translate_Exp(HashTable,head,t1,0);
		struct InterCodes* temp2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
		temp2->code.kind=If;
		temp2->code.u.If.temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
		temp2->code.u.If.op=(struct Operand_*)malloc(sizeof(struct Operand_));
		temp2->code.u.If.temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
		temp2->code.u.If.label=(struct Operand_*)malloc(sizeof(struct Operand_));
		temp2->code.u.If.temp1=t1;
		temp2->code.u.If.op->kind=OP;
		temp2->code.u.If.op->u.value="!=";
		temp2->code.u.If.temp2->kind=CONSTANT;
		temp2->code.u.If.temp2->u.var_no=0;
		temp2->code.u.If.label=label_true;
		temp2->next=NULL;
		temp2->prev=NULL;
		struct InterCodes* temp3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
		temp3->code.kind=GOTO;
		temp3->code.u.dirop=label_false;
		temp3->next=NULL;
		temp1=combine_code(temp1,temp2);
		temp1=combine_code(temp1,temp3);
		return temp1;
	}
	
	if(strcmp(head->lchild->rchild->name,"RELOP")==0){
		Operand t1=new_temp();
		printf("%d\n",t1->u.var_no);
		Operand t2=new_temp();
		
		
		struct InterCodes* temp=NULL;
		struct InterCodes* temp3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
		temp3->next=NULL;
		temp3->code.kind=If;
		temp3->code.u.If.temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
		temp3->code.u.If.op=(struct Operand_*)malloc(sizeof(struct Operand_));
		temp3->code.u.If.temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
		temp3->code.u.If.label=(struct Operand_*)malloc(sizeof(struct Operand_));
		if(strcmp(head->lchild->lchild->name,"ID")==0){
			temp3->code.u.If.temp1->kind=VARIABLE;
			temp3->code.u.If.temp1->u.value=head->lchild->lchild->content;
		}
		else if(strcmp(head->lchild->lchild->name,"INT")==0){
			temp3->code.u.If.temp1->kind=CONSTANT;
			temp3->code.u.If.temp1->u.var_no=atoi(head->lchild->lchild->content);
		}
		else{
			struct InterCodes* temp1=Translate_Exp(HashTable,head->lchild,t1,0);
			temp3->code.u.If.temp1=t1;
			temp=temp1;
			
		}
		temp3->code.u.If.op->kind=OP;
		temp3->code.u.If.op->u.value=head->lchild->rchild->content;

		if(strcmp(head->lchild->rchild->rchild->lchild->name,"ID")==0){
			temp3->code.u.If.temp2->kind=VARIABLE;
			temp3->code.u.If.temp2->u.value=head->lchild->rchild->rchild->lchild->content;
		}
		else if(strcmp(head->lchild->rchild->rchild->lchild->name,"INT")==0){
			temp3->code.u.If.temp2->kind=CONSTANT;
			temp3->code.u.If.temp2->u.var_no=atoi(head->lchild->rchild->rchild->lchild->content);
		}
		else{
			struct InterCodes* temp2=Translate_Exp(HashTable,head->lchild->rchild->rchild,t2,0);
			temp3->code.u.If.temp2=t2;
			temp=combine_code(temp,temp2);
		}
		temp3->code.u.If.label=label_true;
		temp3->next=NULL;
		temp3->prev=NULL;

		struct InterCodes* temp4=(struct InterCodes*)malloc(sizeof(struct InterCodes));
		temp4->code.kind=GOTO;
		temp4->code.u.dirop=label_false;
		temp4->next=NULL;
		
		temp=combine_code(temp,temp3);
		temp=combine_code(temp,temp4);

		return temp;
	}
	else if(strcmp(head->lchild->name,"NOT")==0){
		return Translate_Cond(head,label_false,label_true,HashTable);
	}
	else if(strcmp(head->lchild->rchild->name,"AND")==0){
		Operand l1=new_label();
		struct InterCodes* temp1=Translate_Cond(head->lchild,l1,label_false,HashTable);
		struct InterCodes* temp2=Translate_Cond(head->lchild->rchild->rchild,label_true,label_false,HashTable);
		struct InterCodes* temp3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
		temp3->code.kind=LAB;
		temp3->code.u.dirop=l1;
		temp3->next=NULL;
		temp1=combine_code(temp1,temp3);
		temp1=combine_code(temp1,temp2);

		return temp1;
	}
	else if(strcmp(head->lchild->rchild->name,"OR")==0){
		Operand l1=new_label();
		struct InterCodes* temp1=Translate_Cond(head->lchild,label_true,l1,HashTable);
		struct InterCodes* temp2=Translate_Cond(head->lchild->rchild,label_true,label_false,HashTable);
		struct InterCodes* temp3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
		temp3->code.kind=LAB;
		temp3->code.u.dirop=l1;
		temp3->next=NULL;
		temp1=combine_code(temp1,temp3);
		temp1=combine_code(temp1,temp2);

		return temp1;
	}
	else if(strcmp(head->lchild->name,"LP")==0){
			return Translate_Cond(head->lchild->rchild,label_true,label_false,HashTable);
		}
	else{
		Operand t1=new_temp();
		struct InterCodes* temp1=Translate_Exp(HashTable,head,t1,0);
		struct InterCodes* temp2=(struct InterCodes*)malloc(sizeof(struct InterCodes));
		temp2->code.kind=If;
		temp2->code.u.If.temp1=(struct Operand_*)malloc(sizeof(struct Operand_));
		temp2->code.u.If.op=(struct Operand_*)malloc(sizeof(struct Operand_));
		temp2->code.u.If.temp2=(struct Operand_*)malloc(sizeof(struct Operand_));
		temp2->code.u.If.label=(struct Operand_*)malloc(sizeof(struct Operand_));
		temp2->code.u.If.temp1=t1;
		temp2->code.u.If.op->kind=OP;
		temp2->code.u.If.op->u.value="!=";
		temp2->code.u.If.temp2->kind=CONSTANT;
		temp2->code.u.If.temp2->u.var_no=0;
		temp2->code.u.If.label=label_true;
		temp2->next=NULL;
		temp2->prev=NULL;
		
		struct InterCodes* temp3=(struct InterCodes*)malloc(sizeof(struct InterCodes));
		temp3->code.kind=GOTO;
		temp3->code.u.dirop=label_false;
		temp3->next=NULL;
		temp1=combine_code(temp1,temp2);
		temp1=combine_code(temp1,temp3);
		return temp1;
	}

}
