//题目：打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方
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
