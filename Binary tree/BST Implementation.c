#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _BSTNode{
    int data;
    struct _BSTNode* left;
    struct _BSTNode* right;
}BSTNode;

typedef struct _QueueNode{
    BSTNode* node;
    struct _QueueNode* Next;
}QueueNode;

void Enqueue(QueueNode** FrontPtr, QueueNode** RearPtr, BSTNode* bstnode){
    QueueNode* New_Node = (QueueNode*)malloc(sizeof(QueueNode));
    New_Node->node = bstnode;
    New_Node->Next = NULL;
    
    if(*FrontPtr == NULL && *RearPtr == NULL){
        *FrontPtr = *RearPtr = New_Node;
    }else{
        (*RearPtr)->Next = New_Node;
        *RearPtr = New_Node;
    }
}

void Dequeue(QueueNode** FrontPtr, QueueNode** RearPtr){
    QueueNode* Curr_Node = *FrontPtr;
    
    if(Curr_Node->Next != NULL){
        *FrontPtr = Curr_Node->Next;
    }else{
        *RearPtr = NULL;
        *FrontPtr = NULL;
    }
    free(Curr_Node);
}

BSTNode* Front(QueueNode** FrontPtr){
    if(*FrontPtr != NULL)
        return (*FrontPtr)->node;
    
    return NULL;
}

bool IsEmpty(QueueNode** FrontPtr, QueueNode** RearPtr){
    if(*FrontPtr == NULL  && *RearPtr == NULL)
        return true;
    
    return false;
}

void LevelOrderTraversel(BSTNode** RootPtr){
    if(*RootPtr == NULL) return;
    
    QueueNode* front = NULL;
    QueueNode* rear = NULL;
    
    Enqueue(&front, &rear, *RootPtr);
    
    printf("LevelOrderTraversal: ");
    while(!IsEmpty(&front, &rear)){
        BSTNode* curr_node = Front(&front);
        printf("%d\t", curr_node->data);
        
        Dequeue(&front, &rear);
        if (curr_node->left != NULL) Enqueue(&front, &rear, curr_node->left);
         if (curr_node->right != NULL) Enqueue(&front, &rear, curr_node->right);       
    }
    printf("\n");
}

void Insert(BSTNode** RootPtr, int val){
    if(*RootPtr == NULL){
        BSTNode* New_Node = (BSTNode*)malloc(sizeof(BSTNode));
        New_Node->data = val;
        New_Node->left = New_Node->right = NULL;
        
        *RootPtr = New_Node;
    }else if(val <= (*RootPtr)->data){
        Insert(&(*RootPtr)->left, val);
    }else{
        Insert(&(*RootPtr)->right, val);   
    }
}

void PreOrderTravesel(BSTNode** RootPtr){
    if(*RootPtr == NULL)
        return;
        
    printf("%d\t", (*RootPtr)->data);
    PreOrderTravesel(&(*RootPtr)->left);
    PreOrderTravesel(&(*RootPtr)->right);
}

void InOrderTravesel(BSTNode** RootPtr){
    if(*RootPtr == NULL)
        return;
        
    InOrderTravesel(&(*RootPtr)->left);
    printf("%d\t", (*RootPtr)->data);
    InOrderTravesel(&(*RootPtr)->right);
}

bool Search(BSTNode** RootPtr, int val) 
{
    if(*RootPtr == NULL) return false;
    else if((*RootPtr)->data == val) return true;
    else if(val <= (*RootPtr)->data) return Search(&(*RootPtr)->left, val);
    else return Search(&(*RootPtr)->right, val);
}

int main() {
    BSTNode* root = NULL;
    
    Insert(&root, 15);
    Insert(&root, 7);
    Insert(&root, 20);
    Insert(&root, 3);
    Insert(&root, 25);
    Insert(&root, 8);
    Insert(&root, 12);
    Insert(&root, 11);
    
    if(Search(&root, 6)){
        printf("6 found\n");
    }else{
        printf("6 not found\n");
    }

    if(Search(&root, 11)){
        printf("11 found\n");
    }else{
        printf("11 not found\n");
    }
    
    LevelOrderTraversel(&root);
    printf("Preorder: ");
    PreOrderTravesel(&root);
    printf("\n");
    printf("Inorder: ");
    InOrderTravesel(&root);
    
    return 0;
}
