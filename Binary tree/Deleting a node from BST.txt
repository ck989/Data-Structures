/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

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

struct BstNode* FindMin(struct BstNode* root)
{
    if(root == NULL) 
    {
        printf("Error: Tree is empty\n");
        return NULL;
    }else if(root->left == NULL)
    {
        return root;
    }
    
    return FindMin(root->left);
}

void Inorder(struct BstNode* root)
{
    if(root == NULL) return;
    
    Inorder(root->left);
    printf("%d\t",root->data);
    Inorder(root->right);
}

struct BstNode* delete(struct BstNode* root, int value)
{
    if(root == NULL) return root;
    else if(value < root->data) root->left = delete(root->left, value);
    else if(value > root->data) root->right = delete(root->right, value);
    else // if value is found
    {
        //if it is leaf node
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // if root has one child
        else if(root->left == NULL)
        {
            struct BstNode* temp = root;
            root = root->right;
            free(temp);
        }else if(root->right == NULL)
        {
            struct BstNode* temp = root;
            root = root->left;
            free(temp);  
        }else //if node has 2 children
        {
            struct BstNode* temp =  FindMin(root->right);
            root->data = temp->data;
            root->right = delete(root->data,temp->data);
        }
        
    }
    
    return root;
    
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
    
    printf("nodes before Deleting\n");
    Inorder(root);
    
    root = delete(root,30);
    printf("\n");
    printf("nodes after Deleting\n");
    Inorder(root);
    
    
}
