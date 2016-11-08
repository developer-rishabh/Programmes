#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char arr[100005];
		int n;
		cin>>n;
		bool b=false;
		if(n%3==0)
		{
			for(int j=0;j<n;j++)
				{
					arr[j]='5';
				}
				b=true;
		}
		else 
		for(int i=5;i<=n;i=i+5)
		{
			if((n-i)%3==0)
			{   
			    b=true;
				for(int j=0;j<n-i;j++)
				{
					arr[j]='5';
				}
				for(int j=n-i;j<n;j++)
				{
					arr[j]='3';
				}
			}
		}
		if(!b)
		cout<<-1<<endl;
		else
		cout<<arr<<endl;
	}
}
