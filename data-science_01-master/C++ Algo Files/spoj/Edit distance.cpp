#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		
		int n=s1.length();
		
		int m=s2.length();
		
		int dp[n+1][m+1];
		
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(i==0)
				dp[i][j]=j;
				else if(j==0)
				dp[i][j]=i;
				else if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
				else
				dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
			}
		}
		cout<<dp[n][m]<<endl;
	}
	
} 
