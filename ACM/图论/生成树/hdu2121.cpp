#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#define PI 3.1415926535898
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e3+10;
const double eps = 1e-7;
const int mod = 10007;
const LL inf = 1LL<<60;
using namespace std;
struct edge
{
    int u,v;
    int val;
}es[MAX_N*MAX_N*5];
int in[MAX_N],rt;
int col[MAX_N],pre[MAX_N],ID[MAX_N];
int ZL_Mst(int root,int n,int m)
{
    int sum = 0;
    while(1)
    {
        for(int i = 0;i < n;i++) in[i] = INF;
        for(int i = 0;i < m;i++)
        {
            int u = es[i].u;
            int v = es[i].v;
            if(u!=v&&es[i].val < in[v])
            {
                in[v] = es[i].val;
                pre[v] = u;
                if(u == root)
                    rt = i;
            }
        }
        for(int i = 0;i < n;i++)
        {
            if(i!=root&&in[i] == INF)
                return -1;
        }
        memset(col,-1,sizeof(col));
        memset(ID,-1,sizeof(ID));
        in[root] = 0;
        int tn = 0;
        for(int i = 0;i < n;i++)
        {
            sum+=in[i];
            int v = i;
            while(v!=root&&col[v] != i&&ID[v] == -1)
            {
                col[v] = i;
                v = pre[v];
            }
            if(v!=root&&ID[v] == -1)
            {
                for(int u = pre[v];u!=v;u = pre[u])
                    ID[u] = tn;
                ID[v] = tn++;
            }
        }
        if(tn == 0) break;
        for(int i = 0;i < n;i++)
            if(ID[i] == -1)
                ID[i] = tn++;
        for(int i = 0;i < m;i++)
        {
            int u = es[i].u;
            int v = es[i].v;
            es[i].u = ID[u];
            es[i].v = ID[v];
            if(ID[u]!=ID[v]) es[i].val -=in[v];
        }
        n = tn;
        root = ID[root];
    }
    return sum;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int u,v,w;
        int ma = 0;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            es[i].u = u;
            es[i].v = v;
            ma+=w;
            es[i].val = w;
        }
        ma+=1;
        for(int i = 0;i < n;i++)
        {
            es[i+m].u = n;
            es[i+m].v = i;
            es[i+m].val = ma;
        }
        LL ans = ZL_Mst(n,n+1,m+n);
        if(ans == -1||ans >= 2*ma)
            printf("impossible\n");
        else
        {
            printf("%d %d\n",ans-ma,rt-m);
        }
        cout<<endl;
    }
    return 0;
}
