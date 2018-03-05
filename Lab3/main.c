/*
 * sparceMatrix.c
 *
 * This is function definitions for ADT of Sparse Matrix.
 * Author: Abhigyan Khaund (B16082).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COL 130
#include "SM.h"

int elems = 0;              // Variable to count number of elements in sparse matrix //


/* Function to return number of elements in Sparse matrix*/
int getNumberOfElements(SMatrix *S1)
{
    return elems;
}

/* Function to create Sparse matrix*/
SMatrix* Create(int MaxRow,int MaxCol)
{
    SMatrix *SM;
    int i;
    int MaxElems;
    MaxElems=MaxCol*MaxRow;
    SM = (SMatrix*)malloc(sizeof(SMatrix)*(MaxElems));
    SM[0].row = MaxRow;
    SM[0].col = MaxCol;
    SM[0].value = MaxElems;
    printf("%d %d %d",MaxRow, MaxCol, MaxElems);
    for( i = 1 ; i <= SM[0].value ; i++)
        SM[i].value = 0;

    return SM;
}  

/* Function to delete from Sparse matrix*/
void deleteSM(SMatrix *S1,int r_index,int c_index)
{ 
    int i;
    for ( i=1 ; i <= S1[0].value ; i++ )
    {
        if(S1[i].row==r_index && S1[i].col==c_index)
        {   
            S1[i].value=0;
            printf("Entry deleted,kindly enter a new element");
        }   
    }
}

/* Function to insert into Sparse matrix*/
void insertSM(SMatrix *S1,int r_index,int c_index,float value)
{
    int i,count=0;
    for (i=1;i<=S1[0].value;i++){
        if(S1[i].value==0 && count<1 )
        {
            count++;
            if(r_index<S1[0].row && c_index<S1[0].col){
                S1[i].row=r_index;
                S1[i].col=c_index;
                S1[i].value=value;
                elems++;
                return;
            }
            else 
            {   
                printf("Invalid row or column number");
                exit(1);
            }
        }
        else if (S1[i].value!=0 && S1[i].row==r_index && S1[i].col==c_index)
        {
           S1[i].value=value;
        }
    }
}



/* Function to get value of row, column from Sparse matrix*/
float getvalue(SMatrix *Sm,int row,int col)
{
    float value=0;
    int i,j;
    int limit=(int)Sm[0].value;

    for(i=1;i<=limit;i++)
    {
        if(Sm[i].row==row && Sm[i].col==col)
        {
            value=Sm[i].value;
        }
    }
    if(value!=0)
        return value;
    else 
        return 0;
}

void process(char str[])
{
    FILE* f=fopen(str,"r");
    int maxcol=129, maxrow=0, i;
    float cur;
    if (f == NULL)
    {
        printf("Could not open file %s",str);
        return;
    }
    char c;
    for (c = getc(f); c != EOF; c = getc(f))
        if (c == '\n') 
           maxrow++;
    fclose(f);
    f=fopen(str,"r");
    SMatrix* sm=Create(maxrow,maxcol);
    int currow=0,curcol=0;
    while (fscanf(f,"%f",&cur)!=EOF)
    {
        insertSM(sm,currow,curcol,cur);
        curcol++;
        if (curcol==129)
        {
            curcol=0;
            currow++;
        }
    }
    fclose(f);
    int count[200];
    memset(count,0,sizeof(count));
    char tmp[100]="";
    strcpy(tmp,str);
    strcat(tmp,".out");
    FILE* fo=fopen(tmp,"w");
    for (i=1;i<=maxrow*maxcol;i++)
    {
        if (sm[i].value!=0)
        {
            if(sm[i].col<130)
                count[sm[i].col]++;
        }
    }
    for (i=0;i<130;i++)
       fprintf(fo,"%d\n",count[i]);
    char cmd[100]="";
    strcat(cmd,"plot '");
    strcat(cmd,tmp);
    strcat(cmd,"' with boxes");
    printf("%s\n",cmd);
    char* commandsForGnuplot[] = {"set title \"Histogram\"", cmd };
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    for (i=0;i<2;i++)
        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
    fclose(f); 
}

int main()
{
    process("bunting_1.txt");
    process("bunting_2.txt");
    process("cuckoo_1.txt");
    process("cuckoo_2.txt");
    process("monal_1.txt");
    process("monal_2.txt");
    return 0;
}
