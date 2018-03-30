#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int MAX;
typedef struct qu
{
	char data[20];
} queue;

queue* create()
{
    queue* q=(queue*)malloc(MAX*sizeof(queue));
    return q;
}

int isFull(int front, int rear)
{
	return ((rear==MAX-1 && front==0)||(front==rear+1));
}

int isEmpty(int front)
{
	return (front==-1);
}

void enqueue(queue* q, int *front, int *rear, char item[])
{
	if (isFull(*front, *rear))
	{
		printf("overflow\n");
		return;
	}
	if (*front==-1)
		*front=0;
	if (*rear==MAX-1)
		*rear=0;
	else
		*rear=*rear+1;
	strcpy(q[*rear].data, item);
}

void dequeue(queue* q, int *front, int *rear)
{
	int item;
	if (isEmpty(*front))
	{
		printf("empty\n");
		return;
	}
	printf("%s\n",q[*front].data);
	if (*front==*rear) //1 element only
	{
		*front=-1;
		*rear=-1;
	}
	else if (*front==MAX-1)
		*front=0;
	else
		*front=*front+1;
}

void display(queue *q, int front, int rear)
{
	if (isEmpty(front))
	{
		printf("empty\n");
		return;
	}
	printf("%s\n%s\n", q[front].data, q[rear].data);
}

void count(int front, int rear)
{
	if (isEmpty(front))
		printf("0\n");
	else if (rear>=front)
		printf("%d\n",rear-front+1);
    else
        printf("%d\n",MAX+(rear-front+1));
}

int main() 
{
	char str[20],a[20];
	int front=-1,rear=-1;
	queue *q;
	while (scanf(" %s",str)!=EOF)
	{
		if (strcmp(str,"cr")==0)
		{
			scanf("%d",&MAX);
			q=create();
		}
		else if (strcmp(str,"en")==0)
		{
			scanf(" %s",a);
			enqueue(q, &front, &rear, a);
		}
		else if (strcmp(str,"de")==0)
		{
			dequeue(q, &front, &rear);
		}
		else if (strcmp(str,"ht")==0)
		{
			display(q, front, rear);
		}
		else if (strcmp(str,"si")==0)
		{
			count(front, rear);
		}
	}
    return 0;
}
