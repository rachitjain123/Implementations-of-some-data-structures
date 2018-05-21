# include<stdio.h>
# include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE * reverse(NODE *head);
NODE * insert(NODE *head,int x);
void print(NODE *head);
NODE * reverse(NODE *head)
{
	NODE * current,*prev,*next1;
	current=head;
	prev=NULL;
	while(current!=NULL)
	{
		next1=current->next;
		current->next=prev;
		prev=current;
		current=next1;
	}
	head=prev;
	return head;
}
NODE * insert(NODE *head,int x)
{
	NODE *temp=(NODE *)malloc(sizeof(NODE));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		NODE *tmp1=head;
		while(tmp1->next!=NULL)
			tmp1=tmp1->next;
		tmp1->next=temp;
	}
	return head;
}
void print(NODE *head)
{
	while(head!=NULL)
	{
		printf(" %d",head->data);
		head=head->next;
	}
	printf("\n");
}
int main()
{
	NODE *head=NULL;
	head=insert(head,2);
	head=insert(head,4);
	head=insert(head,6);
	head=insert(head,8);
	print(head);
	head=reverse(head);
	print(head);
	return 0;
}
