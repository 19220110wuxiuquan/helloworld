#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int i;
	int num;
	num=0;
	for(i=a;i<=b;i++)
	{
		if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))//判断闰年的条件为:该年份能被 4 整除同时不能被 100 整除；该年份能被400整除。
		num++;
	}
	printf("%d",num);
	return 0;
 } 
