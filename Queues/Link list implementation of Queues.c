/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(int x)
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

int Qfront()
{
    if(front == NULL)
    {
        printf("no data is present\n");
        return -1;
    }
    
    return front->data;
}

void Print()
{
    struct Node* temp = front;
    
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    
}

int main()
{
    int i,n,x;
    
    
    printf("Enter how many elements to be written in queue\n");
    scanf("%d",&n);
    
    for(i=0; i<n; i++)
    {
        printf("enter the elements\n");
        scanf("%d\n",&x);
        Enqueue(x);
        
    }
    printf("elements before Dequeue\n");
    Print();
    
    Dequeue();
    printf("\n");
    printf("elements after Dequeue\n");
    Print();

    return 0;
}
