#include <bits/stdc++.h>
using namespace std;
int BIT[1000],arr[1000],n;
void update(int x,int delta)
{
    for(;x<=n;x+=x&-x)
	BIT[x]+=delta;
}
int query(int x)
{
    int sum=0;
    for(;x>0;x-=x&-x)
	sum+=BIT[x];
    return sum;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
	cin>>arr[i];
	update(i,arr[i]);
    }
    update(n,-arr[n]);
    cout<<query(5)-query(2)<<endl;
    return 0;
}
