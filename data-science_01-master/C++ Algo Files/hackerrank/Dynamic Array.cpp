#include<bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
	lli n,q;
	cin>>n>>q;
	lli last_ans=0;
	vector<lli>seq_list[n];
	for(int i=0;i<q;i++)
	{
		lli a,x,y;
		cin>>a>>x>>y;
		
		if(a==1)
		{
			seq_list[(x^last_ans)%n].push_back(y);
		}
		else
		{
			last_ans= seq_list[(x^last_ans)%n].at(y%seq_list[(x^last_ans)%n].size());
			cout<<last_ans<<endl;
		}
		
	}
	
	//19	29	C:\Users\risha\Documents\C++ Algo Files\hackerrank\Dynamic Array.cpp	[Error] request for member 'push_back' in 'seq_list.std::vector<_Tp, _Alloc>::operator[]<long long int, std::allocator<long long int> >(((std::vector<long long int>::size_type)((x ^ last_ans) % n)))', which is of non-class type 'long long int'
}
