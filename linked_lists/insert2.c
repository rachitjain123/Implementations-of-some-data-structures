# include<stdlib.h>
# include<stdio.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;
NODE* insert(NODE *head,int x)
{
	NODE *temp=(NODE*)malloc(sizeof(NODE));
	temp->data=x;
	temp->next=head;
	head=temp;
	return head;
}
void print(NODE *head)
{
	printf("LIST is: ");
	while(head!=NULL)
	{
		printf(" %d",head->data);
		head=head->next;
	}
	printf("\n");
}
int main()
{
	NODE * head=NULL;
	printf("how many nos?\n");
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the number \n");
		scanf("%d",&x);
		head=insert(head,x);
		print(head);
	}
	return 0;
}
