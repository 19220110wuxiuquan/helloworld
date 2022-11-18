#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int sum=0;
	int num[5];
	int cnt=0;
	while(x!=-1)
	{
		num[cnt]=x;
		cnt++;
		sum+=x;
		scanf("%d",&x);
	}
	if(cnt>0)
	{
		printf("%d\n",sum/cnt);
		int i;
		for(i=0;i<cnt;i++)
		{
			if(num[i]>sum/cnt);
			printf("%d\n",num[i]);
		}
	}
	return 0;
 } 
