#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

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

/*
void Inorder(struct BstNode* root)
{
    if(root == NULL) return;
    
    Inorder(root->left);
    printf("%d\t",root->data);
    Inorder(root->right);
}
*/

bool ISBSTUtil(struct BstNode* root, int minval, int maxval)
{
    if(root == NULL) return true;
    
    if((root->data > minval) && (root->data < maxval) && (ISBSTUtil(root->left,minval,root->data)) && (ISBSTUtil(root->right,root->data,maxval)))
    {
        return true;
    }
    
    return false;
}

bool ISBST(struct BstNode* root)
{
    return ISBSTUtil(root,INT_MIN,INT_MAX);
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
    
    if(ISBST(root))
    {
        printf("It is binary search tree\n");
    }else
    {
        printf("It is not binary search tree\n");
    }
    
    return 0;
}
