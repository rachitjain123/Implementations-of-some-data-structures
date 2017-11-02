#include <bits/stdc++.h>
using namespace std;
vector<int>adj[100];
stack<int>s;
bool vis[200];
void dfs(int src)
{
    vis[src]=true;
    for(int i=0;i<adj[src].size();i++)
    {
	if(!vis[adj[src][i]])
	    dfs(adj[src][i]);
    }
    s.push(src);
}
int main()
{
    int n,m,p,q;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
	cin>>p>>q;
	adj[p].push_back(q);
    }
    for(int i=0;i<n;i++)
	if(!vis[i])		
	    dfs(i);
    while(!s.empty())
    {
	cout<<s.top()<<" ";
	s.pop();
    }
    return 0;
}
