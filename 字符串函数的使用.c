#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int main(int argc,char const*argv[])
{
	char str[]="helloworld";
	char*p=strchr(str,'l');//查找第一个l所在地址 
	p=strchr(p+1,'l');//查找第二个l所在地址，注意p+1的使用 
	printf("%s\n",p);
	char*t=(char*)malloc(strlen(p)+1);//数组最后多了一个\0 
	char c=*p;
	*p='\0';
	strcpy(t,str);
	printf("%s\n",t);
	free(t);
	return 0;
 } 
