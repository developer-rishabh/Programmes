#include <bits/stdc++.h>
 
#define S(a) scanf("%d",&a)
 
using namespace std;
 
int remrev(int a)
{
	int b=0;
	while(a%10==0 && a!=0)
	a=a/10;
	while(a)
	{
		int k=a%10;
		b=b*10+k;
		a=a/10;
	}
	return b;
}
 
int main() {
 
	int t;
	S(t);
	while(t--)
	{
		int a,b;
		S(a),S(b);
		int reva,revb,revans;
 
		reva=remrev(a);
		revb=remrev(b);
		revans=reva+revb;
		revans=remrev(revans);
		printf("%d\n",revans);
 
 
	}
 
	return 0;
} 
