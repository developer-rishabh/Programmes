#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int dp1[100005];
		int dp2[100005];
		cin>>n;
		int maxc=-1000000009;
		vector<int>vec;
		int a;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			vec.push_back(a);			
		}
		dp1[0]=vec[0];
		if(dp1[0]>maxc)
		maxc=dp1[0];
		if(vec[0]>=0)
		dp2[0]=vec[0];
		else
		dp2[0]=0;
		for(int i=1;i<n;i++)
		{
			dp2[i]=max(dp2[i-1]+vec[i],dp2[i-1]);
			dp1[i]=max(dp1[i-1]+vec[i],vec[i]);
			if(dp1[i] >maxc)
			maxc=dp1[i];
		}
	   cout<<maxc<<" "<<dp2[n-1]<<endl;
	}
}
