#include <bits/stdc++.h>
#define  pb push_back
#define  mp make_pair
#define nl "\n"
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
vector<int>adj[234567];
int indeg[234567];
int perm[234567];
int main()
{
	fastScan;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[b].pb(a);
	}
	for(int i=1;i<=n;i++)
	{
		for(auto x:adj[i])
			indeg[x]++;
	}
	priority_queue<int>pq;
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]==0)
			pq.push(i);
	}
	int tmp=n;
	while(!pq.empty())
	{
		int u=pq.top();
		pq.pop();
		perm[u]=tmp--;
		for(auto x:adj[u])
		{
			if(--indeg[x]==0)
				pq.push(x);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<perm[i]<<" ";
	cout<<nl;
}
