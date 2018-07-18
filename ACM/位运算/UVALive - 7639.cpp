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
const int MAX_N = 1e4+10;
const int INF = 1<<30;
const LL inf = 1e17+10;
using namespace std;
int a[MAX_N];
LL b[MAX_N];
LL sum[MAX_N];
int main()
{
    int T,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Case %d:\n",ti++);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int len = r-l;
            LL ans = 0;
            for(int j = len;j;j = len&(j-1))
            {
                ans^=a[l+j];
            }
            ans^=a[l];
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*
*/
