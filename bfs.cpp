#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000];
queue<int>q;
int level[1000];
bool vis[1000];
void bfs(int a)
{
    q.push(a);
    level[a]=1;
    vis[a]=true;
    while(!q.empty())
    {
	int p=q.front();
	q.pop();
	for(int i=0;i<adj[p].size();i++)
	{
	    if(vis[adj[p][i]]==false)
	    {
		q.push(adj[p][i]);
		level[adj[p][i]]=level[p]+1;
		vis[adj[p][i]]=true;
	    }
	}
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
	int a,b;
	cin>>a>>b;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }
    bfs(1);
    for(int i=1;i<=n;i++)
	cout<<level[i]<<endl;
    return 0;
}
