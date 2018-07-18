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
struct edge
{
    int to,cost;
    edge(){}
    edge(int _t,int _co)
    {
        to = _t;
        cost = _co;
    }
};
int N,R;
vector<edge> G[MAX_N];
int d[MAX_N];
int d2[MAX_N];
typedef pair<int,int> P;
void solve()
{
    priority_queue<P,vector<P>,greater<P> > q;
    fill(d+1,d+N+1,INF);
    fill(d2+1,d2+N+1,INF);
    d[1] = 0;
    q.push(P(0,1));
    while(!q.empty())
    {
        P p = q.top();
        q.pop();
        int v = p.second,dist = p.first;
        if(d2[v] < dist) continue;
        for(int i = 0;i < G[v].size();i++)
        {
            edge &e = G[v][i];
            int dist2 = dist+e.cost;
            if(d[e.to] > dist2)
            {
                swap(d[e.to],dist2);
                q.push(P(d[e.to],e.to));
            }
            if(d2[e.to] > dist2&&d[e.to] < dist2)
            {
                d2[e.to] = dist2;
                q.push(P(d2[e.to],e.to));
            }
        }
    }
    printf("%d\n",d2[N]);
}
int main()
{
    scanf("%d%d",&N,&R);
    int u,v,val;
    for(int i = 0;i < R;i++)
    {
        scanf("%d%d%d",&u,&v,&val);
        G[u].push_back(edge(v,val));
        G[v].push_back(edge(u,val));
    }
    solve();
    return 0;
}
