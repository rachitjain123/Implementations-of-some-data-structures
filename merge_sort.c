#include<stdio.h>
int arr[1000000];
int s[1000000];
void merge(int start,int mid,int end)
{
    int i,p=start,q=mid+1,r=0;
    while(p<=mid||q<=end)
    {
	if(p>mid)
	    s[r++]=arr[q++];
	else if(q>end)
	    s[r++]=arr[p++];
	else if(arr[p]<arr[q])
	    s[r++]=arr[p++];
	else if(arr[p]>=arr[q])
	    s[r++]=arr[q++];
    }
    for(i=start;i<=end;i++)
	arr[i]=s[i-start];
}
void merge_sort(int start,int end)
{
    if(end<=start)
	return;
    int mid=(start+end)/2;
    merge_sort(start,mid);
    merge_sort(mid+1,end);
    merge(start,mid,end);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
    merge_sort(0,n-1);
    for(i=0;i<n;i++)
	printf("%d ",arr[i]);
    return 0;
}
