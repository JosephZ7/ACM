#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <time.h>
#include <algorithm>
#include <iostream>
#define PI acos(-1.0)
#define LL long long
#define INF 0x7fffffff
using namespace std;
const int MAX_N = 1e6+10;
const LL inf = 1e15+10;
const LL mod = 1e6+3;
const double eps = 1e-8;
struct edge
{
    int v,cap,u,next;
    edge(){}
    edge(int _u,int _v,int _cap,int _next)
    {
        u = _u; v = _v; cap = _cap; next = _next;
    }
}es[MAX_N];
int N,M;
int e,head[2000];
int d[2000];
void addedge(int u,int v,int w)
{
    es[e] = edge(u,v,w,head[u]);
    head[u] = e++;
    es[e] = edge(v,u,0,head[v]);
    head[v] = e++;
}

int BFS(int s,int t)
{
    memset(d,-1,sizeof(d));
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = head[u];i!=-1;i = es[i].next)
        {
            int v = es[i].v;
            if(d[v] == -1&&es[i].cap > 0)
            {
                d[v] = d[u]+1;
                if(v == t) return 1;
                q.push(v);
            }
        }
    }
    return 0;
}
int DFS(int s,int c,int t)
{
    if(s == t) return c;
    int flow = 0,f;
    for(int i = head[s];~i;i = es[i].next)
    {
        int v = es[i].v;
        if(es[i].cap > 0&&d[v] == d[s]+1&&(f = DFS(v,min(c,es[i].cap),t)) > 0)
        {
            es[i].cap -=f;
            es[i^1].cap+=f;
            flow+=f;
            if(flow == c) break;
        }
    }
    return flow;
}
int max_flow(int s,int t)
{
    int flow = 0,k;
    while(BFS(s,t))
    {
        //cout<<BFS(s,t)<<endl;
        while(k = DFS(s,INF,t))
            flow+=k;
    }
    return flow;
}
int P[2005],S[2005],E[2005];
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        e = 0;
        memset(head,-1,sizeof(head));
        scanf("%d%d",&N,&M);
        int sum = 0,Ma = 0,s = INF,t = -1;
        for(int i = 0;i < N;i++)
        {
            scanf("%d%d%d",&P[i],&S[i],&E[i]);
            t = max(E[i],t);
            s = min(S[i],s);
            sum+=P[i];
        }
        int ed = t*2+1;
        for(int i = s;i <= t;i++)
            addedge(0,i,M);
        for(int i = 0;i < N;i++)
        {
            for(int j = S[i];j <= E[i];j++)
            {
                addedge(j,j+t,1);
                addedge(j+t,ed,P[i]);
            }
        }
        int ans = max_flow(0,ed);
        //cout<<ans<<endl;
        printf("Case %d: ",ti++);
        if(sum <= ans)
            printf("Yes\n");
        else
            printf("No\n");
        printf("\n");
    }
    return 0;
}
