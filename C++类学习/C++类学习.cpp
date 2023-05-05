#include<iostream>
#include<string.h> 
using namespace std;
class Student
{
	string id;
	char *name;
	int gender;
public:
	Student()
	{};
	Student(string id="19220110",char *pname="wuxiuquan",int gender=1):id(id),gender(gender) 
	{
		name=new char[strlen(pname)+1];
		if(name)
		strcpy(name,pname);
	};
	Student(const Student&s)
	{
		id=s.id;
		name=new char[strlen(s.name)+1];
		if(name)
		strcpy(name,s.name);
		gender=s.gender;
	}
	~Student()
	{
		delete name;
	}
	void print()
	{
		cout<<id<<name<<gender<<endl;
	}		
}; 
int main()
{
	Student s1("19220110","wuxiuquan",1);
	s1.print();
	return 0;
}
