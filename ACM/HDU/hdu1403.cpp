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
const int MAX_N = 4e5+10;
const double eps = 1e-7;
const LL mod = 1000000009;
const LL inf = 1LL<<60;
using namespace std;
struct node
{
    int x,y;
    int val;
    char a[10];
    node(){}
};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char dirz[5] = "udlr";
int f[10];
string ans[MAX_N];
int vis[MAX_N];
void calc()
{
    f[1] = 1;
    for(int i = 2;i <= 9;i++)
        f[i] = f[i-1]*i;
}
int work(char str[])
{
    int res = 0;
    for(int i = 0;i < 9;i++)
    {
        int tmp = 0;
        for(int j = i+1;j < 9;j++)
            if(str[i] > str[j]) tmp++;
        res+=tmp*f[8-i];
    }
    //cout<<res<<endl;
    return res;
}
int flag;
void Astar(char a[])
{
    queue<node> q;
    node st;
    strcpy(st.a,a);
    st.x = 2; st.y = 2;

    st.val = work(a);
    ans[st.val] = "";
    vis[st.val] = 1;

    q.push(st);
    while(!q.empty())
    {
        node now = q.front();
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            node t = now;
            t.x = now.x+dir[i][0];
            t.y = now.y+dir[i][1];
            if(t.x < 3&&t.x >= 0&&t.y < 3&&t.y >= 0)
            {
                swap(t.a[t.x*3+t.y],t.a[now.x*3+now.y]);
                t.val = work(t.a);
                if(vis[t.val] == 0)
                {
                    vis[t.val] = 1;
                    ans[t.val] = dirz[i]+ans[now.val];
                    q.push(t);
                }
            }
        }
    }
}
int main()
{
    calc();
    char x;
    memset(vis,0,sizeof(vis));
    char a[11] = "123456789";
    Astar(a);
    char t[30];
    while(gets(t))
    {
        int g = 0;
        for(int i = 0;i < strlen(t);i++)
        {
            if(t[i]<='8'&&t[i]>='1')
                a[g++] = t[i];
            else if(t[i] == 'x')
                a[g++] = '9';
        }
        a[g] = '\0';
        //cout<<a<<endl;
        int val = work(a);
        if(vis[val] == 0)
            printf("unsolvable\n");
        else
            cout<<ans[val]<<endl;
    }
    return 0;
}
/*
ullddrurdllurdruldr
ullddrurdllurrdlurd
*/
