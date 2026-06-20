#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
}*first=NULL;
void create(int arr[],int n){
	struct node *t,*last;
	first=(struct node *)malloc(sizeof(struct node));
	first->data=arr[0];
	first->prev=NULL;
	first->next=NULL;
	last=first;
	
	for(int i=1;i<n;i++){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=arr[i];
		t->next=NULL;
		t->prev=last;
		last->next=t;
		last=t;
	}	
}
void display(struct node *p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
void insert(struct node *p, int index, int x){
    struct node *t;
    if(index < 0) return;

    if(index == 0){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->prev = NULL;
        t->next = first;

        if(first != NULL){
            first->prev = t;  
        }
        first = t;
    }
    else{
        for(int i = 0; i < index-1 && p != NULL; i++){
            p = p->next;
        }

        if(p == NULL) return;

        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->prev = p;
        t->next = p->next;

        if(p->next != NULL){
            p->next->prev = t; 
        }
        p->next = t;
    }
}

int Delete(struct node *p, int index){
    int x;
    if(index < 1 || first == NULL)
        return -1;
    // delete first node
    if(index == 1){
        p = first;
        first = first->next;
        if(first != NULL)
            first->prev = NULL;

        x = p->data;
        free(p);
    }
    // delete node other than first
    else{
        p = first;
        for(int i = 0; i < index - 1; i++){
            p = p->next;
            if(p == NULL) return -1;
        }
        p->prev->next = p->next;
        if(p->next != NULL){
        	p->next->prev = p->prev;
		}
        x = p->data;
        free(p);
    }
    return x;
}

void reverse(struct node *p){
    struct node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        if (p->prev == NULL){   
            first = p;
        }
        p = p->prev;  // move forward
    }
}

int main(){
	int arr[6]={10,20,30,40,50,60};
	create(arr,6);
	display(first);
	printf("\n");
	insert(first,4,45);
	display(first);
	printf("\n");
	Delete(first,1);
	display(first);
	printf("\n");
	reverse(first);
	display(first);
}