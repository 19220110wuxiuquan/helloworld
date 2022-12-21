#include<stdio.h>
#include<stdlib.h>
void reverse(char*begin,char*end)
{
	int i,length=end-begin+1;
	char ch;
	for(i=0;i<length/2;i++)
	{
		ch=*begin;
		*begin++=*end;
		*end--=ch;
	}
 } 
 int main()
 {
 	char*str=(char*)malloc(sizeof(char)*128);
 	int i=0;
 	char ch;
 	while((ch=getchar())!='\n')
 	{
 		str[i++]=ch;
	}
	reverse(str,str+i-1);
	char*begin=str;
	char*end=str;
	while(*end!='\0')
	{
		if(*end==' ')
		{
			reverse(begin,end-1);
			begin=end+1;
		}
		end++;
	}
	reverse(begin,end-1);
	printf("%s\n",str);
	free(str);
	return 0;
 }
