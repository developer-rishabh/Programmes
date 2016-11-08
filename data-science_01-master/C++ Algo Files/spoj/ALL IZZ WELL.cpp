#include <bits/stdc++.h>
 
using namespace std;
 
char mat[105][105];
int visited[105][105];
 
string str="ALLIZZWELL";
int n,m;
int flag=0;
 
 
bool issafe(int i,int j)
{
	if(!visited[i][j] && i>=1 && j>=1 && i<=n && j<=m)
	return true;
 
	return false;
}
 
void dfs(int i,int j,int index)
{
    if(flag==1)return ;
	visited[i][j]=true;  
	if(str[index]==mat[i][j])
		{
		    if(index==9)
		    {
		      flag=1;
		      return;
			}
			if(issafe(i+1,j))
			{
				dfs(i+1,j,index+1);
			}
			if(issafe(i-1,j))
			{
				dfs(i-1,j,index+1);
			}
			if(issafe(i,j+1))
			{
				dfs(i,j+1,index+1);
			}
			if(issafe(i,j-1))
			{
				dfs(i,j-1,index+1);
			}
			if(issafe(i+1,j+1))
			{
				dfs(i+1,j+1,index+1);
			}
			if(issafe(i-1,j-1))
			{
				dfs(i-1,j-1,index+1);
			}
			if(issafe(i-1,j+1))
			{
				dfs(i-1,j+1,index+1);
			}
			if(issafe(i+1,j-1))
			{
				dfs(i+1,j-1,index+1);
			}
		}
	visited[i][j]=false;
}
int main()
 {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	 
	  scanf("%d%d",&n,&m);
	  flag=0;
	  for(int i=1;i<=n;i++)
	  {
	    for(int j=1;j<=m;j++)
	    {
	      cin>>mat[i][j];
	      visited[i][j]=0;
	    }
	    
	  }
	  for(int i=1;i<=n;i++)
	  {
	  	for(int j=1;j<=m;j++)
	  	 {
		   if(flag==1)
		   break;  
	  	   if(!visited[i][j] && mat[i][j]=='A')	
	       dfs(i,j,0);
	     }
	       if(flag==1)
	       break;
	  }
	  
	  if(flag)
	  cout<<"YES"<<endl;
	  else
	  cout<<"NO"<<endl;
	}
	return 0;
} 
