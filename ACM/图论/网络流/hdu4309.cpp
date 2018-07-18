#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#define LL long long
#define INF 0x7fffffff
using namespace std;
const int MAX_N = 1e4+10;
const LL inf = 1e15+10;
const LL mod = 1e6+3;
struct edge
{
    int u,v,cap,next;
    edge(){}
    edge(int _u,int _v,int _cap,int _next)
    {
        u = _u;v = _v; cap = _cap; next = _next;
    }
}es[MAX_N],tes[MAX_N];

int N,M;
int e,head[205],cur[205],thead[205];
int d[205],ed,st,b,bc[205],bp[205];
void addedge(int u,int v,int w)
{
    es[e] = edge(u,v,w,head[u]);
    head[u] = e++;
    es[e] = edge(v,u,0,head[v]);
    head[v] = e++;
}
int q[205];
int BFS()
{
    int frt = 0,rear = 0;
    memset(d,-1,sizeof(d));
    d[st] = 0;
    q[frt++] = st;
    while(rear < frt)
    {
        int u = q[rear++];
        for(int i = head[u];i!=-1;i = es[i].next)
        {
            int v = es[i].v;
            if(d[v] == -1&&es[i].cap > 0)
            {
                d[v] = d[u]+1;
                q[frt++] = v;
                if(v == ed) return 1;
            }
        }
    }
    return d[ed]!=-1;
}
int DFS(int s,int c)
{
    if(s == ed) return c;
    int f,tmp = c;
    for(int &i = cur[s];i!=-1&&c;i = es[i].next)
    {
        int v = es[i].v;
        if(d[v] == d[s]+1&&es[i].cap > 0&&(f = DFS(v,min(c,es[i].cap))) > 0)
        {
            es[i].cap -=f;
            es[i^1].cap +=f;
            c-=f;
        }
    }
    return tmp-c;
}
int max_flow()
{
    int flow = 0,k;
    while(BFS())
    {
        memcpy(cur,head,sizeof(head));
        flow+=DFS(st,INF);
    }
    return flow;
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        int u,v,p,w;
        memset(head,-1,sizeof(head));
        e = 0;  b = 0;
        st = 204,ed = 203;
        for(int i = 1;i <= N;i++)
        {
            scanf("%d",&w);
            addedge(st,i,w);
        }
        int point = N+1;
        for(int i = 0;i < M;i++)
        {
            scanf("%d%d%d%d",&u,&v,&w,&p);
            if(p < 0)
            {
                addedge(u,point,INF);
                addedge(point,v,INF);
                addedge(point,ed,w);
                ++point;
            }
            else if(p == 0)
                addedge(u,v,INF);
            else
            {
                bp[b] = e;
                bc[b] = w;
                addedge(u,v,1);
                b++;
            }
        }
        memcpy(tes,es,sizeof(tes));
        memcpy(thead,head,sizeof(thead));
        int Mnumber = -INF,Micost = INF;
        for(int i = 0;i < (1<<b);i++)
        {
            memcpy(es,tes,sizeof(es));
            memcpy(head,thead,sizeof(head));
            int cost = 0;
            for(int j = 0;j < b;j++)
            {
                if(i&(1<<j))
                {
                    cost +=bc[j];
                    es[bp[j]].cap = INF;
                }
            }
            int num = max_flow();
            if(num > Mnumber)
            {
                Mnumber = num;
                Micost = cost;
            }
            else if(num == Mnumber)
                Micost = min(Micost,cost);
        }
        if(Mnumber > 0)
            printf("%d %d\n",Mnumber,Micost);
        else
            printf("Poor Heaven Empire\n");
    }
    return 0;
}
