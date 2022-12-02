#include<stdio.h>
#define PI 3.14159
int main()
{
	int h,r;
	scanf("%d %d",&h,&r);
	double t;
	t=(PI*r*r*h)/1000;
	int ret;
	ret=20/t+1;
	printf("%d",ret);
	return 0;
 } 
