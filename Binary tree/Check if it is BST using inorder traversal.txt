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


bool Inorder(struct BstNode* root)
{
    //static int curr_data;
    static int prev_data = 0;
    if(root == NULL)
    {
        return true;
    }
   
    Inorder(root->left);
    prev_data = root->data;
    
    printf("%d\t",root->data);
    Inorder(root->right);
    if(prev_data <= root->data)
    {
        return false;
    }else
    {
        return true;
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
    root = Insert(root,17);
    root = Insert(root,24);
    root = Insert(root,54);
    root = Insert(root,23);
    
    if(Inorder(root))
    {
        printf("It is binary search tree\n");
    }else
    {
        printf("It is not binary search tree\n");
    }
    
    return 0;
}
