#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	struct node* child[26];
	node(){for(int i=0;i<26;i++)child[i]=NULL;};
}node;
vector<string>bad;
set<string>ans;
node GoodsitesTrie;
void add(string str)
{
	node *temp=&GoodsitesTrie;
	for(int i=0;i<str.length();i++)
	{
		int ix=str[i]-'a';
		if(temp->child[ix]==NULL)
		{
			temp->child[ix]=new node();
			temp=temp->child[ix];
		}
		else
			temp=temp->child[ix];
	}
}
string solve(string str)
{
	node *temp=&GoodsitesTrie;
	string sol="";
	for(int i=0;i<str.length();i++)
	{
		int ix=str[i]-'a';
		sol+=str[i];
		if(temp->child[ix]!=NULL)
			temp=temp->child[ix];
		else
			return sol;
	}
	return sol;
}
bool check(string badstr)
{
	int i;
	node *temp=&GoodsitesTrie;
	for(i=0;i<badstr.length();i++)
	{
		int ix=badstr[i]-'a';
		if(temp->child[ix]!=NULL)
			temp=temp->child[ix];
		else
			break;
	}
	if(i==badstr.length())
		return false;
	return true;
}
int main()
{
	int n;char c;string str;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c>>str;
		if(c=='-')
			bad.push_back(str);
		else
			add(str);
	}
	for(int i=0;i<bad.size();i++)
	{
		if(!check(bad[i]))
		{
			cout<<"-1\n";
			return 0;
		}
	}
	for(int i=0;i<bad.size();i++)
		ans.insert(solve(bad[i]));
	cout<<ans.size()<<endl;
	for(auto x:ans)
		cout<<x<<endl;
	return 0;
}