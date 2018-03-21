/* Given a matrix of intergers and a input integer, determine how many times the input integer has appeared in the matrix */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int *arr=(int*)malloc(10000*sizeof(int));
    int i=0;
    while (scanf("%d",&arr[i])!=EOF)
    {
        i++;
    }
    int n=i-1,num=arr[i-1],res=0;
    for (i=0;i<n;i++)
    {
        if (arr[i]==num)
            res++;
    }
    printf("%d\n",res);
    return 0;
}
