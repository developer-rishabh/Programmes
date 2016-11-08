#include<cstdio>

int main()
{
	int t;
	int a[200];
	int n,i,j,temp,m,x;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		a[0]=1;  //array intialiser
		m=1;     //digit counter
		temp=0   //carry over
		for(i=1;i<=n;i++)
		{
			for(j=0;j<m;j++)
			{
				x=a[j]*i+temp //multiplication
				a[j]=x%10;    //digit at place
 				temp=x/10;    //carry over
			}
			while(temp>0)
			{
				a[m]=temp%10;
				temp=temp/10;
				m++;
			}
		}
		for(i=m-1;i>=0;i--)
			print("%d",a[i]);
			printf("\n");
	}
	return 0;
}
