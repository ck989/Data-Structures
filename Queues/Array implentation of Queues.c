/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define MAX_CHAR 10
int A[MAX_CHAR];

int front = -1;
int rear = -1;

bool IsEmpty()
{
    if ((front == -1) && (rear == -1))
    {
        return true;
    }
    
    return false;
}

void Enqueue(int x)
{
    if((rear + 1)%MAX_CHAR == front)
    {
        printf("Queue is full \n");
        return;
    }
    
    if(IsEmpty())
    {
        front = rear = 0;
    }else
    {
        rear = (rear + 1)%MAX_CHAR;
        
    }
    A[rear] = x;
    
}

void Dequeue()
{
    if(IsEmpty())
    {
        return;
    }else if(front == rear)
    {
        front = rear = -1;
    }else
    {
        front = (front + 1)%MAX_CHAR;
    }
}

int Qfront()
{
    return A[front];
}

void Print()
{
    int i;
    int count = ((rear+MAX_CHAR-front)%MAX_CHAR) + 1;
		     
	for( i = 0; i <count; i++)
	{
		printf("%d\t",A[(front+i) % MAX_CHAR]);
	}
	//printf("\n");
}

int main()
{
    int i,n,x;
    
    
    printf("Enter how many elements to be written in queue\n");
    scanf("%d",&n);
    
    for(i=0; i<n; i++)
    {
        printf("enter the element");
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
