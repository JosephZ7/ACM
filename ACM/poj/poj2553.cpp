#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 5500;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
struct edge
{
    int to,next;
};
edge es[MAX_N*MAX_N];
int head[MAX_N],e;
int dfn[MAX_N],low[MAX_N],cnt;
int Stack[MAX_N],top;
int instack[MAX_N],belong[MAX_N],index;
int out[MAX_N],ans[MAX_N];
int V,E;
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
void tarjan(int u)
{
    int i,v;
    low[u] = dfn[u] = cnt++;
    instack[u] = 1;
    Stack[++top] = u;
    for(i = head[u];i!=-1;i = es[i].next)
    {
        v = es[i].to;
        if(dfn[v] == -1)
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(instack[v])
            low[u] = min(low[u],dfn[v]);
    }

    if(low[u] == dfn[u])
    {
        index++;
        do
        {
            v = Stack[top--];
            belong[v] = index;

        }while(top!=0&&v!=u);
    }
}
int main()
{
    int flag;
    while(scanf("%d%d",&V,&E)&&V)
    {
        flag = 1;
        int v,w;
        e = 0; cnt = 1; top = 0; index = 0;
        mem(head,-1); mem(dfn,-1);
        mem(low,-1); mem(instack,0);
        mem(belong,0); mem(out,0);
        mem(ans,0);
        for(int i = 1;i <= E;i++)
        {
            scanf("%d%d",&v,&w);
            addedge(v,w);
        }
        for(int i = 1;i <= V;i++)
            if(dfn[i] == -1)
                tarjan(i);
        for(int i = 1;i <= V;i++)
        {
            for(int j = head[i];j!=-1;j = es[j].next)
            {
                v = es[j].to;
                if(belong[i]!=belong[v])
                    out[belong[i]]++;
            }
        }
        for(int i = 1;i <= V;i++)
        {
            if(!out[belong[i]])
            {
                if(flag)
                {
                    printf("%d",i);
                    flag = 0;
                }
                else
                    printf(" %d",i);
            }
        }
        cout<<endl;
    }
    return 0;
}
