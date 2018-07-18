#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#define PI 3.1415926535898
#define LL long long int
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e6+10;
const double eps = 1e-7;
const LL mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
int d[MAX_N],vis[MAX_N],N,M;
int Stk[MAX_N],top;
struct node
{
    int to,cost,next;
}es[MAX_N];
int e;
int head[MAX_N];
void SPFA(int s)
{
    for(int i = 0;i <= N;i++)
        d[i] = INF;
    d[s] = 0;
    top = 0;
    vis[s] = 1;
    Stk[++top] = s;
    while(top > 0)
    {
        int u = Stk[top];
        top--;
        vis[u] = 0;
        for(int i = head[u];i!=-1;i = es[i].next)
        {
            int v = es[i].to;
            int w = es[i].cost;
            if(d[v] > d[u]+w)
            {
               d[v] = d[u]+w;
               if(!vis[v])
               {
                   vis[v] = 1;
                   Stk[++top] = v;
               }
            }
        }
    }
}
void add(int u,int v,int w)
{
    es[e].to = v;
    es[e].cost = w;
    es[e].next = head[u];
    head[u] = e++;
}
int main()
{
    memset(head,-1,sizeof(head));
    e = 0;
    scanf("%d%d",&N,&M);
    int u,v,w;
    for(int i = 0;i < M;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    SPFA(1);
    printf("%d\n",d[N]);
    return 0;
}
