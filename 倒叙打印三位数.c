#include<stdio.h>
int main()
{
	int i;
	scanf("%d",&i);
	printf("%d\n",i%10*100+i/100+(i-i%10-i/100*100));
	return 0;
 } 
