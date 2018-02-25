#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct matrix
{
	int** val;
};
typedef struct matrix* Matrix;

Matrix adt_createMatrix(int r, int c) 
{
	Matrix m = (Matrix)malloc(sizeof(struct matrix));
	m->val=(int**)malloc(r*sizeof(int *));
	int i;
	for (i=0;i<r;i++)
		m->val[i]=(int*)malloc(c*sizeof(int));
	return m;
}

Matrix adt_loadMatrix(Matrix m, int r, int c) 
{
	int i,j;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			scanf("%d",&(m->val[i][j]));
		}
	}
	return m;
}

void adt_printMatrix(Matrix m, int r, int c)
{
	int i,j;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf("%d ",m->val[i][j]);
		}
		printf("\n");
	}
}

void adt_addMatrix(Matrix m1, Matrix m2, int r, int c) 
{
	int i,j;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			(m1->val[i][j])+=(m2->val[i][j]);
		}
	}
	adt_printMatrix(m1,r,c);
}

void adt_equalityMatrix(Matrix m1, Matrix m2, int r, int c)
{
	int i,j,f=1;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			if (m1->val[i][j]!=m2->val[i][j])
			{
				f=0;
				break;
			}
		}
	}
	if (f)
		printf("Matrices are equal");
	else
		printf("Matrices are not equal");
}

void adt_printTranspose(Matrix m, int r, int c)
{
	int i,j;
	for (i=0;i<c;i++)
	{
		for (j=0;j<r;j++)
		{
			printf("%d ",m->val[j][i]);
		}
		printf("\n");
	}
}

void adt_printTrace(Matrix m, int r, int c)
{
	if (r!=c)
	{
		printf("Non-square matrix: trace does not exist");
		return;
	}
	int i,j,res=0;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			if (i==j)
				res+=m->val[i][j];
		}
	}
	printf("%d",res);
}

void adt_multiplyMatrix(Matrix m1, int r1, int c1, Matrix m2, int r2, int c2)
{
	if (c1!=r2)
	{
		printf("Dimensions incompatible: cannot multiply");
		return;
	}
	Matrix res= adt_createMatrix(r1,c2);
	int i,j,k,sum;
	for (i=0;i<r1;i++)
	{
		for (j=0;j<c2;j++)
		{
			sum=0;
			for (k=0;k<r2;k++)
			{
				sum+=(m1->val[i][k]*m2->val[k][j]);
			}
			res->val[i][j]=sum;
		}
	}
	adt_printMatrix(res,r1,c2);
}

int main() {
	int r1,r2,c1,c2;
	scanf("%d%d",&r1,&c1);
	Matrix m1=adt_createMatrix(r1,c1);
	adt_loadMatrix(m1,r1,c1);
	scanf("%d%d",&r2,&c2);
	Matrix m2=adt_createMatrix(r2,c2);
	adt_loadMatrix(m2,r2,c2);
	char op[1000];
	scanf("%s",op);
	if (strcmp(op,"Add")==0)
	{
		if (r1!=r2 || c1!=c2)
		{
			printf("Dimension mismatch: cannot add");
			return 0;
		}
		adt_addMatrix(m1,m2,r1,c1);
	}
	else if (strcmp(op,"Transpose")==0)
	{
		adt_printTranspose(m1,r1,c1);
	}
	else if (strcmp(op,"Equality")==0)
	{
		if (r1!=r2 || c1!=c2)
		{
			printf("Matrices are not equal");
			return 0;
		}
		adt_equalityMatrix(m1,m2,r1,c1);
	}
	else if (strcmp(op,"Trace")==0)
	{
		adt_printTrace(m1,r1,c1);
	}
	else if (strcmp(op,"Multiply")==0)
	{
		adt_multiplyMatrix(m1,r1,c1,m2,r2,c2);
	}
    return 0;
}
