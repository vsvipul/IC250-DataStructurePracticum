#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    float x,y;
} point;

int main() {

    int n,i;
    float r;
    scanf("%d%f", &n, &r);
    point arr[n];
    for (i=0;i<n;i++)
        scanf("%f", &arr[i].x);
    for (i=0;i<n;i++)
        scanf("%f", &arr[i].y);
    for (i=0;i<n;i++)
    {
        if (sqrt((arr[i].x * arr[i].x)+(arr[i].y * arr[i].y))<r)
            printf("%f  %f\n", arr[i].x, arr[i].y);
    }
    return 0;
}