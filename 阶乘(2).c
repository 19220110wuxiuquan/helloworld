#include<stdio.h>
int main()
{
	int i=1;
	int ret=1;
	int n;
	scanf("%d",&n);
	for(i=n;i>1;i--)
	{
		ret=i*ret;
	}
	printf("%d",ret);
	return 0;
 } 
