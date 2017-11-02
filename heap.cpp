#include<bits/stdc++.h>
using namespace std;
int s[1000000];
void max_heapify(int i,int n)
{
    int left=2*i,largest;
    int right=2*i+1;
    if(left<=n && s[left]>s[i])
	largest=left;
    else
	largest=i;
    if(right<=n && s[right]>s[largest])
	largest=right;
    if(largest!=i)
    {
	swap(s[i],s[largest]);
	max_heapify(largest,n);
    }
}
void build_maxheap(int n)
{
    for(int i=n/2;i>=1;i--)
	max_heapify(i,n);
}
void heap_sort(int n)
{
    int heap_size=n;
    build_maxheap(n);
    for(int i=n;i>=2;i--)
    {
	swap(s[1],s[i]);
	heap_size=heap_size-1;
	max_heapify(1,heap_size);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	scanf("%d",&s[i]);
    heap_sort(n);
    for(int i=1;i<=n;i++)
	printf("%d ",s[i]);
    return 0;
}
