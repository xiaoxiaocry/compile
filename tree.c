
#include "tree.h"
/*struct Node* createNode(char* n,int l){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	
	temp->name=n;
	temp->line=l;
	return temp;
}*/
struct Node* createNode(char* n,int l,char* c){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->bl=0;
	temp->name=n;
	temp->line=l;
	temp->content=c;
	return temp;
}
void be_lchild(struct Node *f,struct Node *s){
	f->lchild = s;
}

void be_rchild(struct Node *f,struct Node *s){
	f->rchild = s;
}
void printTree(struct Node* head,int n){
	if(head!=NULL){
		int i;
		for(i=0;i<n;i++)
			printf(" ");
		if(head->line!=0)
			printf("%s  (%d)\n",head->name,head->line);
		else if(head->content!=NULL)
			printf("%s : %s\n",head->name,head->content);
		else
			printf("%s\n",head->name);
	}
	
	if(head->lchild!=NULL)
		printTree(head->lchild,n+1);
	if(head->rchild!=NULL)	
		printTree(head->rchild,n);
}

void CreatTable(struct HashNode* HashTable[],struct Node *head,int n){
  	if(head!=NULL){
		if(head->line!=0){
		if((strcmp(head->name,"Specifier"))==0){
			if(strcmp(head->lchild->name,"TYPE")==0){
			struct Node *p=head->rchild;
			if((strcmp(p->name,"DecList")==0)){
				while(p->lchild->rchild!=NULL){
					struct Node *pp=p->lchild->lchild->lchild;
					while(strcmp(pp->name,"ID")!=0){
						pp=pp->lchild;
					}
					//printf("%s","1");
					int i=hash(pp->content);
					//printf("%s\n",p->lchild->lchild->lchild->content);
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						//printf("%s","1");
						while(q->next!=NULL){
						q=q->next;
						}
						if(p->lchild->lchild->lchild->bl==0){
						p->lchild->lchild->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						newHashNode->kind="Var";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
 						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->lchild->line,newHashNode->name);
						else
						q->next=newHashNode;}
					}
					else{
						//printf("%s","2");
						if(p->lchild->lchild->lchild->bl==0){
						p->lchild->lchild->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Var";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q=newHashNode;
						HashTable[i]=q;
						//printf("%s\n","1");
						//printf("%s %s %s\n",q->type,q->name,q->kind);
					}
					}
					p=p->lchild->rchild->rchild;
				}
					//printf("%s","1");
					//printf("%s %s\n","1",p->lchild->lchild->lchild->content);
					struct Node *pp=p->lchild->lchild->lchild;
					while(strcmp(pp->name,"ID")!=0){
						pp=pp->lchild;
					}
					//printf("%s","1");
					int i=hash(pp->content);
					//printf("%s %s\n","1",p->lchild->lchild->lchild->content);
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						while(q->next!=NULL){
						q=q->next;
						}
						if(p->lchild->lchild->lchild->bl==0){
						p->lchild->lchild->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Var";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->lchild->line,newHashNode->name);
						else
						q->next=newHashNode;}
					}
					else{
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Var";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q=newHashNode;
						//printf("%s\n","1");
						HashTable[i]=q;
						//printf("%s %s %s\n",HashTable[i]->type,HashTable[i]->name,HashTable[i]->kind);
						}
					}
			}
			if((strcmp(p->name,"ExtDecList"))==0){
					while(p->lchild->rchild!=NULL){
					//printf("%s","1");
					struct Node *pp=p->lchild->lchild->lchild;
					while(strcmp(pp->name,"ID")!=0){
						pp=pp->lchild;
					}
					//printf("%s","1");
					int i=hash(pp->content);
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						//printf("%s","1");
						while(q->next!=NULL){
						q=q->next;
						}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Var";
						struct Node *ap=pp;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->line,newHashNode->name);
						else
						q->next=newHashNode;}
					}
					else{
						//printf("%s","2");
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Var";
						struct Node *ap=pp;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q=newHashNode;
						HashTable[i]=q;}
					}
					p=p->lchild->rchild->rchild;
				}
					//printf("%s","1");
					struct Node *pp=p->lchild->lchild->lchild;
					while(strcmp(pp->name,"ID")!=0){
						pp=pp->lchild;
					}
					//printf("%s","1");
					int i=hash(pp->content);
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						while(q->next!=NULL){
						q=q->next;
						}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Var";
						struct Node *ap=pp;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->line,newHashNode->name);
						else
						q->next=newHashNode;}
					}
					else{
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Var";
						struct Node *ap=pp;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q=newHashNode;
						HashTable[i]=q;}
					}
				}
			if((strcmp(p->name,"FunDec"))==0){
					//printf("%s","1");
					int i=hash(p->lchild->content);
					struct HashNode *SuggestNode=NULL;
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						//printf("%s","1");
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->kind="Func";
						struct Node *r=p->lchild->rchild->rchild;
						struct HashNode *FuncNode=NULL;
						while(q->next!=NULL){
							q=q->next;
						}
						if(strcmp(r->name,"RP")==0){
							FuncNode=NULL;
						}
						if(strcmp(r->name,"VarList")==0){
							while(r->lchild->rchild!=NULL){
							struct Node *pp=r->lchild->lchild->rchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
								struct HashNode *s=FuncNode;
								if(s!=NULL){
									while(s->next!=NULL){
									s=s->next;
									}
								if(pp->bl==0){
								pp->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=pp->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
								struct HashNode *qq=SuggestNode;
								if(qq!=NULL){
									while(qq->next!=NULL){
										qq=qq->next;
									}
									qq->next=newFuncNode;
								}
								else{
									SuggestNode=newFuncNode;
								}

						struct Node *ap=r->lchild->lchild->rchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
								s->next=newFuncNode;}
								}
								else{
								if(pp->bl==0){
								pp->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=pp->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
								struct HashNode *qq=SuggestNode;
								if(qq!=NULL){
									while(qq->next!=NULL){
										qq=qq->next;
									}
									qq->next=newFuncNode;
								}
								else{
									SuggestNode=newFuncNode;
								}
						struct Node *ap=r->lchild->lchild->rchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								q=newFuncNode;
								FuncNode=q;}
								}
								r=r->lchild->rchild->rchild;
							}
							struct HashNode *s=FuncNode;
							if(s!=NULL){
								while(s->next!=NULL){
									s=s->next;
								}
							struct Node *pp=r->lchild->lchild->rchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
							if(pp->bl==0){
							r->lchild->lchild->rchild->lchild->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=pp->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->next=NULL;
							newFuncNode->kind="Var";
								struct HashNode *qq=SuggestNode;
								if(qq!=NULL){
									while(qq->next!=NULL){
										qq=qq->next;
									}
									qq->next=newFuncNode;
								}
								else{
									SuggestNode=newFuncNode;
								}
						struct Node *ap=r->lchild->lchild->rchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
							s->next=newFuncNode;}
							}
							else{
							struct Node *pp=r->lchild->lchild->rchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
								if(pp->bl==0){
								pp->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=pp->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
								struct HashNode *qq=SuggestNode;
								if(qq!=NULL){
									while(qq->next!=NULL){
										qq=qq->next;
									}
									qq->next=newFuncNode;
								}
								else{
									SuggestNode=newFuncNode;
								}
						struct Node *ap=r->lchild->lchild->rchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								s=newFuncNode;
								FuncNode=s;}
							}
						}
						newHashNode->next=NULL;
						newHashNode->Func=FuncNode;
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 4 at Line %d: Redefined function \"%s\".\n",p->line,newHashNode->name);
						else
						q->next=newHashNode;
					}
					else{
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->kind="Func";
						struct Node *r=p->lchild->rchild->rchild;
						struct HashNode *FuncNode=NULL;
						if(strcmp(r->name,"RP")==0){
							FuncNode=NULL;
						}
						if(strcmp(r->name,"VarList")==0){
							while(r->lchild->rchild!=NULL){
								struct HashNode *s=FuncNode;
								if(s!=NULL){
									while(s->next!=NULL){
									s=s->next;
									}
							struct Node *pp=r->lchild->lchild->rchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
								if(pp->bl==0){
								pp->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=pp->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
								struct HashNode *qq=SuggestNode;
								if(qq!=NULL){
									while(qq->next!=NULL){
										qq=qq->next;
									}
									qq->next=newFuncNode;
								}
								else{
									SuggestNode=newFuncNode;
								}
						struct Node *ap=r->lchild->lchild->rchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
								s->next=newFuncNode;}
								}
								else{
							struct Node *pp=r->lchild->lchild->rchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
								if(pp->bl==0){
								pp->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=pp->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
										struct HashNode *qq=SuggestNode;
								if(qq!=NULL){
									while(qq->next!=NULL){
										qq=qq->next;
									}
									qq->next=newFuncNode;
								}
								else{
									SuggestNode=newFuncNode;
								}
						struct Node *ap=r->lchild->lchild->rchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								q=newFuncNode;
								FuncNode=q;}
								}
								r=r->lchild->rchild->rchild;
							}
							struct HashNode *s=FuncNode;
							if(s!=NULL){
								while(s->next!=NULL){
									s=s->next;
								}
							struct Node *pp=r->lchild->lchild->rchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
							if(pp->bl==0){
							pp->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=pp->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->next=NULL;
							newFuncNode->kind="Var";
								struct HashNode *qq=SuggestNode;
								if(qq!=NULL){
									while(qq->next!=NULL){
										qq=qq->next;
									}
									qq->next=newFuncNode;
								}
								else{
									SuggestNode=newFuncNode;
								}
						struct Node *ap=r->lchild->lchild->rchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
							s->next=newFuncNode;}
							}
							else{
							struct Node *pp=r->lchild->lchild->rchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
								if(pp->bl==0){
								pp->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=pp->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
								struct HashNode *qq=SuggestNode;
								if(qq!=NULL){
									while(qq->next!=NULL){
										qq=qq->next;
									}
									qq->next=newFuncNode;
								}
								else{
									SuggestNode=newFuncNode;
								}
						struct Node *ap=r->lchild->lchild->rchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								s=newFuncNode;
								FuncNode=s;}
							}
						}
						newHashNode->next=NULL;
						newHashNode->Func=FuncNode;
						q=newHashNode;
						HashTable[i]=q;

					}
						while(SuggestNode!=NULL){
							struct HashNode *newSuggestNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							int j=hash(SuggestNode->name);
							struct HashNode *qq=HashTable[j];
							newSuggestNode->name=SuggestNode->name;
							newSuggestNode->type=SuggestNode->type;
							newSuggestNode->kind=SuggestNode->kind;
							newSuggestNode->next=NULL;
							newSuggestNode->Func=NULL;
							newSuggestNode->arraysize=NULL;
							if(qq!=NULL){
								while(qq->next!=NULL){
									qq=qq->next;
								}
								qq->next=newSuggestNode;
							}
							else{
								HashTable[j]=newSuggestNode;
							}
							SuggestNode=SuggestNode->next;
						}
				}//////////////////////////
				}
		if(strcmp(head->lchild->name,"StructSpecifier")==0){///
			struct Node *p=head->rchild;
			if(strcmp(p->name,"SEMI")==0){
				if(strcmp(head->lchild->lchild->rchild->name,"OptTag")==0){
					struct Node *p=head->lchild->lchild->rchild;/////////////////////
					int i=hash(p->lchild->content);
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						while(q->next!=NULL){
							q=q->next;
						}
						if(p->lchild->bl==0){
						p->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type="STRUCT";
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						struct HashNode *FuncNode=NULL;
						newHashNode->Func=FuncNode;
						struct Node *r=p->rchild->rchild;
						while(r!=NULL){
							struct Node *s=r->lchild->lchild->rchild;
							while(s->lchild->rchild!=NULL){
							struct Node *pp=s->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
								if(pp->bl==0){
								pp->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=pp->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								newFuncNode->next=NULL;
								if(FuncNode==NULL){
									FuncNode=newFuncNode;
								}
								else{
									struct HashNode *t=FuncNode;
									while(t->next!=NULL){
										t=t->next;
									}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
									t->next=newFuncNode;
								}}
								s=s->lchild->rchild->rchild;
							}
							struct Node *pp=s->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
							if(pp->bl==0){
							pp->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=pp->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
							newFuncNode->next=NULL;
							if(FuncNode==NULL){
								FuncNode=newFuncNode;
							}
							else{
								struct HashNode *t=FuncNode;
								while(t->next!=NULL){
									t=t->next;
								}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
								t->next=newFuncNode;
							}}
							r=r->lchild->rchild;
						}
						struct Node *s=r->lchild->lchild->rchild;
						while(s->lchild->rchild!=NULL){
							struct Node *pp=s->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newFuncNode->type=r->lchild->lchild->lchild->content;
						//printf("%s\n",newFuncNode->type);
						newFuncNode->name=pp->content;
						//printf("%s\n",newFuncNode->name);
						newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						newFuncNode->next=NULL;
						if(FuncNode==NULL){
							FuncNode=newFuncNode;
						}
						else{
							struct HashNode *t=FuncNode;
							while(t->next!=NULL){
								t=t->next;
							}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
								t->next=newFuncNode;
						}}
						s=s->lchild->rchild->rchild;
					}
						/*struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newFuncNode->type=r->lchild->lchild->lchild->content;
						printf("%s",newFuncNode->type);
						newFuncNode->name=s->lchild->lchild->lchild->content;
						printf("%s",newFuncNode->name);
						newFuncNode->kind="Var";
						newFuncNode->next=NULL;
						if(FuncNode==NULL){
							FuncNode=newFuncNode;
						}
						else{
							struct HashNode *t=FuncNode;
							while(t->next!=NULL){
								t=t->next;
							}
							t->next=newFuncNode;
						}*/
					newHashNode->kind="Struct";
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 16 at Line %d: Duplicated name \"%s\".\n",p->line,newHashNode->name);
						else
					q->next=newHashNode;}
					}
					else{
						if(p->lchild->bl==0){
						p->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type="STRUCT";
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						struct HashNode *FuncNode=NULL;
						newHashNode->Func=FuncNode;
						struct Node *r=p->rchild->rchild;
						while(r!=NULL){
							struct Node *s=r->lchild->lchild->rchild;
							while(s->lchild->rchild!=NULL){
							struct Node *pp=s->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
								if(pp->bl==0){
								pp->bl=1;								
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=pp->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								newFuncNode->next=NULL;
								if(FuncNode==NULL){
									FuncNode=newFuncNode;
									newHashNode->Func=FuncNode;
								}
								else{
									struct HashNode *t=FuncNode;
									while(t->next!=NULL){
										t=t->next;
									}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
									t->next=newFuncNode;
								}}
								s=s->lchild->rchild->rchild;
							}
							struct Node *pp=s->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
							if(pp->bl==0){
							pp->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=pp->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
							newFuncNode->next=NULL;
							if(FuncNode==NULL){
								FuncNode=newFuncNode;
								newHashNode->Func=FuncNode;
							}
							else{
								struct HashNode *t=FuncNode;
								while(t->next!=NULL){
									t=t->next;
								}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
								t->next=newFuncNode;
							}}
							r=r->lchild->rchild;
						}
					newHashNode->kind="Struct";

					q=newHashNode;
					HashTable[i]=q;}
					
					}
				}
				
			}
			if((strcmp(p->name,"DecList")==0)){
				if(strcmp(head->lchild->lchild->rchild->name,"Tag")==0){
				while(p->lchild->rchild!=NULL){
					//printf("%s","1");
					int i=hash(p->lchild->lchild->lchild->content);
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						//printf("%s","1");
						while(q->next!=NULL){
						q=q->next;
						}
							struct Node *pp=p->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->lchild->line,newHashNode->name);
						else{
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						q->next=newHashNode;
						}
					}
					}
					else{
						//printf("%s","2");
							struct Node *pp=p->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q=newHashNode;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						HashTable[i]=q;}
					}
					p=p->lchild->rchild->rchild;
				}
					//printf("%s","1");
							struct Node *pp=p->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
					int i=hash(pp->content);
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						while(q->next!=NULL){
						q=q->next;
						}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->lchild->line,newHashNode->name);
						else{
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						q->next=newHashNode;}}
					}
					else{
							struct Node *pp=p->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q=newHashNode;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						HashTable[i]=q;}
					}
					}
					if(strcmp(head->lchild->lchild->rchild->name,"OptTag")==0){
					//printf("%s\n","1");
					struct Node *p=head->lchild->lchild->rchild;/////////////////////
					int j=hash(p->lchild->content);
					struct HashNode *q=HashTable[j];
					if(q!=NULL){
						while(q->next!=NULL){
							q=q->next;
						}
						if(p->lchild->bl==0){
						p->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type="STRUCT";
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						struct HashNode *FuncNode=NULL;
						struct Node *r=p->rchild->rchild;
						while(r!=NULL){
							struct Node *s=r->lchild->lchild->rchild;
							while(s->lchild->rchild!=NULL){
							struct Node *pp=s->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
								if(pp->bl==0){
								pp->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=pp->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								newFuncNode->next=NULL;
								if(FuncNode==NULL){
									FuncNode=newFuncNode;
									newHashNode->Func=FuncNode;
								}
								else{
									struct HashNode *t=FuncNode;
									while(t->next!=NULL){
										t=t->next;
									}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
									t->next=newFuncNode;
								}}
								s=s->lchild->rchild->rchild;
							}
							struct Node *pp=s->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}

							if(pp->bl==0){
							pp->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=pp->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
							newFuncNode->next=NULL;
							if(FuncNode==NULL){
								FuncNode=newFuncNode;
								newHashNode->Func=FuncNode;
							}
							else{
								struct HashNode *t=FuncNode;
								while(t->next!=NULL){
									t=t->next;
								}
								t->next=newFuncNode;
							}}
							r=r->lchild->rchild;
						}
						struct Node *s=r->lchild->lchild->rchild;
						while(s->lchild->rchild!=NULL){
							struct Node *pp=s->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newFuncNode->type=r->lchild->lchild->lchild->content;
						//printf("%s\n",newFuncNode->type);
						newFuncNode->name=pp->content;
						//printf("%s\n",newFuncNode->name);
						newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						newFuncNode->next=NULL;
						if(FuncNode==NULL){
							FuncNode=newFuncNode;
							newHashNode->Func=FuncNode;
						}
						else{
							struct HashNode *t=FuncNode;
							while(t->next!=NULL){
								t=t->next;
							}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
								t->next=newFuncNode;
						}}
						s=s->lchild->rchild->rchild;
					}
						/*struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newFuncNode->type=r->lchild->lchild->lchild->content;
						printf("%s",newFuncNode->type);
						newFuncNode->name=s->lchild->lchild->lchild->content;
						printf("%s",newFuncNode->name);
						newFuncNode->kind="Var";
						newFuncNode->next=NULL;
						if(FuncNode==NULL){
							FuncNode=newFuncNode;
						}
						else{
							struct HashNode *t=FuncNode;
							while(t->next!=NULL){
								t=t->next;
							}
							t->next=newFuncNode;
						}*/
					newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->lchild->line,newHashNode->name);
						else{
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
					q->next=newHashNode;}}
					}
					else{
						if(p->lchild->bl==0){
						p->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type="STRUCT";
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						struct HashNode *FuncNode=NULL;
						newHashNode->Func=FuncNode;
						struct Node *r=p->rchild->rchild;
						while(r!=NULL){
							struct Node *s=r->lchild->lchild->rchild;
							while(s->lchild->rchild!=NULL){
							struct Node *pp=s->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
								if(pp->bl==0){
								pp->bl=1;								
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=pp->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								newFuncNode->next=NULL;
								if(FuncNode==NULL){
									FuncNode=newFuncNode;
									newHashNode->Func=FuncNode;
								}
								else{
									struct HashNode *t=FuncNode;
									while(t->next!=NULL){
										t=t->next;
									}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
									t->next=newFuncNode;
								}}
								s=s->lchild->rchild->rchild;
							}
							struct Node *pp=s->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
							if(pp->bl==0){
							pp->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=pp->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
							newFuncNode->next=NULL;
							if(FuncNode==NULL){
								FuncNode=newFuncNode;
								newHashNode->Func=FuncNode;
							}
							else{
								struct HashNode *t=FuncNode;
								while(t->next!=NULL){
									t=t->next;
								}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
								t->next=newFuncNode;
							}}
							r=r->lchild->rchild;
						}
					newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
					q=newHashNode;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
					HashTable[j]=q;}
					
					}
				p=head->rchild;
				while(p->lchild->rchild!=NULL){
					//printf("%s","1");
					int i=hash(p->lchild->lchild->lchild->content);
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						//printf("%s","1");
						while(q->next!=NULL){
						q=q->next;
						}
							struct Node *pp=p->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->lchild->line,newHashNode->name);
						else{
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						q->next=newHashNode;}}
					}
					else{
						//printf("%s","2");
							struct Node *pp=p->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q=newHashNode;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						HashTable[i]=q;}
					}
					p=p->lchild->rchild->rchild;
				}
					//printf("%s","1");
							struct Node *pp=p->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
					int i=hash(pp->content);
					struct HashNode *q1=HashTable[i];
					if(q!=NULL){
						while(q1->next!=NULL){
						q1=q1->next;
						}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->lchild->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->lchild->line,newHashNode->name);
						else{
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						q1->next=newHashNode;}}
					}
					else{
							struct Node *pp=p->lchild->lchild->lchild;
							while(strcmp(pp->name,"ID")!=0){
								pp=pp->lchild;
							}
						if(pp->bl==0){
						pp->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=pp->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q1=newHashNode;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						HashTable[i]=q1;}
					}
					}
			}
			if((strcmp(p->name,"ExtDecList"))==0){
					if(strcmp(head->lchild->lchild->rchild->name,"Tag")==0){					
					while(p->lchild->rchild!=NULL){
					//printf("%s","1");
					int i=hash(p->lchild->lchild->content);
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						//printf("%s","1");
						while(q->next!=NULL){
						q=q->next;
						}
						if(p->lchild->lchild->bl==0){
						p->lchild->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->lchild->line,newHashNode->name);
						else{
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						q->next=newHashNode;}}
					}
					else{
						//printf("%s","2");
						if(p->lchild->lchild->bl==0){
						p->lchild->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q=newHashNode;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						HashTable[i]=q;}
					}
					p=p->lchild->rchild->rchild;
				}
					//printf("%s","1");
					int i=hash(p->lchild->lchild->content);
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						while(q->next!=NULL){
						q=q->next;
						}
						if(p->lchild->lchild->bl==0){
						p->lchild->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->lchild->line,newHashNode->name);
						else{
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						q->next=newHashNode;}}
					}
					else{
						if(p->lchild->lchild->bl==0){
						p->lchild->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q=newHashNode;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						HashTable[i]=q;}
					}
					}
					if(strcmp(head->lchild->lchild->rchild->name,"OptTag")==0){
					//printf("%s\n","1");
					struct Node *p=head->lchild->lchild->rchild;/////////////////////
					int j=hash(p->lchild->content);
					struct HashNode *q=HashTable[j];
					if(q!=NULL){
						while(q->next!=NULL){
							q=q->next;
						}
						if(p->lchild->bl==0){
						p->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type="STRUCT";
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						struct HashNode *FuncNode=NULL;
						newHashNode->Func=FuncNode;
						struct Node *r=p->rchild->rchild;
						while(r!=NULL){
							struct Node *s=r->lchild->lchild->rchild;
							while(s->lchild->rchild!=NULL){
								if(s->lchild->lchild->lchild->bl==0){
								s->lchild->lchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								printf("%s\n",newFuncNode->type);
								newFuncNode->name=s->lchild->lchild->lchild->content;
								printf("%s\n",newFuncNode->name);
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								newFuncNode->next=NULL;
								if(FuncNode==NULL){
									FuncNode=newFuncNode;
									newHashNode->Func=FuncNode;
								}
								else{
									struct HashNode *t=FuncNode;
									while(t->next!=NULL){
										t=t->next;
									}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
									t->next=newFuncNode;
								}}
								s=s->lchild->rchild->rchild;
							}
							if(s->lchild->lchild->lchild->bl==0){
							s->lchild->lchild->lchild->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=s->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
							newFuncNode->next=NULL;
							if(FuncNode==NULL){
								FuncNode=newFuncNode;
								newHashNode->Func=FuncNode;
							}
							else{
								struct HashNode *t=FuncNode;
								while(t->next!=NULL){
									t=t->next;
								}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
								t->next=newFuncNode;
							}}
							r=r->lchild->rchild;
						}
						struct Node *s=r->lchild->lchild->rchild;
						while(s->lchild->rchild!=NULL){
						if(s->lchild->lchild->lchild->bl==0){
						s->lchild->lchild->lchild->bl=1;
						struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newFuncNode->type=r->lchild->lchild->lchild->content;
						//printf("%s\n",newFuncNode->type);
						newFuncNode->name=s->lchild->lchild->lchild->content;
						//printf("%s\n",newFuncNode->name);
						newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						newFuncNode->next=NULL;
						if(FuncNode==NULL){
							FuncNode=newFuncNode;
							newHashNode->Func=FuncNode;
						}
						else{
							struct HashNode *t=FuncNode;
							while(t->next!=NULL){
								t=t->next;
							}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
								t->next=newFuncNode;
						}}
						s=s->lchild->rchild->rchild;
					}
						/*struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newFuncNode->type=r->lchild->lchild->lchild->content;
						printf("%s",newFuncNode->type);
						newFuncNode->name=s->lchild->lchild->lchild->content;
						printf("%s",newFuncNode->name);
						newFuncNode->kind="Var";
						newFuncNode->next=NULL;
						if(FuncNode==NULL){
							FuncNode=newFuncNode;
						}
						else{
							struct HashNode *t=FuncNode;
							while(t->next!=NULL){
								t=t->next;
							}
							t->next=newFuncNode;
						}*/
					newHashNode->kind="Struct";
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 16 at Line %d: Duplicated name \"%s\".\n",p->lchild->line,newHashNode->name);
						else
					q->next=newHashNode;}
					}
					else{
						if(p->lchild->bl==0){
						p->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type="STRUCT";
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						struct HashNode *FuncNode=NULL;
						newHashNode->Func=FuncNode;
						struct Node *r=p->rchild->rchild;
						while(r!=NULL){
							struct Node *s=r->lchild->lchild->rchild;
							while(s->lchild->rchild!=NULL){
								if(s->lchild->lchild->lchild->bl==0){
								s->lchild->lchild->lchild->bl=1;								
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=s->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								newFuncNode->next=NULL;
								if(FuncNode==NULL){
									FuncNode=newFuncNode;
									newHashNode->Func=FuncNode;
								}
								else{
									struct HashNode *t=FuncNode;
									while(t->next!=NULL){
										t=t->next;
									}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
									t->next=newFuncNode;
								}}
								s=s->lchild->rchild->rchild;
							}
							if(s->lchild->lchild->lchild->bl==0){
							s->lchild->lchild->lchild->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=s->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
							newFuncNode->next=NULL;
							if(FuncNode==NULL){
								FuncNode=newFuncNode;
								newHashNode->Func=FuncNode;
							}
							else{
								struct HashNode *t=FuncNode;
								while(t->next!=NULL){
									t=t->next;
								}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
								t->next=newFuncNode;
							}}
							r=r->lchild->rchild;
						}
					q=newHashNode;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
					HashTable[j]=q;}
					
					}
				p=head->rchild;
				while(p->lchild->rchild!=NULL){
					//printf("%s","1");
					int i=hash(p->lchild->lchild->content);
					struct HashNode *q=HashTable[i];
					if(q!=NULL){
						//printf("%s","1");
						while(q->next!=NULL){
						q=q->next;
						}
						if(p->lchild->lchild->bl==0){
						p->lchild->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->lchild->line,newHashNode->name);
						else{
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						q->next=newHashNode;}}
					}
					else{
						//printf("%s","2");
						if(p->lchild->lchild->bl==0){
						p->lchild->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q=newHashNode;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						HashTable[i]=q;
						//printf("%s %s %s\n",q->type,q->name,q->kind);
							}
					}
					p=p->lchild->rchild->rchild;
				}
					//printf("%s","1");
					int i=hash(p->lchild->lchild->content);
					struct HashNode *q1=HashTable[i];
					if(q1!=NULL){
						while(q1->next!=NULL){
						q1=q1->next;
						}
						if(p->lchild->lchild->bl==0){
						p->lchild->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",p->lchild->lchild->line,newHashNode->name);
						else{
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						q1->next=newHashNode;}}
					}
					else{
						if(p->lchild->lchild->bl==0){
						p->lchild->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						newHashNode->kind="Struct";
						struct Node *ap=p->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						q1=newHashNode;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						HashTable[i]=q1;}
					}
					}
				}
			if((strcmp(p->name,"FunDec"))==0){
					//printf("%s","1");
					int i=hash(p->lchild->content);
					struct HashNode *q=HashTable[i];
					if(strcmp(head->lchild->lchild->rchild->name,"Tag")==0){
					if(q!=NULL){
						//printf("%s","1");
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->kind="Func";
						struct Node *r=p->lchild->rchild->rchild;
						struct HashNode *FuncNode=NULL;
						while(q->next!=NULL){
							q=q->next;
						}
						if(strcmp(r->name,"RP")==0){
							FuncNode=NULL;
						}
						if(strcmp(r->name,"VarList")==0){
							while(r->lchild->rchild!=NULL){
								struct HashNode *s=FuncNode;
								if(s!=NULL){
									while(s->next!=NULL){
									s=s->next;
									}
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
								s->next=newFuncNode;}
								}
								else{
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								q=newFuncNode;
								FuncNode=q;}
								}
								r=r->lchild->rchild->rchild;
							}
							struct HashNode *s=FuncNode;
							if(s!=NULL){
								while(s->next!=NULL){
									s=s->next;
								}
							if(r->lchild->lchild->rchild->lchild->bl==0){
							r->lchild->lchild->rchild->lchild->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->next=NULL;
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
							s->next=newFuncNode;}
							}
							else{
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								s=newFuncNode;
								FuncNode=s;}
							}
						}
						newHashNode->Func=FuncNode;
						newHashNode->next=NULL;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else{
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 4 at Line %d: Redefined function \"%s\".\n",p->line,newHashNode->name);
						else
						q->next=newHashNode;}
					}
					else{
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->kind="Func";
						struct Node *r=p->lchild->rchild->rchild;
						struct HashNode *FuncNode=NULL;
						if(strcmp(r->name,"RP")==0){
							FuncNode=NULL;
						}
						if(strcmp(r->name,"VarList")==0){
							while(r->lchild->rchild!=NULL){
								struct HashNode *s=FuncNode;
								if(s!=NULL){
									while(s->next!=NULL){
									s=s->next;
									}
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
								s->next=newFuncNode;}
								}
								else{
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								q=newFuncNode;
								FuncNode=q;}
								}
								r=r->lchild->rchild->rchild;
							}
							struct HashNode *s=FuncNode;
							if(s!=NULL){
								while(s->next!=NULL){
									s=s->next;
								}
							if(r->lchild->lchild->rchild->lchild->bl==0){
							r->lchild->lchild->rchild->lchild->bl=1;							
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->next=NULL;
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
							s->next=newFuncNode;}
							}
							else{
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								s=newFuncNode;
								FuncNode=s;}
							}
						}
						newHashNode->next=NULL;
						newHashNode->Func=FuncNode;
						q=newHashNode;
						if(is_exist(HashTable,newHashNode->type)==0)
							printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->lchild->lchild->line,newHashNode->type);
						else
						HashTable[i]=q;
					}
					}
					if(strcmp(head->lchild->lchild->rchild->name,"OptTag")==0){
					//printf("%s\n","1");
					struct Node *p=head->lchild->lchild->rchild;/////////////////////
					int j=hash(p->lchild->content);
					struct HashNode *q=HashTable[j];
					if(q!=NULL){
						while(q->next!=NULL){
							q=q->next;
						}
						if(p->lchild->bl==0){
						p->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type="STRUCT";
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						struct HashNode *FuncNode=NULL;
						struct Node *r=p->rchild->rchild;
						while(r!=NULL){
							struct Node *s=r->lchild->lchild->rchild;
							while(s->lchild->rchild!=NULL){
								if(s->lchild->lchild->lchild->bl==0){
								s->lchild->lchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=s->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								newFuncNode->next=NULL;
								if(FuncNode==NULL){
									FuncNode=newFuncNode;
									newHashNode->Func=FuncNode;
								}
								else{
									struct HashNode *t=FuncNode;
									while(t->next!=NULL){
										t=t->next;
									}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
									t->next=newFuncNode;
								}}
								s=s->lchild->rchild->rchild;
							}
							if(s->lchild->lchild->lchild->bl==0){
							s->lchild->lchild->lchild->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=s->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
							newFuncNode->next=NULL;
							if(FuncNode==NULL){
								FuncNode=newFuncNode;
								newHashNode->Func=FuncNode;
							}
							else{
								struct HashNode *t=FuncNode;
								while(t->next!=NULL){
									t=t->next;
								}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
								t->next=newFuncNode;
							}}
							r=r->lchild->rchild;
						}
						struct Node *s=r->lchild->lchild->rchild;
						while(s->lchild->rchild!=NULL){
						if(s->lchild->lchild->lchild->bl==0){
						s->lchild->lchild->lchild->bl=1;
						struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newFuncNode->type=r->lchild->lchild->lchild->content;
						//printf("%s\n",newFuncNode->type);
						newFuncNode->name=s->lchild->lchild->lchild->content;
						//printf("%s\n",newFuncNode->name);
						newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
						newFuncNode->next=NULL;
						if(FuncNode==NULL){
							FuncNode=newFuncNode;
							newHashNode->Func=FuncNode;
						}
						else{
							struct HashNode *t=FuncNode;
							while(t->next!=NULL){
								t=t->next;
							}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
								t->next=newFuncNode;
						}}
						s=s->lchild->rchild->rchild;
					}
						/*struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newFuncNode->type=r->lchild->lchild->lchild->content;
						printf("%s",newFuncNode->type);
						newFuncNode->name=s->lchild->lchild->lchild->content;
						printf("%s",newFuncNode->name);
						newFuncNode->kind="Var";
						newFuncNode->next=NULL;
						if(FuncNode==NULL){
							FuncNode=newFuncNode;
						}
						else{
							struct HashNode *t=FuncNode;
							while(t->next!=NULL){
								t=t->next;
							}
							t->next=newFuncNode;
						}*/
					newHashNode->kind="Struct";
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 16 at Line %d: Duplicated name  \"%s\".\n",p->line,newHashNode->name);
						else
					q->next=newHashNode;}
					}
					else{
						if(p->lchild->bl==0){
						p->lchild->bl=1;
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type="STRUCT";
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->next=NULL;
						struct HashNode *FuncNode=NULL;
						struct Node *r=p->rchild->rchild;
						while(r!=NULL){
							struct Node *s=r->lchild->lchild->rchild;
							while(s->lchild->rchild!=NULL){
								if(s->lchild->lchild->lchild->bl==0){
								s->lchild->lchild->lchild->bl=1;								
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=s->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								newFuncNode->next=NULL;
								if(FuncNode==NULL){
									FuncNode=newFuncNode;
									newHashNode->Func=FuncNode;
								}
								else{
									struct HashNode *t=FuncNode;
									while(t->next!=NULL){
										t=t->next;
									}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
									t->next=newFuncNode;
								}}
								s=s->lchild->rchild->rchild;
							}
							if(s->lchild->lchild->lchild->bl==0){
							s->lchild->lchild->lchild->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=s->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild->lchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
							newFuncNode->next=NULL;
							if(FuncNode==NULL){
								FuncNode=newFuncNode;
								newHashNode->Func=FuncNode;
							}
							else{
								struct HashNode *t=FuncNode;
								while(t->next!=NULL){
									t=t->next;
								}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 15 at Line %d: Redefined field \"%s\".\n",s->lchild->lchild->line,newFuncNode->name);
								else
								t->next=newFuncNode;
							}}
							r=r->lchild->rchild;
						}
					newHashNode->kind="Struct";
					q=newHashNode;
					HashTable[j]=q;}
					
					}
					p=head->rchild;
					if(q!=NULL){
						//printf("%s","1");
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->kind="Func";
						struct Node *r=p->lchild->rchild->rchild;
						struct HashNode *FuncNode=NULL;
						while(q->next!=NULL){
							q=q->next;
						}
						if(strcmp(r->name,"RP")==0){
							FuncNode=NULL;
						}
						if(strcmp(r->name,"VarList")==0){
							while(r->lchild->rchild!=NULL){
								struct HashNode *s=FuncNode;
								if(s!=NULL){
									while(s->next!=NULL){
									s=s->next;
									}
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
								s->next=newFuncNode;}
								}
								else{
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
								q=newFuncNode;
								FuncNode=q;}
								}
								r=r->lchild->rchild->rchild;
							}
							struct HashNode *s=FuncNode;
							if(s!=NULL){
								while(s->next!=NULL){
									s=s->next;
								}
							if(r->lchild->lchild->rchild->lchild->bl==0){
							r->lchild->lchild->rchild->lchild->bl=1;
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->next=NULL;
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
							s->next=newFuncNode;}
							}
							else{
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								s=newFuncNode;
								FuncNode=s;}
							}
						}
						newHashNode->Func=FuncNode;
						newHashNode->next=NULL;
						if(is_exist(HashTable,newHashNode->name)==1)
							printf("Error type 4 at Line %d: Redefined function \"%s\".\n",p->line,newHashNode->name);
						else
						q->next=newHashNode;
					}
					else{
						struct HashNode *newHashNode=(struct HashNode*)malloc(sizeof(struct HashNode));
						newHashNode->type=head->lchild->lchild->rchild->lchild->content;
						//printf("%s\n",newHashNode->type);
						newHashNode->name=p->lchild->content;
						//printf("%s\n",newHashNode->name);
						newHashNode->kind="Func";
						struct Node *r=p->lchild->rchild->rchild;
						struct HashNode *FuncNode=NULL;
						if(strcmp(r->name,"RP")==0){
							FuncNode=NULL;
						}
						if(strcmp(r->name,"VarList")==0){
							while(r->lchild->rchild!=NULL){
								struct HashNode *s=FuncNode;
								if(s!=NULL){
									while(s->next!=NULL){
									s=s->next;
									}
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
								s->next=newFuncNode;}
								}
								else{
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								q=newFuncNode;
								FuncNode=q;}
								}
								r=r->lchild->rchild->rchild;
							}
							struct HashNode *s=FuncNode;
							if(s!=NULL){
								while(s->next!=NULL){
									s=s->next;
								}
							if(r->lchild->lchild->rchild->lchild->bl==0){
							r->lchild->lchild->rchild->lchild->bl=1;							
							struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
							newFuncNode->type=r->lchild->lchild->lchild->content;
							//printf("%s\n",newFuncNode->type);
							newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
							//printf("%s\n",newFuncNode->name);
							newFuncNode->next=NULL;
							newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								if(is_exist_in_Func(FuncNode,newFuncNode->name)==1)
									printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",r->lchild->lchild->line,newFuncNode->name);
								else
							s->next=newFuncNode;}
							}
							else{
								if(r->lchild->lchild->rchild->lchild->bl==0){
								r->lchild->lchild->rchild->lchild->bl=1;
								struct HashNode *newFuncNode=(struct HashNode*)malloc(sizeof(struct HashNode));
								newFuncNode->type=r->lchild->lchild->lchild->content;
								//printf("%s\n",newFuncNode->type);
								newFuncNode->name=r->lchild->lchild->rchild->lchild->content;
								//printf("%s\n",newFuncNode->name);
								newFuncNode->next=NULL;
								newFuncNode->kind="Var";
						struct Node *ap=r->lchild->lchild->rchild->lchild;
						struct Size *as=NULL;
						while(ap->rchild!=NULL){
							struct Size *newas=(struct Size*)malloc(sizeof(struct Size));
							if(as==NULL){
								newas->size=atoi(ap->rchild->rchild->content);
								newas->next=NULL;
								as=newas;
							}
							else{
							struct Size *finds=as;
								while(as->next!=NULL){
									finds=finds->next;
									}
									struct Size *newSizeNode=(struct Size*)malloc(sizeof(struct Size));
									newSizeNode->size=atoi(ap->rchild->rchild->content);
									newSizeNode->next=NULL;
									finds->next=newSizeNode;
							}
							ap=ap->lchild;
							newHashNode->kind="Array";
							newHashNode->arraysize=as;
						}
								s=newFuncNode;
								FuncNode=s;}
							}
						}
						newHashNode->next=NULL;
						newHashNode->Func=FuncNode;
						q=newHashNode;
						HashTable[j]=q;
					}
					}
				}
		}/////////////////
		}		
		}
			if(strcmp(head->name,"Exp")==0){
			if(strcmp(head->lchild->name,"ID")==0){
			if(head->lchild->bl==0){
				head->lchild->bl=1;
				if(head->lchild->rchild!=NULL){
				if(strcmp(head->lchild->rchild->name,"LP")==0){
				if(is_exist(HashTable,head->lchild->content)==0)	{
					printf("Error type 2 at line %d:Undefined function \"%s\"\n",head->line,head->lchild->content);
				}
				}
				else{
				if(is_exist(HashTable,head->lchild->content)==0)	{
					printf("Error type 1 at line %d:Undefined variable \"%s\"\n",head->line,head->lchild->content);
				}
				}
				}
				else{
				if(is_exist(HashTable,head->lchild->content)==0)	{
					printf("Error type 1 at line %d:Undefined variable \"%s\"\n",head->line,head->lchild->content);
				}
				}
			}
			}
		}
			if(strcmp(head->name,"Var")==0){
			if(strcmp(head->lchild->name,"ID")==0){
			if(head->lchild->bl==0){
				head->lchild->bl=1;
				if(is_exist(HashTable,head->lchild->content)==0)	{
					printf("Error type 1 at line %d:Undefined variable \"%s\"\n",head->line,head->lchild->content);
				}
			}
			}
		}
			if(strcmp(head->name,"FunDec")==0){
			if(strcmp(head->lchild->name,"ID")==0){
			if(head->lchild->bl==0){
				head->lchild->bl=1;
				if(is_exist(HashTable,head->lchild->content)==0)	{
					printf("Error type 2 at line %d:Undefined function \"%s\"\n",head->line,head->lchild->content);
				}
			}
			}
		}
	if(head->lchild!=NULL){
		CreatTable(HashTable,head->lchild,n+1);}
	if(head->rchild!=NULL)	
		CreatTable(HashTable,head->rchild,n);
	}
}
int hash(char *name){
	int val=0;
	int i;
	for(;*name;++name){
		val=(val<<2)+*name;
		if(i=val&~98)
			val=(val^(i>>12))&98;
	}
	return val;
}
void PrintHashTable(struct HashNode* HashTable[]){
	int i=0;
	int num=0;
	for(;i<99;i++){
		//printf("%s\n","1");
		struct HashNode *p=HashTable[i];
		if(p!=NULL){
		while(p!=NULL){
			//printf("%s\n","1");
			printf("%s %s %s\n",p->type,p->name,p->kind);
			struct HashNode*q=p->Func;
			struct Size *s=p->arraysize;
			while(q!=NULL){
				printf("%s %s %s11\n",q->type,q->name,q->kind);
				q=q->next;
			}
			while(s!=NULL){
				printf("%d\n",s->size);
				s=s->next;
			}
			p=p->next;
		}
		}
		else{
			num++;
			//printf("%s\n","NULL");
			}
	}
	printf("%d\n",num);
}
int is_exist_in_Func(struct HashNode* FuncNode,char* name){
	if(FuncNode!=NULL){
		//printf("%s111\n",FuncNode->name);
		if(strcmp(FuncNode->name,name)==0){
			return 1;
		}
		else
			is_exist_in_Func(FuncNode->next,name);
	}
	return 0;
}
int is_exist(struct HashNode* HashTable[],char * name){
	int i=hash(name);
	struct HashNode * p =HashTable[i];
	if(p==NULL)
		return 0;
	else
		while(p!=NULL){
			if(strcmp(p->name,name)==0)
				return 1;
			else
				p=p->next;
		}
		
	return 0;
}


