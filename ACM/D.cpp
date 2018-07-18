#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <iostream>
#define PI acos(-1)
#define LL long long
#define INF 0x3f3f3f3f

#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 5e3+10;
const double eps = 1e-8;
const LL inf = 1e18+10;
using namespace std;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int m, n, num[2], vis[200][200];
char G[200][200];

void dfs1(int x, int y)
{
    if(G[x][y] != '0') return;
    if(vis[x][y]) return;
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++)
    {
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        dfs1(nx,ny);
    }
}
void dfs2(int x, int y)
{
    if(G[x][y] != '1') return;
    if(vis[x][y]) return;
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++)
    {
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        dfs2(nx,ny);
    }
}
int check()
{
    for(int i=0; i<=n+1; i++)
        vis[i][0] = vis[i][m+1] = 1;
    for(int i=0; i<=m+1; i++)
        vis[0][i] = vis[n+1][i] = 1;
    for(int i=1; i<=n; i++)
        if(G[i][1]=='1' || G[i][m]=='1')
            return -1;
    for(int i=1; i<=m; i++)
        if(G[1][i]=='1' || G[n][i]=='1')
            return -1;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(!vis[i][j])
            {
                if(G[i][j] == '1')
                {
                    num[1] ++;
                    dfs2(i, j);
                }
                if(G[i][j] == '0')
                {
                    num[0]++;
                    dfs1(i, j);
                }
            }
        }
    if(num[0] == 0 && num[1]==1)
        return 1;
    else if(num[0] == 1 && num[1]==1)
        return 1;
    else if(num[0]==2 && num[1]==1)
        return 0;
    else
        return -1;
}
int main()
{
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        int flag = 0;
        num[0] = num[1] = 0;
        memset(vis, 0, sizeof(vis));
        for(int i=1; i<=n; i++)
            scanf("%s", G[i]+1);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(G[i][j] == '0')
                    flag = 1;
        if(flag == 0)
        {
            puts("1");
            continue;
        }
        printf("%d\n", check());

    }
    return 0;
}
