#include<stdio.h>
int fibonacci(int n)
{
  if(n<=0)
    {
        return 0;
    }
	if(n==1 || n==2)
	{
		return 1;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}
 
int main(void)
{
	int n = 0,total=0;;
	int i = 1;
	int ret = 0;
	printf("输入要求的斐波拉契数列项数：");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		ret = fibonacci(i);
		total = total + ret;//计算前n项和
		printf("%d\n",ret);//打印前n项每个数
	}
	printf("第%d项 = %d\n",n,ret);
	printf("前%d项和 = %d\n",n,total);	
	return 0;
}
