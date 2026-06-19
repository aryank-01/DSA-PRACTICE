#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

// Get height
int height(struct node *n){
    if(n == NULL)
        return 0;
    return n->height;
}

// Max function
int max(int a, int b){
    return (a > b) ? a : b;
}

// Create node
struct node* createNode(int x){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

// Right rotation (LL case)
struct node* rightRotate(struct node *y){
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation (RR case)
struct node* leftRotate(struct node *x){
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor
int getBalance(struct node *n){
    if(n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

// Insert into AVL
struct node* insert(struct node* node, int key){

    // Normal BST insertion
    if(node == NULL)
        return createNode(key);

    if(key < node->data)
        node->left = insert(node->left, key);

    else if(key > node->data)
        node->right = insert(node->right, key);

    else
        return node;

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Get balance
    int balance = getBalance(node);

    // LL case
    if(balance > 1 && key < node->left->data)
        return rightRotate(node);

    // RR case
    if(balance < -1 && key > node->right->data)
        return leftRotate(node);

    // LR case
    if(balance > 1 && key > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL case
    if(balance < -1 && key < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal
void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){

    struct node *root = NULL;

    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30); // triggers rotation
    root = insert(root,40);
    root = insert(root,50);

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}