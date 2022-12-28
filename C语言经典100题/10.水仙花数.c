#include<stdio.h>
int main(int argc,char*argv[])
{
	int x,y,z;//个位，十位，百位
	int i;
	for(i=100;i<=999;i++)
	{
		x=i%10;
		y=i/10%10;
		z=i/100%10;
		if(i==x*x*x+y*y*y+z*z*z)
		{
			printf("%d 是水仙花数\n",i);
		}
	} 
	return 0;
 } 
