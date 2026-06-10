#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
char pop(){
    struct node *t;
    char x;
    if(top==NULL){
        printf("stack underflow!");
        return -1;
    }
    else{
        t = top;
        x = t->data;
        top = top->next;
        free(t);
        return x;
    }
}

int pre(char x){
	if(x=='+'||x=='-') return 1;
	else if(x=='/'||x=='*') return 2;
	return 0;
}
int isoperand(char x){
	if(x=='+'||x=='-'||x=='/'||x=='*'){
		return 0;
	}
	else return 1; 
}
char * intopo(char *infix){
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len+1)*sizeof(char));
    int i=0, j=0;

    while(infix[i] != '\0'){
        if(isoperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else if(infix[i] == '('){
            push(infix[i++]);   // no precedence check
        }
        else if(infix[i] == ')'){
            while(top->data != '('){
                postfix[j++] = pop();
        }
        pop();  // remove '('
        i++;
        }
        else{
            if(pre(infix[i]) > pre(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++] = pop();
            }
        }
    }
    while(top!=NULL){
        postfix[j++] = pop();
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    char infix[100];
    printf("enter your string: ");
    scanf("%s",infix);

    push('#');                 // sentinel

    char *postfix = intopo(infix);

    int len = strlen(postfix);
    if(postfix[len-1] == '#')  // remove sentinel if present
        postfix[len-1] = '\0';

    printf("%s", postfix);     // abc*+

    return 0;
}

