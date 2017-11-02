#include <bits/stdc++.h>
using namespace std;
int sz=0;
int nxt[27][500500];
int ed[500500];
bool found[500500];
string s,tmp;
void insert()
{
	int v=0;
	for(int i=0;i<s.size();i++)
	{
		int c=s[i]-'a';
		if(!found[nxt[c][v]])
		{
			nxt[c][v] = ++sz;
			found[sz] = true;
		}
		v=nxt[c][v];
	}
	++ed[v];
}
bool search()
{
	int v = 0;
	for (int i=0;i<tmp.size();i++) 
	{
		int cc=tmp[i]-'a';
		if (!found[nxt[cc][v]])
			return 0;
		v = nxt[cc][v];
	}
	return ed[v]>0;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		insert();
	}
	for(int i=0;i<q;i++)
	{
		cin>>tmp;
		int ans=search();
		cout<<ans<<endl;
	}
}
// trie
