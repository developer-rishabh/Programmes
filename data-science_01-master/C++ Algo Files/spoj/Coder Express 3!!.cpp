#include<bits/stdc++.h>
#define lli long long int
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	
		int n;
		cin>>n;
		lli arr[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];
	
		int dp[n],dp1[n];
		for(int i=0;i<n;i++)
		dp[i]=dp1[i]=1;
	
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(arr[i]>arr[j])
				{
				dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		for(int i=n-2;i>=0;i--)
		{
			for(int j=n-1;j>i;j--)
			{
				if(arr[i]>arr[j])
				{
				dp1[i]=max(dp1[i],dp1[j]+1);
				}
			}
		}
			
 
		int maxall=dp1[0]+dp[0]-1;
	
		for(int i=0;i<n;i++)
		if(maxall<dp[i]+dp1[i]-1)
		maxall=dp[i]+dp1[i]-1;
	
    	cout<<maxall<<endl;
	}
	return 0;
} 
