#include<bits/stdc++.h>
 
using namespace std;
 
int n,m;
int minerals[2][503][503];
int dp[503][503];
 
void solve()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int temp1=minerals[0][i][j];
			int temp2=minerals[1][i][j];
			
			if(j>0)temp1+=dp[i][j-1];
			if(i>0)temp2+=dp[i-1][j];
			
			dp[i][j]=max(temp1,temp2);
		}
	}
	cout<<dp[n-1][m-1]<<endl;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
 
	while(1)
	{
      cin>>n>>m;
      if(n==0 && m==0)
      break;
     
      for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
        cin>>minerals[1][i][j];
        if(j>0)minerals[1][i][j]+=minerals[1][i][j-1];
  	  }
   	  for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
        cin>>minerals[0][i][j];
        if(i>0) minerals[0][i][j]+=minerals[0][i-1][j];
  	  }
      solve();
    }
 	return 0;
} 
