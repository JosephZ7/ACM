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
struct Point
{
    double x,y,p;
}a[MAX_N];
double cost[1005][1005];
double getdist(Point e1,Point e2)
{
    return sqrt((e1.x-e2.x)*(e1.x-e2.x)+(e1.y-e2.y)*(e1.y-e2.y));
}
int n;
double d[1005];
bool vis[1005];
bool used[1005][1005];
double Ma[1005][1005];
int pre[1005];
double prim()
{
    memset(vis,false,sizeof(vis));
    memset(used,false,sizeof(used));
    memset(Ma,0,sizeof(Ma));
    for(int i = 1;i <= n;i++)
    {
        d[i] = cost[1][i];
        pre[i] = 1;
    }
    vis[1] = true;
    double sum = 0;
    for(int i = 1;i < n;i++)
    {
        double Mi = INF;
        int p = -1;
        for(int j = 1;j <= n;j++)
        {
            if(!vis[j]&&d[j] < Mi)
            {
                Mi = d[j];
                p = j;
            }
        }
        if(Mi == INF) return 0;
        sum+=Mi;
        vis[p] = true;
        used[p][pre[p]] = used[pre[p]][p] = true;
        for(int j = 1;j <= n;j++)
        {
            if(vis[j]&&j!=p)
                Ma[p][j] = Ma[j][p] = max(Ma[j][pre[p]],d[p]);
            if(!vis[j]&&d[j] > cost[p][j])
            {
                d[j] = cost[p][j];
                pre[j] = p;
            }
        }
    }
    return sum;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(cost,0,sizeof(cost));
        for(int i = 1;i <= n;i++)
        {
            scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].p);
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = i+1;j <= n;j++)
            {
                cost[j][i] = cost[i][j] = getdist(a[i],a[j]);
            }
        }
        double ans = prim();
        double Mans = -1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i+1;j <= n;j++)
            {
                if(used[i][j])
                    Mans = max(Mans,(a[i].p+a[j].p)/(ans-cost[i][j]));
                else
                    Mans = max(Mans,(a[i].p+a[j].p)/(ans-Ma[i][j]));
            }
        }
        printf("%.2f\n",Mans);
    }


    return 0;
}
