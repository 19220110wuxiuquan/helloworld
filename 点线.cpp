#include<iostream>
using namespace std;
class Cline;
class Cpoint 
{
    int x, y;
public:
    Cpoint() 
    {
        x = 0;
        y = 0;
    };
    Cpoint(int a, int b) 
    {
        x = a;
        y = b;
    }
    void print() 
    {
        cout << "x:" << x << " y:" << y << endl;
    }
    friend Cline;
};

class Cline 
{
public:
    int a, b;
    bool Isonline(Cpoint p);
};

bool Cline::Isonline(Cpoint p) 
{
    if (p.y == p.x * a + b)
        return true;
    else
        return false;
}

int main() 
{
    Cpoint p(1, 2);
    Cline l;
    l.a = 2;
    l.b = 1;
    if (l.Isonline(p))
        cout << "On the line" << endl;
    else
        cout << "Not on the line" << endl;
    return 0;
}
