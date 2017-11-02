# include<stdio.h>
# include<stdlib.h>
# include<string.h>
int s[100];
struct node
{
    int data;
    struct node* next;
};
typedef struct node NODE;
NODE* top=NULL;
void push(int t)
{
    NODE* temp=(NODE* )malloc(sizeof(NODE));
    temp->data=t;
    temp->next=top;
    top=temp;
}
int pop()
{
    NODE *temp;
    if(top==NULL)
	return 0;
    temp=top;
    int x=temp->data;
    top=top->next;
    free(temp);
    return x;
}
void print()
{
    NODE *temp=top;
    while(temp!=NULL)
    {
	printf("%d ",temp->data);
	temp=temp->next;
    }
    printf("\n");
}
int main()
{
    return 0;
}
