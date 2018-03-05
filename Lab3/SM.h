/*
 * SM.hpp
 *
 * This is an ADT for a Sparse Matrix.
 * Author: Abhigyan Khaund (B16082).
 */

#ifndef _SM_h
#define _SM_h

typedef struct sparseMat{
	int col;
	int row;
	float value;
}SMatrix;


/* Function to return number of elements in Sparse matrix*/
int getNumberOfElements(SMatrix *);

/* Function to create Sparse matrix*/
SMatrix* Create(int ,int );

/* Function to insert into Sparse matrix*/
void insertSM(SMatrix *,int ,int ,float );

/* Function to delete from Sparse matrix*/
void deleteSM(SMatrix *,int,int);

/* Function to get value of row, column from Sparse matrix*/
float getvalue(SMatrix *,int ,int );

#endif
