#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main() 
{
	int r1[100];
	int r2[100];
	int i,x,y;
	srand((unsigned int)time(0));//不能写在for循环内 
	for(i=0;i<10;i++)
	{
		r1[i]=rand()%100;
		printf("%d ",r1[i]);	
		r2[i]=rand()%100;
		printf("%d ",r2[i]);
		printf("\n");
	}
	//生成随机数组 
	for(x=0;x<10;x++)
	{
		for(y=0;y<10;y++)
		{
			if(r1[x]==r2[y])
			{
				printf("有\n");
				printf("在r1中的第%d个，r2中的第%d个",x+1,y+1);
				break;
			}
		}
		if(r1[x]==r2[y])
		{
			break;
		}
	}
	if(x==10)
	{
		printf("没有"); 
	}
	//进行判断 
	return 0;
}