void Op_Program(struct HashNode* HashTable[],struct Node *head){
	//printf("program\n");
	//printf("%s\n",head->name);
	Op_ExtDefList(HashTable,head->lchild);
	
}

void Op_ExtDefList(struct HashNode* HashTable[],struct Node *head){
	//printf("ExtDefList\n");
	
	if(head==NULL)return;
	//printf("%s\n",head->name);
	Op_ExtDef(HashTable,head->lchild);
	Op_ExtDefList(HashTable,head->lchild->rchild);
	
}
void Op_ExtDef(struct HashNode* HashTable[],struct Node *head){
	//printf("ExtDef\n");
	//printf("%s\n",head->name);
	if(strcmp(head->lchild->rchild->name,"ExtDecList")==0){
		Op_Specifier(HashTable,head->lchild);
		Op_ExtDecList(HashTable,head->lchild->rchild);
	}
	else if(strcmp(head->lchild->rchild->name,"SEMI")==0)
		Op_Specifier(HashTable,head->lchild);
	else if(strcmp(head->lchild->rchild->name,"FunDec")==0){
		char* func_id;
		char* func_type;
		int i;
		int line=0;
		char* return_type=(char*)malloc(20);
		//char* return_type;
		Op_Specifier(HashTable,head->lchild);
		func_id=Op_FunDec(HashTable,head->lchild->rchild);
		Op_CompSt(HashTable,head->lchild->rchild->rchild,return_type,&line);
		i=hash(func_id);
		if(line != 0){
			//printf("%d\n",i);
			struct HashNode* p = HashTable[i];
			//printf("%s\n",p->name);
			//printf("%s\n",func_id);
			while(p!=NULL){
				if(strcmp(p->name,func_id)==0)
					func_type=p->type;
				p=p->next;
			}
			//printf("%s\n",func_type);
			//printf("%s\n",return_type);
			/*i=hash(return_id);
			p = HashTable[i];
			while(p!=NULL){
			if(strcmp(p->name,return_id)==0)
				return_type=p->type;
				p=p->next;
			}*/
			if(strcmp(func_type,return_type)!=0)
				printf("Error type 8 at line %d :Type mismatched for return. \n",line);
		}
		
	}
}

