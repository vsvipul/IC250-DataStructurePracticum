#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i, j, n;
    scanf("%d", &n);
    float **arr = (float**) malloc(n*sizeof(float*));
    for (i=0;i<n;i++)
        *(arr+i)=(float*) malloc(n*sizeof(float));
    float res=0;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            scanf("%f", (*(arr+i)+j));
            if (i==j)
                res+= *(*(arr+i)+j);
        }
    printf("%.2f", res);
    return 0;
}