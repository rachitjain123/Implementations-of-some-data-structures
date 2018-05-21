# include<stdlib.h>
# include<stdio.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;
NODE * head,*u,*v;
NODE * insert(int x)
{
	NODE *temp=(NODE*)malloc(sizeof(NODE));
	temp->data=x;
	temp->next=head;
	head=temp;
	return head;
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
void find()
{
	int h=0;
	while(1)
	{
		if(u->next->next=NULL)
			break;
		h++;
		u=u->next;	
		if(h%2==0)
			v=u;

	}
}
int main()
{
	head=NULL;
	int n,i,x;
	while(1)
	{
		printf("Enter the number \n");
		scanf("%d",&x);
		if(x==13)
			break;
		head=insert(x);
		print();
	}
	u=head;
	v=head;
	find();
	return 0;
}