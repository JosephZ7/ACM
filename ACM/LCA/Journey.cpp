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
const LL mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
struct node
{
    int to,cost,next;
}es[MAX_N*2];
int e,head[MAX_N],vis[MAX_N],ver[MAX_N];
int tot,first[MAX_N],dis[MAX_N],R[MAX_N],dp[MAX_N][40];
void add(int u,int v,int w)
{
    es[e].to = v;
    es[e].cost = w;
    es[e].next = head[u];
    head[u] = e++;
}
void dfs(int u,int dep)
{
    vis[u] = 1;
    ver[++tot] = u;
    first[u] = tot;
    R[tot] = dep;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        if(!vis[v])
        {
            dis[v] = dis[u]+es[i].cost;
            dfs(v,dep+1);
            ver[++tot] = u;
            R[tot] = dep;
        }
    }
}
void ST(int len)
{
    for(int i = 0;i <= len;i++)
        dp[i][0] = i;
    for(int j = 1;(1<<j) <= len;j++)
    {
        for(int i = 1;i +(1<<j)-1 <= len;i++)
        {
            int a = dp[i][j-1];
            int b = dp[i+(1<<(j-1))][j-1];
            dp[i][j] = R[a] < R[b]?a:b;
        }
    }
}
int RMQ(int l,int r)
{
    int k = 0;
    while((1<<(k+1)) <= r-l+1) k++;
    int a = dp[l][k],b = dp[r-(1<<k)+1][k ];
    return R[a] < R[b]?a:b;
}
int LCA(int u,int v)
{
    int x = first[u],y = first[v];
    if(x > y) swap(x,y);
    int f = ver[RMQ(x,y)];
    return dis[u]+dis[v]-2*dis[f];
}
int main()
{
    int T,N,Q,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        tot = e = 0;
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        scanf("%d%d",&N,&Q);
        int u,v,w;
        for(int i = 0;i < N-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        int eu,ev,ew;
        scanf("%d%d%d",&eu,&ev,&ew);
        dis[1] = 0;
        dfs(1,1);
        ST(tot);
        printf("Case #%d:\n",ti++);
        for(int i = 0;i < Q;i++)
        {
            scanf("%d%d",&u,&v);
            int da = LCA(u,v);
            int xi = min(LCA(u,eu)+LCA(v,ev),LCA(u,ev)+LCA(v,eu))+ew;
            printf("%d\n",da-xi<0?0:da-xi);
        }
    }
    return 0;
}
/*
*/
