#include <stdio.h>
#include <string.h>

#define MAX 1000
#define initial 1
#define visited 2
#define finished 3
int n;

void create_graph(int adj[MAX][MAX], int adjf[MAX][MAX])
{
    int i,maxedges,f;
    int src,dest;
    scanf("%d",&n);
    scanf("%d",&maxedges);
    scanf("%d",&f);
    for (i=1;i<=maxedges;i++)
    {
        scanf("%d%d",&src,&dest);
        adj[src][dest]=1;
        adjf[dest][src]=1;
        if (!f)
        {
            adjf[src][dest]=1;
            adj[dest][src]=1;
        }
    }
}

void dfs(int adj[MAX][MAX], int state[], int v)
{
    int i;
    state[v]=visited;
    for (i=1;i<=n;i++)
    {
        if (adj[v][i]==1 && state[i]==initial)
            dfs(adj,state,i);
    }
    state[v]=finished;
}

void dftraversal(int adj[MAX][MAX], int state[])
{
    char v;
    for (v=1;v<=n;v++)
        state[v]=initial;
    dfs(adj,state,1);
}

int main()
{
    int adj[MAX][MAX];
    int state[MAX];
    int adjf[MAX][MAX];
    int statef[MAX];
    int j, i, res=1;
    create_graph(adj,adjf);
    dftraversal(adj,state);
    dftraversal(adjf,statef);
    for (i=1;i<=n;i++)
    {
        if (state[i]==initial || statef[i]==initial)
        {    
            res=0;
            break;
        }
    }
    printf("%d",res);
    return 0;
}
