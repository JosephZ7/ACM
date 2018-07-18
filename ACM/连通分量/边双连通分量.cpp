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
const int MAX_N = 1e3+10;
const LL mod = 1e9+7;
const double eps = 1e-6;
using namespace std;
struct node
{
    int to,next;
}es[MAX_N<<1];
int e,head[MAX_N];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
int dfn[MAX_N],low[MAX_N],id,vc;
int stk[MAX_N];
stack<int> s;
void tarjan(int u,int fa)
{
    id++;
    dfn[u] = low[u] = id;
    s.push(u);
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
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
        int v;
        vc++;
        do
        {
            v = s.top(); s.pop();
            stk[v] = vc;
        }while(u!=v);
    }
}
int in[MAX_N];
int main()
{
    memset(head,-1,sizeof(head));
    memset(stk,0,sizeof(stk));
    memset(in,0,sizeof(in));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    id = e = 0;
    vc = 0;
    int n,m;
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    tarjan(1,-1);
    for(int i = 1;i <= n;i++)
    {
        for(int j = head[i];j!=-1;j = es[j].next)
        {
            int v = es[j].to;
            if(stk[i]!=stk[v])
                in[stk[v]]++;
        }
    }
    int cnt = 0;
    for(int i = 1;i <= vc;i++)
        if(in[i] == 1) cnt++;
    printf("%d\n",(cnt+1)/2);
    return 0;
}
/*
*/
