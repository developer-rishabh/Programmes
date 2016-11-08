#include<bits/stdc++.h>

using namespace std;

int main()
{
	char c;
	bool make_open=true;
	while(scanf("%c",&c)!=EOF)
	{
		
		if(c=='"')
			{
				if(make_open)
				{
					printf("``");
				}
				else
				{
					printf("''");
				}
				make_open=(!(make_open));
			}
			else
			printf("%c",c);
		
	}
}
