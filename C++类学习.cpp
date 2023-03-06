#include <iostream>
using namespace std;

class date
{
	int year;
	int month;
	int day;
  public:
	date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void print()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
};
int main()
{
	date today(2023, 3, 6), yesterday(2023, 3, 5), tomorrow(2023, 3, 7);
	yesterday.print();
	today.print();
	tomorrow.print();
	return 0;
}
