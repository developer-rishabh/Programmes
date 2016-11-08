#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int id[10005];
 
void initialise(int n)
{
	for(int i=1;i<=n;i++)
	{
		id[i]=i;
	}
}
int root(int a)
{
	while(id[a]!=a)
	{
		id[a]=id[id[a]];
		a=id[a];
	}
	return a;
}
void union_set(int a,int b)
{
	int c=root(a);
	int d=root(b);
	id[c]=id[d];
}
 
 
int main()
{
	bool flag=true;
	
	int a,b;
	cin>>a>>b;
	initialise(a);
	for(int i=0;i<b;i++)
	{
		int c,d;
		cin>>c>>d;
		if(root(c)!=root(d))
		{
			union_set(c,d);
		}
		else
		{
			flag=false;
		}
	}
	if(flag)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
} 
