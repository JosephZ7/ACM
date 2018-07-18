#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#define LL long long
const int MAX_N = 1e4+10;
using namespace std;
int r,c,n;
int a[555][555];
void paint(int tlx,int tly,int drx,int dry,int col)
{
    if(col == 2)
    {
        for(int i = tlx;i <= drx;i++)
            for(int j = tly;j <= dry;j++)
                a[i][j] = col;
        return ;
    }
    int h = drx-tlx+1;
    if(h == col/2)
    {
        for(int i = tlx;i <= drx;i++)
        {
            a[i][dry] = col;
            a[i][dry-1] = col;
        }
        paint(tlx,tly,drx,dry-2,col-2);
    }
    else
    {
        for(int i = tly;i <= dry;i++)
        {
            a[drx][i] = col;
            a[drx-1][i] = col;
        }
        paint(tlx,tly,drx-2,dry,col-2);
    }
}
void calc()
{
    int i,j,x = 1;
    for(i = 1;i <= r;i++,x+=2)
        for(j = 1;j <= r;j++)
            a[j][i] = x,a[i][j] = x;
    int tlx = 1,tly = r+1;
    int drx = r,dry = c;
    int color = n-(n&1);
    paint(tlx,tly,drx,dry,color);
}
struct node
{
    int x,y;
    node(){}
    node(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
};
vector<node> point[505];
int vis[555][555];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y,int v)
{
    if(x > r||x < 1||y < 1||y > c||v!=a[x][y]||vis[x][y]) return ;
    vis[x][y] = 1;
    point[v].push_back(node(x,y));
    for(int i = 0;i < 4;i++)
    {
        int nx = dir[i][0]+x;
        int ny = dir[i][1]+y;
        dfs(nx,ny,v);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0;i <= n;i++)
            point[i].clear();
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        if(n == 1)
        {
            printf("1 1\n1 1\n");
            continue;
        }
        if(n&1)
        {
            r = (n+1)/2;
            c = n;
        }
        else
        {
            r = n/2;
            c = n+1;
        }
        calc();
        /*
        for(int i = 1;i <= r;i++)
        {
            for(int j = 1;j <= c;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        cout<<endl;
        */
        for(int i = 1;i <= r;i++)
        {
            for(int j = 1;j <= c;j++)
            {
                if(vis[i][j]) continue;
                dfs(i,j,a[i][j]);
            }
        }
        printf("%d %d\n",r,c);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j < point[i].size();j++)
            {
                node t = point[i][j];
                if(j == point[i].size()-1)
                    printf("%d %d\n",t.x,t.y);
                else
                    printf("%d %d ",t.x,t.y);
            }
        }
    }
    return 0;
}
