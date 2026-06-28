#include<stdio.h>
#define size 10
int queue[size];
int front=-1,rear=-1;
void enqueue(int x){
	if(front==-1){
		front=rear=0;
		queue[rear]=x;
	}
	else if((rear+1)%size==front){
		printf("queue is full");
	}
	else{
		rear=(rear+1)%size;
		queue[rear]=x;
	}
}
void dequeue(){
	if(front==-1){
		printf("empty");
	}
	else if(front==rear){
		printf("deleted element: %d",queue[front]);
		front=rear=-1;
	}
	else{
		printf("deleted element: %d",queue[front]);
		front=(front+1)%size;
	}
}
void display(){
	if(front==-1){
		printf("queue is empty");
	}
	else{
	int i=front;
	while(i!=rear){
		printf("%d ",queue[i]);
		i=(i+1)%size;
	}
	printf("%d ",queue[rear]);
    }
}
int main(){
    int choice, x;

    while(1){
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
