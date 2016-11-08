#include<bits/stdc++.h>
 
using namespace std;
 
int visited[105];
int dist[105];
vector<pair<int,int > >adj[105];
 
 
void dijk(int e,int t,int n)
{
	for(int i=0;i<=n;i++)
	dist[i]=1000000;
	
	priority_queue<pair<int,int> >q;
	q.push(make_pair(e,0));
	dist[e]=0;
	while(!q.empty())
	{
		pair<int,int>p=q.top();
		q.pop();
		for(int i=0;i<adj[p.first].size();i++)
		{
			pair<int,int>k = adj[p.first][i];
			if(dist[p.first]+k.second < dist[k.first])
			{
				dist[k.first]=dist[p.first] + k.second;
				q.push(k);
			}
		}
		
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int n,e,t,m;
	cin>>n>>e>>t;
	cin>>m;
	int a,b,c;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		adj[a].push_back(make_pair(b,c));
	}
	for(int i=1;i<=n;++i)
	{
		dijk(i,e,n);
		if(dist[e]<=t)
		{
			++cnt;
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
