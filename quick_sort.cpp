#include<bits/stdc++.h>
using namespace std;
int a[100000];
int partition(int start,int end)
{
    int pivot=a[end];
    int pindex=start;
    for(int i=start;i<end;i++)
    {
	if(a[i]<=pivot)
	{
	    swap(a[i],a[pindex]);
	    pindex++;
	}
    }
    swap(a[pindex],a[end]);
    return pindex;
}
void quicksort(int start,int end)
{
    if(start<end)
    {
	int pindex=partition(start,end);
	quicksort(start,pindex-1);
	quicksort(pindex+1,end);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
    quicksort(0,n-1);
    for(int i=0;i<n;i++)
	printf("%d ",a[i]);
    return 0;
}
