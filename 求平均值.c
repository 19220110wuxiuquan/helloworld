#include<stdio.h>
int main()
{
	int count=0;
	int sum=0;
	int x;

		scanf("%d",&x);
		while(x!=-1)
		{
			sum+=x;
			count++;
			scanf("%d",&x); 
		}
	printf("%f\n",1.0*sum/count);
 	return 0;
 } 
