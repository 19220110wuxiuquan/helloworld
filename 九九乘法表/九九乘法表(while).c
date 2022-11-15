#include<stdio.h>
int main()
{
	int i = 1; int j = 1;
	while(i <= 9)
	{
		j = 1;
		while (j <= i)
		{
			printf("%d*%d=%d" , i, j, i * j);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
	return 0;
}
