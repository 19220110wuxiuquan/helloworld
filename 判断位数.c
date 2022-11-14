#include<stdio.h>
int main()
{
	int i;
	int n=0;
	scanf("%d",&i);
	do{
		n++;
		i/=10;
	   }
	while(i>0);
	printf("%d",n);
	return 0;
}
