#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<int>vec;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			vec.push_back(a);
		}
		int maxi=vec[n-1];
		int sm=0;
		for(int i=n-2;i>=0;i--)
		{
			if(vec[i]>maxi)
			maxi=vec[i];
			else
			sm+=maxi-vec[i];
		}
		cout<<sm<<endl;
	}

}
