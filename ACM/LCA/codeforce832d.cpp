#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <iostream>
#define PI acos(-1)
#define LL long long
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
int up[MAX_N][30];
struct node
{
    int to,next;
}es[MAX_N*4];
int e,head[MAX_N];
int dis[MAX_N],dep[MAX_N];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
void dfs(int u,int fa,int deep)
{
    dep[u] = deep;
    for(int i = 1;i < 20;i++)
        up[u][i] = up[up[u][i-1]][i-1];
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        if(v == fa) continue;
        up[v][0] = u;
        dfs(v,u,deep+1);
    }
}
int kth(int u,int k)
{
    for(int i = 0;i < 20;i++)
    {
        if((1<<i)&k)
            u = up[u][i];
    }
    return u;
}
int LCA(int x,int y)
{
    if(dep[x] < dep[y]) swap(x,y);
    int k = dep[x]-dep[y];
    x = kth(x,k);
    if(x!=y)
    {
        for(int i = 19;i >= 0;i--)
        {
            if(up[x][i]!=up[y][i])
            {
                x = up[x][i];
                y = up[y][i];
            }
        }
        x = up[x][0];
    }
    return x;
}
int getMa(int s,int t,int f)
{
    int lca1 = LCA(s,f),lca2 = LCA(t,f);
    int ans = dep[f]-max(dep[lca1],dep[lca2])+1;
    if(lca1 == lca2)
        ans+=dep[LCA(s,t)]-dep[lca1];
    return ans;
}
int main()
{
    e = 0;
    memset(head,-1,sizeof(head));
    int n,m;
    scanf("%d%d",&n,&m);
    int u;
    for(int i = 2;i <= n;i++)
    {
        scanf("%d",&u);
        addedge(u,i);
        addedge(i,u);
    }
    up[1][0] = 1;
    dfs(1,-1,0);
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int Ma = max(getMa(a,b,c),getMa(b,c,a));
        cout<<max(Ma,getMa(c,a,b))<<endl;
    }
    return 0;
}
/*
*/
