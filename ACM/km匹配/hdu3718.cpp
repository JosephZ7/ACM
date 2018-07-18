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
const int MAX_N = 1e4+10;
const LL mod = 1e9+7;
const double eps = 1e-6;
using namespace std;
int G[305][305],nx,ny;
int link[305],slack[305],lx[305],ly[305],f[105];
bool visx[305],visy[305];
bool dfs(int x)
{
    visx[x] = true;
    for(int y = 0;y < ny;y++)
    {
        if(visy[y]) continue;
        int tmp = lx[x]+ly[y]-G[x][y];
        if(tmp == 0)
        {
            visy[y] = true;
            if(link[y] == -1||dfs(link[y]))
            {
                link[y] = x;
                return true;
            }
        }
        else if(slack[y] > tmp)
            slack[y] = tmp;
    }
    return false;
}
int KM()
{
    memset(link,-1,sizeof(link));
    memset(ly,0,sizeof(ly));
    for(int x = 0;x < nx;x++)
    {
        lx[x] = -INF;
        for(int y = 0;y < ny;y++)
            if(G[x][y] > lx[x])
                lx[x] = G[x][y];
    }
    for(int x = 0;x < nx;x++)
    {
        for(int y = 0;y < ny;y++)
            slack[y] = INF;
        while(true)
        {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(dfs(x)) break;
            int d = INF;
            for(int i = 0;i < ny;i++)
                if(!visy[i]&&slack[i] < d)
                    d = slack[i];
            if(d == INF) return -1;
            for(int i = 0;i < nx;i++)
                if(visx[i])
                    lx[i]-=d;
            for(int i = 0;i < ny;i++)
            {
                if(visy[i]) ly[i]+=d;
                else slack[i]-=d;
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < ny;i++)
    {
        if(link[i]!=-1)
        {
            ans+=G[link[i]][i];
            if(G[link[i]][i] == -INF) return -1;
        }
    }
    return ans;
}
int a[MAX_N];
int main()
{
    int n,m,k;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&k,&m);
        nx = 26,ny = 26;
        char ts[10];
        for(int i = 1;i <= n;i++)
        {
            scanf("%s",ts);
            a[i] = ts[0]-'A';
        }
        while(m--)
        {
            memset(G,0,sizeof(G));
            for(int i = 1;i <= n;i++)
            {
                scanf("%s",ts);
                G[a[i]][ts[0]-'A']++;
            }
            int ans = KM();
            printf("%.4f\n",ans*1.0/n);
        }
    }
    return 0;
}
/*
*/
