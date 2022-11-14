#include<stdio.h>
int main()
{
	int i;
	int ret=1;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		ret=i*ret;
	}
	printf("%d",ret);
	return 0;
 } 
