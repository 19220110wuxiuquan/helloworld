#include<stdio.h>
#include<string.h>
int main()
{
	char dest[20]={"hello"};
	char*source="world!";
	strcat(dest,source);
	printf("%s\n",dest);
	return 0;
}
