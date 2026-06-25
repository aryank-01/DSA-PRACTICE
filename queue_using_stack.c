#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

int s1[SIZE], s2[SIZE];
int top1 = -1, top2 = -1;

/* STACK OPERATIONS */
void push1(int x){
    s1[++top1] = x;
}

void push2(int x){
    s2[++top2] = x;
}

int pop1(){
    return s1[top1--];
}

int pop2(){
    return s2[top2--];
}

/* QUEUE OPERATIONS */
void enqueue(int x){
    if(top1 == SIZE - 1){
        printf("Queue Overflow\n");
        return;
    }
    push1(x);
    printf("Inserted : %d\n", x);
}

void dequeue(){
    int x;

    if(top1 == -1 && top2 == -1){
        printf("Queue is empty\n");
        return;
    }

    if(top2 == -1){
        while(top1 != -1){
            x = pop1();
            push2(x);
        }
    }

    x = pop2();
    printf("Deleted : %d\n", x);
}

void display(){
    int i;

    if(top1 == -1 && top2 == -1){
        printf("Queue is empty\n");
        return;
    }

    /* Print elements in s2 */
    for(i = top2; i >= 0; i--)
        printf("%d ", s2[i]);

    /* Print elements in s1 */
    for(i = 0; i <= top1; i++)
        printf("%d ", s1[i]);

    printf("\n");
}

/* MAIN */
int main(){
    int choice, x;

    while(1){
        printf("\n--- QUEUE USING STACK ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
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
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
