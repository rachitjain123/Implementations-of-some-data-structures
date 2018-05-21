# include<stdio.h>
# include<stdlib.h>
struct node
{
	int data;
	struct node * next;
};
void insert(int data);
void delete(int n);
void print();
typedef struct node NODE;
NODE * head;
void insert(int data)
{
	if(head==NULL)
	{
		NODE *temp=(NODE *)malloc(sizeof(NODE));
		temp->data=data;
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
		tmp1->data=data;
		tmp1->next=NULL;
	}
}
void delete(int n)
{
	NODE *temp=head;
	if(n==1)
	{
		head=temp->next;
		free(temp);
	}
	else
	{
		int i=0;
		for(i=0;i<n-2;i++)
		{
			temp=temp->next;
			n--;
		}
		NODE *temp2=temp->next;
		temp->next=temp2->next;
		free(temp2);
	}
}
void print()
{
	NODE *temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	head=NULL;
	insert(2);
	insert(4);
	insert(6);
	insert(5);
	int n;
	printf("Enter a position\n");
	scanf("%d",&n);
	delete(n);
	print();
	return 0;
}