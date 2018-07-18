#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <deque>
#include <iterator>
#include <vector>
#include <map>
#include <list>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <iostream>
#include <iomanip>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
struct edge
{
    int u,v,cost;
}es[MAX_N];
int n,m;
int fa[MAX_N];
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost < e2.cost;
}
void init()
{
    for(int i = 1;i <= n;i++)
        fa[i] = i;
}
int Find(int x)
{
    if(x == fa[x])
        return fa[x];
    else
        return fa[x] = Find(fa[x]);
}
void mix(int x,int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if(fx == fy)
        return ;
    fa[fy] = fx;
}
int kruskal()
{
    sort(es,es+m,cmp);
    init();
    int Eg[MAX_N],k = 0;
    int ans = 0;
    for(int i = 0;i < m;i++)
    {
        edge e = es[i];
        if(Find(e.u)!=Find(e.v))
        {
            mix(e.u,e.v);
            ans+=e.cost;
            Eg[k++] = i;
        }
    }
    int smst,num;
    for(int i = 0;i < k;i++)
    {
        init();
        smst = 0;
        num = 0;
        for(int j = 0;j < m;j++)
        {
            if(j == Eg[i]) continue;
            if(Find(es[j].u)!=Find(es[j].v))
            {
                mix(es[j].u,es[j].v);
                smst += es[j].cost;
                num++;
            }
        }
        if(num!=k) continue;
        if(smst == ans)
        {
            return -1;
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int x,y,w;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            es[i].u = x;
            es[i].v = y;
            es[i].cost = w;
        }
        int ans = kruskal();
        if(ans == -1)
            puts("Not Unique!");
        else
            printf("%d\n",ans);
    }
    return 0;
}
