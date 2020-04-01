/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop()
{
    struct Node *temp;
    if(top == NULL) return;
    temp = top;
    top = top->link;
    free(temp);
}

void Top()
{
    return top->data;
}

void print()
{
    struct Node* temp = top;
    printf("the list is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    
    Push(2);print();
    Push(8);print();
    Push(10);print();
    Pop();print();
    Top();

}
