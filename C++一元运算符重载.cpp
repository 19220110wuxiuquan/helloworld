#include <iostream>
using namespace std;
class Complex {
private:
    double i;
    double j;
public:
    Complex(int = 0, int = 0);
    void display();
    Complex operator ++();//前缀自增
    Complex operator ++(int);//后缀自增，参数需要加int
};

Complex::Complex(int a, int b) {
    i = a;
    j = b;
}

void Complex::display() {
    cout << i << '+' << j << 'i' << endl;
}


Complex Complex::operator ++() {
    ++i;
    ++j;
    return *this;
}

Complex Complex::operator ++(int) {
    Complex temp =*this;
    ++*this;
    return temp;
}
