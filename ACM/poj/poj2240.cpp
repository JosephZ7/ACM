#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#define PI 3.1415926535898
#define LL long long int
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e5+10;
const double eps = 1e-7;
const LL mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
int n,c[MAX_N];
struct edge
{
    int to;
    double w;
    edge(){}
    edge(int _to,double _w)
    {
        to = _to;
        w = _w;
    }
};
vector<edge> G[200];
int vis[200];
double d[200];
bool SPFA(int s)
{
    memset(vis,0,sizeof(vis));
    memset(c,0,sizeof(c));
    queue<int> q;
    for(int i = 0;i <= n;i++)
        d[i] = 0;
    vis[s] = 1;
    d[s] = 1.0;
    c[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = 0;i < G[u].size();i++)
        {
            int v = G[u][i].to;
            double w = G[u][i].w;
            if(d[v] < d[u]*w)
            {
                d[v] = d[u]*w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    if(c[v] > n) return true;
                    c[v]++;
                    q.push(v);
                }
            }
        }
    }
    return false;
}
int main()
{
    string s;
    int ti = 1;
    map<string,int> mp;
    while(scanf("%d",&n),n)
    {
        mp.clear();
        for(int i = 1;i <= n;i++)
        {
            G[i].clear();
            cin>>s;
            mp[s] = i;
        }
        int m;
        scanf("%d",&m);
        string s1,s2;
        double w;
        int u,v,flag = 0;
        for(int i = 0;i < m;i++)
        {
            cin>>s1>>w>>s2;
            u = mp[s1];
            v = mp[s2];
            G[u].push_back(edge(v,w));
        }
        printf("Case %d: ",ti++);
        for(int i = 1;i <= n;i++)
        {
            if(SPFA(i))
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
