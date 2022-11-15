#include<stdio.h>
//法一  观察初始化
int main()
{
	int i = 0;
	int j = 0;
	int n = 0;
	scanf("%d", &n);
	int a[10][10] = { 0 };
    //存放元素
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j == 0 || i == j)  //第一列和i==j时直接赋值为1
			{
				a[i][j] = 1; 
			}
			if (i >= 2 && j >= 1)
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}
    //打印
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <=i; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