void Op_ExtDecList(struct HashNode* HashTable[],struct Node *head){
	//printf("ExtDecList\n");
	//printf("%s\n",head->name);
	if(head->lchild->rchild==NULL)
		Op_VarDec(HashTable,head->lchild);
	else if(strcmp(head->lchild->rchild->name,"COMMA")==0){
		Op_VarDec(HashTable,head->lchild);
		Op_ExtDecList(HashTable,head->lchild->rchild->rchild);
	}
		
}

void Op_Specifier(struct HashNode* HashTable[],struct Node *head){
	//printf("Specifier\n");
	//printf("%s\n",head->name);
	if(strcmp(head->lchild->name,"TYPE")==0)
		return;
	else if(strcmp(head->lchild->name,"StructSpecifier")==0)
		Op_StructSpecifier(HashTable,head->lchild);
}

void Op_StructSpecifier(struct HashNode* HashTable[],struct Node *head){
	//printf("structspecifier\n");
	//printf("%s\n",head->name);
	if(strcmp(head->lchild->rchild->name,"OptTag")==0){
		Op_OptTag(HashTable,head->lchild->rchild);
		Op_DefList(HashTable,head->lchild->rchild->rchild->rchild);
	}
	else {
		Op_Tag(HashTable,head->lchild->rchild);
	}		
}

