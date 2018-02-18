#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

////////// begin ADT ////////////

struct vec
{
    float *val;
};

typedef struct vec *Vector;

Vector adt_createVector(int dim) 
{
    Vector a= (Vector) malloc(sizeof(struct vec));
    a->val = (float*)malloc(dim*sizeof(float));
    return a;
}

void adt_loadVector(Vector vec, int dim) 
{
    float tmp;
    int i;
    for (i=0;i<dim;i++)
    {
        scanf("%f", &tmp);
        vec->val[i]=tmp;
    }
}

Vector adt_addVector(Vector vec1, Vector vec2, int dim) 
{
    int i;
    for (i=0;i<dim;i++)
        vec1->val[i]+=vec2->val[i];
    return vec1;
}

float adt_normVector(Vector vec, int dim)
{
    float sum=0;
    int i;
    for (i=0;i<dim;i++)
        sum+=(vec->val[i])*(vec->val[i]);
    sum=sqrt(sum);
    return sum;
}

Vector adt_scaleVector(Vector vec, float norm, int dim)
{
    int i;
    for (i=0;i<dim;i++)
        vec->val[i] *= norm;
    return vec;
}

///////// end of ADT //////////

int main() {
    /* Function names starting with adt_ are from the vector ADT */
    /* Get vector dimension from stdin */
    int dim;
    scanf("%d", &dim);
    float norm2;
    /* Create the empty vectors */
    Vector vec1 = adt_createVector(dim);
    Vector vec2 = adt_createVector(dim);
    Vector vec3 = adt_createVector(dim);
    Vector vec4 = adt_createVector(dim);
    /* Populate the vectors from stdin */
    adt_loadVector(vec1,dim);
    adt_loadVector(vec2,dim);
    /* perform operations */
    vec3 = adt_addVector(vec1,vec2,dim);
    norm2 = adt_normVector(vec2,dim);
    vec4 = adt_scaleVector(vec3,norm2,dim);
    /* Display the result */
    int i;
    for (i=0;i<dim;i++)
        printf("%.2f 	 ", vec4->val[i]);
    return 0;
}
