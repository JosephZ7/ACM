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
char a[2][20][20];
int vis[2][20][20];
int N,M,T;
int flag;
struct node
{
    int x,y;
    int c,time;
};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void BFS(int c,int x,int y)
{
    queue<node> q;
    node st;
    st.x = x;
    st.y = y;
    st.c = c;
    st.time = 0;
    vis[c][x][y] = 1;
    q.push(st);

    while(!q.empty())
    {
        node now = q.front();
        q.pop();
        //printf("(%d , %d , %d)->\n",now.c,now.x,now.y);
        if(a[now.c][now.x][now.y] == 'P')
        {
            if(now.time <= T)
                flag = 1;
            return ;
        }
        for(int i = 0;i < 4;i++)
        {
            node t;
            t.x = now.x+dir[i][0];
            t.y = now.y+dir[i][1];
            t.c = now.c;
            t.time = now.time+1;
            if(t.x >= 0&&t.y >=0&&t.x < N&&t.y < M)
            {
                if(!vis[now.c][t.x][t.y]&&a[now.c][t.x][t.y] == '#')
                    t.c = !now.c;

                if(!vis[t.c][t.x][t.y]&&a[t.c][t.x][t.y] !='*')
                {
                    vis[t.c][t.x][t.y] = 1;
                    q.push(t);
                }
            }
        }
    }
}
int main()
{
    int C;
    scanf("%d",&C);
    while(C--)
    {
        memset(vis,0,sizeof(vis));
        flag = 0;
        scanf("%d%d%d",&N,&M,&T);
        for(int i = 0;i < 2;i++)
            for(int j = 0;j < N;j++)
                scanf("%s",a[i][j]);

        for(int i = 0;i < 2;i++)
        {
            for(int j = 0;j < N;j++)
            {
                for(int k = 0 ;k < M;k++)
                {
                    if(a[i][j][k] == '#'&&a[i^1][j][k] == '#')
                    {
                        vis[i][j][k] = 1;
                        vis[i^1][j][k] = 1;
                    }
                    else if(a[i][j][k] == '#'&&a[i^1][j][k] == '*')
                        vis[i][j][k] = 1;
                }
            }
        }
        BFS(0,0,0);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
/*
*/
