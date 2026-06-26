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
	first->next=NULL;
	last=first;
	
	for(int i=1;i<n;i++){
	t=(struct node *)malloc(sizeof(struct node));
	t->data=arr[i];
    t->next=NULL;
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
int count(struct node *p){
	if(p==0) return 0;
	else return count(p->next)+1;
}
void add(struct node *p){
	int sum=0;
	while(p!=0){
		sum+=p->data;
		p=p->next;
	}
	printf("\nsum of elemnts: %d",sum);
}
void max(struct node *p){
	int max =0;
	while(p!=0){
		if(p->data>max){
		max=p->data;
	    p=p->next;
	    }
	}
	printf("\nmax number: %d",max);
}
struct node* search(struct node *p,int x){  //linear_search
	while(p!=0){
		if(p->data==x){
			return p;
		}
		p=p->next;
	}
	return NULL; //if key not found
}
void insert(struct node *p,int x,int index){
	if(index<0 || index>count(p)) return;
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	if(index==0){
     	t->next=first;
     	first=t;
	    }
	else{
		for(int i=0;i<index-1;i++){
			p=p->next;
		}
		t->next=p->next;
		p->next=t;
	}
}
int main(){
	int arr[5]={2,4,6,8,10};
	create(arr,5);
	display(first);
	printf("\nlengh is: %d",count(first));
	add(first);
	max(first);
	printf("\nyour key is found & is in: %p\n",search(first,8));
	insert(first,69,3); //inserted 69 after 3rd element
	display(first);
	return 0;
}