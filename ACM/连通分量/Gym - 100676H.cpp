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
    LL w;
}es[MAX_N*4],es2[MAX_N*4];
int head[MAX_N],e,e2,head2[MAX_N];
int id,low[MAX_N],dfn[MAX_N],stk[MAX_N],vc,vis[MAX_N];
LL dis[MAX_N][2];
void addedge(int u,int v,LL w)
{
    es[e].to = v;
    es[e].w = w;
    es[e].next = head[u];
    head[u] = e++;
}
void addedge2(int u,int v,LL w)
{
    es2[e2].to = v;
    es2[e2].w = w;
    es2[e2].next = head2[u];
    head2[u] = e2++;
}
stack<int> s;
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
            low[u] = min(low[v],low[u]);
        }
        else if(v!=fa)
            low[u] = min(dfn[v],low[u]);
    }
    if(dfn[u] == low[u])
    {
        vc++;
        do
        {
            v = s.top(); s.pop();
            stk[v] = vc;
            vis[vc] = min(vis[vc],v);
        }while(u!=v);
    }
}
LL mlen;
int st,ed;
void Findmax(int u,int fa,LL len,int f)
{
    dis[u][f] = len;
    if(f&&mlen < len)
    {
        st = u;
        mlen = len;
    }
    for(int i = head2[u];i!=-1;i = es2[i].next)
    {
        int v = es2[i].to;
        LL w = es2[i].w;
        if(v == fa) continue;
        Findmax(v,u,len+w,f);
    }
}
void init(int n)
{
    while(!s.empty()) s.pop();
    memset(head,-1,sizeof(head));
    memset(head2,-1,sizeof(head2));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(stk,0,sizeof(stk));
    memset(dis,0,sizeof(dis));
    e = id = vc = 0;
    e2 = 0;
    for(int i = 0;i <= n;i++)
        vis[i] = INF;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        init(n);
        int a,b;
        LL c;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%lld",&a,&b,&c);
            addedge(a,b,c);
            addedge(b,a,c);
        }
        tarjan(1,-1);
        for(int i = 1;i <= n;i++)
        {
            for(int j = head[i];j!=-1;j = es[j].next)
            {
                int v = es[j].to;
                LL w = es[j].w;
                if(stk[i]!=stk[v])
                {
                    //printf("u:%d:  %d v:%d: %d\n",i,stk[i],v,stk[v]);
                    addedge2(stk[i],stk[v],w);
                }
            }
        }
        mlen = -1;
        Findmax(1,-1,0,1);
        ed = st;
        mlen = -1;
        Findmax(st,-1,0,1);
        swap(st,ed);
        Findmax(ed,-1,0,0);
        int num = 0;
        LL alen = inf;
        for(int i = 1;i <= vc;i++)
        {
           // printf("%I64d %I64d\n",dis[i][0],dis[i][1]);
            if(alen > max(dis[i][0],dis[i][1]))
            {
                alen = max(dis[i][0],dis[i][1]);
                num = vis[i];
            }
            else if(alen == max(dis[i][0],dis[i][1]))
                num = min(num,vis[i]);
        }
        printf("%d %lld\n",num,alen);
    }
    return 0;
}
/*
*/
