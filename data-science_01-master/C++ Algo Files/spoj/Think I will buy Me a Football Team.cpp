#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	int cnt=0;
	while(true)
	{
		cin>>t;
		if(t==0)break;
		cnt++;
		int mat[t][t];
		int smr[t]={0};
		int smc[t]={0};
		int smans[t]={0};
		int sm=0;
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<t;j++)
			{
				cin>>mat[i][j];
				sm+=mat[i][j];
				smr[i]+=mat[i][j];
			}
		}
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<t;j++)
			{
	     		smc[i]+=mat[j][i];
			}
		}
		
		for(int i=0;i<t;i++)
		{
			smans[i]=smr[i]-smc[i];
		}
		int ans=0;
		for(int i=0;i<t;i++)
		{
			if(smans[i]>0)
			ans+=smans[i];
		}
		cout<<cnt<<". "<<sm<<" "<<ans<<endl;
	}
	
} 
