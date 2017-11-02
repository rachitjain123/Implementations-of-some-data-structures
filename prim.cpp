#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> iPair;
priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
vector<pair<int,int> >::iterator it;
vector<pair<int,int> >adj[3005];
bool vis[3005];
int key[3005];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
	int x,y,r;
	cin>>x>>y>>r;
	key[x]=key[y]=INT_MAX;
	adj[x].push_back(make_pair(y,r));
	adj[y].push_back(make_pair(x,r));
    }
    int src;
    cin>>src;
    pq.push(make_pair(0,src));
    key[src]=0;
    while(!pq.empty())
    {
	int u=pq.top().second;
	pq.pop();
	vis[u]=true;
	for(it=adj[u].begin();it!=adj[u].end();it++)
	{
	    int v=it->first;
	    int weight=it->second;
	    if(vis[v]==false && key[v]>weight)
	    {
		key[v]=weight;
		pq.push(make_pair(key[v],v));
	    }
	}
    }
    int ans=0;
    for(int i=1;i<=n;i++)
	ans+=key[i];
    cout<<ans<<"\n";
    return 0;
}
