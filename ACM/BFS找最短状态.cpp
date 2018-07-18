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
int vis[1000007][4][3];
struct node
{
    int num,op2,op3;
};
void change(int num,int a[])
{
    for(int i = 5;i >= 1;i--)
    {
        a[i] = num%10;
        num/=10;
    }
}
int getnum(int a[])
{
    int sum = 0;
    for(int i = 1;i <= 5;i++)
        sum = sum*10+a[i];
    return sum;
}
void BFS()
{
    int a[6];
    memset(vis,0x7f,sizeof(vis));
    queue<node> q;
    vis[12345][0][0] = 0;
    node st;
    st.num = 12345; st.op2 = 0; st.op3 = 0;
    q.push(st);
    while(!q.empty())
    {
        node now = q.front(); q.pop();
        change(now.num,a);
        int op2 = now.op2,op3 = now.op3,fsta = now.num,sta;
        for(int i = 1;i <= 4;i++)
        {
            if(a[i] == a[i+1]) continue;
            swap(a[i],a[i+1]);
            sta = getnum(a);
            if(vis[sta][op2][op3] > vis[fsta][op2][op3]+1)
            {
                vis[sta][op2][op3] = vis[fsta][op2][op3]+1;
                q.push(node{sta,op2,op3});
            }
            swap(a[i],a[i+1]);
        }
        if(op2 < 3)
        {
            for(int i = 1;i <= 5;i++)
            {
                a[i] = (a[i]+1)%10;
                sta = getnum(a);
                if(vis[sta][op2+1][op3] > vis[fsta][op2][op3]+1)
                {
                    vis[sta][op2+1][op3] = vis[fsta][op2][op3]+1;
                    q.push(node{sta,op2+1,op3});
                }
                a[i] = (a[i]+9)%10;
            }
        }
        if(op3 < 2)
        {
            for(int i = 1;i <= 5;i++)
            {
                if(a[i] == 0) continue;
                int t = a[i];
                a[i] = (a[i]*2)%10;
                sta = getnum(a);
                if(vis[sta][op2][op3+1] > vis[fsta][op2][op3]+1)
                {
                    vis[sta][op2][op3+1] = vis[fsta][op2][op3]+1;
                    q.push(node{sta,op2,op3+1});
                }
                a[i] = t;
            }
        }
    }
}

int main()
{
    int ed; BFS();
    while(scanf("%d",&ed)!=EOF)
    {
        //cout<<ed<<endl;
        int ans = 0x7f;
        for(int i = 0;i < 4;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                ans = min(ans,vis[ed][i][j]);
            }
        }
        printf("%d\n",ans == 0x7f?-1:ans);
    }
    return 0;
}
