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
struct node
{
    int id,w;
    bool operator < (const node &e)const
    {
        return w < e.w;
    }
}a[MAX_N];
int vis[MAX_N];
int main()
{
    int N;
    memset(vis,0,sizeof(vis));
    scanf("%d",&N);
    int Mi = INF;
    for(int i = 1;i <= N;i++)
    {
        scanf("%d",&a[i].w);
        a[i].id = i; Mi = min(Mi,a[i].w);
    }
    sort(a+1,a+N+1);
    int ans = 0;
    for(int i = 1;i <= N;i++)
    {
        //printf("%d\n",a[i].w);
        if(!vis[i])
        {
            vis[i] = 1;
            int tid = a[i].id,len = 1,mi = a[i].w;
            int sum = a[i].w;
            while(tid!=i)
            {
                len++;
                sum+=a[tid].w;
                vis[tid] = 1;
                mi = min(mi,a[tid].w);
                tid = a[tid].id;
            }
            ans+=min(sum+(len-2)*mi,sum+mi+(len+1)*Mi);
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
*/
