#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node* next; 
};
typedef struct node NODE;
NODE *front=NULL;
NODE *rear=NULL;
void enqueue(int x)
{
    NODE *temp=(NODE *)malloc(sizeof(NODE));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL &&rear==NULL)
    {
	front=rear=temp;
	return;
    }
    rear->next=temp;
    rear=temp;
}
void dequeue()
{
    NODE *temp=front;
    if(front==NULL)
	return;
    if(front==rear)
	front=rear=NULL;
    else
	front=front->next;
    free(temp);
}
int main()
{
    return 0;
}
