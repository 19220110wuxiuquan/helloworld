#include<stdio.h>
#include<string.h>
#define ANSWER "Grant"
#define SIZE 40
char *s_gets(char*st,int n);
int main()
{
	char Try[SIZE];
	puts("Who is buried in Grant's tomb?");
	s_gets(Try,SIZE);
	while(strcmp(Try,ANSWER))
	{
		puts("No,that's wrong.Try again.");
		s_gets(Try,SIZE);
	}
	puts("That's right!");
	return 0;
 } 
 char *s_gets(char*st,int n)
 {
 	char *ret_val;
 	int i=0;
 	ret_val=fgets(st,n,stdin);
 	if(ret_val)
 	{
 		while(st[i]!='\n'&&st[i]!='\0')
 		{
 			i++;
		}
		if(st[i]=='\n')
		{
			st[i]='\0';
		}
		else
		{
			while(getchar()!='\n')
			continue;
		}
	 }
	 return ret_val;
 }
