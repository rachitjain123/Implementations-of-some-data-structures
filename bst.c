#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct qnode
{
    struct node *data;
    struct qnode *next;
};
typedef struct node NODE;
typedef struct qnode QNODE;
QNODE *front=NULL;
QNODE *rear=NULL;
void enqueue(NODE *x)
{
    QNODE *temp=(QNODE *)malloc(sizeof(QNODE));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL &&rear==NULL)
    {
	front=rear=temp;
	return;
    }
    rear->next=temp;
    rear=temp;
}
void dequeue()
{
    QNODE *temp=front;
    if(front==NULL)
	return;
    if(front==rear)
	front=rear=NULL;
    else
	front=front->next;
    free(temp);
}
NODE * getnewnode(int data)
{
    NODE *newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
NODE *insert(NODE * root,int data)
{
    if(root==NULL)
	root=getnewnode(data);
    else if(data<=root->data)
	root->left=insert(root->left,data);
    else
	root->right=insert(root->right,data);
    return root;
}
bool search(NODE*root,int data)
{
    if(root==NULL)
	return false;
    else if(root->data==data)
	return true;
    else if(data<=root->data)
	return search(root->left,data);
    else
	return search(root->right,data);
}
int min(NODE *root)
{
    if(root->left==NULL)
	return root->data;
    return min(root->left);
}
int max(NODE *root)
{
    if(root->right==NULL)
	return root->data;
    return max(root->right);
}
int maximum(int a,int b)
{
    if(a>b)
	return a;
    else
	return b;
}
int height(NODE *root)
{
    if(root==NULL)
	return -1;
    return maximum(height(root->left),height(root->right))+1;
}
void levelorder(NODE *root)
{
    if(root==NULL)
	return;
    enqueue(root);
    while(front!=NULL)
    {
	NODE *current=front->data;
	dequeue();
	printf("%d ",current->data);
	if(current->left!=NULL)
	    enqueue(current->left);
	if(current->right!=NULL)
	    enqueue(current->right);
    }
}
void preorder(NODE *root)
{
    if(root==NULL)
	return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(NODE *root)
{
    if(root!=NULL)
    {
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
    }
}
void postorder(NODE *root)
{
    if(root==NULL)
	return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
bool is_binary_search_tree(NODE *root,int minvalue,int maxvalue)
{
    if(root==NULL)
	return true;
    if(root->data>minvalue && root->data<maxvalue && is_binary_search_tree(root->left,minvalue,root->data)&& is_binary_search_tree(root->right,root->data,maxvalue))
	return true;
    else
	return false;
}
NODE *Findmin(NODE *root)
{
    if(root==NULL)
	return NULL;
    while(root->left!=NULL)
	root=root->left;
    return root;
}
NODE *delete(NODE *root,int data)
{
    if(root==NULL)
	return root;
    else if(data<root->data)
	root->left=delete(root->left,data);
    else if(data>root->data)
	root->right=delete(root->right,data);
    else
    {
	if(root->left==NULL && root->right==NULL)
	{
	    free(root);
	    return NULL;
	}
	else if(root->left==NULL)
	{
	    NODE *temp=root;
	    root=root->right;
	    free(temp);
	}
	else if(root->right==NULL)
	{
	    NODE *temp=root;
	    root=root->left;
	    free(temp);
	}
	else
	{
	    NODE *temp=Findmin(root->right);
	    root->data=temp->data;
	    root->right=delete(root->right,temp->data);
	}
    }
    return root;
}
NODE *Find(NODE *root, int data) 
{
    if(root == NULL) 
	return NULL;
    else if(root->data == data) 
	return root;
    else if(root->data < data) 
	return Find(root->right,data);
    else return Find(root->left,data);
}
NODE * getsuccessor(NODE *root,int data)
{
    NODE *current=Find(root,data);
    if(current==NULL)
	return NULL;
    if(current->right!=NULL)
	return Findmin(current->right);
    else
    {
	NODE *successor=NULL;
	NODE *ancestor=root;
	while(ancestor!=current)
	{
	    if(current->data<ancestor->data)
	    {
		successor=ancestor;
		ancestor=ancestor->left;
	    }
	    else
		ancestor=ancestor->right;
	}
	return successor;
    }
}
int main()
{
    NODE *root=NULL;
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,12);
    /* tree:
       15
       /  \
       10   20
       / \    \
       8   12   25
       */
    printf("minimum element is %d\n",min(root));
    printf("maximum element is %d\n",max(root));
    printf("height of tree is %d\n",height(root));
    int n;
    printf("level ordering:\n");
    levelorder(root);
    printf("\npre ordering:\n");
    preorder(root);
    printf("\nin ordering:\n");
    inorder(root);
    printf("\npost ordering:\n");
    postorder(root);
    if(is_binary_search_tree(root,-1000000,1000000)==true)
	printf("\nbinary search tree\n");
    else
	printf("\nnot a binary search tree\n");
    printf("Enter data of which you want to find successor :");
    int x;
    scanf("%d",&x);
    NODE *successor=getsuccessor(root,x);
    if(successor==NULL)
	printf("No successor found\n");
    else
	printf("Succesor is %d\n",successor->data);
    int num;
    printf("enter number to be deleted from tree :");
    scanf("%d",&num);
    delete(root,num);
    printf("After deleting tree- level ordering:\n");
    levelorder(root);
    printf("\nenter number be searched\n");
    scanf("%d",&n);
    if(search(root,n)==true)
	printf("Found\n");
    else
	printf("Not Found\n");
    return 0;
}
