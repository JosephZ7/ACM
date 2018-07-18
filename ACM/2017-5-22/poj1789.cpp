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
const int MAX_N = 4e6+10;
const double eps = 1e-7;
const int mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
int fa[MAX_N/2];
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
char s[MAX_N][10];
int getcost(int p1,int p2)
{
    int num = 0;
    for(int i = 0;i < 7;i++)
    {
        if(s[p1][i]!=s[p2][i])
            num++;
    }
    return num;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0) break;
        k = 0;
        init(n);
        int x;
        for(int i = 1;i <= n;i++)
        {
            scanf("%s",s[i]);
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = i+1;j <= n;j++)
            {
                es[k].u = i;
                es[k].v = j;
                es[k++].cost = getcost(i,j);
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
        printf("The highest possible quality is 1/%d.\n",ans);
    }

    return 0;
}

