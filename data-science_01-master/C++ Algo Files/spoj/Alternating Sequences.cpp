#include<bits/stdc++.h>
#define lli long long int
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	lli arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	int dp[n];
	for(int i=0;i<n;i++)
	dp[i]=1;
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(abs(arr[i])>abs(arr[j]) && arr[i]*arr[j]<0)
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	int maxall=-1;
	for(int i=0;i<n;i++)
	if(maxall<dp[i])
	maxall=dp[i];
	
    cout<<maxall<<endl;	
} 
