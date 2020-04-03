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

struct BstNode* search(struct BstNode* root, int value)
{
    if(root == NULL) return NULL;
    else if(root->data == value) return root;
    else if(value <= root->data) return search(root->left,value);
    else return search(root->right,value);
}

struct BstNode* GetSuccessor(struct BstNode* root, int value)
{
    struct BstNode* curr_node = search(root,value);
    
    if(curr_node->right != NULL) //if it has right subtree
    {
        return FindMin(root->right);
    }else
    {
        //if it has no right subtree
        
        struct BstNode* ancestor = root;
        struct BstNode* sucessor = NULL;
        while(ancestor != curr_node)
        {
            if(curr_node->data < ancestor->data)
            {
                sucessor = ancestor;
                ancestor = ancestor->left;
            }else
            {
                ancestor = ancestor->right;
            }
        }
        return sucessor;
        
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
    
    struct BstNode* sucessor = GetSuccessor(root,10);
    struct BstNode* sucessor1 = GetSuccessor(root,25);
    printf("the successor of 10 is %d \n",sucessor->data);
    printf("the successor of 25 is %d ",sucessor1->data);
}
