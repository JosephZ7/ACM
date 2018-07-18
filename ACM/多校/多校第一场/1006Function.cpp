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
const int mod = 1e9+7;
const double eps = 1e-8;
struct node
{
    int to,next;
}es[MAX_N];
int e,head[MAX_N];
int dfn[MAX_N],low[MAX_N],stk[MAX_N],id,vc;
int in[MAX_N],in1[MAX_N],a[MAX_N],b[MAX_N],sum[MAX_N];
int ans[MAX_N];
stack<int> s;
int n,m;
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
void tarjan(int u)
{
    id++;
    dfn[u] = low[u] = id;
    s.push(u);
    int v;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        v = es[i].to;
        if(!dfn[v])
        {
            tarjan(v);
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
        }while(v!=u);
    }
}
void init()
{
    while(!s.empty()) s.pop();
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(stk,0,sizeof(stk));
    e = vc = id = 0;
}
int Ac;
void FindAc()
{
    for(int i = 0;i < n;i++)
        addedge(a[i],i);
    memset(in,0,sizeof(in));
    for(int i = 0;i < n;i++)
        if(!dfn[i]) tarjan(i);
    for(int i = 0;i < n;i++)
        in[stk[i]]++;
    Ac = vc;
}
void FindBc()
{
    for(int i = 0;i < m;i++)
        addedge(b[i],i);
    memset(in1,0,sizeof(in1));
    for(int i = 0;i < m;i++)
        if(!dfn[i]) tarjan(i);
    for(int i = 0;i < m;i++)
        in1[stk[i]]++;
    for(int i = 1;i <= vc;i++)
        sum[in1[i]]+=in1[i];
}
int main()
{
    int ti = 1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(sum,0,sizeof(sum));
        memset(ans,0,sizeof(ans));
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        for(int i = 0;i < m;i++)
            scanf("%d",&b[i]);
        init(); FindAc();
        init(); FindBc();
        for(int i = 1;i <= Ac;i++)
        {
            for(int j = 1;j*j <= in[i];j++)
            {
                if(in[i]%j == 0)
                {
                    ans[i]+=sum[j];
                    if(in[i]/j!=j)
                        ans[i]+=sum[in[i]/j];
                }
            }
        }
        LL ANS = 1;
        for(int i = 1;i <= Ac;i++)
            ANS = ANS*ans[i]%mod;
        printf("Case #%d: %I64d\n",ti++,ANS);
    }
    return 0;
}
/*
*/
