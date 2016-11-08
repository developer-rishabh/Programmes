#include<bits/stdc++.h>
#define S(a)  scanf("%d",&a)
#define lli long long int

using namespace std;

int main()
{
	long long int a,b;
	
        
	while(scanf ("%lld %lld", &a, &b) != EOF)
	{
		lli maxi=0;
		lli temp_a=a,temp_b=b;
		if(a>b){lli temp=b;b=a;a=temp;}

		for (lli i=a;i<=b;i++)
		{
			lli j=i;
			lli cnt=1;
			while(j!=1)
			{
				if(j&1)
				{
					j=3*j+1;
				}
				else
				j=j/2;
			        cnt++;
			}
			if(cnt>maxi)
			maxi=cnt;
		}
               printf("%lld %lld %lld\n",temp_a,temp_b,maxi);
	}
	
	
}
