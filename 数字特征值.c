#include <stdio.h>
int main()
{
    int num,a=1,digit=0,count=1;
    scanf("%d", &num);
    do{
        if((num+count)%2==0){
            digit = digit + a;
        } 
        count++;    
        num /= 10;
        a *= 2;
    }while(num>0);
    printf("%d", digit);
    return 0;
}
