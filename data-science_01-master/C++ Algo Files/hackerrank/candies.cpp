#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector<int>vec;
	int arr1[100005]={0},arr2[100005]={0}; 
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		vec.push_back(a);
	}
	arr1[0]=1;
	arr2[n-1]=1;
	for(int i=1;i<n;i++)
	{
		if(vec[i]>vec[i-1])
		arr1[i]=arr1[i-1]+1;
		else
		arr1[i]=1;
	}
	for(int i=n-2;i>-1;i--)
	{
		if(vec[i]>vec[i+1])
		arr2[i]=arr2[i+1]+1;
		else
		arr2[i]=1;
	}
	int sm=0;
	for(int i=0;i<n;i++)
	{
		sm+=max(arr1[i],arr2[i]);
	}
	cout<<sm<<endl;
}
