#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	vector<int>vec;
	
	cin>>n>>m;

	int t=m;
	for(int i=0;i<m;i++)
	{
		int c;
		cin>>c;
		vec.push_back(c);
	}
	int dp[255]={0};
	dp[0]=1;
	for(int i=0;i<m;i++)
	for(int j=vec[i];j<=n;j++)
	{
		dp[j]+=dp[j-vec[i]];
	}
	cout<<dp[n]<<endl;
	
}
