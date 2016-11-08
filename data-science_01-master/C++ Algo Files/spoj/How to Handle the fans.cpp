#include <bits/stdc++.h>
 
 
using namespace std;
#define lli long long int
 
const lli  N =1000000;
const lli  MAX = 4*N;
 
 
lli tree[MAX];
lli lazy[MAX];
 
 
void update_tree(int node, int a,int b,int i,int j,lli value)
{
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
 
		if(a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(a>b || a>j ||b<i)return;
 
	if(a>=i && b<=j)
	{
		tree[node]+=value;
		if(a!=b)
		{
			lazy[node*2]+=value;
			lazy[node*2+1]+=value;
		}
		return;
	}
 
	update_tree(node*2,a,(a+b)/2,i,j,value);
	update_tree(node*2+1,(a+b)/2+1,b,i,j,value);
 
	tree[node]=tree[node*2]+tree[node*2+1];
 
}
lli query_tree(int node,int a,int b,int i,int j)
{
	if(a>b || a>j ||b<i)return 0;
 
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		if(a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
 
	if(a>=i && b<=j) return tree[node];
 
	lli q1=query_tree(node*2,a,(a+b)/2,i,j);
	lli q2=query_tree(node*2+1,1+(a+b)/2,b,i,j);
 
	lli res=q1+q2;
	return res;
 
}
int main() {
	// your code goes here
 
	int n,q;
	cin>>n>>q;
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
 
	for(int i=0;i<q;i++)
	{
		string s;
		int a,b;
		cin>>s>>a>>b;
		if(s=="find")
		{
			cout<<query_tree(1,0,n-1,a,b)<<endl;
		}
		else
		{
			update_tree(1,0,n-1,a,a,b);
		}
 
	}
	return 0;
} 
