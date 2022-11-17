#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	double sum=0.0;
	for(i=1;i<=n;i++)
	{
	     sum+=1.0/i;
	}
	printf("f(%d)=%f\n",n,sum);
	return 0;	
}
