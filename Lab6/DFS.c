#include <stdio.h>
#include <string.h>

#define MAX 1000
#define initial 1
#define visited 2
#define finished 3
int n;
int adj[MAX][MAX];
int state[MAX];

void create_graph(int* min, int* max)
{
    int i,maxedges,f;
    char src,dest;
    scanf("%d",&n);
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

void dfs(int v, int min, int max)
{
    int i;
    printf("%c ",v+'0');
    state[v]=visited;
    for (i=min;i<=max;i++)
    {
        if (adj[v][i]==1 && state[i]==initial)
            dfs(i,min,max);
    }
    state[v]=finished;
}

void dftraversal(int min, int max)
{
    char v;
    for (v=min;v<=max;v++)
        state[v]=initial;
    scanf("%c",&v);
    dfs(v-'0',min,max);
  /*  for (v=1;v<=n;v++)
    {
        if (state[v]==initial)
            dfs(v,min,max);
    }
    printf("\n"); */
}

int main()
{
    int min=1000,max=0;
    create_graph(&min,&max);
    dftraversal(min,max);
    return 0;
}
