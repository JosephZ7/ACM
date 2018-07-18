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
const int MAX_N = 3e5+10;
const double eps = 1e-7;
const int mod = 10007;
const LL inf = 1LL<<60;
using namespace std;
int sum[MAX_N],a[MAX_N];
int n,k,ans;
int main()
{

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    int cnt = 0;
    sum[cnt++] = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == 0)
            sum[cnt++] = i;
    }
    sum[cnt++] = n+1;
    if(k >= cnt-1)
    {
        printf("%d\n",n);
        return 0;
    }
    ans = 0;
    for(int i = k+1;i < cnt;i++)
    {
        ans = max(ans,sum[i]-sum[i-k-1]-1);
    }
    cout<<ans<<endl;
    return 0;
}
