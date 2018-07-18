#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#define LL long long
#define PI acos(-1)
#define INF 0x7fffffff
const LL mod = 1000000007;
const int MAX_N = 1e3+10;
const double eps = 1e-6;
using namespace std;
int n,m,t;
char a[30][30];
struct node
{
    int x,y,sta,tim;
}st;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int vis[30][30][1<<11];
bool check(int x,int y)
{
    if(x < n&&x >= 0&&y < m&&y >= 0&&a[x][y]!='*')
        return true;
    return false;
}
int BFS()
{
    memset(vis,0,sizeof(vis));
    queue<node> q;
    st.sta = 0;
    st.tim = 0;
    vis[st.x][st.y][st.sta] = 1;
    q.push(st);
    while(!q.empty())
    {
        node now = q.front(); q.pop();
        //printf("%c\n",a[now.x][now.y]);
        if(now.tim >= t) return -1;
        if(a[now.x][now.y] == '^')
        {
            if(now.tim < t)
                return now.tim;
            else
                return -1;
        }
        for(int i = 0;i < 4;i++)
        {
            node t;
            t.x = now.x+dir[i][0];
            t.y = now.y+dir[i][1];
            t.sta = now.sta;
            t.tim = now.tim+1;
            if(!check(t.x,t.y)) continue;
            if(a[t.x][t.y] <= 'j'&&a[t.x][t.y] >= 'a')
            {
                int sta = now.sta|(1<<(a[t.x][t.y]-'a'));
                if(!vis[t.x][t.y][sta])
                {
                    t.sta = sta;
                    vis[t.x][t.y][sta] = 1;
                    q.push(t);
                }
            }
            else if(a[t.x][t.y] <= 'J'&&a[t.x][t.y] >= 'A')
            {
                int sta = now.sta&(1<<(a[t.x][t.y]-'A'));
                if(sta&&!vis[t.x][t.y][t.sta])
                {
                    vis[t.x][t.y][t.sta] = 1;
                    q.push(t);
                }
            }
            else if(!vis[t.x][t.y][t.sta])
            {
                vis[t.x][t.y][t.sta] = 1;
                q.push(t);
            }

        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%s",a[i]);
            for(int j = 0;j < m;j++)
            {
                if(a[i][j] == '@')
                {
                    st.x = i;
                    st.y = j;
                    st.tim = 0;
                }
            }
        }
        int ans = BFS();
        cout<<ans<<endl;
    }
    return 0;
}
/*
*/