char* Op_OptTag(struct HashNode* HashTable[],struct Node *head){
	//printf("OptTag\n");
	if(head==NULL)return "\0";
	//printf("%s\n",head->name);
	if(head==NULL)return "\0";
	else return head->lchild->name;
}

char* Op_Tag(struct HashNode* HashTable[],struct Node *head){	
	//printf("Tag\n");
	//printf("%s\n",head->name);
	return head->lchild->name;
}

char* Op_VarDec(struct HashNode* HashTable[],struct Node *head){
	//printf("VarDec\n");
	//printf("%s\n",head->name);
	if(strcmp(head->lchild->name,"ID")==0){
		int i=hash(head->lchild->content);
		struct HashNode* p=HashTable[i];
		while(p!=NULL){
			if(strcmp(p->name,head->lchild->content)==0)
				break;
			p=p->next;
		}
		if(p!=NULL)return p->type;
		return "ID";
	}
	else{
		return Op_VarDec(HashTable,head->lchild);
	}
}

char* Op_FunDec(struct HashNode* HashTable[],struct Node *head){
	//printf("FunDec\n");
	//printf("%s\n",head->name);
	if(strcmp(head->lchild->rchild->rchild->name,"RP")!=0){
		Op_VarList(HashTable,head->lchild->rchild->rchild);
		return head->lchild->content;
	}
	else{
		return head->lchild->content;
	}
}

