#include <iostream>
using namespace std;
class Animal
{
	public:
	virtual void speak()
	{
		cout<<"动物在说话"<<endl;
	}
};
class Cat:public Animal
{
	void speak()
	{
		cout<<"小猫在说话"<<endl;
	}
};
class Dog:public Animal
{
	void speak()
	{
		cout<<"小狗在说话"<<endl;
	}
};
//地址早绑定 在编译阶段就确定函数地址
//如果想执行让具体动物说话，那这个函数就不能被提前绑定,需要在运行时确定函数地址

//动态多态满足条件
//1.有继承关系
//2.子类要重写父类的虚函数
void dospeak(Animal&animal)
{
	animal.speak();
}
int main()
{
	Cat cat1;
	Dog dog2;
	dospeak(cat1);
	dospeak(dog2);
	return 0;
}
