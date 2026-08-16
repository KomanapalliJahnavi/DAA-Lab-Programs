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
    struct Node *newNode, *current, *parent;
    newNode = createNode(value);
    if(root == NULL)
        return newNode;
    current = root;
    parent = NULL;
    while(current != NULL){
        parent = current;
        if(value < current->data)
            current = current->left;
        else if(value > current->data)
            current = current->right;
        else{
            free(newNode);
            return root;
        }
    }
    if(value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}

struct Node* deleteNode(struct Node *root, int value)
{
    struct Node *current, *parent, *child;
    struct Node *successor;
    current = root;
    parent = NULL;
    while(current != NULL && current->data != value){
        parent = current;
        if(value < current->data)
            current = current->left;
        else
            current = current->right;
    }
    if(current == NULL)
        return root;
    if(current->left != NULL && current->right != NULL){
        successor = current->right;
        parent = current;
        while(successor->left != NULL){
            parent = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        current = successor;
    }
    if(current->left != NULL)
        child = current->left;
    else
        child = current->right;
    if(parent == NULL){
        free(current);
        return child;
    }
    if(parent->left == current)
        parent->left = child;
    else
        parent->right = child;
    free(current);
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
