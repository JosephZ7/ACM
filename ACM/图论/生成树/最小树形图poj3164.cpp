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
const int MAX_N = 1e2+10;
const double eps = 1e-7;
const int mod = 10007;
const LL inf = 1LL<<60;
using namespace std;
int n,m;
struct Point
{
    double x,y;
}a[MAX_N];
struct edge
{
    int u,v;
    double val;
}es[MAX_N*MAX_N*5];
double in[MAX_N];
int col[MAX_N],pre[MAX_N],ID[MAX_N];
double getdist(Point e1,Point e2)
{
    return sqrt((e1.x-e2.x)*(e1.x-e2.x)+(e1.y-e2.y)*(e1.y-e2.y));
}
double ZL_Mst(int root)
{
    double sum = 0;
    while(1)
    {
        for(int i = 0;i < n;i++) in[i] = INF;
        for(int i = 0;i < m;i++)
        {
            int u = es[i].u;
            int v = es[i].v;
            if(u!=v&&es[i].val < in[v])
            {
                in[v] = es[i].val;
                pre[v] = u;
            }
        }
        for(int i = 0;i < n;i++)
        {
            if(i!=root&&in[i] == INF)
                return -1;
        }
        memset(col,-1,sizeof(col));
        memset(ID,-1,sizeof(ID));
        in[root] = 0;
        int tn = 0;
        for(int i = 0;i < n;i++)
        {
            sum+=in[i];
            int v = i;
            while(v!=root&&col[v] != i&&ID[v] == -1)
            {
                col[v] = i;
                v = pre[v];
            }
            if(v!=root&&ID[v] == -1)
            {
                for(int u = pre[v];u!=v;u = pre[u])
                    ID[u] = tn;
                ID[v] = tn++;
            }
        }
        if(!tn) break;
        for(int i = 0;i < n;i++)
            if(ID[i] == -1)
                ID[i] = tn++;
        for(int i = 0;i < m;i++)
        {
            int u = es[i].u;
            int v = es[i].v;
            es[i].u = ID[u];
            es[i].v = ID[v];
            if(ID[u]!=ID[v]) es[i].val -=in[v];
        }
        n = tn;
        root = ID[root];
    }
    return sum;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        for(int i = 0;i < n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        int u,v;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            es[i].u = u-1;
            es[i].v = v-1;
            if(u!=v)
                es[i].val = getdist(a[u-1],a[v-1]);
            else
                es[i].val = INF;
        }
        double ans = ZL_Mst(0);
        if(ans == -1)
            printf("poor snoopy\n");
        else
            printf("%.2f\n",ans);
    }
    return 0;
}
