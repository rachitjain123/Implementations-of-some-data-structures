#include<bits/stdc++.h>
using namespace std;
pair<int,pair<int,int> >adj[123456];
int size[123456];
int s[123456];
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
int kruskal(int m)
{
    int cost=0,mincost=0;
    for(int i=0;i<m;i++)
    {
	int u=adj[i].second.first;
	int v=adj[i].second.second;
	cost=adj[i].first;
	if(root(u)!=root(v))
	{
	    mincost+=cost;
	    union1(u,v);
	}
    }
    return mincost;
}
int main()
{
    int n,m;
    cin>>n>>m;
    initialise(n);
    for(int i=0;i<m;i++)
    {
	int u,v,wt;
	cin>>u>>v>>wt;
	adj[i]=make_pair(wt,make_pair(u,v));
    }
    sort(adj,adj+m);
    cout<<"Minimum cost is: "<<kruskal(m);
    return 0;
}
