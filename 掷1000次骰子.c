#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 7 
int main()
{
	int value;
	int count;
	int freq[SIZE]={0};
	int max;
	for(count=0;count<1000;count++)
	{
		value=rand()%6+1;
		++freq[value];
	}
	printf("%s%15s\n","Value","Frequency");
	for(value=1;value<SIZE;value++)
	{
		printf("%d%15d\n",value,freq[value]);
	}
	return 0;
 } 
