#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	
}*top=NULL;
void push(int x){
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL) printf("stack overflow");
	else{
		t->data=x;
		t->next=top;
		top=t;
	}
}
void pop(){
	struct node *t;
	int x;
	if(top==NULL) printf("stack underflow!");
	else{
		t=top;
		x=t->data;
		top=top->next;
		free(t);
		printf("element removed is %d\n",x);
	}
}
void display(){
	struct node *p;
	p=top;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void peek(){
    if(top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element is %d\n", top->data);
}

int main(){
	push(10);
	push(20);
	push(30);
	display();
	pop();
	display();
	peek();
	return 0;
}