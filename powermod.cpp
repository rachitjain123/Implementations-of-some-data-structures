int powermod(int x,int y,int mod)
{
    int res=1;
    x=x%mod;
    while(y>0)
    {
	if(y%2==1)
	    res=(res*x)%mod;
	y/=2;
	x=(x*x)%mod;
    }
    return res%mod;
}
