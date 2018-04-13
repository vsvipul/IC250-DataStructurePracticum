#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define initial 1
#define waiting 2
#define visited 3

void create_graph(int adj[MAX][MAX], int* n, int* min, int* max)
{
    int i,maxedges,f,tmp;
    char src,dest;
    scanf("%d",&tmp);
    *n=tmp;
    scanf("%d",&maxedges);
    scanf("%d",&f);
    for (i=1;i<=maxedges;i++)
    {
        scanf(" %c %c ",&src,&dest);
        adj[src-'0'][dest-'0']=1;
        if (!f)
            adj[dest-'0'][src-'0']=1;
        if (dest-'0'< *min)
            *min=dest-'0';
        if (src-'0'< *min)
            *min=src-'0';
        if (dest-'0'> *max)
            *max=dest-'0';
        if (src-'0'> *max)
            *max=src-'0';
    }
}

int isFull(int rear)
{
    return (rear==MAX-1);
}

int isEmpty(int front, int rear)
{
    return (front==-1 || front==rear+1);
}

void enqueue(int queue[], int *front, int *rear, int item)
{
    if (isFull(*rear))
    {
        printf("Queue Overflow!\n");
        return;
    }
    if (*front==-1)
        *front=0;
    *rear=*rear+1;
    queue[*rear]=item;
}

int dequeue(int queue[], int *front, int *rear)
{
    int item;
    if (isEmpty(*front,*rear))
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    item=queue[*front];
    *front=*front+1;
    return item;
}

void bfs(int v,int adj[MAX][MAX], int n, int state[], int queue[], int front, int rear, int min, int max)
{
    int i;
    enqueue(queue,&front,&rear,v);
    state[v]=waiting;
    while (!isEmpty(front,rear))
    {
        v=dequeue(queue,&front,&rear);
        printf("%c ",v+'0');
        state[v]=visited;
        for (i=min;i<=max;i++)
        {
            if (adj[v][i]==1 && state[i]==initial)
            {
                enqueue(queue,&front,&rear,i);
                state[i]=waiting;
            }
        }
    }
    printf("\n");
}

void bftraversal(int adj[MAX][MAX], int n, int state[], int queue[], int front, int rear, int min, int max)
{
    char v;
    for (v=min;v<=max;v++)
        state[v]=initial;
    scanf("%c",&v);
    bfs(v-'0',adj,n,state,queue,front,rear,min,max);
    /* // Add code to print all vertices (unreachable from starting vertex)
    for (v=0;v<n;v++)
    {
        if (state[v]==initial)
            bfs(v,adj,n,state,queue,front,rear);
    }
    */
}

int main()
{
    int n,adj[MAX][MAX],state[MAX],queue[MAX];
    int min=1000,max=0;
    int front=-1,rear=-1;
    create_graph(adj,&n, &min,&max);
    bftraversal(adj,n,state,queue,front,rear,min,max);
    return 0;
}
