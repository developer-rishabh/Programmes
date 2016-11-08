#include<bits/stdc++.h>
 
 
 
using namespace std;
 
 
int main()
{
 
	float dp[555][3600];
 
	dp[0][0]=0;
 
	for(int i=0;i<555;i++)
	dp[i][0]=0;
	
	for(int i=2;i<555;i++)
	dp[i][1]=0;
	
	for(int i=1;i<=6;i++)
	dp[1][i]=1/6.0;
	
	for(int i=7;i<3600;i++)
	dp[1][i]=0;
		
	for(int i=2;i<555;i++)
	{
		for(int j=2;j<3600;j++)
		{
			
			dp[i][j]=0;
			for(int k=1;k<=6;k++)
			{
				if(j-k>=0)
				dp[i][j]=dp[i][j] + dp[i-1][j-k];
			}
			dp[i][j]=dp[i][j]/6.0;
			
		}
	}
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		if(n>550 || k >3300 )
		{
	        cout<<0<<endl;
	        continue;
	    }
		int ans=100*dp[n][k];
		cout<<ans<<endl;
	}
	return 0;
} 
