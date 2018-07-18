#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#define LL long long
#define INF 0x7fffffff
using namespace std;
const int MAX_N = 1e4+10;
const LL inf = 1e15+10;
const LL mod = 1e6+3;
const double eps = 1e-8;
struct node
{
    int to,next;
}es[MAX_N*10];
int e,head[MAX_N],cnt[MAX_N];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
int in[MAX_N],pos[MAX_N],sum1[MAX_N],sum2[MAX_N];
stack<int> s;
vector<int> G[MAX_N];
int low[MAX_N],dfn[MAX_N],id,vc,stk[MAX_N];
void tarjan(int u,int fa)
{
    id++;
    low[u] = dfn[u] = id;
    s.push(u);
    int v;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        v = es[i].to;
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
        }
        else if(!stk[v])
            low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        vc++;
        do
        {
            v = s.top(); s.pop();
            stk[v] = vc;
            sum1[vc]++;
        }while(u!=v);
    }
}
int vis[MAX_N];
int dfs(int u)
{
    int sum = 0;
    for(int i = 0;i < G[u].size();i++)
    {
        int v = G[u][i];
        if(vis[v]) continue;
        vis[v] = 1;
        sum+=sum1[v];
        sum+=dfs(v);
    }
    return sum;
}
void init()
{
    while(!s.empty()) s.pop();
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(stk,0,sizeof(stk));
    memset(in,0,sizeof(in));
    memset(head,-1,sizeof(head));
    memset(sum1,0,sizeof(sum1));
    memset(sum2,0,sizeof(sum2));
    vc = id = e = 0;
}
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        init();
        int n,m;
        scanf("%d%d",&n,&m);
        int u,v;
        for(int i = 0;i <= n;i++)
            G[i].clear();
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u+1,v+1);
        }
        for(int i = 1;i <= n;i++)
            if(!dfn[i])
                tarjan(i,-1);
        for(int i = 1;i <= n;i++)
        {
            for(int j = head[i];j!=-1;j = es[j].next)
            {
                v = es[j].to;
                if(stk[i]!=stk[v])
                {
                    G[stk[v]].push_back(stk[i]);
                    in[stk[i]]++;
                }
            }
        }
        int ans = 0,Ma = -1;
        int k = 0;
        for(int i = 1;i <= vc;i++)
        {
            if(in[i]) continue;
            memset(vis,0,sizeof(vis));
            sum2[i] = dfs(i);
        }
        for(int i = 1;i <= n;i++)
            Ma = max(Ma,sum1[stk[i]]+sum2[stk[i]]-1);

        for(int i = 1;i <= n;i++)
            if(sum1[stk[i]]+sum2[stk[i]]-1 == Ma)
                pos[k++] = i;
        printf("Case %d: %d\n",ti++,Ma);
        sort(pos,pos+k);
        for(int i = 0;i < k;i++)
        {
            if(i == k-1)
                printf("%d\n",pos[i]-1);
            else
                printf("%d ",pos[i]-1);
        }
    }
    return 0;
}
/*
*/
