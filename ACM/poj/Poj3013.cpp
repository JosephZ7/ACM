#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 5e5+10;
const double eps = 1e-7;
const LL mod = 1000000009;
const LL inf = 1LL<<60;
using namespace std;
int V,E;
struct node
{
    int to,next;
    LL cost;
}es[MAX_N<<1];

int e,head[MAX_N];
int vis[MAX_N];
LL pr[MAX_N];
LL d[MAX_N];

void SPFA()
{
    int s = 1;
    queue<int> q;
    d[s] = 0;
    vis[s] = 1;
    q.push(s);
    int u,v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u];i!=-1;i = es[i].next)
        {
            v = es[i].to;
            if(d[u]+es[i].cost < d[v])
            {
                d[v] = d[u]+es[i].cost;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
void add(int u,int v,LL w)
{
    es[e].to = v;
    es[e].cost = w;
    es[e].next = head[u];
    head[u] = e++;
}
void init()
{
    e = 0;
    for(int i = 0;i <= V+1;i++)
            d[i] = inf;
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&V,&E);
        init();
        for(int i = 1;i <= V;i++)
            cin>>pr[i];

        int u,v;
        LL w;
        for(int i = 0;i < E;i++)
        {
            scanf("%d%d",&u,&v);
            cin>>w;
            add(u,v,w);
            add(v,u,w);
        }
        SPFA();
        int flag = 0;
        LL ans = 0;
        //for(int i = 1;i <= V;i++)
            //printf("%d ",d[i]);
        for(int i = 2;i <= V;i++)
        {
            if(d[i] == inf)
            {
                flag = 1;
                break;
            }
            ans+=d[i]*pr[i];
        }
        if(flag)
            printf("No Answer\n");
        else
            cout<<ans<<endl;
    }
    return 0;
}
/*
*/
