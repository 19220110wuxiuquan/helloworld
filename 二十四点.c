#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
char op[5] = { '#', '+', '-', '*', '/', };
float cal(float x, float y, int op)
{
	switch (op)									
	{
	case 1:return x + y;
	case 2:return x - y;
	case 3:return x*y;
	case 4:return x / y;
	}
}
float m1(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(i, j, op1);
	r2 = cal(r1, k, op2);
	r3 = cal(r2, t, op3);
	return r3;
}
float m2(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(j, k, op2);
	r2 = cal(i, r1, op1);
	r3 = cal(r2, t, op3);
	return r3;
}
float m3(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(k, t, op3);
	r2 = cal(j, r1, op2);
	r3 = cal(i, r2, op1);
	return r3;
}
float m4(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(j, k, op2);
	r2 = cal(r1, t, op3);
	r3 = cal(i, r2, op1);
	return r3;
}
float m5(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(i, j, op1);
	r2 = cal(k, t, op3);
	r3 = cal(r1, r2, op2);
	return r3;
}
int get24(int i, int j, int k, int t)
{
	int op1, op2, op3;
	int flag = 0;
	for (op1 = 1; op1 <= 4; op1++){						
		for (op2 = 1; op2 <= 4; op2++){
			for (op3 = 1; op3 <= 4; op3++){
				if (m1(i, j, k, t, op1, op2, op3) == 24)
				{
					printf("((%d%c%d)%c%d)%c%d=24\n", i, op[op1], j, op[op2], k, op[op3], t);
					flag = 1;
				}
				if (m2(i, j, k, t, op1, op2, op3) == 24)
				{
					printf("(%d%c(%d%c%d))%c%d=24\n", i, op[op1], j, op[op2], k, op[op3], t);
					flag = 1;
				}
				if (m3(i, j, k, t, op1, op2, op3) == 24)
				{
					printf("%d%c(%d%c(%d%c%d))=24\n", i, op[op1], j, op[op2], k, op[op3], t);
					flag = 1;
				}
				if (m4(i, j, k, t, op1, op2, op3) == 24)
				{
					printf("%d%c((%d%c%d)%c%d)=24\n", i, op[op1], j, op[op2], k, op[op3], t);
					flag = 1;
				}
				if (m5(i, j, k, t, op1, op2, op3) == 24)
				{
					printf("(%d%c%d)%c(%d%c%d)=24\n", i, op[op1], j, op[op2], k, op[op3], t);
					flag = 1;
				}
			}
		}
	}
	return flag;
}
int main()
{
	int i, j, k, t;
	char end;
	do{
		printf("将随机产生1到13的四个数\n");
		//printf("请输入1到13的四个数\n");
		srand(time(NULL));
		i = 1 + (rand() % 13);
		j = 1 + (rand() % 13); 
		k = 1 + (rand() % 13);
		t = 1 + (rand() % 13);
		printf("%d %d %d %d\n", i, j, k, t);
		//scanf("%d %d %d %d", &i, &j, &k, &t);
		if (get24(i, j, k, t));
		else printf("这四个数算不出来24\n");
		end = getchar();
	} while (end=='\n');
	getche ();
	return 0;
}
