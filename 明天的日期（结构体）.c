#include<stdio.h>
#include<stdbool.h>
int numberofdays(struct date d);
bool isleap(struct date d);//判断是否是闰年 
//整个结构可以作为参数的值传入函数，这时候是在函数内新建一个结构变量，并复制调用者的数据结构，也可以返回一个结构
 struct date {
 	int month;
 	int day;
 	int year;
 };//声明了一个结构体 
 int main(int argc,char const *argv[])
 {
 	struct date today,tomorrow;//结构体的名称为today,tomorrow 
 	printf("Enter today's date (yyyy mm dd):");//要求输入today的日期 
 	scanf("%i-%i-%i",&today.year,&today.month,&today.day);//输入日期 ，注意&的优先级没有.高 
 	if(today.day!=numberofdays(today))//如果这一天不是这个月的最后一天，那么就是day简单地加一天 
 	{
 		tomorrow.day=today.day+1;
 		tomorrow.month=today.month;
 		tomorrow.year=today.year;
	}
	else if(today.month==12)//如果是十二月的最后一天 
	{
		tomorrow.day=1;
		tomorrow.month=1;
		tomorrow.year=today.year+1;
	}
	else//1-11月的最后一天 
	{
		tomorrow.day=1;
		tomorrow.month=today.month+1;
		tomorrow.year=today.year;
	}
	printf("Tomorrow's date is%i-%i-%i",tomorrow.year,tomorrow.month,tomorrow.day); 
	return 0;
 }
 int numberofdays(struct date d)
 {
 	int days;
 	const int dayspermonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 	if(d.month==2&&isleap(d))
 	{
 		days=29;
	}
	else
	{
		days=dayspermonth[d.month-1];
	}
	return days;
 }
 bool isleap(struct date d)
 {
 	bool leap=false;
 	if((d.year%4==0&&d.year%100!=0)||d.year%400==0)
 	{
 		leap=true;
	}
	return leap;
 }