void Op_VarList(struct HashNode* HashTable[],struct Node *head){
	//printf("VarList\n");
	//printf("%s\n",head->name);
	if(head->lchild->rchild==NULL)
		Op_ParameDec(HashTable,head->lchild);
	else{
		Op_ParameDec(HashTable,head->lchild);
		Op_VarList(HashTable,head->lchild->rchild->rchild);
	}
}

void Op_ParameDec(struct HashNode* HashTable[],struct Node *head){
	//printf("ParameDec\n");
	//printf("%s\n",head->name);
	Op_Specifier(HashTable,head->lchild);
	Op_VarDec(HashTable,head->lchild->rchild);
}

void Op_CompSt(struct HashNode* HashTable[],struct Node *head,char* s,int* sline){
	//printf("CompSt\n");
	//printf("%s\n",head->name);
	Op_DefList(HashTable,head->lchild->rchild);
	Op_StmtList(HashTable,head->lchild->rchild->rchild,s,sline);
}

void Op_StmtList(struct HashNode* HashTable[],struct Node *head,char* s,int* sline){
	//printf("stmtList\n");
	//printf("1\n");
	if(head==NULL)return;
	//printf("%s\n",head->name);
	
	Op_Stmt(HashTable,head->lchild,s,sline);
	Op_StmtList(HashTable,head->lchild->rchild,s,sline);
}

