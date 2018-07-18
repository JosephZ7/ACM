#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
const int MAX_N = 1e6+10;
const int mod = 100;
const double eps = 1e-6;
using namespace std;
int n,k;
struct node
{
    int to,next;
    LL w;
}es[MAX_N*4];
int e,head[MAX_N],son[MAX_N];
void addedge(int u,int v,LL w)
{
    es[e].to = v;
    es[e].w = w;
    es[e].next = head[u];
    head[u] = e++;
}
LL ans;
void dfs(int u,int fa)
{
    son[u] = 1;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        LL w = es[i].w;
        if(v == fa) continue;
        dfs(v,u);
        son[u]+=son[v];
        LL t = min(son[v],k);
        ans+=t*w;
    }
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        e = 0; memset(head,-1,sizeof(head));
        memset(son,0,sizeof(son));
        int u,v;
        LL w;
        for(int i = 0;i < n-1;i++)
        {
            scanf("%d%d%lld",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        ans = 0;
        dfs(1,-1);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
*/
