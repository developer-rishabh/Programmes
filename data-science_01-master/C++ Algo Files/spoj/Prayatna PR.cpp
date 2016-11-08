#include<bits/stdc++.h>
 
using namespace std;
 
vector<int>vec[100005];
 
int visited[100005];
 
void dfs(int u)
{
	visited[u]=1;
	for(int i=0;i<vec[u].size();i++)
	{
		if(!visited[vec[u][i]])
		{
			dfs(vec[u][i]);
		}
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			visited[i]=0;
			vec[i].clear();
		}
		int peers;
		cin>>peers;
		for(int i=0;i<peers;i++)
		{
			int a,b;
			cin>>a>>b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		int cnt=0;
		
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
			{
				dfs(i);
				cnt++;
			}
		}
		cout<<cnt<<endl;		
	}
} 
