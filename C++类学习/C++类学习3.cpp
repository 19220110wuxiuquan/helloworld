#include<iostream>
using namespace std;
class Date{
	int year;
	int month;
	int day;
	public:
		Date(int year,int month=2,int day=26):year(year),month(month),day(day)
		{}
		~Date()
		{
			cout<<"~Date";Output();
		}
			void Output()
			{
				cout<<year<<"-"<<month<<"-"<<day<<endl;
			}
}; 
int main()
{
	Date *pd1=new Date(2019);
	Date *pd2=new Date(2019,6,18);
	pd1->Output();
	pd2->Output();
	delete pd1;
	delete pd2;
	return 0;
}
