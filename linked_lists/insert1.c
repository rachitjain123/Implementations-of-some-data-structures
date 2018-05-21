# include<stdlib.h>
# include<stdio.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;
NODE * head;
void insert(int x)
{
	NODE *temp=(NODE*)malloc(sizeof(NODE));
	temp->data=x;
	temp->next=head;
	head=temp;
}
void print()
{
	NODE *temp=head;
	printf("LIST is: ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	head=NULL;
	printf("how many nos?\n");
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the number \n");
		scanf("%d",&x);
		insert(x);
		print();
	}
	return 0;
}
