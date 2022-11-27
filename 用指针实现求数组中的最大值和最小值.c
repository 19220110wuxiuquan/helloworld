#include<stdio.h>
#define SIZE 5
void minmax(int a[],int len,int*max,int*min)
{
	int i;
	*min=*max=a[0];
	for(i=1;i<len;i++)
	{
		if(a[i]<*min)
		{
			*min=a[i];
		}
		if(a[i]>*max)
		{
			*max=a[i];
		}
	}
}
int main()
{
	int a[SIZE];
	int min,max;
	int i;
	for(i=0;i<SIZE;i++)
	{
		scanf("%d",&a[i]);
	}
	minmax(a,sizeof(a)/sizeof(a[0]),&max,&min);
	printf("max=%d min=%d\n",max,min);
	return 0;
	
 } 
