#include<stdio.h>

int A[10000009];

int upper_bound(int low, int high, int n,int last)
{
	int ans = last;
	while(low <= high)
	{
		int mid = (low + high) >> 1;
		if(A[mid] > a)
			ans = mid, high = mid-1;
		else
			low = mid + 1;
	}
	return ans+1;
}
