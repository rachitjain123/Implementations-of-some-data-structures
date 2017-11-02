#include<bits/stdc++.h>
using namespace std;
int BIT[123456],n;
void update(int x,int delta)
{
    for(;x<=n;x+=x&-x)
        BIT[x]+=delta;
}
int pt_query(int x)
{
    int sum=0;
    for(;x>0;x-=x&-x)
        sum+=BIT[x];
    return sum;
}
void range_update(int l,int r,int val)
{
    update(l,val);
    update(r+1,-val);
}
int main()
{
    n=5;
    range_update(2,4,5);
    cout<<pt_query(4)<<"\n";
}
