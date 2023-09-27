/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/



#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* Next;  
}Node;

struct Node* Head;   
struct Node* temp;

void insert(int x)
{
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->Next = Head;
    Head =temp;
}

void print()
{
    Node* temp = Head;
    printf("the list is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->Next;
    }
    printf("\n");
}

void endnode()
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));    
    printf("enter the element to be entered at the end of the node\n");
    scanf("%d",&temp1->data);
    temp1->Next = NULL;
    while(temp->Next != NULL)
    {
        temp = temp->Next;  
    }
    temp->Next = temp1;
    print();
}
// head node will not be NULL at this point of time

int main(void)
{
    Head = NULL;     //address of the head node will be initially NULL
    int n,i,x;
    printf("enter how many numbers?\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the number");
        scanf("%d",&x);
        insert(x);
        print();
    }
    endnode();
}

