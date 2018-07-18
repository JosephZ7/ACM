
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
int root;
int low[MAX_N],dfn[MAX_N],id;
bool is[MAX_N];
void tarjan(int u,int fa)
{
    id++;
    low[u] = dfn[u] = id;
    int son = 0;
    int v;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        v = es[i].to;
        if(!dfn[v])
        {
            tarjan(v,u);
            son++;
            low[u] = min(low[v],low[u]);
            if(u == root&&son > 1||(u!=root&&dfn[u] <= low[v]))
                is[u] = true;
        }
        else if(v!=fa)
            low[u] = min(low[u],dfn[v]);
    }
}

int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        if(N == 0) break;
        memset(low,0,sizeof(low));
        memset(dfn,0,sizeof(dfn));
        e = id = 0;
        memset(is,false,sizeof(is));
        memset(head,-1,sizeof(head));
        int u,v;
        while(scanf("%d",&u),u)
        {
            while(getchar()!='\n')
            {
                scanf("%d",&v);
                addedge(u,v);
                addedge(v,u);
            }
        }
        root = 1;
        tarjan(1,-1);
        int sum = 0;
        for(int i = 1;i <= N;i++)
            if(is[i])
                sum++;
        cout<<sum<<endl;
    }
    return 0;
}
