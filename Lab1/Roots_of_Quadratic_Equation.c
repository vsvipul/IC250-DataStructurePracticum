#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sgn(float a)
{
    if (a>0)
        return 1;
    else if (a<0)
        return -1;
    return 0;
}

float pos(float a)
{
    if (a<0)
        return -a;
    return a;
}

int main() {
    float a,b,c,r11,r12,r21,r22,q;
    scanf("%f%f%f", &a, &b, &c);
    if (b*b-4*a*c>=0)
    {
       r11= (-b-sqrt((b*b)-(4*a*c)))/(2*a);
       r12= (-b+sqrt((b*b)-(4*a*c)))/(2*a);
       printf("r11 %f  	 r12 %f\n",r11,r12);
    }
    else
    {
        printf("r11%f+i %f  r12%f-i %f\n",-b/(2*a),pos(sqrt(-(b*b)+(4*a*c))/(2*a)),-b/(2*a),pos(sqrt(-(b*b)+(4*a*c))/(2*a)));
    }
    q = (-b-sgn(b)*sqrt(b*b-4*a*c))/2;
    r21= q/a;
    r22= c/q;
    printf("r21 %f  	 r22 %f\n",r21,r22);
    return 0;
}
