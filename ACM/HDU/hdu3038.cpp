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
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 2e5+10;
const double eps = 1e-7;
const LL mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
int fa[MAX_N],val[MAX_N];
int Find(int x)
{
    if(x == fa[x])
        return fa[x];
    int fx = fa[x];
    fa[x] = Find(fa[x]);
    val[x]+=val[fx];
    return fa[x];
}
int main()
{
    int N,M;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        memset(val,0,sizeof(val));
        for(int i = 0;i <= N;i++)
            fa[i] = i;
        int ans = 0;
        int u,v,w;
        for(int i = 0;i < M;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            u--;
            int fx = Find(u);
            int fy = Find(v);
            if(fx!=fy)
            {
                fa[fy] = fx;
                val[fy] = w+val[u]-val[v];
                //cout<<val[fy]<<endl;
            }
            else if(val[v]-val[u]!=w)
                ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
