//题目描述：有1，2，3，4，四个数，问能组成多少个互不相同的且无重复数字的三位数，都是多少？
#include<stdio.h>
int main() 
{
	int g=0,s=0,b=0;
	int count=0;
	for(b=1;b<5;b++)
	{
		for(s=1;s<5;s++)
		{
			for(g=1;g<5;g++)
			{
				if(g!=s&&g!=b&&b!=s)
				{
					printf("%d%d%d\n",b,s,g);
					count++;
				}
			}
		}
	} 
	printf("count=%d",count);
	return 0;
}
