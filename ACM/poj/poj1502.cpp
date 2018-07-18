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
int N;
int cost[200][200];
int d[200],vis[200];
void dijkstra(int s)
{
    for(int i = 0;i <= N;i++)
        d[i] = INF;
    memset(vis,0,sizeof(vis));
    d[s] = 0;
    int Mi,u = s;
    for(int i = 0;i < N-1;i++)
    {
        Mi = INF;
        for(int v = 1;v <= N;v++)
        {
            if(!vis[v]&&d[v] < Mi)
            {
                Mi = d[v];
                u = v;
            }
        }
        vis[u] = 1;
        for(int k = 1;k <= N;k++)
            d[k] = min(d[k],d[u]+cost[u][k]);
    }
}
int change(char s[])
{
    int len = strlen(s);
    int t = 1;
    int sum = 0;
    for(int i = len-1;i >= 0;i--)
    {
        sum+=t*(s[i]-'0');
        t*=10;
    }
    return sum;
}
int main()
{
    scanf("%d",&N);
    char x[10];
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= N;j++)
            cost[i][j] = INF;
        cost[i][i] = 0;
    }
    for(int i = 2;i <= N;i++)
    {
        for(int j = 1;j < i;j++)
        {
            scanf("%s",x);
            if(x[0]!='x')
                cost[i][j] = cost[j][i] = change(x);
        }
    }
    dijkstra(1);
    int ans = 0;
    for(int i = 1;i <= N;i++)
        ans = max(ans,d[i]);
    cout<<ans<<endl;
    return 0;
}
