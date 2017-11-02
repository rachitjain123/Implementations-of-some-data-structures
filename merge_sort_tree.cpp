#include <bits/stdc++.h>
#define  pb push_back
#define  mp make_pair
#define nl "\n"
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
#define maxno 1000002
using namespace std;
int s[maxno];
int id[maxno];
int isprime[maxno];
vector<int>primes;
int cnt[maxno][180];
int pref[180][maxno];
struct megh
{
	vector<int>v;
}seg[5*maxno];
int mid(int i,int j)
{
	return (i+(j-i)/2);
}
void build(int node,int i,int j)
{
	if(i==j)
		seg[node].v.push_back(s[i]);
	else
	{
		build(2*node,i,mid(i,j));
		build(2*node+1,mid(i, j)+1,j);
		merge(seg[2*node].v.begin(),seg[2*node].v.end(),seg[2*node + 1].v.begin(),seg[2*node+1].v.end(),back_inserter(seg[node].v));
	}
}
int query(int node,int i,int j,int l,int r,int val)
{
	if(i>j||i>r||l>j)
		return 0;
	else if(i>=l && j<=r)
		return lower_bound(seg[node].v.begin(),seg[node].v.end(),val)-seg[node].v.begin();
	else
		return(query(2*node,i,mid(i, j),l,r,val)+query(2*node+1,mid(i,j)+1,j,l,r,val));
}
void primecal()
{
	for(int p=2;p*p<=maxno;p++)
	{
		if(isprime[p]==1)
		{
			for(int i=p*2;i<=maxno;i+=p)
				isprime[i]=0;
		}
	}
	for(int i=2;i<=1000;i++)
	{
		if(isprime[i]==1)
		{
			id[i]=primes.size();
			primes.pb(i);
		}
	}
}
int main()
{
	fastScan;
	for(int i=2;i<=maxno;i++)
		isprime[i]=1;
	primecal();
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<primes.size();j++)
		{
			if(primes[j]>s[i])
				break;
			while(s[i]%primes[j]==0)
			{
				cnt[i][j]++;
				s[i]/=primes[j];
			}
		}
	}
	build(1,1,n);
	for(int i=0;i<primes.size();i++)
	{
		for(int j=1;j<=n;j++)
			pref[i][j]=pref[i][j-1]+cnt[j][i];
	}
	int sz=primes.size()-1;
	int af=1009;
	int q;cin>>q;
	while(q--)
	{
		int l,r,x,y,ans=0;
		cin>>l>>r>>x>>y;
		while(isprime[x]!=1)
			x++;
		while(isprime[y]!=1)
			y--;
		if(x>y)
		{
			cout<<ans<<nl;
			continue;
		}
		if(x>primes[sz])
		{
			int n1=query(1,1,n,l,r,x);
			int n2=query(1,1,n,l,r,y+1);
			ans+=n2-n1;
			cout<<ans<<nl;
			continue;
		}
		if(y>primes[sz])
		{
			int n1=query(1,1,n,l,r,af);
			int n2=query(1,1,n,l,r,y+1);
			ans+=n2-n1;
			y=primes[sz];
			if(x>y)
			{
				cout<<ans<<nl;
				continue;
			}
		}
		for(int i=id[x];i<=id[y];i++)
			ans+=pref[i][r]-pref[i][l-1];
		cout<<ans<<nl;
	}
	return 0;
}
