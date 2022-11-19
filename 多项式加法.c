#include<stdio.h>
#include<string.h>
int main() {
    int mi, xi, cnt, a[110], i, f, zero;
    cnt = 0;
    memset(a, 0, sizeof(a));//数组清零
    while (scanf("%d %d", &mi, &xi)) {//读入幂次、系数
        if (mi == 0)
            cnt++;
        a[mi] += xi;
        if (cnt == 2)
            break;
    }
    //printf("%d\n",cnt);
    f = 1;//判断第一个系数
    zero = 0;//判断系数都为0
    for (i = 105; i >=0 ; i--) {
        //系数不为0
        if (a[i] != 0) {
            zero = 1;
            if (f > 1)//第2个系数、幂次
                if (a[i] > 0)
                    printf("+"); //符号输出
 
            if (a[i] != 1 || i == 0) //系数不为1或幂次为0
                printf("%d", a[i]);
            //幂次输出
            if (i == 1) // 幂次为1
                printf("x");
            if (i > 1) // 幂次大于1
                printf("x%d", i);//x^i 输出幂次
            f++;
        }
    }
    if (!zero)
        printf("0");
    return 0;
}
