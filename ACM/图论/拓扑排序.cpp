#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=30;

int head[maxn],ip,indegree[maxn];
int n,m,seq[maxn];

struct note
{
    int v,next;
} edge[maxn*maxn];

void init()
{
    memset(head,-1,sizeof(head));
    ip=0;
}

void addedge(int u,int v)
{
    edge[ip].v=v,edge[ip].next=head[u],head[u]=ip++;
}

int topo()//拓扑，可做模板
{
    queue<int>q;
    int indeg[maxn];
    for(int i=0; i<n; i++)
    {
        indeg[i]=indegree[i];
        if(indeg[i]==0)
            q.push(i);
    }
    int k=0;
    bool res=false;
    while(!q.empty())
    {
        if(q.size()!=1)res=true;
        int u=q.front();
        q.pop();
        seq[k++]=u;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].v;
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }
    if(k<n)return -1;//存在有向环，总之不能进行拓扑排序
    if(res)return 0;//可以进行拓扑排序，并且只有唯一一种方式，seq数组即是排序完好的序列
    return 1;//可以进行拓扑排序，有多种情况，seq数组是其中一种序列
}
