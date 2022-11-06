#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	char a[20]={};
	char c;
	int i = 0;
	int j = 0;
	printf("你想输入的字符串：\n");
	fgets(a,sizeof(a),stdin);    //在键盘上获取字符串
	printf("请输入你想要删除的字符:\n");
	scanf("%c",&c);
	getchar();
	for(i = 0;i < sizeof(a);i++)
	{
		if(a[i] != c)
			a[j++] = a[i];
	}
	a[i] = '\0';
	printf("%s\n",a);
	return 0;
}
