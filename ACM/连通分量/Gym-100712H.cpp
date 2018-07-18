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
const int MAX_N = 1e5+10;
const LL inf = 1e15+10;
const LL mod = 1e6+3;
const double eps = 1e-8;
struct node
{
    int to,next;
}es[MAX_N*10];
int e,head[MAX_N];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
int in[MAX_N];
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
        if(v == fa) continue;
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
        }while(u!=v);
    }
}
int mlen,st;
void Findmax(int u,int fa,int len)
{
    if(mlen < len) st = u,mlen = len;
    for(int i = 0;i < G[u].size();i++)
    {
        int v = G[u][i];
        if(v == fa) continue;
        Findmax(v,u,len+1);
    }
}
void init()
{
    while(!s.empty()) s.pop();
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(stk,0,sizeof(stk));
    memset(in,0,sizeof(in));
    memset(head,-1,sizeof(head));
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
            addedge(u,v);
            addedge(v,u);
        }
        tarjan(1,-1);
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = head[i];j!=-1;j = es[j].next)
            {
                v = es[j].to;
                //printf("u:%d stk[u]: %d v:%d stk[v]: %d\n",i,stk[i],v,stk[v]);
                if(stk[i]!=stk[v])
                {
                    cnt++;
                    G[stk[i]].push_back(stk[v]);
                }
            }
        }
        mlen = -1;
        Findmax(1,-1,0);
        Findmax(st,-1,0);
        printf("%d\n",cnt/2-mlen);
    }
    return 0;
}
/*
2
7 7
1 2
2 3
3 1
3 4
4 5
4 6
6 7
3 3
1 2
2 3
3 1
*/
