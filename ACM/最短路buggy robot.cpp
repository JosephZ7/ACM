#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
const int mod = 1000000000;
const int MAX_N = 1e3+10;
using namespace std;
char a[55][55];
char cmd[55];
struct node
{
    int x,y,v,id;
    node(){}
    node(int _x,int _y,int _v,int _id)
    {
        x = _x; y = _y; v = _v; id = _id;
    }
    bool operator < (const node &e)const
    {
        return v > e.v;
    }
}st,ed;
int dp[55][55][55];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
char cdir[] = {'U','D','L','R'};
int n,m,len;
void Dijkstra()
{
    for(int i = 0;i < 55;i++)
        for(int j = 0;j < 55;j++)
            for(int k = 0;k < 55;k++)
                dp[i][j][k] = INF;
    priority_queue<node> q;
    dp[st.x][st.y][0] = 0;
    q.push(node(st.x,st.y,dp[st.x][st.y][0],0));
    while(!q.empty())
    {
        node now = q.top(); q.pop();
        if(now.x == ed.x&&now.y == ed.y)
            return ;
        if(now.id < len)
        {
            int p;
            for(p = 0;p < 4;p++)
                if(cdir[p] == cmd[now.id+1])
                    break;
            int nx = now.x+dir[p][0];
            int ny = now.y+dir[p][1];
            if(a[nx][ny] == 0||a[nx][ny] == '#')
            {
                nx = now.x; ny = now.y;
            }
            if(dp[nx][ny][now.id+1] > dp[now.x][now.y][now.id])
            {
                dp[nx][ny][now.id+1] = dp[now.x][now.y][now.id];
                q.push(node(nx,ny,dp[nx][ny][now.id+1],now.id+1));
            }
        }
        if(now.id < len&&dp[now.x][now.y][now.id+1] > dp[now.x][now.y][now.id]+1)
        {
            dp[now.x][now.y][now.id+1] = dp[now.x][now.y][now.id]+1;
            q.push(node(now.x,now.y,dp[now.x][now.y][now.id+1],now.id+1));
        }
        for(int i = 0;i < 4;i++)
        {
            int nx = now.x+dir[i][0];
            int ny = now.y+dir[i][1];
            if(a[nx][ny] == 0||a[nx][ny] == '#') continue;
            if(dp[nx][ny][now.id] > dp[now.x][now.y][now.id]+1)
            {
                dp[nx][ny][now.id] = dp[now.x][now.y][now.id]+1;
                q.push(node(nx,ny,dp[nx][ny][now.id],now.id));
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
        scanf("%s",a[i]+1);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
        {
            if(a[i][j] == 'R')
                st.x = i,st.y = j;
            if(a[i][j] == 'E')
                ed.x = i,ed.y = j;
        }

    scanf("%s",cmd+1);
    len = strlen(cmd+1);
    Dijkstra();
    int ans = INF;
    for(int i = 0;i <= len;i++)
        ans = min(ans,dp[ed.x][ed.y][i]);
    cout<<ans<<endl;
    return 0;
}
