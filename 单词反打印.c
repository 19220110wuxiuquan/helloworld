#include<stdio.h>
#include<string.h>
int main(void)
{
    char word[30];
    printf("Please enter the words :");
    scanf("%s",word);
    printf("The word you enter is : %s\n",word);
    printf("The reverse word you enter is :");
    for(int i = strlen(word)-1;i>=0;i--){
        printf("%c",word[i]);
    }
    printf("\n");
    return 0;
}
