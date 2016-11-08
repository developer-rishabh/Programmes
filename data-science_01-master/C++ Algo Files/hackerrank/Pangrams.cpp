#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	bool ans=true;
	bool map_alpha[26];
	getline(cin,s);                    //careful of space dilimiter
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=65 && s[i]<=90)
		map_alpha[s[i]-'A']=true;
		else if(s[i]>=97 && s[i]<=122)
		map_alpha[s[i]-'a']=true;
	}
	for(int i=0;i<26;i++)
	{
		if(!map_alpha[i])
		ans=false;
	}
	if(ans)
	cout<<"pangram"<<endl;
	else
	cout<<"not pangram"<<endl;
}


