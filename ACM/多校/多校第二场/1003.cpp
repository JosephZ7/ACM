#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
const int MAX_N = 2e5+5e4+10;
const LL mod = 1e9+7;
const double eps = 1e-6;
using namespace std;
LL a[MAX_N*2],Ma[MAX_N];
int b[MAX_N];
priority_queue<int> q;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(!q.empty()) q.pop();
        memset(Ma,0,sizeof(Ma));
        LL x;
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld",&x);
            a[i] = x-i;
        }
        int k = 0;
        for(int i = 1;i <= n;i++)
            scanf("%d",&b[i]);
        for(int i = n;i >= 1;i--)
            Ma[i] = max(Ma[i+1],a[i]);
        for(int i = 1;i <= n;i++)
            q.push(Ma[b[i]]);
        LL Max = 0;
        LL ans = 0;
        for(int i = n+1;i <= n<<1;i++)
        {
            if(Max < q.top())
            {
                a[i] = q.top()-i;
                q.pop();
            }
            else
                a[i] = Max-i;
            ans = (ans+a[i]+i)%mod;
            Max = max(Max,a[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
*/
