#include<stdio.h>
int main()
{
	int a[10];
  int i;
  for(i=0;i<10;i++)
  {
    scanf("%d",&a[i]);
	int query,i;
	printf("Input:");
	scanf("%d",&query);
	for(i=0;i<10;i++)
	{
		if(query==a[i])
		{
			printf("Number %d at %d\n",query,i);
			break;
		}
	
	}
	if(i==10)
	printf("not found\n");
	return 0;
 } 
