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


int n;



void insert(int x)
{
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->Next = Head;
    Head = temp;
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


void delete()
{
    int m,j=1;
    struct Node* prev_node = Head;
    printf("which node should be deleted?");
    scanf("%d",&m);
    
    if(m>n)
    {
        printf("ERROR: There are only %d nodes",n);
        return;    
    }
    
    while(j < m-1)
    {
        prev_node = prev_node->Next;
    }
    struct Node* temp2 = prev_node->Next;
    prev_node->Next = temp2->Next;
    free(temp2);
    print();
}

// head node will not be NULL at this point of time



int main(void)

{
    
Head = NULL;     //address of the head node will be initially NULL
    
int i,x;
    
printf("enter how many numbers?\n");
    
scanf("%d",&n);
    
for(i=0;i<n;i++)
    
{
        
printf("enter the number");
        
scanf("%d",&x);
        
insert(x);
        
print();
    
}
    
    
delete();

}


