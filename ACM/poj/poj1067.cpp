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
const int MAX_N = 2e5+10;
const double eps = 1e-7;
const LL mod = 999999997;
const LL inf = 1LL<<60;
using namespace std;
struct Point
{
    int x,y;
};
int a[4][8];
LL res;
struct node
{
    int step;
    int m[4][8];
    Point gap[4];
    LL val;
};
LL work(int x[][8])
{
    LL sum = 0;
    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 8;j++)
        {
            sum+=sum*3+x[i][j];
            sum%=mod;
        }
    return sum;
}
int BFS()
{
    map<LL,int> Q;
    queue<node> q;
    node st;
    int k = 0;
    for(int i = 0;i < 4;i++)
    {
        for(int j = 1;j <= 7;j++)
        {
            if(a[i][j]%10 == 1)
            {
                int t = a[i][j]/10;
                st.m[t-1][0] = a[i][j];
                st.gap[k].x = i;
                st.gap[k++].y = j;
                st.m[i][j] = 0;
            }
            else
                st.m[i][j] = a[i][j];
        }
    }
    st.step = 0;
    st.val = work(st.m);
    Q[st.val] = 1;

    q.push(st);
    node t;
    int nx,ny;
    while(!q.empty())
    {
        node now = q.front();
        q.pop();
        if(now.val == res)
            return now.step;

        for(int i = 0;i < 4;i++)
        {
            t = now;
            nx = now.gap[i].x;
            ny = now.gap[i].y-1;
            if(nx < 4&&nx >= 0&&ny < 8&&ny >= 0)
            {
                int num = t.m[nx][ny];
                if(num == 0||num%10 == 7) continue;
                int flag = 1;
                t.step = now.step+1;
                for(int j = 0;j < 4&&flag;j++)
                    for(int k = 0;k < 8&&flag;k++)
                    {
                        if(t.m[j][k] == num+1)
                        {
                            t.gap[i].x = j;
                            t.gap[i].y = k;
                            swap(t.m[nx][ny+1],t.m[j][k]);
                            flag = 0;
                            break;
                        }
                    }
                t.val = work(t.m);
                if(Q[t.val] == 0)
                {
                    Q[t.val] = 1;
                    q.push(t);
                }
            }
        }
    }
    return -1;
}
int as[4][8];
int main()
{
    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 7;j++)
            as[i][j] = (i+1)*10+j+1;
    int T;
    scanf("%d",&T);
    res = work(as);
    while(T--)
    {
        memset(a,0,sizeof(a));
        for(int i = 0;i < 4;i++)
            for(int j = 1;j <= 7;j++)
                scanf("%d",&a[i][j]);
        int ans = BFS();
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
