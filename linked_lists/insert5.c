# include<stdlib.h>
# include<stdio.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;
NODE * head;
void insert(int data,int n)
{
	NODE *temp1=(NODE *)malloc(sizeof(NODE ));
	temp1->data=data;
	temp1->next=NULL;
	if(n==1)
	{
		temp1->next=head;
		head=temp1;
		return;
	}
	NODE* temp2=head;
	int i=0;
	for(i=0;i<n-2;i++)
		temp2=temp2->next;
	temp1->next=temp2->next;
	temp2->next=temp1;
}
void print()
{
	NODE* temp=head;
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
	insert(2,1);
	insert(3,2);
	insert(4,1);
	insert(5,2);
	print();
	return 0;
}
