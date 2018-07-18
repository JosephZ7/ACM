#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <deque>
#include <iterator>
#include <vector>
#include <map>
#include <list>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <iostream>
#include <iomanip>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 3e4+10;
const double eps = 1e-8;
const LL mod = 1000000007;
using namespace std;
int fa[MAX_N],rk[MAX_N],ans[MAX_N];
void init(int N)
{
    for(int i = 0;i < N;i++)
    {
        fa[i] = i;
        rk[i] = 0;
        ans[i] = 1;
    }
}
int Find(int x)
{
    if(x == fa[x])
        return fa[x];
    else
        return fa[x] = Find(fa[x]);
}
void mix(int x,int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y)
        return ;
    if(rk[x] > rk[y])
    {
        fa[y] = x;
        ans[x] += ans[y];
    }
    else
    {
        fa[x] = y;
        if(rk[x] == rk[y])
            rk[y]++;
        ans[y]+=ans[x];
    }
}
int a[MAX_N];
int main()
{
    int N,M;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        if(N == 0&&M == 0)
            break;
        init(N);
        int num,x;
        for(int i = 0;i < M;i++)
        {
            scanf("%d",&num);
            for(int j = 0;j < num;j++)
            {
                scanf("%d",&a[j]);
            }
            for(int j = 1;j < num;j++)
            {
                mix(a[j],a[j-1]);
            }
        }
        int cnt = Find(0);
        printf("%d\n",ans[cnt]);
    }
    return 0;
}

