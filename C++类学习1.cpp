#include<iostream>
using namespace std;
class Date
{
	int year;
	int month;
	int day;
public:
	void init_date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	bool isLeapyear()
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			return true;
		else
			return false;
	}
	void print()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
};
void main()
{
	Date oneday;
	oneday.print();
	oneday.init_date(2023,3,6);
	oneday.print();
}
