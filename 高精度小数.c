#include<stdio.h>
int main() 
{
    int a, b, i, t;
    scanf("%d/%d", &a, &b);
    printf("0.");
    for (i = 0; i < 200; i++) 
    {
        t = a * 10 / b;
        a = a * 10 % b;
        printf("%d", t);
        if (a == 0) //除尽，结束循环
            break;
    }
    printf("\n");
    return 0;
}
