#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <vector>
#include <map>
#include <list>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <iostream>
#include <iomanip>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a) memset(a,0,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
int head[2005];
int vis[2005][32];
int d[2005][32];
int cnt,e;
struct Edge
{
    int v,next,lt,spend;
}es[2005];
struct Node
{
    int u,time;
};
void SPFA(int s)
{
    queue<Node> q;
    for(int i = 1;i <= cnt;i++)
        for(int j = 18;j <= 30;j++)
            d[i][j] = INF;
    mem(vis);
    for(int j = 18;j <= 30;j++)
    {
        vis[s][j] = 1;
        d[s][j] = 0;
        Node x;
        x.u = s;
        x.time = j;
        q.push(x);
    }
    while(!q.empty())
    {
        Node x = q.front();
        int u = x.u;
        int time = x.time;
        q.pop();
        vis[u][time] = 0;
        for(int i = head[u];i!=-1;i = es[i].next)
        {
            int v = es[i].v , lt = es[i].lt, spend = es[i].spend;
            if(time <= lt)
            {
                if(d[u][time] < d[v][lt+spend])
                {
                    d[v][lt+spend] = d[u][time];
                    if(vis[v][lt+spend] == 0)
                    {
                        vis[v][lt+spend] = 1;
                        Node t;
                        t.u = v;
                        t.time = lt+spend;
                        q.push(t);
                    }
                }
            }
            else
            {
                if(d[u][time]+1 < d[v][lt+spend])
                {
                    d[v][lt+spend] = d[u][time]+1;
                    if(vis[v][lt+spend] == 0)
                    {
                        vis[v][lt+spend] = 1;
                        Node t;
                        t.u = v;
                        t.time = lt+spend;
                        q.push(t);
                    }
                }
            }
        }
    }
}
int main()
{
    int T,ti = 1;
    string st,ed;
    string s1,s2;
    int lt,spend;
    scanf("%d",&T);
    while(T--)
    {
        map<string,int> q;
        memset(head,-1,sizeof(head));
        int n;
        cnt = 0;
        e = 0;
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            cin>>s1>>s2>>lt>>spend;
            if(q[s1] == 0) q[s1] = ++cnt;
            if(q[s2] == 0) q[s2] = ++cnt;
            if(lt <= 6) lt+=24;
            if(lt < 18|| lt+spend > 30)
                continue;
            int u = q[s1],v = q[s2];
            es[e].v = v; es[e].lt = lt; es[e].spend = spend;
            es[e].next = head[u]; head[u] = e++;
        }
        cin>>st>>ed;
        if(q[st] == 0) q[st] = ++cnt;
        if(q[ed] == 0) q[ed] = ++cnt;
        SPFA(q[st]);
        int ans = INF;
        for(int k = 18;k <= 30;k++)
            ans = min(ans,d[q[ed]][k]);
        printf("Test Case %d.\n",ti++);
        if(ans == INF)
            printf("There is no route Vladimir can take.\n");
        else
            printf("Vladimir needs %d litre(s) of blood.\n",ans);
    }
    return 0;
}
