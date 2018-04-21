#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
#define infinity 99999
#define NIL -1

int n;
int adj[MAX][MAX];
int state[MAX];
int distance[MAX];
int pre[MAX];
int queue[MAX],front=-1,rear=-1;
char name[12][3]={"MN","CH","DD","MU","DL","KL","GU","BH","CN","GO","HY","KK"};

void insert_edge(int s, int d)
{
    adj[s][d]=1;
    adj[d][s]=1;
}

void create_graph()
{
	n=12;
	insert_edge(0,1);
	insert_edge(1,2);
	insert_edge(1,4);
	insert_edge(3,4);
	insert_edge(4,5);
	insert_edge(5,6);
	insert_edge(3,9);
	insert_edge(4,7);
	insert_edge(7,10);
	insert_edge(8,10);
	insert_edge(9,10);
	insert_edge(9,11);
	insert_edge(8,11);
	insert_edge(5,8);
	insert_edge(2,4);
	insert_edge(3,7);
}

int isFull()
{
	return (rear==MAX-1);
}

int isEmpty()
{
	return (front==-1 || front==rear+1);
}

void enqueue(int item)
{
	if (isFull())
	{
		printf("Queue Overflow!\n");
		return;
	}
	if (front==-1)
		front=0;
	rear=rear+1;
	queue[rear]=item;
}

int dequeue()
{
	int item;
	if (isEmpty())
	{
		printf("Queue Underflow!\n");
		exit(1);
	}
	item=queue[front];
	front=front+1;
	return item;
}

void bfs(int v)
{
	int i;
	enqueue(v);
	state[v]=waiting;
	distance[v]=0;
	pre[v]=NIL;
	while (!isEmpty())
	{
		v=dequeue();
		state[v]=visited;
		for (i=0;i<n;i++)
		{
			if (adj[v][i]==1 && state[i]==initial)
			{
				enqueue(i);
				state[i]=waiting;
				pre[i]=v;
				distance[i]=distance[v]+1;
			}
		}
	}
}

void bftraversal()
{
	int v,i;
	for (v=0;v<n;v++)
	{
		state[v]=initial;
		pre[v]=NIL;
		distance[v]=infinity;
	}
    char tmp[2];
	scanf(" %s",tmp);
    for (i=0;i<12;i++)
    {
        if (strcmp(tmp,name[i])==0)
        {
            v=i;
            break;
        }
    }
	bfs(v);
}

int main()
{
	int v,i,count,path[MAX];
	create_graph();
	bftraversal();
    char tmp[2];
	scanf(" %s",tmp);
    for (i=0;i<12;i++)
    {
        if (strcmp(tmp,name[i])==0)
        {
            v=i;
            break;
        }
    }
	printf("%d",distance[v]);
/*    count=0;
    while (v!=NIL)
    {
        count++;
        path[count]=v;
        v=pre[v];
    }
    printf("Shortest path is: ");
    for (i=count;i>1;i--)
        printf("%d->",path[i]);
    printf("%d\n",path[i]); */
	return 0;
}
