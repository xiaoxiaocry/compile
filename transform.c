#include "transform.h"

MemoryNodes* Memory=NULL;


	


int var_address(Operand var,int size){
	
	if(Memory==NULL){
		Memory=(MemoryNodes*)malloc(sizeof(MemoryNodes));
		Memory->name=var;
		Memory->address=4;
		Memory->size=size;
		Memory->next=NULL;
		
		return 4;
	}
	else{
		MemoryNodes* p=Memory;
		while(p->next!=NULL){
			if(is_equal(p->name,var))
				return p->address;
			p=p->next;
		}
		
		if(is_equal(p->name,var))
			return p->address;
		else{
			MemoryNodes* temp=(MemoryNodes*)malloc(sizeof(MemoryNodes));
			temp->name=var;
			temp->size=size;
			temp->next=NULL;
			temp->address=p->address+p->size;
			p->next=temp;
			return temp->address;
		}
	}
}
			

int is_equal(Operand v1,Operand v2){
	if(v1->kind==v2->kind){
		if(v1->kind==VARIABLE){
			if(strcmp(v1->u.value,v2->u.value)==0)
				return 1;
		}
		else{
			if(v1->u.var_no==v2->u.var_no)
				return 1;
		}
		
	}
	if(v2->kind==ARRAY){
		if(strcmp(v1->u.value,v2->u.value)==0)
			return 1;
	}
	return 0;
}

