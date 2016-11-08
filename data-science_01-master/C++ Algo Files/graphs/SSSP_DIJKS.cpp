//don_rt
//Single Source Shortest Path 
//Dijkstra's Algo


#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>


using namespace std;

const int MAX =100001;
const int INF =(1<<20);															//for filling initial weights

#define pii pair<int ,int >
#define mp make_pair
#define pb(x) push_back(x)

struct comp 
{
	bool operator() (const pii &a, const pii &b)
	{																			// to define the type of priority queue	 #compairator 
		return a.second > b.second;												//top always contains smallest weight edge		
	}
};

priority_queue<pii,vector <pii> ,comp> Q;
vector<pii> graph[MAX];
int dis[MAX];																	//distance from source vertex

bool visited[MAX];																//zero for open node, one for closed node	

int main()
{
	int u,v,w,sor,edges,nodes;
	cin>>nodes>>edges;															//graph elements
	
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v>>w;
		graph[u].pb(mp(v,w));
		graph[v].pb(mp(u,w));													//can be ommited in case of directed graph
	
	}					
	
	cin>>sor;																	//source vertex	
	
	for(int i=1;i<=nodes;i++)
		dis[i]=INF;																//initialise with INF weight so that  every node behaves as an open node	
		
	dis[sor]=0;																	//trivial case shotest distance with itself is zero
	
	Q.push(mp(sor,0));
	
	int siz;
	
	while(!Q.empty())
	{
		u=Q.top().first;
		Q.pop();
		
		if(visited[u])
		continue;
		
		siz=graph[u].size();
		for(int i=0;i<siz;i++)
		{
			v=graph[u][i].first;
			w=graph[u][i].second;
			
			if(!visited[v] && dis[u]+w < dis[v])										//greedy approach		
			{
				dis[v]=dis[u]+w;
				Q.push(pii(v,dis[v]));												//push the updated v node to queue			
			}
		}
		visited[u]=1;																// u node compeleted	
	}
	
	for(int i=1;i<=nodes;i++)
	cout<<"Node "<<i <<" shortest distance "<<dis[i]<<endl;							//showing result		
}


