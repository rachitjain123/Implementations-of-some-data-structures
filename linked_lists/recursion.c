# include<stdio.h>
# include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;
void insert(int x,NODE *head)
{
	if(head->next==NULL)
	{
		NODE *temp=(NODE *)malloc(sizeof(NODE));
		temp->data=x;
		temp->next=NULL;
		head->next=temp;
	}
	else
		insert(x,head->next);
}
void print(NODE *head)
{
	if(head==NULL)
		return;
	print(head->next);
	printf(" %d",head->data);
}
void delete(int n,NODE *head)
{
	if(head->next==NULL)
		return;
	if(head->next->data==n)
	{
		head=head->next->next;
		free(head->next);
		return;
	}
	else
		return(head->next);
}
int main()
{
	NODE *head=NULL;
	int n,i,x;
	printf("Enter number of values?\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the number\n");
		scanf("%d",&x);
		if(i==1)
		{
			NODE *temp=(NODE *)malloc(sizeof(NODE));
			temp->data=x;
			temp->next=NULL;
			head=temp;
		}
		else
			insert(x,head);
		print(head);
		printf("\n");
	}
	printf("enter value to be deleted");
	int g;
	scanf("%d",&g);
	delete(g,head);
	print(head);
	return 0;
}
