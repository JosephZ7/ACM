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
struct edge
{
    int to,cost,next;

}G1[MAX_N],G2[MAX_N];
int head1[MAX_N],head2[MAX_N],e1,e2;
int d[MAX_N],vis[MAX_N];
int P,Q;
void SPFA(int s)
{
    for(int i = 0;i <= P;i++)
        d[i] = INF;
    memset(vis,0,sizeof(vis));
    vis[s] = 1;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head1[u];i != -1;i = G1[i].next)
        {
            int v = G1[i].to;
            int w = G1[i].cost;
            if(d[v] > d[u]+w)
            {
                d[v] = d[u]+w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
void SPFA2(int s)
{
    for(int i = 0;i <= P;i++)
        d[i] = INF;
    memset(vis,0,sizeof(vis));
    vis[s] = 1;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head2[u];i!=-1;i = G2[i].next)
        {
            int v = G2[i].to;
            int w = G2[i].cost;
            if(d[v] > d[u]+w)
            {
                d[v] = d[u]+w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
void add(int u,int v,int w)
{
    G1[e1].cost = w;
    G1[e1].to = v;
    G1[e1].next = head1[u];
    head1[u] = e1++;

    G2[e2].cost = w;
    G2[e2].to = u;
    G2[e2].next = head2[v];
    head2[v] = e2++;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        e1 = e2 = 0;
        memset(head1,-1,sizeof(head1));
        memset(head2,-1,sizeof(head2));
        scanf("%d%d",&P,&Q);
        int u,v,w;
        for(int i = 0;i < Q;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        SPFA(1);
        LL ans = 0;
        for(int i = 2;i <= P;i++)
            ans+=d[i];
        SPFA2(1);
        for(int i = 2;i <= P;i++)
            ans+=d[i];
        printf("%I64d\n",ans);
    }
    return 0;
}
