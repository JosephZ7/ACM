#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>
#define LL long long
#define INF 0x7fffffff
#define PLL pair<LL,LL>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MAX_N = 1e5+10;
const LL inf = 1e15+10;
const int mod = 1e9+7;

vector<PLL> G[MAX_N];
vector<int> st;
LL d[MAX_N];
int N,M;
void dijkstra(const vector<int> &s)
{
    fill(d,d+N+1,1e18);
    priority_queue<PLL,vector<PLL>,greater<PLL> > q;
    for(int i = 0;i < s.size();i++)
    {
        int x = s[i];
        d[x] = 0;
        q.push({d[x],x});
    }
    while(!q.empty())
    {
        int u = q.top().second; q.pop();
        for(int i = 0;i < G[u].size();i++)
        {
            PLL e = G[u][i];
            LL v = e.first,w = e.second;
            if(d[v] > d[u]+w)
            {
                d[v] = d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
vector<int> s,e;
LL solve()
{
    LL Mi = 1e18;
    for(int i = 0;i < 20;i++)
    {
        s.clear(); e.clear();
        for(int j = 0;j < st.size();j++)
        {
            if((st[j]>>i)&1)
                s.push_back(st[j]);
            else
                e.push_back(st[j]);
        }
        dijkstra(s);
        for(int j = 0;j < e.size();j++)
            Mi = min(Mi,d[e[j]]);
        dijkstra(e);
        for(int j = 0;j < s.size();j++)
            Mi = min(Mi,d[s[j]]);
    }
    return Mi;
}
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        st.clear();
        scanf("%d%d",&N,&M);
        for(int i = 1;i <= N;i++)
            G[i].clear();
        int u,v,w,K,x;
        for(int i = 0;i < M;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back({v,w});
        }
        scanf("%d",&K);
        while(K--) scanf("%d",&x),st.push_back(x);
        printf("Case #%d: %lld\n",ti++,solve());
    }
    return 0;
}
/*
*/
