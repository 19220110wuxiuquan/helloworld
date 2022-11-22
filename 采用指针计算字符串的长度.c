 #include<stdio.h>
 int main()
 {
 	char *name="WORLD";
 	char*ptr;
 	int length;
 	ptr=name;
 	printf("%s\n",name);
 	while(*ptr!='\0')
 	{
 		printf("%c@%p\n",*ptr,ptr);
 		ptr++;
	}
	length=ptr-name;
	printf("length:%d",length);
	return 0;
 }
