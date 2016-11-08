//don_rt
#include<bits/stdc++.h>
 
using namespace std;
long long int dp[5005];
int main()
{
	
	
	while(true)
	{
		memset(dp,0,sizeof(dp));
		string s;
		cin>>s;
		if(s[0]=='0')
		break;
		int l=s.length();
		dp[0]=1;
		long long int val;
		for(int i=1;i<l;i++)
		{
			val=(s[i-1]-'0')*10+(s[i]-'0');
			if(s[i]-'0')
			dp[i]=dp[i-1];
			if(val>=10 && val<=26)
			{
				if(i>=2)
				dp[i]=dp[i]+dp[i-2];
				else
				dp[i]=dp[i]+dp[0];
			}
		}
		printf("%lld\n",dp[l-1]);
	}
} 
