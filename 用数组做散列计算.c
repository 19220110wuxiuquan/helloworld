#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	const int num=10;//规定数组的大小 
	int count[num];//定义数组 
	int i;
	for(i=0;i<num;i++)
	{
		count[i]=0;
	}//初始化数组 
	while(x!=-1)
	{
		if(x>=0&&x<=9)
		{
			count[x]++;
		}
		scanf("%d",&x);
	}//数组参与运算 
	for(i=0;i<num;i++)
	{
		printf("%d:%d\n",i,count[i]);
	}//遍历数组输出 
	return 0;
 } 
