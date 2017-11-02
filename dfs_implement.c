node* Insert(node *head,int val)
{
    node* temp;
    temp=(node*)malloc(sizeof(node*));
    temp->val=val;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    temp->next=head;
    return temp;
}

void dfs(node* temp, int i)
{
    b[i]=1;
    while(temp!=NULL)
    {
        int x=temp->val;
        if(b[x]==0)
            dfs(a[x],x);
        temp=temp->next;
    }
    printf("%d ",i);
    return;
}
