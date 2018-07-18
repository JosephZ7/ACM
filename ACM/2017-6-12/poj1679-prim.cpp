#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#define PI 3.1415926535898
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-7;
const int mod = 10007;
const LL inf = 1LL<<60;
using namespace std;
int cost[200][200];
int n,m;
int used[200][200];
int Ma[200][200];
int vis[200];
int pre[200];
int d[200];
int prim()
{
    int sum = 0;
    memset(vis,0,sizeof(vis));
    memset(used,0,sizeof(used));
    memset(Ma,0,sizeof(Ma));
    d[0] = 0;
    vis[0] = 1;
    pre[0] = -1;
    for(int i = 1;i < n;i++)
    {
        d[i] = cost[0][i];
        pre[i] = 0;
    }
    for(int i = 1;i < n;i++)
    {
        int Mi = INF;
        int p = -1;
        for(int j = 0;j < n;j++)
        {
            if(!vis[j]&&d[j] < Mi)
            {
                Mi = d[j];
                p = j;
            }
        }
        if(Mi == INF) return -1;
        sum+=Mi;
        vis[p] = 1;
        used[p][pre[p]] = used[pre[p]][p] = 1;
        for(int j = 0;j < n;j++)
        {
            if(vis[j])
                Ma[j][p] = Ma[p][j] = max(Ma[j][pre[p]],d[p]);
            if(!vis[j]&&d[j] > cost[p][j])
            {
                d[j] = cost[p][j];
                pre[j] = p;
            }
        }
    }
    return sum;
}
int Mst;
int judge()
{
    int cMst = INF;
    for(int i = 0;i < n;i++)
    {
        for(int j = i+1;j < n;j++)
        {
            if(cost[i][j]!=INF&&!used[i][j])
                cMst = min(cMst,Mst+cost[i][j]-Ma[i][j]);
        }
    }
    if(cMst == INF) return -1;
    return cMst;
}
int main()
{
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int u,v,w;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
                cost[i][j] = INF;
            cost[i][i] = 0;
        }
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[v-1][u-1] = cost[u-1][v-1] = w;
        }
        Mst = prim();
        if(Mst == -1||Mst == judge())
            printf("Not Unique!\n");
        else
            printf("%d\n",Mst);
    }
    return 0;
}
