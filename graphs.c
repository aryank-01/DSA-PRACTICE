#include<stdio.h>

#define SIZE 20

int queue[SIZE];
int front = -1;
int rear = -1;

int isEmpty()
{
    if(front == -1 || front > rear)
        return 1;
    return 0;
}

void enqueue(int x)
{
    if(rear == SIZE-1)
        printf("Queue is Full\n");
    else
    {
        if(front == -1)
            front = 0;
        queue[++rear] = x;
    }
}

int dequeue()
{
    if(isEmpty())
        return -1;
    return queue[front++];
}

void BFS(int G[7][7], int start, int n)
{
    int i, j;
    int visited[7] = {0};

    printf("%d ", start);
    visited[start] = 1;
    enqueue(start);

    while(!isEmpty())
    {
        i = dequeue();
        for(j = 1; j < n; j++)
        {
            if(G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}
void DFS(int G[7][7], int v, int n)
{
    static int visited[7] = {0};   // keeps track of visited nodes
    int j;

    printf("%d ", v);              // visit the vertex
    visited[v] = 1;                // mark as visited

    for(j = 1; j < n; j++)         // check all adjacent vertices
    {
        if(G[v][j] == 1 && visited[j] == 0)
        {
            DFS(G, j, n);          // recursive call
        }
    }
}
int main()
{
    int G[7][7] = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    BFS(G,1,7);
    DFS(G, 1, 7);
    
    return 0;
}