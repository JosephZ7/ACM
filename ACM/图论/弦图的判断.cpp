#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <iostream>
#define PI acos(-1)
#define LL long long
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e3+10;
const double eps = 1e-8;
const LL inf = 1e18+10;
using namespace std;
struct node
{
    int to,next;
}es[MAX_N*MAX_N*4];
int e,head[MAX_N];
void addedge(int u,int v)
{
    es[e].to = v;
    es[e].next = head[u];
    head[u] = e++;
}
int cost[MAX_N][MAX_N],f[MAX_N],id[MAX_N],vis[MAX_N];
void MCS(int n)
{
    for(int i = 0;i <= n;i++)
    {
        f[i] = 0; vis[i] = 0;
    }
    for(int i = n;i >= 1;i--)
    {
        int u = -1;
        for(int v = 1;v <= n;v++)
            if(!vis[v]&&(u == -1||f[u] < f[v]))
                u = v;
        vis[u] = 1;
        id[i] = u;
        for(int v = 1;v <= n;v++)
            if(!vis[v]&&cost[u][v])
                f[v]++;
    }
}
bool check(int n)
{
    for(int u = 1; u <= n; ++u)
    {
        int t = u + 1;
        while(t <= n && !cost[id[u]][id[t]]) ++t;
        if(t > n) continue;
        for(int v = t + 1; v <= n; ++v)
        if(cost[id[u]][id[v]])
            if(!cost[id[t]][id[v]]) return false;
    }
    return true;
}
void init()
{
    memset(head,-1,sizeof(head));
    memset(cost,0,sizeof(cost));
    e = 0;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n&&!m) break;
        init();
        int u,v;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            cost[u][v] = 1;
            cost[v][u] = 1;
            addedge(u,v);
            addedge(v,u);
        }
        MCS(n);
        if(check(n))
            printf("Perfect\n");
        else
            printf("Imperfect\n");
        printf("\n");
    }
    return 0;
}
/*
*/


//堆优化

int n, m;
vector<int> g[maxn];
bool connect[maxn][maxn];

int id[maxn];
int label[maxn];
int seq[maxn];

struct Stat {
    int lab, u;
    Stat( int lab, int u ) : lab(lab), u(u) {}
    bool operator<( const Stat & b ) const {
        return lab<b.lab;
    }
};
void mcs() {
    priority_queue<Stat> pq;
    memset( label, 0, sizeof(label) );
    memset( id, 0, sizeof(id) );
    for( int u=1; u<=n; u++ ) pq.push(Stat(0,u));

    for( int i=n; i>=1; i-- ) {
        while( id[pq.top().u] ) pq.pop();
        int u = pq.top().u;
        pq.pop();
        id[u] = i;
        for( int t=0; t<g[u].size(); t++ ) {
            int v = g[u][t];
            if( !id[v] ) {
                label[v]++;
                pq.push( Stat(label[v],v) );
            }
        }
    }
    for( int u=1; u<=n; u++ )
        seq[id[u]] = u;
}

bool check() {
    vector<int> c;
    for( int i=1; i<=n; i++ ) {
        int u = seq[i];
        c.clear();
        for( int t=0; t<g[u].size(); t++ ) {
            int v = g[u][t];
            if( id[v]>id[u] )
                c.push_back(v);
        }
        if( c.empty() ) continue;
        int sc = c[0];
        for( int t=1; t<c.size(); t++ )
            if( id[c[t]]<id[sc] ) sc=c[t];
        for( int t=0; t<c.size(); t++ ) {
            int v = c[t];
            if( v==sc ) continue;
            if( !connect[sc][v] ) return false;
        }
    }
    return true;
}
void init( int n ) {
    memset( connect, false, sizeof(connect) );
    for( int u=1; u<=n; u++ ) g[u].clear();
}
int main() {
    while(1) {
        scanf( "%d%d", &n, &m );
        if( n==0 && m==0 ) return 0;
        init(n);
        for( int i=1,u,v; i<=m; i++ ) {
            scanf( "%d%d", &u, &v );
            connect[u][v] = connect[v][u] = true;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        mcs();
        printf( "%s\n\n", check() ? "Perfect" : "Imperfect" );
    }
}
