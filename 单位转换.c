#include<stdio.h>
#define FEET_TO_CM 30.48
#define INCH_TO_CM 2.54
int main(int argc, char* argv[])
{
    int feet;
    float cm, inches;
    printf("CONVERT CM TO INCHES!\n");
    printf("Enter the height in centimeters :");
    scanf("%f", &cm);
    while(cm > 0) {
        feet = cm / FEET_TO_CM;
        inches = (cm - feet * FEET_TO_CM) / INCH_TO_CM;
        printf("%.1f cm = %d feet , %.1f inches\n", cm, feet, inches);
        printf("Enter the height in centimeters( <=0 TO QUIT ):");
        scanf("%f", &cm);
    }
    printf("PROGRAM EXIT!\n");
    return 0;
}
