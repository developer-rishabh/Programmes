#include<bits/stdc++.h>

const double g(9.8);

using namespace std;


double height(int t)
{
	return (g*t*t)/2;
}

void result(int t)
{
	cout<<height(t)<<endl;
}

int main()
{
	int h,t;
	cin>>h>>t;
	result(t);
	
}
	
