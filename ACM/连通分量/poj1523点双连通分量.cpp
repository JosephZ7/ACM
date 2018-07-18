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
}es[MAX_N*MAX_N];
int e,head[MAX_N];
struct edge
{
    int u,v;
};
stack<edge> s;
vector<int> bcc[MAX_N];
int Bcc,bccno[MAX_N];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
int dfn[MAX_N],low[MAX_N],id;
int iscut[MAX_N],son;
void tarjan(int u)
{
    id++;
    dfn[u] = low[u] = id;
    for(int i = head[u];i!=-1;i = es[i].next)
    {
        int v = es[i].to;
        if(!dfn[v])
        {
            s.push(edge{u,v});
            tarjan(v);
            low[u] = min(low[v],low[u]);
            if(low[v] >= dfn[u])
            {
                iscut[u]++;
                Bcc++;
                bcc[Bcc].clear();
                if(u == 1)
                    son++;
                while(!s.empty())
                {
                    edge tmp = s.top(); s.pop();
                    if(bccno[tmp.u]!=Bcc)
                    {
                        bccno[tmp.u] = Bcc;
                        bcc[Bcc].push_back(tmp.u);
                    }
                    if(bccno[tmp.v]!=Bcc)
                    {
                        bccno[tmp.v] = Bcc;
                        bcc[Bcc].push_back(tmp.v);
                    }
                    if(u == tmp.u&&v == tmp.v) break;
                }
            }
        }
        else if(dfn[v] < dfn[u])
        {
            s.push(edge{u,v});
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(son > 1)
        iscut[1] = 1;
}
int main()
{
    int ti = 1;
    int u,v;
    while(scanf("%d",&u)!=EOF)
    {
        if(u == 0) break;
        while(!s.empty()) s.pop();
        son = Bcc = 0;
        memset(head,-1,sizeof(head));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(bccno,0,sizeof(bccno));
        memset(iscut,0,sizeof(iscut));
        for(int i = 0;i < MAX_N;i++)
            bcc[i].clear();
        id = e = 0;
        int Mn = 0;
        scanf("%d",&v);
        Mn = max(u,v);
        addedge(u,v);
        addedge(v,u);
        while(scanf("%d",&u)!=EOF)
        {
            if(u == 0) break;
            scanf("%d",&v);
            Mn = max(Mn,u);
            Mn = max(Mn,v);
            addedge(u,v);
            addedge(v,u);
        }
        printf("Network #%d\n",ti++);

        tarjan(1);
        int flag = 0;
        for(int i = 1;i <= Mn;i++)
        {
            if(i == 1&&son > 1)
            {
                flag = 1;
                printf("  SPF node %d leaves %d subnets\n",i,son);
            }
            else if(i > 1&&iscut[i])
            {
                flag = 1;
                printf("  SPF node %d leaves %d subnets\n",i,iscut[i]+1);
            }
        }
        if(flag == 0)
            printf("  No SPF nodes\n");
        printf("\n");
    }
    return 0;
}
/*
*/
