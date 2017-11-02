#include<bits/stdc++.h>
using namespace std;
int fac[123456];
int power(int x,int y,int p)
{
    int res=1;
    x=x%p;
    while(y>0)
    {
	if(y&1)
	    res=(res*x)%p;
	y=y>>1;
	x=(x*x)%p;
    }
    return res;
}

int modInverse(int n,int p)
{
    return power(n, p-2, p);
}

int nCrModPFermat(int n,int r,int p)
{
    if(r==0)
	return 1;
    return(fac[n]*modInverse(fac[r],p)%p*modInverse(fac[n-r],p)%p)%p;
}
int main()
{
    int n=10,r=2,p=13;
    fac[0]=1;
    for (int i=1;i<=100005;i++)
	fac[i]=fac[i-1]*i%p;
    cout<<"Value of nCr % p is " <<nCrModPFermat(n,r,p);
    return 0;
}
