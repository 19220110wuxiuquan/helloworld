#include<stdio.h>
#include<string.h>
char* str_cat(char * str1, char * str2)
{
    char *addr1=str1;
    while(*addr1!='\0')
	addr1++;
    while((*addr1++=*str2++)!='\0');
    return str1;
}

int main()
{
	char dest[20]={"hello"};
	char*source="world!";
	str_cat(dest,source);
	printf("%s\n",dest);
	return 0;
}
