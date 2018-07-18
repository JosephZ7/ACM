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
struct node
{
    int u,v,w,flag,x;
}es[MAX_N];
int n,m,fa[MAX_N];
int vis[MAX_N];
bool cmp(const node &x,const node &y)
{
    return x.w < y.w;
}
void init()
{
    for(int i = 0;i <= MAX_N;i++)
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
int tmp;
int Kruskal()
{
    init();
    int sum = 0;
    int cnt = 0;
    for(int i = 0;i < m;i++)
    {
        if(es[i].x) continue;
        if(Find(es[i].u)!=Find(es[i].v))
        {
            sum+=es[i].w;
            cnt++;
            mix(es[i].u,es[i].v);
            if(!tmp) es[i].flag = 1;
            if(cnt == n-1)
                break;
        }
    }
    return sum;
}
int main()
{
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        int u,v,w;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            es[i].u = u; es[i].v = v; es[i].w = w;
            es[i].flag = 0;
            es[i].x = 0;
        }
        sort(es,es+m,cmp);
        for(int i = 1;i < m;i++)
            if(es[i-1].w == es[i].w)
                vis[i-1] = vis[i] = 1;
        tmp = 0;
        int ans1 = Kruskal(),fg = 0;
        tmp = 1;
        for(int i = 0;i < m;i++)
        {
            if(vis[i]&&es[i].flag)
            {
                es[i].x = 1;
                int ans2 = Kruskal();
                if(ans1 == ans2)
                {
                    fg = 1;
                    printf("Not Unique!\n");
                    break;
                }
                es[i].x = 0;
            }
        }
        if(!fg)
            printf("%d\n",ans1);
    }
    return 0;
}
