#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
const int MAX_N = 5e5+10;
const int mod = 100;
const double eps = 1e-6;
using namespace std;
LL a[MAX_N],b[MAX_N];
int pos[MAX_N],pre[MAX_N],nxt[MAX_N];
void print(int n)
{
    for(int i = 0;i <= n+1;i++)
    {
        printf("i:%d pre:%d  nxt:%d i:%d\n",i,pre[i],nxt[i],i);
    }
    cout<<endl;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k,x;
        scanf("%d%d",&n,&k);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&x);
            pos[x] = i;
            pre[i] = i-1;
            nxt[i] = i+1;
        }
        pre[0] = 0; nxt[n+1] = n+1;
        LL ans = 0;
        int l,r;
        for(int i = 1;i <= n;i++)
        {
            l = r = 0;
            x = pos[i];
            for(int j = x;l <= k&&j >= 1;j = pre[j])
                a[++l] = j-pre[j];
            for(int j = x;r <= k&&j <= n;j = nxt[j])
                b[++r] = nxt[j]-j;
            LL tmp = 0;
            for(int j = 1;j <= l;j++)
            {
                if(k-j+1 >=1&&k-j+1 <= r)
                {
                    //printf("i: %d a: %lld  i: %d b: %lld\n",j,a[j],k-j+1,b[k-j+1]);
                    tmp+=a[j]*b[k-j+1];
                }
            }
            ans+=tmp*i;
            pre[nxt[x]] = pre[x];
            nxt[pre[x]] = nxt[x];
            //print(n);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
*/
