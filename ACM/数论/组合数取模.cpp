//打表
LL d[MAX_N],inv[MAX_N],f[MAX_N];
LL q_pow(LL a,LL b)
{
    LL tmp = 1;
    a%=mod;
    while(b)
    {
        if(b&1)
            tmp = tmp*a%mod;
        b>>=1;
        a = a*a%mod;
    }
    return tmp;
}
LL C(LL n,LL m)
{
    return f[n]*inv[n-m]%mod*inv[m]%mod;
}
void init()
{
    f[0] = 1;
    for(LL i = 1;i <= MAX_N;i++)
        f[i] = f[i-1]*i%mod;
    inv[MAX_N-1] = q_pow(f[MAX_N-1],mod-2);
    for(LL i = MAX_N-2;i >= 0;i--)
        inv[i] = (inv[i+1]*(i+1))%mod;

}

//lucas定理 mod是素数
LL n,m,p;

LL q_pow(LL a,LL b)
{
    LL tmp = 1;
    a%=mod;
    while(b)
    {
        if(b&1)
            tmp = tmp*a%mod;
        b>>=1;
        a = a*a%mod;
    }
    return tmp;
}
LL C(LL n, LL m)
{
    if(m > n) return 0;
    LL ans = 1;
    for(int i=1; i<=m; i++)
    {
        LL a = (n + i - m) % mod;
        LL b = i % mod;
        ans = ans * (a * q_pow(b, mod-2) % mod) % mod;
    }
    return ans;
}
LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    return C(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;
}
