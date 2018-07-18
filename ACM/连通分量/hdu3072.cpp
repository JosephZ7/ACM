#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
const int MAX_N = 5e4+10;
const LL mod = 1e9+7;
const double eps = 1e-6;
using namespace std;
struct node
{
    int to,next,w;

}es[MAX_N<<2];
int e,head[MAX_N];
void addedge(int u,int v,int w)
{
    es[e].to = v;
    es[e].next = head[u];
    es[e].w = w;
    head[u] = e++;
}
int dfn[MAX_N],low[MAX_N],id,vc;
int stk[MAX_N];
stack<int> s;
void tarjan(int u)
{
    id++;
    dfn[u] = low[u] = id;
    s.push(u);
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[v],low[u]);
        }
        else if(!stk[v])
            low[u] = min(dfn[v],low[u]);
    }
    if(dfn[u] == low[u])
    {
        int v;
        vc++;
        do
        {
            v = s.top(); s.pop();
            stk[v] = vc;
        }while(u!=v);
    }
}
int in[MAX_N],cost[MAX_N];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        memset(stk,0,sizeof(stk));
        memset(in,0,sizeof(in));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        for(int i = 1;i <= n;i++)
            cost[i] = INF;
        id = e = 0;
        vc = 0;
        int u,v,w;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u+1,v+1,w);
        }
        for(int i = 1;i <= n;i++)
            if(!dfn[i]) tarjan(i);
        for(int i = 1;i <= n;i++)
        {
            for(int j = head[i];j!=-1;j = es[j].next)
            {
                int v = es[j].to;
                //cout<<v<<endl;
                int w = es[j].w;
                if(stk[i]!=stk[v])
                {
                    in[stk[v]]++;
                    cost[stk[v]] = min(w,cost[stk[v]]);
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= vc;i++)
        {
            if(in[i])
                ans+=cost[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
*/
