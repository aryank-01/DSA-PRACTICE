#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*first=NULL;

void create(int arr[],int n){
	struct node *t,*last;
	first=(struct node *)malloc(sizeof(struct node));
	first->data=arr[0];
	first->next=first;
	last=first;
	
	for(int i=1;i<n;i++){
	t=(struct node *)malloc(sizeof(struct node));
	t->data=arr[i];
    t->next=last->next;
    last->next=t;
	last=t;
	}
}
void display(struct node *p){
	do{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=first);
}

void insert(struct node *p,int index,int x){
	struct node *t;
	if(index == 0){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if(first == NULL){
            t->next = t;
            first = t;
        }
        else{
            p = first;
            while(p->next != first){
                p = p->next;   // move to last node
            }
            t->next = first;
            p->next = t;
            first = t;
        }
    }
    else{
	for(int i=0;i<index-1;i++){
		p=p->next;
	}
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	t->next=p->next;
	p->next=t;
    }
}
int Delete(struct node *p,int index){
	struct node *q=NULL;
	int x;
	if(index<1 || index>7) return -1;
	if(index==1){
		q=first;
		x=first->data;
		first=first->next;
		free(q);
		return x;
	}
	else{
		for(int i=0;i<index-1;i++){
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		free(p);
		return x;
	}
}
int main(){
	int arr[5]={2,5,6,3,1};
	create(arr,5);
	display(first);
	printf("\n");
	insert(first,2,99);
	display(first);
	printf("\n");
	Delete(first,3);
	display(first);
	return 0;
}