# include<stdio.h>
# include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;
NODE * insert(int x,NODE *head)
{
	if(head==NULL)
	{
		NODE *temp=(NODE *)malloc(sizeof(NODE));
		temp->data=x;
		temp->next=NULL;
		head=temp;
	}
	else
	{
		NODE *tmp1=head;
		while(tmp1->next!=NULL)
			tmp1=tmp1->next;
		tmp1->next=(NODE *)malloc(sizeof(NODE));
		tmp1=tmp1->next;
		tmp1->data=x;
		tmp1->next=NULL;
	}
	return head;
}
void print(NODE *head)
{
	printf("LIST IS \n");
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
	int n,i,x;
	printf("Enter number of values?\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the number\n");
		scanf("%d",&x);
		head=insert(x,head);
		print(head);
	}
	return 0;
}
