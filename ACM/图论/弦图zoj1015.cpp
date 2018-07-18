#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <iostream>
#define PI acos(-1)
#define LL long long
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e3+10;
const double eps = 1e-8;
const LL inf = 1e18+10;
using namespace std;
struct node
{
    int to,next;
}es[MAX_N*MAX_N*4];
int e,head[MAX_N];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
int cost[MAX_N][MAX_N],f[MAX_N],id[MAX_N],vis[MAX_N];
void MCS(int n)
{
    for(int i = 0;i <= n;i++)
    {
        f[i] = 0; vis[i] = 0;
    }
    for(int i = n;i >= 1;i--)
    {
        int u = -1;
        for(int v = 1;v <= n;v++)
            if(!vis[v]&&(u == -1||f[u] < f[v]))
                u = v;
        vis[u] = 1;
        id[i] = u;
        for(int v = 1;v <= n;v++)
            if(!vis[v]&&cost[u][v])
                f[v]++;
    }
}
bool check(int n)
{
    for(int u = 1; u <= n; ++u)
    {
        int t = u + 1;
        while(t <= n && !cost[id[u]][id[t]]) ++t;
        if(t > n) continue;
        for(int v = t + 1; v <= n; ++v)
        if(cost[id[u]][id[v]])
            if(!cost[id[t]][id[v]]) return false;
    }
    return true;
}
void init()
{
    memset(head,-1,sizeof(head));
    memset(cost,0,sizeof(cost));
    e = 0;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n&&!m) break;
        init();
        int u,v;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            cost[u][v] = 1;
            cost[v][u] = 1;
            addedge(u,v);
            addedge(v,u);
        }
        MCS(n);
        if(check(n))
            printf("Perfect\n");
        else
            printf("Imperfect\n");
        printf("\n");
    }
    return 0;
}
/*
*/
