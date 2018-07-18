#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#define LL long long
const int MAX_N = 1e6+10;
const double eps = 1e-8;
using namespace std;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n,m,vis[200][200];
char a[200][200];
bool check(int x,int y)
{
    if(1 <= x&&x <= n&&1 <= y&&y <= m)
        return true;
    return false;
}
int flag;
void dfs0(int x,int y)
{
    if(x == 1||x == n||y == 1||y == m)
        flag = 1;
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++)
    {
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(!vis[nx][ny]&&check(nx,ny)&&a[nx][ny] == '0')
            dfs0(nx,ny);
    }
}
void dfs1(int x,int y)
{
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++)
    {
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(!vis[nx][ny]&&check(nx,ny)&&a[nx][ny] == '1')
            dfs1(nx,ny);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        flag = 0;
        for(int i = 1;i <= n;i++)
            scanf("%s",a[i]+1);
        int n1 = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(!vis[i][j]&&a[i][j] == '1')
                    dfs1(i,j),n1++;
            }
        }
        if(n1 == 1)
        {
            int t1 = 0;
            for(int i = 1;i <= n;i++)
                for(int j = 1;j <= m;j++)
                    if(!vis[i][j]&&a[i][j] == '0')
                    {
                        flag = 0;
                        dfs0(i,j);
                        if(!flag) t1++;
                    }
            if(t1 == 0)
                printf("1\n");
            else if(t1 == 1)
                printf("0\n");
            else
                printf("-1\n");
        }
        else
            printf("-1\n");
    }
    return 0;
}
