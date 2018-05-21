#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    set<int>st;
    for(int i=0;i<n;i++)
    {
	int a;cin>>a;
	st.insert(a);
	auto it=st.find(a);
	it++;
	if(it!=st.end())
	    st.erase(it);
    }
    cout<<st.size()<<"\n";
    return 0;
}
