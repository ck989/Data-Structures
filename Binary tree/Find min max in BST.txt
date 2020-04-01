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

bool Search(struct BstNode* root, int data)
{
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left,data);
    else return Search(root->right,data);
}

int FindMin(struct BstNode* root)
{
    if(root == NULL) 
    {
        printf("Error: Tree is empty\n");
        return -1;
    }else if(root->left == NULL)
    {
        return root->data;
    }
    
    return FindMin(root->left);
}

int FindMax(struct BstNode* root)
{
    if(root == NULL) 
    {
        printf("Error: Tree is empty\n");
        return -1;
    }else if(root->right == NULL)
    {
        return root->data;
    }
    
    return FindMax(root->right);
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
    
    int n,m;
    
    n = FindMin(root);
    printf("The min value is %d\n",n);
    
    m = FindMax(root);
    printf("The max value is %d\n",m);
    return 0;
}
