#include<bits/stdc++.h>

using namespace std;

int main()
{
	int arr[6][6]={0};
	for(int i=0;i<6;i++)
	for(int j=0;j<6;j++)
	{
		scanf("%d",&arr[i][j]);
	}
	int maxi=-90000;
	for(int i=1;i<5;i++)
	for(int j=1;j<5;j++)
	{
		int sm=0;
		sm=arr[i][j]+arr[i+1][j+1] +arr[i-1][j-1]+ arr[i+1][j-1]+ arr[i-1][j]+ arr[i-1][j+1]+ arr[i+1][j];
		if (sm>maxi)
		   maxi=sm;
	}
	cout<<maxi<<endl;
	
}
