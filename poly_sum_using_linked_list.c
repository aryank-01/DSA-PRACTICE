#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int coff;
	int exp;
	struct node *next;
}*poly=NULL;
void create(){
	struct node *last,*t;
	int num;
	printf("enter number of terms: ");
	scanf("%d",&num);
	printf("enter each term with coff and exp: \n");
	for(int i=0;i<num;i++){
		t=(struct node *)malloc(sizeof(struct node));
		scanf("%d%d",&t->coff,&t->exp);
		t->next=NULL;
		if(poly==NULL) poly=last=t;
		else{
			last->next=t;
			last=t;
		}
	}
}
void displaysum(struct node *p,int x){
	int sum;
	while(p!=NULL){
		printf("%dx%d +",p->coff,p->exp);
		sum+=p->coff*pow(x,p->exp);
		p=p->next;
	}
	printf("%d=",sum);
	
}
int main(){
	create();
	displaysum(poly,2);
return 0;
}