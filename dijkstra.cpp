#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
vector<pair<int,int> >::iterator it;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vector<pair<int,int> >adj[3005];
		bool visited[3005];
		int n,m;
		scanf("%d%d",&n,&m);
		int dist[4000];
		for(int i=0;i<m;i++)
		{
			int x,y,r;
			scanf("%d%d%d",&x,&y,&r);
			visited[x]=false;
			visited[y]=false;
			dist[x]=INT_MAX;
			dist[y]=INT_MAX;
			adj[x].push_back(make_pair(y,r));
			adj[y].push_back(make_pair(x,r));
		}
		int src;
		scanf("%d",&src);
		priority_queue<iPair,vector<iPair>,greater<iPair> >pq;
		pq.push(make_pair(0,src));
		dist[src]=0;
		while(!pq.empty())
		{
			int u=pq.top().second;
			pq.pop();
			if(!visited[u])
			{
				for(it=adj[u].begin();it!=adj[u].end();it++)
				{
					int v=it->first;
					int weight=it->second;
					if(dist[v]>dist[u]+weight)
					{
						dist[v]=dist[u]+weight;
						pq.push(make_pair(dist[v],v));
					}
				}
			}
			visited[u]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=src)
			{
				if(dist[i]==INT_MAX)
					printf("-1 ");
				else
					printf("%d ",dist[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
