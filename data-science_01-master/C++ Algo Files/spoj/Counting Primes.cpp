//yo
 
#include <bits/stdc++.h>
 
using namespace std;
 
bool prime[1000009];
 
const int N=10001;
const int MAX=5*N;
 
int arr[N];
int tree[MAX];
int lazy[MAX];
 
void run_seive()
{
 
	memset(prime,true,sizeof(prime));
	prime[0]=0;
	prime[1]=0;
 
	for(int i=2;i<sqrt(1000001);i+=1)
	{
		if(prime[i])
		{
 
			for(int j=i*2;j<1000000;j+=i)
			prime[j]=0;
		}
	}
 
}
 
void build_tree(int node,int a, int b)
{
 
	if(a>b)return ;
	if(a==b)
	{
		if(prime[arr[a]])
		tree[node]=1;
		else 
		tree[node]=0;
		return;
	}
	build_tree(node*2,a,(a+b)/2);
	build_tree(node*2+1,1+(a+b)/2,b);
 
	tree[node]=tree[node*2]+tree[node*2+1];
 
}
 
void update_tree(int node,int a,int b,int i,int j,int v)
{
	if(lazy[node]!=0)
	{
		if(prime[lazy[node]]==1)
		tree[node]=b-a+1;
		else
		tree[node]=0;
 
		if(a!=b)
		{
			lazy[node*2]=lazy[node];
			lazy[node*2+1]=lazy[node];
		}
		lazy[node]=0;
	}
 
	if(a>b || a>j ||b<i)return;
 
	if(a>=i && b<=j)
	{
		if(prime[v])
		tree[node]=b-a+1;
		else
		tree[node]=0;
 
		if(a!=b)
		{
 
				lazy[node*2]=v;
				lazy[node*2+1]=v;
 
		}
		lazy[node]=0;
		return;
	}
 
	update_tree(node*2,a,(a+b)/2,i,j,v);
	update_tree(1+node*2,1+(a+b)/2,b,i,j,v);
 
	tree[node]=tree[node*2]+tree[node*2+1];
}
int query_tree(int node,int a,int b,int i,int j)
{
 
 
	if(lazy[node]!=0)
	{
		if(prime[lazy[node]]==1)
		tree[node]=b-a+1;
		else
		tree[node]=0;
 
		if(a!=b)
		{
			lazy[node*2]=lazy[node];
			lazy[node*2+1]=lazy[node];
		}
		lazy[node]=0;
	}
	if(a>b || a>j || b<i)return 0;
 
	if(a>=i && b<=j)return tree[node];
 
	int q1=query_tree(node*2,a,(a+b)/2,i,j);
	int q2=query_tree(node*2+1,1+(a+b)/2,b,i,j);
 
	int res=q1+q2;
 
	return res;
 
}
 
int main() {
 
 
	int t,n,q;
	scanf("%d",&t);
	run_seive();
	int k=1;
	while(t--)
	{
 
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
		printf("Case %d:\n",k++);
		scanf("%d%d",&n,&q);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
 
		}
 
		build_tree(1,0,n-1);
 
		for(int i=0;i<q;i++)
		{
			int a1,a2,a3,a4;
			scanf("%d",&a1);
 
			if(a1==0)
			{
				scanf("%d%d%d",&a2,&a3,&a4);
				update_tree(1,0,n-1,a2-1,a3-1,a4);
			}
			else
			{
				scanf("%d%d",&a2,&a3);
				int x=query_tree(1,0,n-1,a2-1,a3-1);
 
				printf("%d\n",x);
			}
		}
	}
 
 
	return 0;
}
 
