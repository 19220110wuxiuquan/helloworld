#include<stdio.h>
#define SIZE 10
int sump(int*start,int*end)
{
	int total=0;
	while(start<end)
	{
		total+=*start;
		start++;
	}
	return total;
 } 
 int main()
 {
 	int a[SIZE];
 	int i;
 	for(i=0;i<SIZE;i++)
 	{
 		scanf("%d",&a[i]);
	}
	long answer;
	answer=sump(a,a+SIZE);
	printf("%ld",answer);
	return 0;
 }
