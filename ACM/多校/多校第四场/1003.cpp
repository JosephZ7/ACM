#include <stdio.h>
#include<math.h>
#include<cstring>
#include<iostream>
#define LL long long
const LL mod = 998244353;
const int MAX_N = 1e6+10;
using namespace std;
LL l,r,k,ans[MAX_N],f[MAX_N];
int isp[MAX_N],cnt;
LL pri[MAX_N];
void Euler(LL p)
{
    LL t = 0;
    for(LL i = l/p*p;i <= r;i+=p)
    {
        if(i >= l)
        {
            t = 0;
            while(f[i-l]%p==0)
            {
                t++;
                f[i-l]/=p;
            }
            ans[i-l] = ans[i-l]*(t*k+1)%mod;
        }
    }
}
void init()
{
    cnt = 0;
    memset(isp,0,sizeof(isp));
    isp[0] = 1; isp[1] = 1;
    for(int i = 2;i < MAX_N;i++)
    {
        if(!isp[i])
            pri[cnt++] = i;
        for(int j = 0;j < cnt&&pri[j]*i < MAX_N;j++)
        {
            isp[i*pri[j]] = 1;
            if(i%pri[j] == 0) break;
        }
    }
}
int main()
{
    int T;
    init();
    //cout<<cnt<<endl;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&l,&r,&k);
        LL d = r-l;
        for(int i = 0;i <= d;i++)
        {
            f[i] = i+l;
            ans[i] = 1;
        }
        for(int i = 0;i < cnt;i++)
        {
            if(pri[i]*pri[i] > r) break;
            Euler(pri[i]);
        }
        LL ANS = 0;
        for(int i = 0;i <= d;i++)
        {
            if(f[i] > 1)
                ans[i] = ans[i]*(k+1)%mod;
            ANS = (ANS+ans[i])%mod;
        }
        printf("%lld\n",ANS);
    }
    return 0;
}
