/* Let the universal set be {A,B,C,D,E,F,G,H,I,J}. You are given two subsets of this set. Determine the intersection of these two sets. */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {
    char a[20],b[20];
    scanf(" %[^\n]",a);
    scanf(" %[^\n]",b);
    int i;
    int m1[10],m2[10];
    memset(m1,0,sizeof(m1));
    memset(m2,0,sizeof(m2));
    for (i=0;i<strlen(a);i++)
        if (a[i]!=' ')
            m1[a[i]-'A']++;
    for (i=0;i<strlen(b);i++)
        if (b[i]!=' ')
            m2[b[i]-'A']++;
    int f=1;
    for (i=0;i<10;i++)
    {
        if (m1[i] && m2[i])
        {
            f=0;
            printf("%c ",i+'A');
        }
    }
    if (f)
        printf("NULL");
    return 0;
}
