#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a) memset(a,0,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
struct edge
{
    int from,to,cost;
    bool operator <(const edge &a) const
    {
        return cost < a.cost;
    }
}es[10005];
int fa[105];
int Find(int x)
{
    if(x == fa[x])
        return x;
    return fa[x] = Find(fa[x]);
}
int main()
{
    int n,m,u,v,w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n == 0&&m == 0) break;
        for(int i = 0;i < m;i++)
            scanf("%d%d%d",&es[i].from,&es[i].to,&es[i].cost);
        sort(es,es+m);
        int ans = INF;
        for(int i = 0;i <= m-n+1;i++)
        {
            int tmp = -1,sum = 0;
            for(int j = 1;j <= n;j++)
                fa[j] = j;
            for(int j = i;j < m;j++)
            {
                int fx = Find(es[j].from);
                int fy = Find(es[j].to);
                if(fx!=fy)
                {
                    sum++;
                    fa[fx] = fy;
                    if(sum == n-1)
                    {
                        tmp = es[j].cost-es[i].cost;
                        break;
                    }
                }
            }
            if(tmp!=-1&&tmp < ans)
                ans = tmp;
        }
        if(ans != INF)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
