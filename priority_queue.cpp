#include<bits/stdc++.h>
using namespace std;
int s[1000000],n;
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
int extract_maximum()
{
    if(n==0)
    {
	cout<<"Can't remove elemt as queue is empty";
	return;
    }
    int max=s[1];
    s[1]=s[n];
    n--;
    max_heapify(1,n);
}
void increase_value (int Arr[ ], int i, int val)
{
    if(val < Arr[ i ])
    {
	cout<<”New value is less than current value, can’t be inserted” <<endl;
	return;
    }
    Arr[ i ] = val;
    while( i > 1 and Arr[ i/2 ] < Arr[ i ])
    {
	swap|(Arr[ i/2 ], Arr[ i ]);
	i = i/2;
    }
}
void insert_value (int Arr[ ], int val)
{
    length = length + 1;
    Arr[ length ] = -1;
    increase_val (Arr, length, val);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	scanf("%d",&s[i]);
    build_maxheap();
    printf("maximum element is %d\n",s[1]);
    extract_maximum(n);
    printf("maximum element is extracted and new maximum is %d",s[1]);
    return 0;
}
