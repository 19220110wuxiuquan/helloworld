#include<stdio.h>
int main()
{
	char str[]="dlrowolleh";
	puts(str);
	char*phead=str;
	char*ptail=str;
	while(*ptail)
	{
		ptail++;
	}
	ptail--;
	while(phead<=ptail)
	{
		char tmp=*phead;
		*phead=*ptail;
		*ptail=tmp;
		phead++;
		ptail--;
	}
	puts(str);
	return 0;
 } 
