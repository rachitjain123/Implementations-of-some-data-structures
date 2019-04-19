void permute(int l,int r)
{
    if(l==r)
    {
	// do something
	return;
    }
    for(int i=l;i<=r;i++)
    {
	swap(v[i],v[l]);
	permute(l+1,r);
	swap(v[i],v[l]);
    }
}
