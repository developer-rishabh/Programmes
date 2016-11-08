#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string s;
	int n;
	cin>>n;
	while(n!=0)
	{
		int i;
		getchar();
		getline(cin,s);
		int k=s.length();
		set<char>set_CH;
		map<char,int>CH_map;
		for (i=0;i<k && i<n;i++)
		{
			if(!CH_map[s[i]])
			{
				CH_map[s[i]]=1;
				set_CH.insert(s[i]);
			}
			else
			{
				CH_map[s[i]]++;
			}
		}
		int u=0,d=i-u;
		while(i<k)
		{
			set_CH.insert(s[i]);
			CH_map[s[i]]++;
			
			if(set_CH.size()>n)
			{
				while(CH_map[s[u]]>1)
				CH_map[s[u++]]--;
				
				CH_map[s[u]]=0;
				set_CH.erase(s[u++]);
			}
			i++;
			d=max(d,i-u);
		}
		
		cout<<d<<endl;
		cin>>n;
	}
	return 0;
} 
