#include<stdio.h>
#define SEC_PER_YEAR 3.156e7
int main(void)
{
    float year, second;
    printf("Enter how many years old you are :");
    scanf("%f", &year);
    second = year * SEC_PER_YEAR;
    printf("You are:%.1f years old.\n", year);
    printf("And you are %e seconds old,too.\n", second);
    return 0;
}
