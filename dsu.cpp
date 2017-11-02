#include<bits/stdc++.h>
using namespace std;
int s[100000];
int size[100000];
void initialise(int n)
{
    for(int i=0;i<n;i++)
    {
	s[i]=i;
	size[i]=1;
    }
}
int root(int i)
{
    while(s[i]!=i)
    {
	s[i]=s[s[i]];
	i=s[i];
    }
    return i;
}
void union1(int a,int b)
{
    int root_a=root(a);
    int root_b=root(b);
    if(size[root_a]<size[root_b])
    {
	s[root_a]=s[root_b];
	size[root_b]+=size[root_a];
    }
    else
    {
	s[root_b]=s[root_a];
	size[root_a]+=size[root_b];
    }
}
bool find(int a,int b)
{
    if(root(a)==root(b))
	return true;
    else
	return false;
}
int main()
{
    return 0;
}
