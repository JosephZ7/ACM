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
const int MAX_N = 3e5+10;
const double eps = 1e-6;
const LL mod = 1000000009;
const LL inf = 1LL<<60;
using namespace std;
LL deg[1000];
int n,m;
LL a[100][100];
LL getans()
{
    LL sum = 1;
    for(int i = 1;i < n;i++)
    {
        for(int j = i+1;j < n;j++)
        {
            while(a[j][i])
            {
                LL t = a[i][i]/a[j][i];

                for(int k = i;k < n;k++)
                    a[i][k] = a[i][k]-a[j][k]*t;

                for(int k = i;k < n;k++)
                    swap(a[i][k],a[j][k]);
                sum = -sum;
            }
        }
        if(a[i][i] == 0)
            return 0;
        sum = sum*a[i][i];
    }
    if(sum < 0)
        sum = -sum;
    return sum;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(deg,0,sizeof(deg));
        scanf("%d%d",&n,&m);
        int u,v;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            deg[u]++; deg[v]++;
            a[u][v] = a[v][u] = -1;
            a[u][u] = deg[u];
            a[v][v] = deg[v];
        }
        LL ans = getans();
        cout<<ans<<endl;
    }
    return 0;
}
/*
*/
