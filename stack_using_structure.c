#include<stdio.h>
#include<stdlib.h>
struct stack{
	int size;
	int top;
	int *s;
};
void create(struct stack *st){
	printf("enter the size of stack: ");
	scanf("%d",&st->size);
	st->top=-1;
	st->s=(int *)malloc(st->size*sizeof(int));
}
void display(struct stack *st){
    if(st->top == -1){
        printf("Stack is empty\n");
        return;
    }
    for(int i = st->top; i >= 0; i--){
        printf("%d ", st->s[i]);
    }
    printf("\n");
}

void push(struct stack *st,int x){
	if(st->top==st->size-1) printf("overflow!");
	else{
		st->top++;
		st->s[st->top]=x;
	}
}
void pop(struct stack *st){
	if(st->top==-1) printf("underflow!");
	else{
		int x=st->s[st->top--];
		printf("%d poped from stack\n",x);	
	}
}
void peek(struct stack *st){
    if(st->top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element is: %d\n", st->s[st->top]);
}

int main(){
	struct stack st;
	create(&st);
	push(&st,8);
	push(&st,2);
	push(&st,6);
	display(&st);
	pop(&st);
	display(&st);
	peek(&st);
	return 0;
}