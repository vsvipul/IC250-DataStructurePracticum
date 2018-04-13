#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert_edge(int ver, int adj[1000][1000], char src, char dest)
{
    adj[(int)src][(int)dest]=1;
}

void display(int ver, int adj[1000][1000], int min, int max)
{
    int i,j;
    for (i=min;i<=max;i++)
    {
        for (j=min;j<=max;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
}

struct edge
{
    struct vertex* destvertex;
    struct edge* nextedge;
};

struct vertex
{
    char info;
    struct vertex* nextvertex;
    struct edge* firstedge;
};

struct vertex* findvertex(struct vertex* start, char u)
{
	struct vertex *p, *loc;
	p=start;
	while (p!=NULL)
	{
		if (p->info==u)
		{
			loc=p;
			return loc;
		}
		p=p->nextvertex;
	}
	loc=NULL;
	return loc;
}

struct vertex* insertvertex_list(struct vertex* start, char u)
{
    if (findvertex(start,u)!=NULL)
        return start;
    struct vertex *tmp,*p;
    tmp=malloc(sizeof(struct vertex));
    tmp->info=u;
    tmp->nextvertex=NULL;
    tmp->firstedge=NULL;
    if (start==NULL)
    {
        start=tmp;
        return start;
    }
    p=start;
    while (p->nextvertex!=NULL)
        p=p->nextvertex;
    p->nextvertex=tmp;
    return start;
}

struct vertex* insertedge_list(struct vertex* start, char u, char v)
{
    struct vertex *locu,*locv;
    struct edge *tmp,*p;
    locu=findvertex(start, u);
    locv=findvertex(start, v);
    if (locu==NULL || locv==NULL)
    {
        printf("Start or end vertex not present. Insert that first.\n");
        return start;
    }
    tmp=malloc(sizeof(struct edge));
    tmp->destvertex=locv;
    tmp->nextedge=NULL;
    if (locu->firstedge==NULL) //first edge in that vertex
    {
        locu->firstedge=tmp;
        return start;
    }
    p=locu->firstedge;
    while (p->nextedge!=NULL)
        p=p->nextedge;
    p->nextedge=tmp;
    return start;
}

void display_list(struct vertex* start)
{
    struct vertex *p;
    struct edge *q;
    p=start;
    while (p!=NULL)
    {
        printf("%c",p->info);
        q=p->firstedge;
        while (q!=NULL)
        {
            printf(" %c",q->destvertex->info);
            q=q->nextedge;
        }
        printf("\n");
        p=p->nextvertex;
    }
}

 
/* function to swap data of two nodes a and b*/
void swap(struct edge *a, struct edge *b)
{
    struct vertex* temp = a->destvertex;
    a->destvertex = b->destvertex;
    b->destvertex = temp;
}

/* Bubble sort the given linked lsit */
void bubbleSort(struct edge *start)
{
    int swapped, i;
    struct edge *ptr1=start;
    struct edge *lptr = NULL;
 
    /* Checking for empty list */
    if (ptr1 == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = start;
 
        while (ptr1->nextedge != lptr)
        {
            if (ptr1->destvertex > ptr1->nextedge->destvertex)
            { 
                swap(ptr1, ptr1->nextedge);
                swapped = 1;
            }
            ptr1 = ptr1->nextedge;
        }
        lptr = ptr1;
    }
    while (swapped);
}


void sort_list(struct vertex* start)
{
    struct vertex* p=start;
    while (p!=NULL)
    {
        bubbleSort(p->firstedge);
        p=p->nextvertex;
    }
}

int main()
{
    int dir,ver,edg,i;
    int min=1000,max=0;
    char sr,dt;
    scanf("%d%d", &ver, &edg);
    int adj[1000][1000];
    int hash[10000];
    memset(adj,0,sizeof(adj));
    memset(hash,0,sizeof(hash));
    struct vertex* start=NULL;
    scanf("%d", &dir);
    char src[edg],dest[edg];
    for (i=0;i<edg;i++)
    {
        scanf(" %c %c", &sr, &dt);
        src[i]=sr;
        dest[i]=dt;
        hash[sr]=1;
        hash[dt]=1;
        if ((int)dt< min)
            min=(int)dt;
        if ((int)sr< min)
            min=(int)sr;
        if ((int)dt> max)
            max=(int)dt;
        if ((int)sr> max)
            max=(int)sr;
    }
    for (i=min;i<=max;i++)
    {
        if (hash[i])
            start=insertvertex_list(start,(char)i);
    }
    for (i=0;i<edg;i++)
    {
        insert_edge(ver,adj,src[i],dest[i]);
        start=insertedge_list(start,src[i],dest[i]);
        if (!dir)
        {
            insert_edge(ver,adj,dest[i],src[i]);
            start=insertedge_list(start,dest[i],src[i]);
        }
    }
    display(ver,adj,min,max);
    sort_list(start);
    display_list(start);
    return 0;
}
