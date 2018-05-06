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
char name[12][3]={"BH","CH","CN","DD","DL","GO","GU","HY","KK","KL","MN","MU"};
//                  0    1    2   3    4     5    6    7    8    9    10   11
void insert_edge(int s, int d)
{
    adj[s][d]=1;
    adj[d][s]=1;
}

void create_graph()
{
	n=12;
	insert_edge(10,1);
	insert_edge(1,4);
	insert_edge(1,3);
	insert_edge(3,4);
	insert_edge(4,9);
	insert_edge(6,9);
	insert_edge(4,11);
	insert_edge(4,0);
	insert_edge(0,11);
	insert_edge(9,2);
	insert_edge(5,11);
	insert_edge(0,7);
	insert_edge(5,7);
	insert_edge(5,8);
    insert_edge(7,2);
    insert_edge(8,2);
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
//	printf("%d",distance[v]);
    count=0;
    while (v!=NIL)
    {
        count++;
        path[count]=v;
        v=pre[v];
    }
    for (i=count-1;i>1;i--)
        printf("%s ",name[path[i]]); 
	return 0;
}
