#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c;
	scanf("%f %f %f",&a,&b,&c);
	if(fabs(a-b) < 0.000001||fabs(a-c) < 0.000001||fabs(b-c) < 0.000001)
	 printf("yes");
	else
	 printf("no");
	return 0;
 } 
