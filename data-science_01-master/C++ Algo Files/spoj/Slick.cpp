#include<bits/stdc++.h>
using namespace std;
 
int arr[251][251];
int visited[251][251]={0};
int n,m;
 
bool isSafe(int a,int b)
{
	if(a>=0 && b>=0 && a<n && b< m && arr[a][b]==1 && visited[a][b]==0)return true;
	
	return false;
}
int cnter=0;
void dfs(int i,int j)
{ 
	visited[i][j]=1;
	if(isSafe(i-1,j))
	{
		dfs(i-1,j);
		cnter++;
	}
	if(isSafe(i+1,j))
	{
		dfs(i+1,j);
		cnter++;
	}
	if(isSafe(i,j-1))
	{
		dfs(i,j-1);
		cnter++;
	}
	if(isSafe(i,j+1))
	{
		dfs(i,j+1);
		cnter++;
	}
}
int  main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x,size;
	while(true)
	{
		cin>>n>>m;
		if(n==0 && m==0)
		{
			break;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>x;
				arr[i][j]=x;
				visited[i][j]=0;
			}
		}
		map<int ,int >mymap;
		map<int ,int >::iterator it;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cnter=0;
				if(isSafe(i,j))
				{
					dfs(i,j);
					cnter++;
					cnt++;
					if(mymap.find(cnter)!=mymap.end())
					{
						mymap[cnter]++;
					}
					else
					{
						mymap[cnter]=1;
					}
				}
			}
		}
		cout<<cnt<<endl;
		for(it=mymap.begin();it!=mymap.end();++it)	
		{
			cout<<it->first<<" "<<it->second<<endl;
		}	
	
	}
}
 
