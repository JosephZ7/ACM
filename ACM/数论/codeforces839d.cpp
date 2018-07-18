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
const int MAX_N = 1e6+10;
const double eps = 1e-8;
const LL inf = 1e18+10;
const LL mod = 1e9+7;
using namespace std;
LL f[MAX_N],g[MAX_N],ct[MAX_N],cnt,pri[MAX_N],vis[MAX_N],mu[MAX_N];
void init()
{
    memset(vis,0,sizeof(vis));
    mu[1] = 1; cnt = 0;
    for(int i = 2;i < MAX_N;i++)
    {
        if(!vis[i])
        {
            pri[cnt++] = i;
            mu[i] = -1;
        }
        for(int j = 0;j < cnt&&i*pri[j] < MAX_N;j++)
        {
            vis[i*pri[j]] = 1;
            if(i%pri[j]) mu[i*pri[j]] = -mu[i];
            else
            {
                mu[i*pri[j]] = 0;
                break;
            }
        }
    }
}
LL q_pow(LL a,LL b)
{
    LL tmp = 1;
    while(b)
    {
        if(b&1)
            tmp = tmp*a%mod;
        b>>=1;
        a = a*a%mod;
    }
    return tmp;
}
int main()
{
    init();
    memset(ct,0,sizeof(ct));
    int n,x;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&x),ct[x]++;
    LL cnt = 0;
    for(LL i = 2;i <= 1000000;i++)
        for(LL j = 1;j*i <= 1000000;j++)
            g[i]+=ct[i*j];
    for(int i = 2;i <= 1000000;i++)
    {
        if(!g[i]) continue;
        g[i] = g[i]*q_pow(2LL,g[i]-1)%mod;
    }
    LL ans = 0;
    for(LL i = 2;i <= 1000000;i++)
    {
        for(LL j = 1;j*i <= 1000000;j++)
        {
            f[i] = (f[i]+mu[j]*g[i*j])%mod;
        }
        ans = (ans+f[i]*i)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
