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
using namespace std;
int f[1005],k;
void Findf(LL x)
{
    k = 0;
    for(LL i = 2;i*i <= x;i++)
    {
        if(x%i == 0)
        {
            f[k++] = i;
            while(x%i == 0) x/=i;
        }
    }
    if(x > 1)
        f[k++] = x;
}
LL q[MAX_N];
LL solve(LL x)
{
    int t = 0;
    q[t++] = -1;
    for(int i = 0;i < k;i++)
    {
        int tl = t;
        for(int j = 0;j < tl;j++)
            q[t++] = -1*q[j]*f[i];
    }
    LL ans = 0;
    for(int i = 1;i < t;i++)
        ans+=x/q[i];
    return x-ans;
}
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        LL A,B,N;
        scanf("%lld%lld%lld",&A,&B,&N);
        Findf(N);
        printf("Case #%d: %lld\n",ti++,solve(B)-solve(A-1));
    }
    return 0;
}
/*
*/
