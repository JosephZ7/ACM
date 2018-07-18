#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#define PI 3.1415926535898
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e6+10;
const double eps = 1e-7;
const int mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
int fa[MAX_N];
void init(int n)
{
    for(int i = 0;i <= n;i++)
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
struct node
{
    int u,v;
    double cost;
}es[MAX_N];
int k;
bool cmp(const node &x,const node &y)
{
    return x.cost < y.cost;
}
int p[MAX_N];
int main()
{
    int n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        k = 0;
        init(n);
        int x;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&p[i]);
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                scanf("%d",&x);
                if(i!=j)
                {
                    es[k].u = i;
                    es[k].v = j;
                    es[k++].cost = x+p[i]+p[j];
                }
            }
        }
        sort(es,es+k,cmp);
        int ans = 0;
        for(int i = 0;i < k;i++)
        {
            if(Find(es[i].u) != Find(es[i].v))
            {
                mix(es[i].u,es[i].v);
                ans+=es[i].cost;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

