#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#define LL long long
const int mod = 1000000000;
const int MAX_N = 1e3+10;
using namespace std;
int p;
int n,m;
struct edge
{
    int u,v,w;
    bool operator < (const edge &e)const
    {
        return w < e.w;
    }
}es[MAX_N];
vector<int> G[MAX_N];
LL vis[MAX_N],fa[MAX_N],E[MAX_N];
LL deg[MAX_N][MAX_N],Cnt[MAX_N][MAX_N];
int Find(int x,LL f[])
{
    if(x == f[x])
        return x;
    else
        return Find(f[x],f);
}
LL det(LL a[][MAX_N],int n)
{
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            a[i][j]%=p;
    LL ans = 1;
    for(int i = 1;i < n;i++)
    {
        for(int j = i+1;j < n;j++)
        {
            while(a[j][i])
            {
                LL t = a[i][i]/a[j][i];
                for(int k = i;k < n;k++)
                    a[i][k] = (a[i][k]-a[j][k]*t)%p;
                for(int k = i;k < n;k++)
                    swap(a[i][k],a[j][k]);
                ans = -ans;
            }
        }
        if(a[i][i] == 0)
            return 0;
        ans = (ans*a[i][i])%p;
    }
    return (ans+p)%p;
}
void solve()
{
    sort(es,es+m);
    LL Edge = -1;
    LL ans = 1;
    for(int i = 0;i <= n;i++)
    {
        fa[i] = i;
        vis[i] = 0;
    }
    for(int i = 0;i <= m;i++)
    {
        if(es[i].w!=Edge||i == m)
        {
            for(int j = 1;j <= n;j++)
            {
                if(vis[j])
                {
                    LL u = Find(j,E);
                    G[u].push_back(j);
                    vis[j] = 0;
                }
            }
            for(int j = 1;j <= n;j++)
            {
                if(G[j].size() > 1)
                {
                    for(int u = 1;u <= n;u++)
                        for(int v = 1;v <= n;v++)
                            Cnt[u][v] = 0;
                    int len = G[j].size();
                    for(int u = 0;u < len;u++)
                        for(int v = u+1;v< len;v++)
                        {
                            int su = G[j][u];
                            int sv = G[j][v];
                            Cnt[u][v] = (Cnt[v][u]-=deg[su][sv]);
                            Cnt[u][u]+=deg[su][sv];
                            Cnt[v][v]+=deg[su][sv];
                        }
                    ans = (ans*det(Cnt,len))%p;
                    for(int u = 0;u < len;u++)
                        fa[G[j][u]] = j;
                }
            }
            for(int j = 1;j <= n;j++)
            {
                fa[j] = E[j] = Find(j,fa);
                G[j].clear();
            }
            if(i == m)
                break;
            Edge = es[i].w;
        }
        int u = es[i].u;
        int v = es[i].v;
        int fu = Find(u,fa);
        int fv = Find(v,fa);
        if(fu == fv)
            continue;
        vis[fu] = vis[fv] = 1;
        E[Find(fu,E)] = Find(fv,E);
        deg[fu][fv]++;
        deg[fv][fu]++;
    }
    int flag = 0;
    for(int i = 2;i <= n&&!flag;i++)
        if(E[i]!=E[i-1])
            flag = 1;
    if(m == 0)
        flag = 1;
    if(flag == 0)
        cout<<ans%p<<endl;
    else
        cout<<0<<endl;
}
int main()
{

    while(scanf("%d%d%d",&n,&m,&p),n,m,p)
    {
        memset(deg,0,sizeof(deg));
        for(int i = 0;i <= n;i++)
            G[i].clear();
        for(int i = 0;i < m;i++)
            scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].w);
        solve();
    }
    return 0;
}
