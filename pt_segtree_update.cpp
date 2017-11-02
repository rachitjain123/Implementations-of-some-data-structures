#include<bits/stdc++.h>
using namespace std;
int arr[20];
int tree[50];
void build_tree(int node,int a,int b)
{
    if(a>b)
	return;
    if(a==b)
    {
	tree[node]=arr[a];
	return;
    }
    build_tree(node*2,a,(a+b)/2);
    build_tree(node*2+1,(a+b)/2+1,b);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
void update_tree(int node,int a,int b,int i,int value)
{
    if(a==b)
    {
	tree[node]+=value;
	return;
    }
    int mid=(a+b)/2;
    if(a<=i && i<=mid)
    	update_tree(node*2,a,mid,i,value);
    else
    	update_tree(node*2+1,mid+1,b,i,value);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
int query_tree(int node,int a,int b,int i,int j)
{
    if(a>b||a>j||b<i)
	return -INT_MAX;
    if(a>=i && b<=j)
	return tree[node];
    int q1=query_tree(node*2,a,(a+b)/2,i,j);
    int q2=query_tree(node*2+1,1+(a+b)/2,b,i,j);
    int res=max(q1,q2);
    return res;
}
int main()
{
    for(int i=0;i<20;i++)
	arr[i]=i;
    int n=20;
    build_tree(1,0,n-1);
    cout<<query_tree(1,0,n-1,0,10)<<"\n";
    return 0;
}
