#include <stdio.h>
int main ()
{
	int i,a[10]={1,2,3,4,5,6,7,8,9,10};
	int *p=a;
	int tmp;
	int *q=a+9;
	while(p<q)
	{
		tmp=*p;
		*p=*q;
		*q=tmp;
		p++;
		q--;
	}
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
