#include <stdio.h>
#include <stdlib.h>
#include <cmath>
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
const int MAX_N = 1e5+10;
const double eps = 1e-7;
const LL mod = 1000000007;
const LL inf = 1LL<<60;
using namespace std;
map<int,int> mp;
int fa[MAX_N],rk[MAX_N];
int Find(int x)
{
    if(x == fa[x])
        return fa[x];
    int temp = fa[x];
    fa[x] = Find(fa[x]);
    rk[x] = (rk[x]+rk[temp])%2;
    return fa[x];
}
int l[MAX_N],r[MAX_N];
char op[MAX_N][10];
int main()
{
    int N,q;
    scanf("%d",&N);
    scanf("%d",&q);
    int num = 0,f;
    mp.clear();
    for(int i = 0;i < MAX_N;i++)
    {
        fa[i] = i;
        rk[i] = 0;
    }
    int i;
    for(i = 1;i <= q;i++)
        scanf("%d%d%s",&l[i],&r[i],op[i]);
    int u,v;
    for(i = 1;i <= q;i++)
    {
        u = l[i]-1; v = r[i];
        if(mp[u] == 0)
            mp[u] = ++num;
        u = mp[u];
        if(mp[v] == 0)
            mp[v] = ++num;
        v = mp[v];
        if(op[i][0] == 'o')
            f = 1;
        else
            f = 0;
        int fx = Find(u);
        int fy = Find(v);
        if(fx!=fy)
        {
            fa[fy] = fx;
            rk[fy] = (rk[v]+rk[u]+f)%2;
        }
        else if((rk[u]+rk[v])%2!=f)
            break;
    }
    cout<<(i-1)<<endl;
    return 0;
}
/*
*/
