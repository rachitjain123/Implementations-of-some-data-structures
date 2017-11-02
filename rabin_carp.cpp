#include<bits/stdc++.h>
#define q 100003
#define d 100003
using namespace std;
char pat[100000];
char text[100000];
void search(int len1,int len2)
{
    int h=1,p=0,t=0;
    for(int i=0;i<len1-1;i++)
	h=(h*d)%q;
    for(int i=0;i<len1;i++)
    {
	p=(d*p+pat[i])%q;
	t=(d*t+text[i])%q;
    }
    for(int i=0;i<=len2-len1;i++)
    {
	if(p==t)
	    printf("Pattern found at index: %d \n",i);
	if(i<len2-len1)
	    t=(d*(t-text[i]*h)+text[i+len1]+q)%q;
    }
}
int main()
{
    cout<<"Enter text and pattern :";
    scanf("%s%s",text,pat);
    search(strlen(pat),strlen(text));
    return 0;
}
