#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x){
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;

    if(front == NULL){   // empty queue
        front = rear = t;
    }
    else{
        rear->next = t;
        rear = t;
    }
}

void dequeue(){
    struct node *q;

    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        q = front;
        printf("Deleted : %d\n", q->data);
        front = front->next;
        free(q);

        if(front == NULL)   // queue became empty
            rear = NULL;
    }
}

void display(){
    struct node *p = front;

    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        while(p != NULL){
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}
int main(){
    int choice, x;

    while(1){
        printf("\n--- QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
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
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
