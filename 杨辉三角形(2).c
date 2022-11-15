#include<stdio.h> 
//法二 采用扫雷初始化的方法，把数组空间行和列各创建大一行，防止越界
int main()
{
	int a[10][10] = { 0 };
	int i = 0;
	int j = 0;
	int n = 0;
	a[0][0] = 1;
	//输入数字
	scanf("%d", &n);
	for (i = 1; i <= n; i++)  //实际使用的数组大小是a[n+1][n+1]，多用到i=0行j=0列，但不打印出来
	{
		for (j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	//打印
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
 
	return 0;
}
