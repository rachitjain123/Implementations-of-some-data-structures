#include <bits/stdc++.h>
#define  pb push_back
#define  mp make_pair
#define nl "\n"
#define int long long int
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
#define mod (int)(1e9+7)
#define MAX (int)5000001
using namespace std;
int lp[MAX];
void sieve()
{
	for(int i=2;i<=MAX;i++)
	{
		if(lp[i]==0)
		{
			lp[i]=i;
			for(int j=2*i;j<=MAX;j+=i)
			{
				if(lp[j]==0)
					lp[j]=i;
			}
		}
	}
}
int main()
{
	fastScan;
	sieve();
}
