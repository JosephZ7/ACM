#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX_N = 1e3+10;
const LL p = 998244353;
LL a[MAX_N];
int ch[MAX_N<<5][2];
int sz;
int num[MAX_N<<5];
void clr()
{
    sz = 0;
    memset(num,0,sizeof(num));
    memset(ch,0,sizeof(ch));
}
void Insert(LL x)
{
    int u = 0;
    for(int i = 32;i >= 0;i--)
    {
        int zt = (x>>i)&1;
        if(!ch[u][zt])
            ch[u][zt] = ++sz;

        u = ch[u][zt];
        num[u]++;
    }
}
void del(LL x)
{
    int u = 0;
    for(int i = 32;i >= 0;i--)
    {
        u = ch[u][(x>>i)&1];
        num[u]--;
    }
}
LL query(LL x)
{
    int u = 0;
    LL ans = 0;
    for(int i = 32;i >= 0;i--)
    {
        int zt = (x>>i)&1;
        if(num[ch[u][zt^1]])
        {
            ans+=(1<<i);
            u = ch[u][zt^1];
        }
        else
            u = ch[u][zt];
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        clr();
        int n;
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%lld",&a[i]),Insert(a[i]);
        LL Ma = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(i == j) continue;
                del(a[i]); del(a[j]);
                Ma = max(Ma,query(a[i]+a[j]));
                Insert(a[i]); Insert(a[j]);
            }
        }
        printf("%lld\n",Ma);
    }
    return 0;
}
