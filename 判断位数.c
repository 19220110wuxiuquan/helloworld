#include<stdio.h>
int main()
{
	int i;
	int n=0;
	scanf("%d",&i);
	while(i>0)
	{
		i/=10;
		n++;
	}
	printf("%d",n);
	return 0;
}
