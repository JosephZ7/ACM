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
const int MAX_N = 1e6+10;
const LL inf = 1e15+10;
const LL mod = 1e6+3;
struct edge
{
    int v,cap,next;
    edge(){}
    edge(int _v,int _cap,int _next)
    {
        v = _v; cap = _cap; next = _next;
    }
}es[1515151];

int N,M;
int e,head[MAX_N/10],cur[MAX_N];
int d[MAX_N/10],ed,st;
void addes(int u,int v,int w)
{
    es[e] = edge(v,w,head[u]);
    head[u] = e++;
    es[e] = edge(u,0,head[v]);
    head[v] = e++;
}
int BFS()
{
    memset(d,0,sizeof(d));
    d[st] = 1;
    queue<int> q;
    q.push(st);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = head[u];i!=-1;i = es[i].next)
        {
            int v = es[i].v;
            if(d[v] == 0&&es[i].cap)
            {
                d[v] = d[u]+1;
                q.push(v);
                if(v == ed) return 1;
            }
        }
    }
    return 0;
}
int DFS(int s,int c)
{
    if(s == ed||c == 0) return c;
    int f,flow = 0;
    for(int &i = cur[s];i!=-1;i = es[i].next)
    {
        int v = es[i].v;
        if(d[v] == d[s]+1&&es[i].cap > 0)
        {
            f = DFS(v,min(c-flow,es[i].cap));
            flow+=f;
            es[i].cap -=f;
            es[i^1].cap +=f;
            if(flow == c) return flow;
        }
    }
    return flow;
}
int max_flow()
{
    int flow = 0,k;
    while(BFS() == 1)
    {
        memcpy(cur,head,sizeof(head));
        k = DFS(st,INF);
        if(k == 0) break;
        flow+=k;
    }
    return flow;
}
int a[205][205];
int main()
{
    int ti = 1;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        e = 0;
        memset(head,-1,sizeof(head));
        st = N*M+1;
        ed = N*M+2;
        for(int i = 0;i < N;i++)
            for(int j = 0;j < M;j++)
                scanf("%d",&a[i][j]);
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < M;j++)
            {
                if(a[i][j] == 2)
                    addes(i*M+j,ed,INF);
                if(a[i][j] == 1)
                    addes(st,i*M+j,INF);

                if(i-1 >= 0)
                    addes(i*M+j,(i-1)*M+j,1);
                if(i+1 < N)
                    addes(i*M+j,(i+1)*M+j,1);
                if(j+1 < M)
                    addes(i*M+j,i*M+j+1,1);
                if(j-1 >= 0)
                    addes(i*M+j,i*M+j-1,1);
            }
        }
        printf("Case %d:\n",ti++);
        printf("%d\n",max_flow());
    }
    return 0;
}
