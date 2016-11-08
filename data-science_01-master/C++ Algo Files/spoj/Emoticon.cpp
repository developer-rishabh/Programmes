#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
	
		int count_e=0,count_k=0,ans=0;	
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='K')
			{
			   ans+=count_e;;
			   count_k++;
			}
			else if(s[i]=='E')
			{
				count_e+=count_k;
			}
			
		}
		printf("%d\n",ans);
	}
	return 0;
} 
