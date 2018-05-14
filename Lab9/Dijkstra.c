#include <stdio.h>

#define MAX 1000
#define temp 0
#define perm 1
#define infinity 99999
#define NIL -1

int n;
int adj[MAX][MAX];
int pre[MAX];
int pathlength[MAX];
int status[MAX];

void create_graph(int* s)
{
	int i,maxedges,origin,dest,wt,tmp;
	scanf("%d%d",&n,&maxedges);
	scanf("%d",&tmp);
	*s=tmp;
	for (i=1;i<=maxedges;i++)
	{
		scanf("%d%d%d",&origin,&dest,&wt);
		adj[origin][dest]=wt;
	}
}

void findpath(int s, int v)
{
	int i,u;
	int shortdist=0;
	while (v!=s)
	{
		u=pre[v];
		shortdist+=adj[u][v];
		v=u;
	}
	printf("%d\n",shortdist);
}

int min_temp()
{
	int i;
	int min=infinity;
	int k=NIL;
	for (i=1;i<=n;i++)
	{
		if (status[i]==temp && pathlength[i]<min)
		{
			min=pathlength[i];
			k=i;
		}
	}
	return k;
}

void dijkstra(int s)
{
	int i,current;
	for (i=1;i<=n;i++)
	{
		pre[i]=NIL;
		pathlength[i]=infinity;
		status[i]=temp;
	}
	pathlength[s]=0;
	while (1)
	{
		current=min_temp();
		if (current==NIL)
			return;
		status[current]=perm;
		for (i=1;i<=n;i++)
		{
			if (adj[current][i]!=0 && status[i]==temp)
			{
				if (pathlength[current]+adj[current][i] < pathlength[i])
				{
					pre[i]=current;
					pathlength[i]=pathlength[current]+adj[current][i];
				}
			}
		}
	}
}

int main()
{
	int i,s,v;
	create_graph(&s);
	dijkstra(s);
	for (i=1;i<=n;i++)
	{
		if (i==s)
			continue;
		printf("%d %d ",s,i);
	    if (pathlength[i]==infinity)
			printf("INF\n");
		else
			findpath(s,i);
	}
}
