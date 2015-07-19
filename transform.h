#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "translate.h"

typedef struct MemoryNode{
	Operand name;
	int address;
	int size;
	struct MemoryNode* next;
}MemoryNodes;



int var_address(Operand var,int sizes);

int is_equal(Operand v1,Operand v2);

void pre_transform(FILE *fp1);

void transform_codes(struct InterCodes* codes1,FILE *fp1);


