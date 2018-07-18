#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX_N = 1e3 + 10;
const int mod = 1000000007;
LL gcd(LL a,LL b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
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
LL polya(LL m,LL n)
{
    LL ans = 0;
    for(int i = 1;i <= n;i++)
        ans+=q_pow(m,gcd(i,n));
    if(n&1)
        ans+=n*q_pow(m,n/2+1);
    else
        ans+=n/2*q_pow(m,n/2)+n/2*q_pow(m,n/2+1);
    ans = ans%mod*q_pow(2*n,mod-2)%mod;
    return ans;
}
int main()
{
    LL m,n;
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&m,&n);
        printf("Case #%d: %lld\n",ti++,polya(m,n));
    }
    return 0;
}
