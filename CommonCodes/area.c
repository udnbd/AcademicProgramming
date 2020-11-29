#include <stdio.h>
#include <math.h>

int main(){

    double a,b,c,p,area;

    printf("Enter A: ");
    scanf("%lf",&a);

    printf("Enter B: ");
    scanf("%lf",&b);

    printf("Enter C: ");
    scanf("%lf",&c);

    p = (a+b+c)/2;

    area = sqrt(p*(p-a)*(p-b)*(p-c));

    printf("Area is : %lf",area);


}