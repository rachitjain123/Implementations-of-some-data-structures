node* findlca(node* root, int x,int y)
{
	if(root==NULL)
		return NULL;
	if(root->key==x||root->key==y)
		return root;
	node* left=findlca(root->left,x,y);
	node* right=findlca(root->right,x,y);
	if(left!=NULL && right!=NULL)
		return root;
	if(left==NULL)
		return right;
	return left;
}