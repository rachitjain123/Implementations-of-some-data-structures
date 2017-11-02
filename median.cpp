#include<bits/stdc++.h>
using namespace std;
priority_queue<int>maxi;
priority_queue<int, vector<int>, greater<int> >mini;
int s[100000];
void median(int a)
{
    if(maxi.empty() && mini.empty())
    {
	mini.push(a);
	return;
    }
    if(!maxi.empty() && a>maxi.top()||maxi.empty())
    {
	mini.push(a);
	return;
    }
    if(!mini.empty() && a<mini.top()||mini.empty())
    {
	maxi.push(a);
	return;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
	scanf("%d",&s[i]);
	median(s[i]);
	if(maxi.size()>mini.size()+1)
	{
	    mini.push(maxi.top());
	    maxi.pop();
	}
	if(mini.size()>maxi.size()+1)
	{
	    maxi.push(mini.top());
	    mini.pop();
	}
	printf("Median is ");
	if(mini.size()>maxi.size())
	    printf("%d\n",mini.top());
	else if(maxi.size()>mini.size())
	    printf("%d\n",maxi.top());
	else
	{
	    double p=(double)mini.top();
	    double q=(double)maxi.top();
	    printf("%f\n",(p+q)/2);
	}
    }
    return 0;
}
