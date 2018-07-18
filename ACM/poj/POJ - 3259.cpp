#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#define PI acos(-1)
#define LL long long
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e3+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
int N,M,W;
struct node
{
    int v,w;
    node(){}
    node(int _v,int _w)
    {
        v = _v;
        w = _w;
    }
};
vector<node> G[MAX_N];
int d[MAX_N],vis[MAX_N],c[MAX_N];
bool SPFA(int s)
{
    for(int i = 0;i <= N;i++)
        d[i] = INF;
    memset(vis,0,sizeof(vis));
    queue<int> q;
    vis[s] = 1;
    d[s] = 0;
    c[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = 0;i < G[u].size();i++)
        {
            int v = G[u][i].v;
            int w = G[u][i].w;
            if(d[v] > d[u]+w)
            {
                d[v] = d[u]+w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    if(c[v] > N) return true;
                    c[v]++;
                    q.push(v);
                }
            }
        }
    }
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(c,0,sizeof(c));
        scanf("%d%d%d",&N,&M,&W);
        int S,E,T;
        for(int i = 1;i <= N;i++)
            G[i].clear();
        for(int i = 0;i < M;i++)
        {
            scanf("%d%d%d",&S,&E,&T);
            G[S].push_back(node(E,T));
            G[E].push_back(node(S,T));
        }
        for(int i = 0;i < W;i++)
        {
            scanf("%d%d%d",&S,&E,&T);
            G[S].push_back(node(E,-T));
        }
        if(SPFA(1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
/*
*/
