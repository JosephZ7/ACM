#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<stack>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX_N = 1e5+10;
const LL inf = 0x7fffffffffffffff;
struct node
{
    LL x,y,r;
    int c;
}a[1005];
struct edge
{
    int to,next;
}es[2000005];
int e,head[2005];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
LL getdist(node e1,node e2)
{
    return (e1.x-e2.x)*(e1.x-e2.x)+(e1.y-e2.y)*(e1.y-e2.y);
}
int dfn[1005],low[1005],deg[1005];
int ans,scn[1005],id,vc;
int in[1005];
stack<int> s;
void tarjan(int u)
{
    dfn[u] = low[u] = ++id;
    s.push(u);
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(!scn[v])
            low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        vc++;
        int v;
        do
        {
            v = s.top(); s.pop();
            scn[v] = vc;
        }while(v!=u);
    }
}
void init()
{
    e = id = vc = 0;
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(deg,0,sizeof(deg));
    memset(scn,0,sizeof(scn));
    memset(in,0,sizeof(in));
    while(!s.empty()) s.pop();
}
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        ans = 0;
        init();
        int N;
        scanf("%d",&N);
        for(int i = 1;i <= N;i++)
        {
            scanf("%lld%lld%lld%d",&a[i].x,&a[i].y,&a[i].r,&a[i].c);
        }
        for(int i = 1;i <= N;i++)
        {
            for(int j = i+1;j <= N;j++)
            {
                if(getdist(a[i],a[j]) <= a[i].r*a[i].r)
                    addedge(i,j),deg[j]++;
                if(getdist(a[i],a[j]) <= a[j].r*a[j].r)
                    addedge(j,i),deg[i]++;
            }
        }
        for(int i = 1;i <= N;i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        for(int i = 1;i <= N;i++)
        {
            for(int j = head[i];j!=-1;j = es[j].next)
            {
                int v = es[j].to;
                if(scn[i]!=scn[v])
                    in[scn[v]]++;
            }
        }
        for(int i = 1;i <= vc;i++)
        {
            if(in[i] == 0)
            {
                int Mi = 1e9;
                for(int j = 1;j <= N;j++)
                {
                    if(scn[j] == i)
                        Mi = min(Mi,a[j].c);
                }
                ans+=Mi;
            }
        }
        printf("Case #%d: %d\n",ti++,ans);
    }
    return 0;
}
/*
*/
