/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*
    Queues is implemented using Link list
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct Node{
    struct BstNode* data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(struct BstNode* x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    
    if ((front == NULL) && (rear == NULL))
    {
        front = rear = temp;
        return;
    }
    
    //adding new at rear end to make time complexity O(1)
    rear->next = temp;
    rear = temp;
}

bool IsEmpty()
{
    if ((front == NULL) && (rear == NULL))
    {
        return true;
    }
    
    return false;
}

void Dequeue()
{
    struct Node* temp = front;
    if(front == NULL) return;
    if(front == rear){
        front = rear = NULL;
    }else
    {
        front = front->next;
    }
    
    free(temp);
    
}

struct BstNode* Qfront()
{
    if(front == NULL)
    {
        printf("no data is present\n");
        return -1;
    }
    
    return front->data;
}

struct BstNode* GetNewNode(int data)
{
    struct BstNode* newnode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct BstNode* Insert(struct BstNode* root, int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
    }else if(data <= root->data)
    {
        root->left = Insert(root->left,data);
    }else
    {
        root->right = Insert(root->right,data);
    }
    
    return root;
}

void LevelOrder(struct BstNode* root)
{
    if(root == NULL) return;
    
    Enqueue(root);
    while(!IsEmpty())
    {
        struct BstNode* current = Qfront();
        printf("%d\t",current->data);
        if(current->left != NULL) Enqueue(current->left);
        if(current->right != NULL) Enqueue(current->right);
        Dequeue();
    }
}

int main()
{
    struct BstNode* root = NULL;
    
    root = Insert(root,20);
    root = Insert(root,30);
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,25);
    root = Insert(root,22);
    
    LevelOrder(root);
    
}


