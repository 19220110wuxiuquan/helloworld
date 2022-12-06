#include<stdio.h>
int max(int x,int y);
int min(int x,int y);
int add(int x,int y);
void process(int,int,int(*fun)(int,int));
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	process(a,b,max);
	process(a,b,min);
	process(a,b,add);
	return 0;
 } 
 int max(int x,int y)
 {
 	printf("max=");
 	return(x>y?x:y);
 }
  int min(int x,int y)
 {
 	printf("min=");
 	return(x<y?x:y);
 }
  int add(int x,int y)
 {
 	printf("sum=");
 	return(x+y);
 }
void process(int x,int y,int(*fun)(int,int))
 {
 	int result;
 	result=(*fun)(x,y);
 	printf("%d\n",result);
 }
