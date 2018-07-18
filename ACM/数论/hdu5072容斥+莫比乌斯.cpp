#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<math.h>
#include<set>
#include<stack>
#include<vector>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX_N = 1e5+10;
const int INF = 1<<30;
using namespace std;
int a[MAX_N],mu[MAX_N],vis[MAX_N],f[MAX_N];
int pri[MAX_N],cnt,d[MAX_N],num[MAX_N];
void Mobius()
{
    memset(vis,0,sizeof(vis));
    mu[1] = 1;
    cnt = 0;
    for(int i = 2; i < MAX_N; i++)
    {
        if(!vis[i])
        {
            pri[cnt++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < cnt&&i*pri[j] < MAX_N; j++)
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
int main()
{
    int T;
    Mobius();
    scanf("%d",&T);
    while(T--)
    {
        memset(f,0,sizeof(f));
        memset(num,0,sizeof(num));
        memset(d,0,sizeof(d));
        int n,Ma = 0;
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
            f[a[i]]++;
            Ma = max(Ma,a[i]);
        }
        LL ans = (LL)n*(n-1)*(n-2)/6;
        for(int i = 1;i <= Ma;i++)
        {
            for(int j = i;j <= Ma;j+=i)
                num[i]+=f[j];
            for(int j = i;j <= Ma;j+=i)
                d[j]+=mu[i]*num[i];
        }
        LL tmp = 0;
        for(int i = 0;i < n;i++)
            if(a[i]!=1)
                tmp+=(LL)d[a[i]]*(n-d[a[i]]-1);
        printf("%lld\n",ans-tmp/2);
    }
    return 0;
}
