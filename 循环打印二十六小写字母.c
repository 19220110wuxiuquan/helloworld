#include<stdio.h>
int main(void)
{
	int i;
	char ch[26];
	char c = 'a';
	for (i = 0; i < 26; i++,c++)
		ch[i]=c;
	for (i = 0; i < 26; i++)
		printf("%c", ch[i]);
	printf("\n");
	return 0;
}
