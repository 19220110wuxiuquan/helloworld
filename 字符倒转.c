#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int main()
{
	char *str[SIZE]={0};
	int i;
	for(i=0;i<SIZE;i++)
	{
		str[i] = (char*)malloc(sizeof(char)*128);
		scanf("%s",str[i]);
	}
	for(i=0;i<SIZE/2;i++)
	{
		char*t=str[i];
		str[i]=str[SIZE-1-i];
		str[SIZE-1-i]=t;
	}
	for(i=0;i<SIZE;i++)
	{
		printf("%s ",str[i]);
		free(str[i]);
	}
	return 0;
} 
