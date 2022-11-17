#include<stdio.h>
int main()
{
	int ret=1;
	int n;
	scanf("%d",&n);
	int i=n;
	for(;n>1;n--)
	{
		ret*=n;
	}
	printf("%d",ret);
	return 0;
 } 
