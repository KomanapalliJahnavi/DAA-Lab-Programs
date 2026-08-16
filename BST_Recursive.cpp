#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int value){
    if(root == NULL)
        return createNode(value);
    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);
    return root;
}

struct Node* minimum(struct Node *root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node *root, int value){
    struct Node *temp;
    if(root == NULL)
        return root;
    if(value < root->data)
        root->left = deleteNode(root->left, value);
    else if(value > root->data)
        root->right = deleteNode(root->right, value);
    else{
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }
        temp = minimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node *root = NULL;
    int n, value, deleteValue, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("BST before deletion: ");
    inorder(root);
    printf("\nEnter value to delete: ");
    scanf("%d", &deleteValue);
    root = deleteNode(root, deleteValue);
    printf("BST after deletion: ");
    inorder(root);
    return 0;
}
