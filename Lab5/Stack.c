#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int MAX;
typedef struct sta
{
	char data[10];
} stack;

stack* create()
{
	stack* s=(stack*)malloc(MAX*sizeof(stack));
    if (s==NULL)
    {
        printf("overflow\n");
        exit(1);
    }
	return s;
}

int isFull(int top)
{
	return (top==MAX-1);
}

int isEmpty(int top)
{
	return (top==-1);
}

void push(stack* s, int *top, char item[])
{
	if (isFull(*top))
	{
		printf("overflow\n");
		exit(1);
	}
	*top=*top+1;
	strcpy(s[*top].data, item);
}

void pop(stack* s, int *top)
{
	int item;
	if (isEmpty(*top))
	{
		printf("underflow\n");
		exit(1);
	}
	printf("%s\n",s[*top].data);
	*top=*top-1;
}

void peek(stack* s, int top)
{
	if (isEmpty(top))
	{
		printf("underflow\n");
		exit(1);
	}
	printf("%s\n", s[top].data);
}


int main() 
{
	char str[10],a[10];
	int top=-1;
	stack *s;
	while (scanf(" %s",str)!=EOF)
	{
		if (strcmp(str,"cr")==0)
		{
			scanf("%d",&MAX);
			s=create();
		}
		else if (strcmp(str,"pu")==0)
		{
			scanf(" %s",a);
			push(s, &top, a);
		}
		else if (strcmp(str,"po")==0)
		{
			pop(s, &top);
		}
		else 
		{
			peek(s, top);
		}
	}
    return 0;
}
