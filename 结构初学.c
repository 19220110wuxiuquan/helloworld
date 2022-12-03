#include<stdio.h>
	struct date{
		int month;
		int day;
		int year;
	};//声明一种结构 
int main(int argc,char const * argv[])
{
	struct date today={07,31,2014};//定义结构变量 
	/*today.month=07;
	today.day=31;
	today.year=2014;*/
	struct date thismonth={.month=7,.year=2019}; 
	struct date *pdate=&today;
	printf("address of today is %p\n",pdate); 
	printf("%i-%i-%i\n",today.year,today.month,today.day);
	printf("%i-%i-%i",thismonth.year,thismonth.month,thismonth.day);
	return 0;
 } 
 //结构用.和名字访问其中的成员
 //结构中的数据类型可以不一样
 //结构变量的名字不是结构变量的地址，需要用& 
