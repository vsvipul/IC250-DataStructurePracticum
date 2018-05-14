#include <stdio.h>
#define MAX 1000
#define INF 10000000

int adj[MAX][MAX];
int n;

void printmst(char s, int parent[], int min, int max)
{
	int i,res=0;
	for (i=min;i<=max;i++)
	{
		if (i!=s)
			res+=adj[i][parent[i]];
	}
	printf("%d\n",res);
}

int minkey(int key[], int mstset[], int min, int max)
{
	int i, mini=INF, minindex;
	for (i=min;i<=max;i++)
	{
		if (!mstset[i] && key[i]<mini)
		{
			mini=key[i];
			minindex=i;
		}
	}
	return minindex;
}

void prims(char s, int min, int max)
{
	int i,j;
	int parent[MAX];
	int key[MAX];
	int mstset[MAX];
	for (i=min;i<=max;i++)
	{
		key[i]=INF;
		mstset[i]=0;
	}
	key[s]=0;
	parent[s]=-1;
	for (i=0;i<n-1;i++)
	{
		int u=minkey(key,mstset,min,max);
		mstset[u]=1;
		for (j=min;j<=max;j++)
		{
			if (adj[u][j] && !mstset[j] && adj[u][j]<key[j])
			{
				parent[j]=u;
				key[j]=adj[u][j];
			}
		}
	}
	printmst(s, parent, min, max);
}

int main()
{
	int i,j,e,wt,min=INF,max=0;
	char s,sr,dt;
	scanf("%d%d",&n,&e);
	scanf(" %c",&s);
	while (e--)
	{
		scanf(" %c %c %d",&sr,&dt,&wt);
		adj[sr][dt]=wt;
		adj[dt][sr]=wt;
		if (sr<min)
			min=sr;
		if (dt<min)
			min=dt;
		if (sr>max)
			max=sr;
		if (dt>max)
			max=dt;
	}
	prims(s,min,max);
	return 0;
}
