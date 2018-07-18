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
const int MAX_N = 1e3+10;
const LL inf = 1e15+10;
const LL mod = 1e6+3;
const double eps = 1e-8;
int N,M;
int a[MAX_N];
struct node
{
    int to,next;

}es[MAX_N*4];
int e,head[MAX_N];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
int in[MAX_N];
int low[MAX_N],dfn[MAX_N],id,stk[MAX_N],vc;
stack<int> s;
void tarjan(int u)
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
            tarjan(v);
            low[u] = min(low[v],low[u]);
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
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        memset(low,0,sizeof(low));
        memset(dfn,0,sizeof(dfn));
        memset(stk,0,sizeof(stk));
        while(!s.empty()) s.pop();
        e = id = 0;
        vc = 0;
        memset(in,0,sizeof(in));
        memset(head,-1,sizeof(head));
        for(int i = 1;i <= N;i++)
        {
            scanf("%d",&a[i]);
        }
        int u,v;
        for(int i = 0;i < M;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        for(int i = 1;i <= N;i++)
            if(!dfn[i])
                tarjan(i);
        for(int i = 1;i <= N;i++)
        {
            for(int j = head[i];j!=-1;j = es[j].next)
            {
                int v = es[j].to;
                if(stk[v] != stk[i])
                    in[stk[v]]++;
            }
        }
        int Micon = 0,Mcost = 0;
        for(int i = 1;i <= vc;i++)
        {
            if(in[i] == 0)
            {
                int Mi = INF;
                for(int j = 1;j <= N;j++)
                    if(stk[j] == i&&Mi > a[j])
                        Mi = a[j];
                Micon++;
                Mcost+=Mi;
            }
        }
        printf("%d %d\n",Micon,Mcost);
    }
    return 0;
}
