# include<stdio.h>
# include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;
NODE *head;
void insert(int x)
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
}
void print()
{
	NODE *temp=head;
	printf("LIST IS \n");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	int n,i,x;
	head=NULL;
	printf("Enter number of values?\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the number\n");
		scanf("%d",&x);
		insert(x);
		print();
	}
	return 0;
}
