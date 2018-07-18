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
struct node
{
    int x,y;
}a[10000];
double dist(node e1,node e2)
{
    return sqrt((e1.x-e2.x)*(e1.x-e2.x)+(e1.y-e2.y)*(e1.y-e2.y));
}
double cost[300][300];
double d[10000];
double ans;
int vis[10000],n;
int pre[10000];
void dijkstra(int s)
{
    for(int i = 0;i <= n;i++)
        d[i] = 1e10;
    memset(vis,0,sizeof(vis));
    d[s] = 0;
    vis[s] = 1;
    int u;
    double Mi;
    for(int i = 0;i < n-1;i++)
    {
        Mi = 1e10;
        u = s;
        for(int v = 1;v <= n;v++)
        {
            if(!vis[v]&&d[v] < Mi)
            {
                Mi = d[v];
                u = v;
            }
        }
        vis[u] = 1;
        for(int k = 1;k <= n;k++)
        {
            if(!vis[k])
                d[k] = min(d[k],max(d[u],cost[u][k]));
        }
    }
}
int main()
{
    int ti = 1;
    while(scanf("%d",&n)&&n)
    {
        for(int i = 0;i < n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
                cost[i][j] = INF;
            cost[i][i] = 0;
        }
        ans = -INF;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
            {
                cost[i][j] = dist(a[i-1],a[j-1]);
                cost[j][i] = dist(a[j-1],a[i-1]);
            }
        dijkstra(1);
        printf("Scenario #%d\n",ti++);
        printf("Frog Distance = %.3f\n\n",d[2]);
    }
    return 0;
}