void pre_transform(FILE *fp1){
	fprintf(fp1,".data\n");
	
	//fprintf(fp1,"_prompt: .asciiz \"Enter an integer:\"\n");
	fprintf(fp1,"\t_ret: .asciiz \"\\n\"\n");
	fprintf(fp1,"\ta: .word 0\n");
	fprintf(fp1,"\t.globl main\n");
	fprintf(fp1,".text\n");
	fprintf(fp1,"read:\n\tli $v0, 5\n\tsyscall\n\tjr $ra\n\n");
	fprintf(fp1,"write:\n\tli $v0, 1\n\tsyscall\n\tli $v0, 4\n\tla $a0, _ret\n\tsyscall\n\tmove $v0, $0\n\tjr $ra\n\n");
}
void transform_codes(struct InterCodes* codes1,FILE *fp1){
	char* a[4];
	int arg_bl=0;
	int i=0;
	int all=4;
	for(i=0;i<4;i++){
		a[i]=NULL;
	}
	pre_transform(fp1);
	while(codes1!=NULL){
		if(codes1==NULL){
			exit(0);
		}
		else{
			struct InterCode ic=codes1->code;
			if(ic.kind==ASSIGN){
				struct Operand_* temp1=ic.u.assign.left;
				struct Operand_* temp2=ic.u.assign.right;
				int first=0;
				int second=1;
				int k_first=-1;
				int k_second=-1;
				int k=0;
				for(k=0;k<4;k++){
					if(a[k]==NULL)
						break;
					if(temp1->kind==VARIABLE){
						if(strcmp(temp1->u.value,a[k])==0){
							k_first=k;
							//fprintf(fp1,"move $t0, $a%d\n",k);
						}
					}
					if(temp2->kind==VARIABLE){
						if(strcmp(temp2->u.value,a[k])==0){
							k_second=k;
							fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
				}
				//if(temp2->kind!=CONSTANT)
					//second=var_address(temp2,4);
				if(temp2->kind==VARIABLE||temp2->kind==TEMP){
					if(k_second==-1){
						int l_second=var_address(temp2,4);
						fprintf(fp1,"lw $t1 %d($t6)\n",l_second);
					}
					
				}
				if(temp1->kind!=ADDRESS){
					if(temp2->kind==CONSTANT){
						fprintf(fp1,"li $t%d, %d",first,temp2->u.var_no);
					}
					else if(temp2->kind==ADDRESS){
						fprintf(fp1,"lw $t%d, 0(t%d)",first,second);
					}
					else if(temp2->kind==CALL){
						if(arg_bl!=1){
						fprintf(fp1,"addi $sp, $sp, -4\n");
						fprintf(fp1,"sw $ra, 0($sp)\n");
						}
						fprintf(fp1,"jal %s\n",temp2->u.value);
						int n=0;
						for(n=all/4;n>1;n--){
							fprintf(fp1,"lw $a%d, %d($sp)\n",all/4-n,all/4-n);
						}
						fprintf(fp1,"lw $ra, %d($sp)\n",all-4);
						fprintf(fp1,"addi $sp, $sp, %d\n",all);
						fprintf(fp1,"move  $t%d, $v0",first);
						all=4;
						arg_bl=0;
					}
					else{
						fprintf(fp1,"move $t%d, $t%d",first,second);
					}
				}
				else{
					if(temp2->kind==CONSTANT){
						fprintf(fp1,"li $t2, %d\n",temp2->u.var_no);
						fprintf(fp1,"sw $t2, 0($t%d)",first);
					}
					else if(temp2->kind==ADDRESS){
						fprintf(fp1,"lw $t2, 0(t%d)\n",second);
						fprintf(fp1,"sw $t2, 0($t%d)",first);
					}
					else{
					fprintf(fp1,"sw $t%d, 0($t%d)",second,first);
					}
				}
				if(k_first!=-1){
					fprintf(fp1,"\n");
					fprintf(fp1,"move a%d $t0",k_first);
				}
				else{

					fprintf(fp1,"\n");
					int l_first=var_address(temp1,4);
					fprintf(fp1,"sw $t0 %d($t6)\n",l_first);
					
				}
				if(k_second!=-1){
					//fprintf(fp1,"\n");
					//fprintf(fp1,"move a%d $t1",k_second);
				}
			}
			if(ic.kind==ASL){
				struct Operand_* temp1=ic.u.assign.left;
				struct Operand_* temp2=ic.u.assign.right;
				//int first=var_address(temp1,4);
				int first=0;
				int second=1;
				int k_first=-1;
				int k_second=-1;
				int k=0;
				for(k=0;k<4;k++){
					if(a[k]==NULL)
						break;
					if(temp1->kind==VARIABLE){
						if(strcmp(temp1->u.value,a[k])==0){
							k_first=k;
							//fprintf(fp1,"move $t0, $a%d\n",k);
						}
					}
					if(temp2->kind==VARIABLE){
						if(strcmp(temp2->u.value,a[k])==0){
							k_second=k;
							fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
				}
				//if(temp2->kind!=CONSTANT)
					//second=var_address(temp2,4);
				if(temp2->kind==CONSTANT){
					fprintf(fp1,"li $t2 %d\n",temp2->u.var_no);
					fprintf(fp1,"sw $t2, 0($t%d)",first);
				}
				else{
					if(k_first==-1){
						int l_first=var_address(temp1,4);
						fprintf(fp1,"lw $t0 %d($t6)\n",l_first);
					}
					if(k_second==-1){
						int l_second=var_address(temp2,4);
						fprintf(fp1,"lw $t1 %d($t6)\n",l_second);
					}
					fprintf(fp1,"sw $t%d, 0($t%d)",second,first);
				}
				if(k_first!=-1){
					fprintf(fp1,"\n");
					fprintf(fp1,"move a%d $t0",k_first);
				}
				if(k_second!=-1){
					//fprintf(fp1,"\n");
					//fprintf(fp1,"move a%d $t1",k_second);
				}
			}
			if(ic.kind==ASR){
				struct Operand_* temp1=ic.u.assign.left;
				struct Operand_* temp2=ic.u.assign.right;
				//int first=var_address(temp1,4);
				int first=0;
				int second=1;
				int k_first=-1;
				int k_second=-1;
				int k=0;
				for(k=0;k<4;k++){
					if(a[k]==NULL)
						break;
					if(temp1->kind==VARIABLE){
						if(strcmp(temp1->u.value,a[k])==0){
							k_first=k;
							//fprintf(fp1,"move $t0, $a%d\n",k);
						}
					}
					if(temp2->kind==VARIABLE){
						if(strcmp(temp2->u.value,a[k])==0){
							k_second=k;
							fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
				}
				if(k_second==-1){
					int l_second=var_address(temp2,4);
					fprintf(fp1,"lw $t1 %d($t6)\n",l_second);
				}
				//if(temp2->kind!=CONSTANT)
					//second=var_address(temp2,4);
				fprintf(fp1,"lw $t%d, 0($t%d)",first,second);
				if(k_first!=-1){
					fprintf(fp1,"\n");
					fprintf(fp1,"move a%d $t0",k_first);
				}
				else{
					fprintf(fp1,"\n");
					int l_first=var_address(temp1,4);
					fprintf(fp1,"sw $t0 %d($t6)\n",l_first);
				}
				if(k_second!=-1){
					//fprintf(fp1,"\n");
					//fprintf(fp1,"move a%d $t1",k_second);
				}
			}
			if(ic.kind==ADD){
				struct Operand_* temp1=ic.u.binop.op1;
				struct Operand_* temp2=ic.u.binop.op2;
				struct Operand_* temp0=ic.u.binop.result;
				//int first=var_address(temp0,4);
				int first=0;
				int second=1;
				//if(temp1->kind!=CONSTANT)
					//second=var_address(temp1,4);
				int third=2;
				//if(temp2->kind!=CONSTANT)
					//third=var_address(temp2,4);
				int k_first=-1;
				int k_second=-1;
				int k_third=-1;
				int k=0;
				for(k=0;k<4;k++){
					if(a[k]==NULL)
						break;
					if(temp1->kind==VARIABLE){
						if(strcmp(temp1->u.value,a[k])==0){
							k_second=k;
							fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
					if(temp2->kind==VARIABLE){
						if(strcmp(temp2->u.value,a[k])==0){
							k_third=k;
							fprintf(fp1,"move $t2, $a%d\n",k);
						}
					}
					if(temp0->kind==VARIABLE){
						if(strcmp(temp0->u.value,a[k])==0){
							k_first=k;
							//fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
				}
				if(temp1->kind==VARIABLE||temp1->kind==TEMP){
					if(k_second==-1){
						int l_second=var_address(temp1,4);
						fprintf(fp1,"lw $t1 %d($t6)\n",l_second);
					}
				}
				else if(temp1->kind==ARRAY){
					if(k_second==-1){
						int l_second=var_address(temp1,4);
						fprintf(fp1,"addi $t1,$t6,%d\n",l_second);
					}
				}
				if(temp2->kind==VARIABLE||temp2->kind==TEMP){
					if(k_third==-1){
						int l_third=var_address(temp2,4);
						fprintf(fp1,"lw $t2 %d($t6)\n",l_third);
					}
				}
				
				if(temp1->kind==CONSTANT&&temp2->kind!=CONSTANT){
					fprintf(fp1,"addi $t%d, $t%d, %d",first,third,temp1->u.var_no);
				}
				if(temp1->kind!=CONSTANT&&temp2->kind==CONSTANT){
					fprintf(fp1,"addi $t%d, $t%d, %d",first,second,temp2->u.var_no);
				}
				if(temp1->kind==CONSTANT&&temp2->kind==CONSTANT){
					fprintf(fp1,"li $t1 %d\n",temp1->u.var_no);
					fprintf(fp1,"addi $t%d, $t1, %d",first,temp2->u.var_no);
				}
				if(temp1->kind!=CONSTANT&&temp2->kind!=CONSTANT){
					fprintf(fp1,"add $t%d, $t%d, $t%d",first,second,third);
				}
				if(k_first!=-1){
					fprintf(fp1,"\n");
					fprintf(fp1,"move a%d $t0",k_first);
				}
				else{
					fprintf(fp1,"\n");
					int l_first=var_address(temp0,4);
					fprintf(fp1,"sw $t0 %d($t6)\n",l_first);
				}
				if(k_second!=-1){
					//fprintf(fp1,"\n");
					//fprintf(fp1,"move a%d $t1",k_second);
				}
			}
			if(ic.kind==SUB){
				struct Operand_* temp1=ic.u.binop.op1;
				struct Operand_* temp2=ic.u.binop.op2;
				struct Operand_* temp0=ic.u.binop.result;
				//int first=var_address(temp0,4);
				int first=0;
				int second=1;
				//if(temp1->kind!=CONSTANT)
					//second=var_address(temp1,4);
				int third=2;
				//if(temp2->kind!=CONSTANT)
					//third=var_address(temp2,4);
				int k_first=-1;
				int k_second=-1;
				int k_third=-1;
				int k=0;
				for(k=0;k<4;k++){
					if(a[k]==NULL)
						break;
					if(temp1->kind==VARIABLE){
						if(strcmp(temp1->u.value,a[k])==0){
							k_second=k;
							fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
					if(temp2->kind==VARIABLE){
						if(strcmp(temp2->u.value,a[k])==0){
							k_third=k;
							fprintf(fp1,"move $t2, $a%d\n",k);
						}
					}
					if(temp0->kind==VARIABLE){
						if(strcmp(temp0->u.value,a[k])==0){
							k_first=k;
							//fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
				}
				if(temp1->kind==VARIABLE||temp1->kind==TEMP){
					if(k_second==-1){
						int l_second=var_address(temp1,4);
						fprintf(fp1,"lw $t1 %d($t6)\n",l_second);
					}
				}
				if(temp2->kind==VARIABLE||temp2->kind==TEMP){
					if(k_third==-1){
						int l_third=var_address(temp2,4);
						fprintf(fp1,"lw $t2 %d($t6)\n",l_third);
					}
				}
				
		
				if(temp1->kind==CONSTANT&&temp2->kind!=CONSTANT){
					fprintf(fp1,"li $t1 %d\n",temp1->u.var_no);
					fprintf(fp1,"sub $t%d, $t1, $t%d",first,third);
				}
				if(temp1->kind!=CONSTANT&&temp2->kind==CONSTANT){
					fprintf(fp1,"addi $t%d, $t%d, -%d",first,second,temp2->u.var_no);
				}
				if(temp1->kind==CONSTANT&&temp2->kind==CONSTANT){
					fprintf(fp1,"li $t1 %d\n",temp1->u.var_no);
					fprintf(fp1,"addi $t%d, $t1, -%d",first,temp2->u.var_no);
				}
				if(temp1->kind!=CONSTANT&&temp2->kind!=CONSTANT){
					fprintf(fp1,"sub $t%d, $t%d, $t%d",first,second,third);
				}
				if(k_first!=-1){
					fprintf(fp1,"\n");
					fprintf(fp1,"move a%d $t0",k_first);
				}
				else{
					fprintf(fp1,"\n");
					int l_first=var_address(temp0,4);
					fprintf(fp1,"sw $t0 %d($t6)\n",l_first);
				}
				if(k_second!=-1){
					//fprintf(fp1,"\n");
					//fprintf(fp1,"move a%d $t1",k_second);
				}
			}
			if(ic.kind==MUL){
				struct Operand_* temp1=ic.u.binop.op1;
				struct Operand_* temp2=ic.u.binop.op2;
				struct Operand_* temp0=ic.u.binop.result;
				//int first=var_address(temp0,4);
				int first=0;
				int second=1;
				//if(temp1->kind!=CONSTANT)
					//second=var_address(temp1,4);
				int third=2;
				//if(temp2->kind!=CONSTANT)
					//third=var_address(temp2,4);
				int k_first=-1;
				int k_second=-1;
				int k_third=-1;
				int k=0;
				for(k=0;k<4;k++){
					if(a[k]==NULL)
						break;
					if(temp1->kind==VARIABLE){
						if(strcmp(temp1->u.value,a[k])==0){
							k_second=k;
							fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
					if(temp2->kind==VARIABLE){
						if(strcmp(temp2->u.value,a[k])==0){
							k_third=k;
							fprintf(fp1,"move $t2, $a%d\n",k);
						}
					}
					if(temp0->kind==VARIABLE){
						if(strcmp(temp0->u.value,a[k])==0){
							k_first=k;
							//fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
				}

				if(temp1->kind==VARIABLE||temp1->kind==TEMP){
					if(k_second==-1){
						int l_second=var_address(temp1,4);
						fprintf(fp1,"lw $t1 %d($t6)\n",l_second);
					}
				}
				if(temp2->kind==VARIABLE||temp2->kind==TEMP){
					if(k_third==-1){
						int l_third=var_address(temp2,4);
						fprintf(fp1,"lw $t2 %d($t6)\n",l_third);
					}
				}
				if(temp1->kind==CONSTANT&&temp2->kind!=CONSTANT){
					fprintf(fp1,"li $t1 %d\n",temp1->u.var_no);
					fprintf(fp1,"mul $t%d, $t%d, $t1",first,third);
				}
				if(temp1->kind!=CONSTANT&&temp2->kind==CONSTANT){
					fprintf(fp1,"li $t2 %d\n",temp2->u.var_no);
					fprintf(fp1,"mul $t%d, $t%d, $t2",first,second);
				}
				if(temp1->kind==CONSTANT&&temp2->kind==CONSTANT){
					fprintf(fp1,"li $t1 %d\n",temp1->u.var_no);
					fprintf(fp1,"li $t2 %d\n",temp2->u.var_no);
					fprintf(fp1,"mul $t%d, $t1, $t2",first);
				}
				if(temp1->kind!=CONSTANT&&temp2->kind!=CONSTANT){
					fprintf(fp1,"mul $t%d, $t%d, $t%d",first,second,third);
				}
				if(k_first!=-1){
					fprintf(fp1,"\n");
					fprintf(fp1,"move a%d $t0",k_first);
				}
				else{
					fprintf(fp1,"\n");
					int l_first=var_address(temp0,4);
					fprintf(fp1,"sw $t0 %d($t6)\n",l_first);
				}
				if(k_second!=-1){
					//fprintf(fp1,"\n");
					//fprintf(fp1,"move a%d $t1",k_second);
				}
			}
			if(ic.kind==DV){
				struct Operand_* temp1=ic.u.binop.op1;
				struct Operand_* temp2=ic.u.binop.op2;
				struct Operand_* temp0=ic.u.binop.result;
				//int first=var_address(temp0,4);
				int first=0;
				int second=1;
				//if(temp1->kind!=CONSTANT)
					//second=var_address(temp1,4);
				int third=2;
				//if(temp2->kind!=CONSTANT)
				//	third=var_address(temp2,4);
				int k_first=-1;
				int k_second=-1;
				int k_third=-1;
				int k=0;
				for(k=0;k<4;k++){

					if(a[k]==NULL)
						break;
					if(temp1->kind==VARIABLE){
						if(strcmp(temp1->u.value,a[k])==0){
							k_second=k;
							fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
					if(temp2->kind==VARIABLE){
						if(strcmp(temp2->u.value,a[k])==0){
							k_third=k;
							fprintf(fp1,"move $t2, $a%d\n",k);
						}
					}
					if(temp0->kind==VARIABLE){
						if(strcmp(temp0->u.value,a[k])==0){
							k_first=k;
							//fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
				}
				
				if(temp1->kind==VARIABLE||temp1->kind==TEMP){
					if(k_second==-1){
						int l_second=var_address(temp1,4);
						fprintf(fp1,"lw $t1 %d($t6)\n",l_second);
					}
				}
				if(temp2->kind==VARIABLE||temp2->kind==TEMP){
					if(k_third==-1){
						int l_third=var_address(temp2,4);
						fprintf(fp1,"lw $t2 %d($t6)\n",l_third);
					}
				}


				if(temp1->kind==CONSTANT&&temp2->kind!=CONSTANT){
					fprintf(fp1,"li $t1 %d\n",temp1->u.var_no);
					fprintf(fp1,"div $t%d, $t1, $t%d\n",first,third);
					fprintf(fp1,"mflo $t%d",first);
				}
				if(temp1->kind!=CONSTANT&&temp2->kind==CONSTANT){
					fprintf(fp1,"li $t2 %d\n",temp2->u.var_no);
					fprintf(fp1,"div $t%d, $t%d, $t2\n",first,second);
					fprintf(fp1,"mflo $t%d",first);
				}
				if(temp1->kind==CONSTANT&&temp2->kind==CONSTANT){
					fprintf(fp1,"li $t1, %d\n",temp1->u.var_no);
					fprintf(fp1,"li $t2, %d\n",temp2->u.var_no);
					fprintf(fp1,"div $t%d, $t1, $t2\n",first);
					fprintf(fp1,"mflo $t%d",first);
				}
				if(temp1->kind!=CONSTANT&&temp2->kind!=CONSTANT){
					fprintf(fp1,"mul $t%d, $t%d, $t%d",first,second,third);
					fprintf(fp1,"mflo $t%d",first);
				}
				if(k_first!=-1){
					fprintf(fp1,"\n");
					fprintf(fp1,"move a%d $t0",k_first);
				}
				else{
					fprintf(fp1,"\n");
					int l_first=var_address(temp0,4);
					fprintf(fp1,"sw $t0 %d($t6)\n",l_first);
				}
				if(k_second!=-1){
					//fprintf(fp1,"\n");
					//fprintf(fp1,"move a%d $t1",k_second);
				}
			}
			if(ic.kind==READD){
				struct Operand_* temp1=ic.u.dirop;
				//int first=var_address(temp1,4);
				int first=0;
				fprintf(fp1,"addi $sp, $sp, -4\n");
				fprintf(fp1,"sw $ra, 0($sp)\n");
				fprintf(fp1,"jal read\n");
				fprintf(fp1,"lw $ra, 0($sp)\n");
				fprintf(fp1,"addi $sp, $sp, 4\n");
				fprintf(fp1,"move $t%d, $v0\n",first);
				int l_first=var_address(temp1,4);
				fprintf(fp1,"sw $t%d,%d($t6)",first,l_first);
			}
			if(ic.kind==WRITEE){
				struct Operand_* temp1=ic.u.dirop;
				int first=0;
				//if(temp1->kind!=CONSTANT){
				//	first=var_address(temp1,4);
				//}
				int k_first=-1;
				int k=0;
				for(k=0;k<4;k++){
					if(a[k]==NULL)
						break;
					if(temp1->kind==VARIABLE){
						if(strcmp(temp1->u.value,a[k])==0){
							k_first=k;
							fprintf(fp1,"move $t0, $a%d\n",k);
						}
					}
				}
				if(temp1->kind==CONSTANT){
					fprintf(fp1,"li $t2, %d\n",temp1->u.var_no);
					fprintf(fp1,"move $a0, $t2\n");
				}
				else{
					int l_first=var_address(temp1,4);
					fprintf(fp1,"lw $t%d,%d($t6)\n",first,l_first);
					fprintf(fp1,"move $a0, $t%d\n",first);
				}
					fprintf(fp1,"addi $sp, $sp, -4\n");
					fprintf(fp1,"sw $ra, 0($sp)\n");
					fprintf(fp1,"jal write\n");
					fprintf(fp1,"lw $ra, 0($sp)\n");
					fprintf(fp1,"addi $sp, 4");
				if(k_first!=-1){
					fprintf(fp1,"\n");
					fprintf(fp1,"move a%d $t0",k_first);
				}
			}
			if(ic.kind==FUNCTION){
				int k=0;
				for(k=0;k<4;k++)
					a[k]=NULL;
				struct Operand_* temp1=ic.u.dirop;
				fprintf(fp1,"\n");
				fprintf(fp1,"%s:\n",temp1->u.value);

				if(strcmp(temp1->u.value,"main")==0)
				fprintf(fp1,"la $t6,a\n");
			}
			if(ic.kind==PARAM){
				int j=0;
				while(a[j]!=NULL){
					j++;
				}
				if(j==4){
					//fprintf(fp1,"the function has too mach param to run\n");
				}
				else
					a[j]=ic.u.dirop->u.value;
			}
			if(ic.kind==LAB){
				struct Operand_* temp1=ic.u.dirop;
				fprintf(fp1,"label%d:",temp1->u.var_no);
			}
			if(ic.kind==RETURNN){
				struct Operand_* temp1=ic.u.dirop;
				int first=0;
				//if(temp1->kind!=CONSTANT)
					//first=var_address(temp1,4);
				int k_first=-1;
				int k=0;
				for(k=0;k<4;k++){
					if(a[k]==NULL)
						break;
					if(temp1->kind==VARIABLE){
						if(strcmp(temp1->u.value,a[k])==0){
							k_first=k;
							fprintf(fp1,"move $t0, $a%d\n",k);
						}
					}
				}
				if(temp1->kind==VARIABLE||temp1->kind==TEMP){
					if(k_first==-1){
						int l_first=var_address(temp1,4);
						fprintf(fp1,"lw $t0 %d($t6)\n",l_first);
					}
				}
				if(temp1->kind!=CONSTANT){
					fprintf(fp1,"move $v0, $t%d\n",first);
				}
				else{
					fprintf(fp1,"li $t2, %d\n",temp1->u.var_no);
					fprintf(fp1,"move $v0, $t2\n");
				}
				fprintf(fp1,"jr $ra");
			}
			if(ic.kind==GOTO){
				struct Operand_* temp1=ic.u.dirop;
				fprintf(fp1,"j label%d",temp1->u.var_no);
			}
			if(ic.kind==DEC){
				struct Operand_* temp1=ic.u.assign.left;
				struct Operand_* temp2=ic.u.assign.right;
				var_address(temp1,temp2->u.var_no);
			}
			if(ic.kind==ARG){
				struct Operand_* temp1=ic.u.dirop;
				int l_third=var_address(temp1,4);
				fprintf(fp1,"lw $t0 %d($t6)\n",l_third);
				if(arg_bl==0){
					int a_size=0;
					while(a[a_size]!=NULL){
						a_size++;
					}
					a_size++;
					a_size=a_size*4;
					fprintf(fp1,"addi $sp, $sp, -%d\n",a_size);
					int m=0;
					for(m=a_size/4;m>1;m--){
						fprintf(fp1,"sw $a%d, %d($sp)\n",a_size/4-m,a_size/4-m);
					}
					fprintf(fp1,"sw $ra,%d($sp)\n",a_size-4);
					all=a_size;
					arg_bl=1;
					i=0;
					//fprintf(fp1,"move ")
					fprintf(fp1,"move $a%d, $t0",i);
					i++;
				}
				else{
					fprintf(fp1,"move $a%d,$t0",i);
					i++;
				}
			}
			if(ic.kind==If){
				struct Operand_* temp1=ic.u.If.temp1;
				struct Operand_* temp2=ic.u.If.op;
				struct Operand_* temp3=ic.u.If.temp2;
				struct Operand_* temp4=ic.u.If.label;	
				
				int k_first=-1;
				int k_second=-1;
				int k=0;
				for(k=0;k<4;k++){
					if(a[k]==NULL)
						break;
					if(temp1->kind==VARIABLE){
						if(strcmp(temp1->u.value,a[k])==0){
							k_first=k;
							fprintf(fp1,"move $t0, $a%d\n",k);
						}
					}
					if(temp3->kind==VARIABLE){
						if(strcmp(temp3->u.value,a[k])==0){
							k_second=k;
							fprintf(fp1,"move $t1, $a%d\n",k);
						}
					}
				}
				if(temp1->kind==VARIABLE||temp1->kind==TEMP){
					if(k_first==-1){
						int l_first=var_address(temp1,4);
						fprintf(fp1,"lw $t0 %d($t6)\n",l_first);
					}
				}
				if(temp3->kind==VARIABLE||temp3->kind==TEMP){
					if(k_second==-1){
						int l_second=var_address(temp3,4);
						fprintf(fp1,"lw $t1 %d($t6)\n",l_second);
					}
				}
				if(strcmp(temp2->u.value,"==")==0){
					if(temp1->kind==CONSTANT&&temp3->kind!=CONSTANT){
						int second=1;
						//int second=var_address(temp3,4);
						fprintf(fp1,"li $t2, %d\n",temp1->u.var_no);
						fprintf(fp1,"beq $t2, $t%d, label%d",second,temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind==CONSTANT){
						//int first=var_address(temp1,4);	
						int first=0;
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"beq $t%d, $t2, label%d",first,temp4->u.var_no);
					}
					if(temp1->kind==CONSTANT&&temp3->kind==CONSTANT){
						fprintf(fp1,"li $t1, %d\n",temp1->u.var_no);
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"beq $t1, $t2, label%d",temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind!=CONSTANT){
						//int first=var_address(temp1,4);
						//int second=var_address(temp3,4);
						int first=0;
						int second=1;
						fprintf(fp1,"beq $t%d, $t%d, label%d",first,second,temp4->u.var_no);
					}
				}
				if(strcmp(temp2->u.value,"!=")==0){
					if(temp1->kind==CONSTANT&&temp3->kind!=CONSTANT){
						//int second=var_address(temp3,4);
						int second=1;
						fprintf(fp1,"li $t2, %d\n",temp1->u.var_no);
						fprintf(fp1,"bne $t2, $t%d, label%d",second,temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind==CONSTANT){
						//int first=var_address(temp1,4);
						int first=0;
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"bne $t%d, $t2, label%d",first,temp4->u.var_no);
					}
					if(temp1->kind==CONSTANT&&temp3->kind==CONSTANT){
						fprintf(fp1,"li $t1, %d\n",temp1->u.var_no);
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"bne $t1, $t2, label%d",temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind!=CONSTANT){
						//int first=var_address(temp1,4);
						//int second=var_address(temp3,4);
						int first=0;
						int second=1;
						fprintf(fp1,"bne $t%d, $t%d, label%d",first,second,temp4->u.var_no);
					}
				}
				if(strcmp(temp2->u.value,">")==0){
					if(temp1->kind==CONSTANT&&temp3->kind!=CONSTANT){
						//int second=var_address(temp3,4);
						int second=1;
						fprintf(fp1,"li $t2, %d\n",temp1->u.var_no);
						fprintf(fp1,"bgt $t2, $t%d, label%d",second,temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind==CONSTANT){
						//int first=var_address(temp1,4);
						int first=0;
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"bgt $t%d, $t2, label%d",first,temp4->u.var_no);
					}
					if(temp1->kind==CONSTANT&&temp3->kind==CONSTANT){
						fprintf(fp1,"li $t1, %d\n",temp1->u.var_no);
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"bgt $t1, $t2, label%d",temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind!=CONSTANT){
						//int first=var_address(temp1,4);
						//int second=var_address(temp3,4);
						int first=0;
						int second=1;
						fprintf(fp1,"bgt $t%d, $t%d, label%d",first,second,temp4->u.var_no);
					}
				}
				if(strcmp(temp2->u.value,"<")==0){
					if(temp1->kind==CONSTANT&&temp3->kind!=CONSTANT){
						//int second=var_address(temp3,4);
						int second=1;
						fprintf(fp1,"li $t2, %d\n",temp1->u.var_no);
						fprintf(fp1,"blt $t2, $t%d, label%d",second,temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind==CONSTANT){
						//int first=var_address(temp1,4);
						int first=0;
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"blt $t%d, $t2, label%d",first,temp4->u.var_no);
					}
					if(temp1->kind==CONSTANT&&temp3->kind==CONSTANT){
						fprintf(fp1,"li $t1, %d\n",temp1->u.var_no);
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"blt $t1, $t2, label%d",temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind!=CONSTANT){
						//int first=var_address(temp1,4);
						//int second=var_address(temp3,4);
						int first=0;
						int second=1;
						fprintf(fp1,"blt $t%d, $t%d, label%d",first,second,temp4->u.var_no);
					}
				}
				if(strcmp(temp2->u.value,">=")==0){
					if(temp1->kind==CONSTANT&&temp3->kind!=CONSTANT){
						//int second=var_address(temp3,4);
						int second=1;
						fprintf(fp1,"li $t2, %d\n",temp1->u.var_no);
						fprintf(fp1,"bge $t2, $t%d, label%d",second,temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind==CONSTANT){
						//int first=var_address(temp1,4);
						int first=0;
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"bge $t%d, $t2, label%d",first,temp4->u.var_no);
					}
					if(temp1->kind==CONSTANT&&temp3->kind==CONSTANT){
						fprintf(fp1,"li $t1, %d\n",temp1->u.var_no);
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"bge $t1, $t2, label%d",temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind!=CONSTANT){
						//int first=var_address(temp1,4);
						//int second=var_address(temp3,4);
						int first=0;
						int second=1;
						fprintf(fp1,"bge $t%d, $t%d, label%d",first,second,temp4->u.var_no);
					}
				}
				if(strcmp(temp2->u.value,"<=")==0){
					if(temp1->kind==CONSTANT&&temp3->kind!=CONSTANT){
						//int second=var_address(temp3,4);
						int second=1;
						fprintf(fp1,"li $t2, %d\n",temp1->u.var_no);
						fprintf(fp1,"ble $t2, $t%d, label%d",second,temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind==CONSTANT){
						//int first=var_address(temp1,4);
						int first=0;
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"ble $t%d, $t2, label%d",first,temp4->u.var_no);
					}
					if(temp1->kind==CONSTANT&&temp3->kind==CONSTANT){
						fprintf(fp1,"li $t1, %d\n",temp1->u.var_no);
						fprintf(fp1,"li $t2, %d\n",temp3->u.var_no);
						fprintf(fp1,"ble $t1, $t2, label%d",temp4->u.var_no);
					}
					if(temp1->kind!=CONSTANT&&temp3->kind!=CONSTANT){
						//int first=var_address(temp1,4);
						//int second=var_address(temp3,4);
						int first=0;
						int second=1;
						fprintf(fp1,"ble $t%d, $t%d, label%d",first,second,temp4->u.var_no);
					}
				}
			}
			fprintf(fp1,"\n");
			fprintf(fp1,"\n");
			codes1=codes1->next;
		}
	}

}
