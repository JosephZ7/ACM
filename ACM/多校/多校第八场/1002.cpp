#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#define LL long long
const int MAX_N = 1e6+10;
const double eps = 1e-8;
const LL mod = 1e9+7;
using namespace std;

LL q_pow(LL a,LL b){LL tmp; for(tmp = 1;b;b>>=1,a*=a) if(b&1) tmp*=a; return tmp;}
bool vis[MAX_N];
LL mu[MAX_N],ans[MAX_N],sum[MAX_N],pri[MAX_N];
int cnt;
void get_mu()
{
    memset(vis,false,sizeof(vis));
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
            vis[i*pri[j]] = true;
            if(i%pri[j]) mu[i*pri[j]] = -mu[i];
            else
            {
                mu[i*pri[j]] = 0;
                break;
            }
        }
    }
}
void init()
{
    memset(ans,0,sizeof(ans));
    memset(sum,0,sizeof(sum));
    for(int j = 1;j < MAX_N;j++)
    {
        ans[j]++;
        for(int i = j;i < MAX_N;i+=j)
            ans[i+1]++;
    }
    for(int i = 1;i < MAX_N;i++)
    {
        ans[i] = (ans[i]+ans[i-1])%mod;
    }
    for(int j = 1;j < MAX_N;j++)
    {
        if(mu[j] == 0) continue;
        for(int i = j;i < MAX_N;i+=j)
        {
            sum[i] = (sum[i]+mu[j]*ans[i/j]+mod)%mod;
        }
    }
    for(int i = 1;i < MAX_N;i++)
    {
        sum[i] = (sum[i]+sum[i-1])%mod;
    }
}
int main()
{
    int n;
    get_mu();
    init();
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",sum[n]);
    }
    return 0;
}
