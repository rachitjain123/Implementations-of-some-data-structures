#include <bits/stdc++.h>
#define nl "\n"
#define pb push_back
using namespace std;
vector<int>nos;
vector<vector<int> >res;
vector<int>subset;
void cal_subsets(int index)
{
	for(int i=index;i<nos.size();i++) 
	{
		subset.pb(nos[i]);
		res.pb(subset);
		cal_subsets(i+1);
		subset.pop_back();
	}
	return;
}
int main()
{
	int num;
	cout<<"Enter how many numbers do u wish to find subsets of: ";
	cin>>num;
	cout<<"Enter required nos: "<<nl;
	for(int i=0;i<num;i++)
	{
		int a;cin>>a;
		nos.pb(a);
	}
	cal_subsets(0);
	for(int i=0;i<res.size();i++)
	{
		for (int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}