void Op_Stmt(struct HashNode* HashTable[],struct Node *head,char* s,int* sline){
	//printf("Stmt\n");
	if(head==NULL)return;
	//printf("%s\n",head->name);
	if(head->lchild->rchild==NULL)
		Op_CompSt(HashTable,head->lchild,s,sline);
	else if(strcmp(head->lchild->rchild->name,"SEMI")==0){
		Op_Exp(HashTable,head->lchild);
	}
	else if(strcmp(head->lchild->name,"RETURN")==0){
		struct Exp_TYPE* p=Op_Exp(HashTable,head->lchild->rchild);
		
		if(s!=NULL) strcpy(s,p->type);
		*sline=p->line;
		//printf("%s%d\n",p->type,p->line);
	}
	else {
		struct Node* p=head->lchild->rchild->rchild;
		Op_Exp(HashTable,p);
		p=p->rchild->rchild;
		Op_Stmt(HashTable,p,s,sline);
		if(p->rchild!=NULL){
			p=p->rchild->rchild;
			Op_Stmt(HashTable,p,s,sline);
		}
	}
}

void Op_DefList(struct HashNode* HashTable[],struct Node *head){
	//printf("DefList\n");
	if(head==NULL)return;
	//printf("%s\n",head->name);
	
	Op_Def(HashTable,head->lchild);
	if(head->lchild!=NULL)
	Op_DefList(HashTable,head->lchild->rchild);
}

