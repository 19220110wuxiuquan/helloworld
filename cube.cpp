#include<iostream>
using namespace std;
class Cube 
{
	//属性
	int m_l;
	int m_w;
	int m_h;
	//行为
public:
	Cube(int l, int w, int h)
	{
		m_l = l;
		m_w = w;
		m_h = h;
	}
	int cube_s()
	{
		int s = (m_l * m_w + m_l * m_h + m_w) * 2;
		return s;
	}
	int cube_v()
	{
		int v = m_l * m_w * m_h;
		return v;
	}
};
bool issame(Cube& c1,Cube&c2)
{
	if (c1.cube_s() == c2.cube_s() && c1.cube_v() == c2.cube_v())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	Cube c1(2, 3, 4);
	cout << c1.cube_s() << endl;
	cout << c1.cube_v() << endl;
	return 0;
}
