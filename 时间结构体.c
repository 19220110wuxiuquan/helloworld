#include<stdio.h>
struct date{
	int month;
	int day;
	int year;
};
int main()
{
	struct date today;
	today.month=11;
	today.day=29;
	today.year=2022;
	printf("Today's date is %i-%i-%i.\n",today.year,today.month,today.day);
	return 0;
 } 
