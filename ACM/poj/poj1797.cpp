#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#define PI 3.1415926535898
#define LL long long int
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e6+10;
const double eps = 1e-7;
const LL mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
int cost[1005][1005];
int d[10000];
int vis[10000],n,m;
void dijkstra(int s)
{
    for(int i = 0;i <= n;i++)
        d[i] = -INF;
    memset(vis,0,sizeof(vis));
    d[s] = INF;
    int u;
    int Mi;
    for(int i = 0;i < n-1;i++)
    {
        Mi = -INF;
        u = s;
        for(int v = 1;v <= n;v++)
        {
            if(!vis[v]&&d[v] > Mi)
            {
                Mi = d[v];
                u = v;
            }
        }
        vis[u] = 1;
        for(int k = 1;k <= n;k++)
        {
            d[k] = max(d[k],min(d[u],cost[u][k]));
        }
    }
}
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int u,v,w;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
                cost[i][j] = -INF;
            cost[i][i] = 0;
        }
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v] = max(w,cost[u][v]);
            cost[v][u] = max(w,cost[v][u]);
        }
        dijkstra(1);
        //for(int i = 1;i <= n;i++)
            //printf("%d\n",d[i]);
        printf("Scenario #%d:\n",ti++);
        printf("%d\n\n",d[n]);
    }
    return 0;
}
