#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	int roll;
	char fname[20],lname[20],dob[20],place[20],dept[20];
} stu;

int n;
int comp(const void *p, const void *q) 
{
	char a[20],b[20];
	if (n==1)
	{
	    int l = ((stu*)p)->roll;
	    int r = ((stu*)q)->roll; 
	    	return (l - r);
	}
	else if (n==2)
	    	return strcmp(((stu*)p)->fname,((stu*)q)->fname);
	else if (n==3)
	    	return strcmp(((stu*)p)->lname,((stu*)q)->lname);
	else if (n==4)
	    	return strcmp(((stu*)p)->dob,((stu*)q)->dob);
	else if (n==5)
	    	return strcmp(((stu*)p)->place,((stu*)q)->place);
	else
		return strcmp(((stu*)p)->dept,((stu*)q)->dept);
}

int main()
{
	int i=0,j;
	scanf("%d",&n);
	stu* arr=(stu*)malloc(100000*sizeof(stu));
	while (scanf("%d %s%s%s%s%s",&arr[i].roll,arr[i].fname,arr[i].lname,arr[i].dob,arr[i].place,arr[i].dept)!=EOF)
		i++;
	int len=i;
	qsort(arr, len, sizeof(stu), comp);
	for (j=0;j<len;j++)
		printf("%d %s %s %s %s %s\n",arr[j].roll,arr[j].fname,arr[j].lname,arr[j].dob,arr[j].place,arr[j].dept);
	return 0;
}
