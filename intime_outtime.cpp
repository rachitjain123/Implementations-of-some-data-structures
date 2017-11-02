#include <bits/stdc++.h>
using namespace std;
struct node
{
	int in_time;
	int out_time;
};
int time1=0;
node nd[123456];
bool vis[123456];
vector<int>adj[123456];
void dfs(int s)
{
	nd[s].in_time=time1++;
	vis[s]=true;
	for(int i=0;i<adj[s].size();i++)
	{
		if(!vis[adj[s][i]])
			dfs(adj[s][i]);
	}
	nd[s].out_time=time1++;
}
int main()
{
	int q,n,m;
	cin>>q>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		cout<<nd[i].in_time<<" "<<nd[i].out_time<<endl;
	for(int i=0;i<q;i++)
	{
		int u,v,x,y;
		scanf("%d%d%d%d",&u,&v,&x,&y);
		if(nd[u].in_time<nd[x].in_time && nd[u].out_time>nd[x].out_time)
		{
			if(nd[u].in_time<nd[y].in_time && nd[u].out_time>nd[y].out_time)
				cout<<"YES"<<"\n";
		}
		else if(nd[v].in_time<nd[x].in_time && nd[v].out_time>nd[x].out_time)
		{
			if(nd[v].in_time<nd[y].in_time && nd[v].out_time>nd[y].out_time)
				cout<<"YES"<<"\n";
		}
		else
			cout<<"NO"<<"\n";
	}
	return 0;
}