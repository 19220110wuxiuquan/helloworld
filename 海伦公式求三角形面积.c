#include<stdio.h>
#include<math.h>
int main()
{
	double a, b, c, p, s;
	printf("Please input a,b,c :\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	p = 1.0 / 2 * (a + b + c);
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	if (a + b > c && a + c > b && b + c > a)
	{
		printf("a=%5.2f,b=%5.2f,c=%5.2f\n", a, b, c);
		printf("p=%5.2f\n", p);
		printf("s=%5.2f\n", s);

	}
	else
		printf("input data error\n");
	return 0;
}
