int MAXLOG=20
int par[MAXN][MAXLOG]; // initially all -1
void dfs(int v,int p=-1)
{
    par[v][0]=p;
    if(p+1)
	h[v]=h[p]+1;
    for(int i=1;i<MAXLOG;i++)
    {
	if(par[v][i-1]+1)
	    par[v][i]=par[par[v][i-1]][i-1];
    }
    for(auto u:adj[v])
    {
	if(p-u)
	    dfs(u,v);
    }
}
int LCA(int v,int u)
{
    if(h[v]<h[u])
	swap(v,u);
    for(int i=MAXLOG-1;i>=0;i--)
    {
	if(par[v][i]+1 && h[par[v][i]]>=h[u])
	    v=par[v][i];
    }
    //now h[v]=h[u]
    if(v==u)
	return v;
    for(int i=MAXLOG-1;i>=0;i--)
    {
	if(par[v][i]-par[u][i])
	{
	    v=par[v][i];
	    u=par[u][i];
	}
    }
    return par[v][0];
}
int get(int u,int v)
{
    return h[u]+h[v]-2*h[lca(u,v)];
}