void Op_Def(struct HashNode* HashTable[],struct Node *head){
	//printf("Def\n");
	if(head==NULL)return;
	//printf("%s\n",head->name);
	Op_Specifier(HashTable,head->lchild);
	Op_DecList(HashTable,head->lchild->rchild);
}

void Op_DecList(struct HashNode* HashTable[],struct Node *head){
	//printf("DecList\n");
	//printf("%s\n",head->name);
	if(head->lchild->rchild==NULL)
		Op_Dec(HashTable,head->lchild);
	else{
		Op_Dec(HashTable,head->lchild);
		Op_DecList(HashTable,head->lchild->rchild->rchild);	
	}
}

void Op_Dec(struct HashNode* HashTable[],struct Node *head){
	//printf("Dec\n");
	//printf("%s\n",head->name);
	if(head->lchild->rchild==NULL)
		Op_VarDec(HashTable,head->lchild);
	else if(strcmp(head->lchild->rchild->name,"ASSIGNOP")==0){
			char * temp1;
			struct Exp_TYPE* temp2;
			temp1=Op_VarDec(HashTable,head->lchild);
			temp2=Op_Exp(HashTable,head->lchild->rchild->rchild);
			if(strcmp(temp2->type,"E")!=0){
			if(strcmp(temp1,temp2->type)!=0)
				printf("Error type 5 at Line %d:Type mismatched for assignment. \n",head->line);	}}
	else{
		Op_VarDec(HashTable,head->lchild);
		Op_Exp(HashTable,head->lchild->rchild->rchild);
	}
}
int is_same(struct HashNode* HashTable[],char*a , char* b){
	int i=hash(a);
	int j=hash(b);

	struct HashNode* t1=HashTable[i];
	struct HashNode* t2=HashTable[j];
	
	while(t1!=NULL){
		if(strcmp(t1->name,a)==0)
			break;
		t1=t1->next;
	}
	while(t2!=NULL){
		if(strcmp(t2->name,b)==0)
			break;
		t1=t1->next;
	}
	t1=t1->Func;
	t2=t2->Func;
	while(t1!=NULL&&t2!=NULL){
		//printf("%s %s\n",t1->type,t2->type);
		if(strcmp(t1->type,t2->type)!=0)
			return 0;
		t1=t1->next;
		t2=t2->next;
	}
	if(t1==NULL&&t2!=NULL)
		return 0;
	if(t2==NULL&&t1!=NULL)
		return 0;

	return 1;
}
struct Exp_TYPE* Op_Exp(struct HashNode* HashTable[],struct Node *head){
	//printf("Exp\n");
	//printf("%s\n",head->name);
	if(strcmp(head->lchild->name,"Exp")==0){
		struct Node* p = head->lchild;
		//printf("%s\n",p->rchild->name);
		if(strcmp(p->rchild->name,"ASSIGNOP")==0){
			struct Exp_TYPE* temp1,*temp2;
			temp1=Op_Exp(HashTable,p);
			temp2=Op_Exp(HashTable,p->rchild->rchild);
			if(strcmp(temp1->type,"E")!=0&&strcmp(temp2->type,"E")!=0){
			if(temp1->is_num==1)
				printf("Error type 6 at Line %d:The left-hand side of an assignment must be a variable. \n",head->line);
			else if((strcmp(temp1->type,temp2->type)!=0&&(strcmp(temp1->type,"INT")==0||strcmp(temp1->type,"FLOAT")==0||strcmp(temp2->type,"FLOAT")==0||strcmp(temp2->type,"INT")==0))||temp1->array_dem!=temp2->array_dem)
				printf("Error type 5 at Line %d:Type mismatched for assignment. \n",head->line);	
			else if(!(strcmp(temp1->type,"INT")==0||strcmp(temp1->type,"FLOAT")==0||strcmp(temp2->type,"FLOAT")==0||strcmp(temp2->type,"INT")==0)&&temp1->array_dem==0&&temp2->array_dem==0)
				if(!is_same(HashTable,temp1->type,temp2->type))
					printf("Error type 5 at Line %d:Type mismatched for assignment. \n",head->line);
			}

			struct Exp_TYPE* temp=(struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
			temp->line=head->line;
			temp->type="INT";
			temp->is_num=0;
			temp->array_dem=0;
			return temp;
		}
		else if(strcmp(p->rchild->name,"LB")!=0){
			if(strcmp(p->rchild->name,"DOT")==0){
				struct Exp_TYPE* temp1;
				temp1=Op_Exp(HashTable,p);
				if(strcmp(temp1->type,"E")!=0){
				int t=hash(temp1->type);
				struct HashNode* h=HashTable[t];			
				//printf("%s\n",temp1->type);
				if(h==NULL){
					printf("Error type 13 at Line %d: Illegal use of \".\".\n",p->line);
					struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
					temp->line=p->line;
					temp->type="E";//if error,we suggest that this Exp is INT;
					temp->is_num=0;
					temp->array_dem=0;
					return temp;
				}
				//printf("%s %s\n",h->name,h->type);
				while(h->next!=NULL){
					if(strcmp(temp1->type,h->name)==0)
						break;
					h=h->next;
				}
				if(h==NULL)
					printf("Error type 13 at Line %d: Illegal use of \".\".\n",p->line);
				else{
					//printf("%s\n",h->type);
					if(strcmp(h->type,"STRUCT")!=0)
						printf("Error type 13 at Line %d: Illegal use of \".\".\n",p->line);
					else{
					/*char* name=p->lchild->content;
					char* type;
					int t=hash(name);
					struct HashNode* h=HashTable[t];
					if(h==NULL){
						struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
						temp->line=head->line;
						temp->type="E";
						temp->is_num=1;
						temp->array_dem=0;
						return temp;
					}
					while(h->next!=NULL){
						if(strcmp(name,h->name)==0)
							break;
						h=h->next;
					}
					type=h->type;
					t=hash(type);
					h=HashTable[t];
					if(h==NULL){
						printf("Error type 13 at Line %d: Illegal use of \".\".\n",p->line);
					}
					else{*/
					
					
					//else{
						int if_ex=0;
					//	printf("%s %s\n",h->name,h->type);
						h=h->Func;
					//	printf("1\n");
						//if(h==NULL)
						//	printf("2\n");
					//	printf("%s\n",h->name);
						while(h->next!=NULL){
							if(strcmp(p->rchild->rchild->content,h->name)==0)
							{	if_ex=1;break;}
							h=h->next;
						}
						if(if_ex!=1)
							printf("Error type 14 at Line %d:Non-existent field \"%s\".\n",p->line,p->rchild->rchild->content);
						else{
							struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
							temp->line=p->line;
							temp->type=h->type;			
							temp->is_num=0;
							temp->array_dem=0;
							return temp;
						}}
					}
				}
				struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
				temp->line=p->line;
				temp->type="E";//if error,we suggest that this Exp is INT;
				temp->is_num=0;
				temp->array_dem=0;
				return temp;
			}
			else{
				struct Exp_TYPE* temp1,*temp2;
				temp1=Op_Exp(HashTable,p);
				temp2=Op_Exp(HashTable,p->rchild->rchild);
				if(strcmp(temp1->type,"E")!=0)
				if(strcmp(temp1->type,temp2->type)!=0||(strcmp(temp1->type,"INT")!=0&&strcmp(temp1->type,"FLOAT")!=0)||(strcmp(temp2->type,"INT")!=0&&strcmp(temp2->type,"FLOAT")!=0))
					printf("Error type 7 at Line %d:Type mismatched for operands.\n",p->line);
	
				struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
				temp->line=p->line;
				temp->type="INT";
				temp->is_num=0;
				temp->array_dem=0;
				return temp;
			}
		}
		else{
			struct Exp_TYPE* temp1,*temp2;
			temp1=Op_Exp(HashTable,p);
			temp2=Op_Exp(HashTable,p->rchild->rchild);
			//printf("%s %d\n",temp1->type,temp1->array_dem);
			if((strcmp(temp1->type,"Array")!=0&&temp1->id!=NULL)||temp1->array_dem==0)
				printf("Error type 10 at Line %d: \"%s\" is not an array.\n",p->line,temp1->id);
			else{
				if(strcmp(temp2->type,"INT")!=0)
					printf("Error type 12 at Line %d:\"%s\" is not an integer.\n",p->line,temp2->id);
				else{
					struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
					temp->line=p->line;
					temp->is_num=0;
					temp->array_dem=temp1->array_dem-1;
					if(temp->array_dem>0)
						temp->type="Array";
					else
						temp->type="INT";
					return temp;
				}
			}
			struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
			temp->line=p->line;
			temp->type="INT";//if error,we suggest that this Exp is INT;
			temp->is_num=0;
			temp->array_dem=0;
			return temp;
		}
	}
	else if(head->lchild->rchild==NULL){
		if(strcmp(head->lchild->name,"INT")==0){
			struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
			temp->line=head->line;
			temp->type="INT";
			temp->is_num=1;
			temp->array_dem=0;
			temp->id=head->lchild->content;
			return temp;
		}
		else if(strcmp(head->lchild->name,"FLOAT")==0){
			struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
			temp->line=head->line;
			temp->type="FLOAT";
			temp->is_num=1;
			temp->array_dem=0;
			temp->id=head->lchild->content;
			return temp;
		}
		else{
			//printf("%s\n",head->lchild->name);
			//printf("%s\n",head->lchild->content);
			int i = hash(head->lchild->content);
			struct HashNode* q = HashTable[i];
			if(q==NULL){
				struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
				temp->line=head->line;
				temp->type="E";
				temp->is_num=0;
				temp->array_dem=0;
				return temp;
			}
			while(q!=NULL){
				//printf("%s %s\n",q->name,head->lchild->content);
				if(strcmp(q->name,head->lchild->content)==0)
					break;
				q=q->next;
			}
			if(q==NULL){
				struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
				temp->line=head->line;
				temp->type="E";
				temp->is_num=0;
				temp->array_dem=0;
				return temp;
			}
			struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
			temp->line=head->line;
			temp->type=q->type;
			temp->is_num=0;
			temp->id=head->lchild->content;
			temp->array_dem=0;
			if(q->kind!=NULL)
				if(strcmp(q->kind,"Array")==0)
					temp->type=q->kind;
			if(strcmp(temp->type,"Array")==0){
				struct Size* asize=q->arraysize;
				temp->array_dem++;
				while(asize->next!=NULL){
					asize=asize->next;
					temp->array_dem++;
				}
			}
			
			return temp;
		}
	}
	else if(strcmp(head->lchild->rchild->name,"Exp")==0){
		return Op_Exp(HashTable,head->lchild->rchild);	
	}
	else{
		if(head->lchild->rchild->rchild->rchild==NULL){
			char* name=head->lchild->content;
			int i = hash(name);
			struct HashNode* q=HashTable[i];
			if(q==NULL){
				struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
				temp->line=head->line;
				temp->type="E";
				temp->is_num=0;
				temp->array_dem=0;
				return temp;
			}
			while(q!=NULL){
				if(strcmp(q->name,name)==0)
					break;
				q=q->next;
			}
			if(q==NULL){
				struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
				temp->line=head->line;
				temp->type="E";
				temp->is_num=0;
				temp->array_dem=0;
				return temp;
			}
			if(q->kind==NULL){
				printf("Error type 11 at Line %d: \"%s\" is not a function.\n",head->line,q->name);
			}
			else if(strcmp(q->kind,"Func")!=0){
				printf("Error type 11 at Line %d: \"%s\" is not a function.\n",head->line,q->name);
			}
			else{
				struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
				temp->line=head->line;
				temp->type=q->type;
				temp->is_num=0;
				temp->array_dem=0;
				return temp;
			}
			
		}
		else{
			char* name=head->lchild->content;
			int i = hash(name);
			struct HashNode* q=HashTable[i];
			struct Args_TYPE* t=Op_Args(HashTable,head->lchild->rchild->rchild);
			if(q==NULL){
				struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
				temp->line=head->line;
				temp->type="E";
				temp->is_num=0;
				temp->array_dem=0;
				return temp;
			}
			while(q!=NULL){
				if(strcmp(q->name,name)==0)
					break;
				q=q->next;	
			}
			if(q==NULL){
				struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
				temp->line=head->line;
				temp->type="E";
				temp->is_num=0;
				temp->array_dem=0;
				return temp;
			}
			if(q->kind==NULL){
				printf("Error type 11 at Line %d: \"%s\" is not a function.\n",head->line,q->name);
			}
			else if(strcmp(q->kind,"Func")!=0){
				printf("Error type 11 at Line %d: \"%s\" is not a function.\n",head->line,q->name);
			}
			else{
				struct HashNode* temp1=q->Func;
				struct Args_TYPE* temp2=t;
				while(temp1!=NULL&&temp2!=NULL){
					if(strcmp(temp1->type,temp2->type)!=0){
						temp1=q->Func;
						temp2=t;
						printf("Error type 9 at Line %d:Function \"%s(%s",head->line,q->name,temp1->type);
						temp1=temp1->next;
						while(temp1!=NULL){
							printf(" %s",temp1->type);
							temp1=temp1->next;
						}
						printf(")\" is not applicable for arguments \"(%s",temp2->type);
						temp2=temp2->next;
						while(temp2!=NULL){
							printf(" %s",temp2->type);
							temp2=temp2->next;
						}
						printf(")\".\n");
				
						struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
						temp->line=head->line;
						temp->type="E";
						temp->is_num=0;
						temp->array_dem=0;
						return temp;
					}
					temp1=temp1->next;
					temp2=temp2->next;
				}
				if(temp1==NULL&&temp2==NULL){
				struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
				temp->line=head->line;
				temp->type=q->type;
				temp->is_num=0;
				temp->array_dem=0;
				return temp;}
				else{
						temp1=q->Func;
						temp2=t;
						if(temp1==NULL)
						printf("Error type 9 at Line %d:Function \"%s(",head->line,q->name);
						else{
						printf("Error type 9 at Line %d:Function \"%s(%s",head->line,q->name,temp1->type);
						temp1=temp1->next;}
						while(temp1!=NULL){
							printf(" %s",temp1->type);
							temp1=temp1->next;
						}
						if(temp2==NULL)
						printf(")\" is not applicable for arguments \"(");
						else{
						printf(")\" is not applicable for arguments \"(%s",temp2->type);
						temp2=temp2->next;}
						while(temp2!=NULL){
							printf(" %s",temp2->type);
							temp2=temp2->next;
						}
						printf(")\".\n");
				
						struct Exp_TYPE* temp = (struct Exp_TYPE*)malloc(sizeof(struct Exp_TYPE));
						temp->line=head->line;
						temp->type="E";
						temp->is_num=0;
						temp->array_dem=0;
						return temp;
				}
			}
		}
	}
}

struct Args_TYPE* Op_Args(struct HashNode* HashTable[],struct Node *head){
	struct Exp_TYPE* temp1;
	struct Args_TYPE* temp2;
	temp1=Op_Exp(HashTable,head->lchild);
	if(head->lchild->rchild==NULL){
		temp2=(struct Args_TYPE*)malloc(sizeof(struct Args_TYPE));
		temp2->type=temp1->type;
		temp2->next=NULL;		
		return temp2;
	}
	else{
		struct Args_TYPE* temp3=(struct Args_TYPE*)malloc(sizeof(struct Args_TYPE));
		temp2=Op_Args(HashTable,head->lchild->rchild->rchild);
		temp3->type=temp1->type;
		temp3->next=temp2;
		return temp3;
	}
}
