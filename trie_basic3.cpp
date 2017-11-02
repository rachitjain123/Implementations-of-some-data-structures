#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3000010;
int tree[N][2],cnt[N][2];
int len=0;
void insert(int n)
{
	int cur=0;
	for(int j=30;j>=0;j--)
	{
		int flag=(((1<<j)&n)>=1);
		if (tree[cur][flag]==0)
			tree[cur][flag]=++len;
		cnt[cur][flag]++;
		cur=tree[cur][flag];

	}
}
void del(int n)
{
	int cur=0;
	for(int j=30;j>=0;j--)
	{
		int flag=(((1<<j)&n)>=1);
		cnt[cur][flag]--;
		cur=tree[cur][flag];
	}
}
int tot(int p,int l)
{
	int cur=0;
	int ans=0;
	for(int j=30;j>=0;j--)
	{
		int flag=((1<<j)&l);
		int t2=(1<<j)&p;
		if (flag)
		{
			if (t2)			
			{  
				ans+=cnt[cur][1];
				cur=tree[cur][0];
			}
			else
			{  
				ans+=cnt[cur][0];
				cur=tree[cur][1];
			}

		}
		else
		{
			if(t2)
				cur=tree[cur][1];
			else
				cur=tree[cur][0];
		}
		if(!cur)
			break;
	}
	return ans;
}
int main()
{
	int i,j,q;
	cin>>q;
	int x,p,l;
	for(i=0;i<q;i++)
	{
		cin>>x>>p;
		if (x==1)
			insert(p);
		else if (x==2)
			del(p);
		else
		{
			cin>>l;
			cout<<tot(p,l)<<"\n";
		}
	}
	return 0;
}