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
int fa[MAX_N];
struct edge
{
    int u,v,w;
    int flag;
}es[MAX_N*MAX_N];
void init()
{
    for(int i = 0;i <= n+1;i++)
        fa[i] = i;
}
int Find(int x)
{
    return x == fa[x]?fa[x]:fa[x] = Find(fa[x]);
}
void mix(int x,int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if(fx!=fy)
        fa[fy] = fx;
}
bool cmp(const edge &e1,const edge &e2)
{
    return e1.w < e2.w;
}
int vis[1005],flag,can;
int Kruskal()
{
    init();
    int sum = 0;
    int cnt = 0;
    for(int i = 1;i <= m;i++)
    {
        if(es[i].flag) continue;
        if(Find(es[i].u)!=Find(es[i].v))
        {
            cnt++;
            if(flag) vis[i] = 1;
            sum+=es[i].w;
            mix(es[i].u,es[i].v);
            if(cnt == n-1)
            {
                can = 1;
                break;
            }
        }
    }
    if(cnt == n-1)
        can = 1;
    return sum;
}
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        init();
        int u,v,w;
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            es[i].u = u;
            es[i].v = v;
            es[i].w = w;
            es[i].flag = 0;
        }
        sort(es+1,es+m+1,cmp);
        printf("Case #%d : ",ti++);
        can = 0;
        flag = 1;
        int ans = Kruskal();
        flag = 0;
        if(can == 0)
        {
            printf("No way\n");
            continue;
        }
        //cout<<ans<<endl;
        int tans = INF,tmp;
        for(int i = 1;i <= m;i++)
        {
            if(vis[i])
            {
                es[i].flag = 1;
                can = 0;
                tmp = Kruskal();
                if(can == 1)
                    tans = min(tans,tmp);
                es[i].flag = 0;
            }
        }
        if(tans == INF)
            printf("No second way\n");
        else
            printf("%d\n",tans);
    }


    return 0;
}
