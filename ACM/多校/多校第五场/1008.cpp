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
const int MAX_N = 1e4+10;
const double eps = 1e-8;
const LL inf = 1e18+10;
using namespace std;
int a[105];
LL B[MAX_N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,cnt = 0;
        LL x;
        scanf("%d%d",&n,&m);
        for(int i = 0;i <= m;i++)
            scanf("%I64d",&B[i]);
        int i = 1;
        while(cnt < n)
        {
            while(B[i] == 0&&i <= m) i++;
            if(i == m+1) break;
            if(i&&B[i] > 0)
            {
                a[cnt++] = i;
                B[i]--;
                for(int j = i+1;j <= m;j++)
                    if(B[j] >= B[j-i]) B[j]-=B[j-i];
            }
            i = 1;
        }
        for(int i = 0;i < cnt;i++)
        {
            if(i == cnt-1)
                printf("%d\n",a[i]);
            else
                printf("%d ",a[i]);
        }
    }
    return 0;
}
/*
*/
