#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#define PI 3.1415926535898
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e4+10;
const double eps = 1e-7;
const int mod = 10007;
const LL inf = 1LL<<60;
using namespace std;
int N,M,K;
struct node
{
    int s,v;
}a[MAX_N];
int dp[MAX_N];
bool cmp(const node &x,const node &y)
{
    return x.v > y.v;
}
bool check(int x)
{
    for(int i = 0;i <= M;i++)
        dp[i] = 0;
    for(int i = 0;i < N;i++)
    {
        if(a[i].v < x) break;
        for(int j = M;j >= a[i].s;j--)
        {
            dp[j] = max(dp[j],dp[j-a[i].s]+a[i].v);
        }
    }
    for(int i = 0;i <= M;i++)
        if(dp[i] >= K)
            return true;
    return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d",&N,&M,&K);
    for(int i = 0;i < N;i++)
        scanf("%d%d",&a[i].s,&a[i].v);
    sort(a,a+N,cmp);
    int l = 0,r = 1000000;
    int ans = -1;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else
            r = mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
