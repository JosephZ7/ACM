#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <time.h>
#include <algorithm>
#include <iostream>
#define PI acos(-1.0)
#define LL long long
#define INF 0x7fffffff
using namespace std;
const int MAX_N = 1e3+10;
const LL inf = 1e15+10;
const LL mod = 1e6+3;
const double eps = 1e-8;
int cap[MAX_N][MAX_N];
int f[MAX_N],pre[MAX_N];
int N,M;
int BFS()
{
    queue<int> q;
    for(int i = 0;i <= M;i++)
        pre[i] = -1;
    pre[1] = 0;
    f[1] = INF;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        if(u == M) break;
        for(int i = 2;i <= M;i++)
        {
            if(cap[u][i] > 0&&pre[i] == -1)
            {
                pre[i] = u;
                f[i] = min(f[u],cap[u][i]);
                q.push(i);
            }
        }
    }
    if(pre[M] == -1)
        return -1;
    else
        return f[M];
}
int max_flow()
{
    int ins = 0;
    int sum = 0;
    while((ins = BFS())!=-1)
    {
        int k = M;
        while(k!=1)
        {
            int v = pre[k];
            cap[k][v]+=ins;
            cap[v][k]-=ins;
            k = v;
        }
        sum+=ins;
    }
    return sum;
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        for(int i = 0;i <= M;i++)
            f[i] = INF;
        memset(cap,0,sizeof(cap));
        int u,v,w;
        for(int i = 0;i < N;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(u!=v)
                cap[u][v]+=w;
        }
        printf("%d\n",max_flow());
    }
    return 0;
}
