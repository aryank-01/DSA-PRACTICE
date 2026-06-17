#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node *root, int x){

    struct node *t;

     if(root == NULL){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = x;
        t->left = t->right = NULL;
        return t;
    }

    struct node *prev = NULL;
    struct node *ptr = root;

    while(ptr != NULL){
        prev = ptr;

        if(x == ptr->data){
            printf("Element already exists\n");
            return root;
        }
        else if(x < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if(x < prev->data)
        prev->left = t;
    else
        prev->right = t;

    return root;
}

struct node* findMin(struct node* root){

    while(root->left != NULL)
        root = root->left;

    return root;
}

struct node* deleteNode(struct node* root, int key){

    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else{

        if(root->left == NULL && root->right == NULL)
            return NULL;

        else if(root->left == NULL)
            return root->right;

        else if(root->right == NULL)
            return root->left;

        struct node* temp = findMin(root->right);  //inorder sucessor
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct node *root){

    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){

    struct node *root = NULL;

    root = insert(root,50);
    root = insert(root,30);
    root = insert(root,70);
    root = insert(root,20);
    root = insert(root,40);

    printf("Inorder: ");
    inorder(root);

    root = deleteNode(root,30);

    printf("\nAfter deletion: ");
    inorder(root);

}