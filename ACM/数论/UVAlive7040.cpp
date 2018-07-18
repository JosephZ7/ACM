#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
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
LL C[MAX_N];
LL invv[MAX_N+10];
void init_C(LL k)
{
    C[0] = 1;
    for(long long i = 1; i <= k;i ++) C[i] = C[i - 1] *(k - i +1) % mod * invv[i] %mod;
}

void init()
{
    invv[1] = 1;
    for (int i = 2; i < MAX_N;i ++)
        invv[i] = (mod-mod/i)*invv[mod%i]%mod;
}
int main()
{
    int T,ti = 1;
    init();
    scanf("%d",&T);
    while(T--)
    {
        LL n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        init_C(k);
        int Cmk = 1;
        for(int i = 1;i <= min(k,m-k);i++)
            Cmk = Cmk*(m-i+1)%mod*invv[i]%mod;
        LL ans = 0,tmp = 1;
        for(LL i = k;i >= 1;i--)
        {
            ans = (ans+tmp*C[i]*i%mod*q_pow(i-1,n-1)%mod+mod)%mod;
            tmp = -tmp;
        }
        ans = Cmk*ans%mod;
        printf("Case #%d: %lld\n",ti++,ans);
    }
	return 0;
}
