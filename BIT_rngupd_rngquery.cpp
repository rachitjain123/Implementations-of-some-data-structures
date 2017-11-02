#include<bits/stdc++.h>
using namespace std;
int n;
int BIT1[123456];
int BIT2[123456];
int sum1(int x)
{
    int sum=0;
    for(;x>0;x-=x&-x)
        sum+=BIT1[x];
    return sum;
}
int sum2(int x)
{
    int sum=0;
    for(;x>0;x-=x&-x)
        sum+=BIT2[x];
    return sum;
}
void update1(int x,int delta)
{
    for(;x<=n;x+=x&-x)
        BIT1[x]+=delta;
}
void update2(int x,int delta)
{
    for(;x<=n;x+=x&-x)
        BIT2[x]+=delta;
}
int sum(int x)
{
    return (sum1(x)*x-sum2(x));
}
void range_update(int l,int r,int val)
{
    update1(l,val);
    update1(r+1,-val);
 
    update2(l,val*(l-1));
    update2(r+1,-val*r);
}
 
int range_sum(int l,int r)
{
    return sum(r)-sum(l-1);
}
int main()
{
    n=5;
    int l=1,r=4,val=10;
    range_update(l,r,val);
    cout<<range_sum(l,r)<<"\n";
    return 0;
}
