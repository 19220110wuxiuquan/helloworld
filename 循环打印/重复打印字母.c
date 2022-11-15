#include<stdio.h>
int main()
{
    int i,j;
    char c;
    for(i=0;i<=6;i++)
    {
        for(j=0,c='A';j<i;j++,c++)
        {
            printf("%c",c);
        }
        printf("\n");
    }
    return 0;
}
