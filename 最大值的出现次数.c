#include<stdio.h>
int search(int a[],int n)
{
	int i;
	int t=0;
	int max=a[0];
	for(i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			max=a[i];
		}
	}
	return max;
}
int main()
{
	int n;
	int a[]={0};
	scanf("%d",&n);
	int i,count=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int max=search(a,n);
	for(i=0;i<n;i++)
	{
		if(a[i]==max)
		{
			count++;
		}
	}
	printf("%d",count);
	return 0;
 } 
