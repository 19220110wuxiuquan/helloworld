#include<stdio.h>
int main()
{
	char a[80];//声明文段数组大小 
	int i=0;
	int count =0;
	gets(a);//输入文段 
	while(a[i]==' ')
	i++;//每遇到一个空格，单词计数加一 
	if(a[i]!='\0')
	count++;//如果单词计数没有到最后即会车时，单词数加一 ，此段保证一个单词也能组成一个句子。 
	while(a[i]!='\0')
	{
		if(a[i]==' '&&a[i+1]!=' '&&a[i+1]!='\0')
			count++;
		i++;
	}
	printf("%s:%d Words\n",a,count);
	return 0;
 } 
