#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX_N = 1e5+10;
const LL inf = 0x7fffffffffffffff;
LL N; int B;
map<LL,LL> q;
map<LL,LL>::reverse_iterator it;
int k,vis[20005];
int main()
{
    scanf("%d%lld",&B,&N);
    if(N == 1)
    {
        printf("1\n");
        return 0;
    }
    k = 0;
    LL tmp = N;
    for(int i = 2;i < B;i++)
    {
        if(N%i == 0) vis[k++] = i;
        while(tmp%i == 0)
        {
            tmp/=i;
        }
    }
    if(tmp!=1)
    {
        printf("impossible\n");
        return 0;
    }
    q[N] = 0;
    for(it = q.rbegin();it!=q.rend();it++)
    {
        LL now = it->first;
        LL tmp = it->second;
        for(int i = k-1;i >= 0;i--)
        {
            if(vis[i] < tmp%B) break;
            if(now%vis[i]) continue;
            if((inf-vis[i])/B < tmp) continue;
            LL fir = now/vis[i],sec = tmp*B+vis[i];
            if((!q[fir])||q[fir] > sec)
                q[fir] = sec;
        }
    }
    printf("%lld\n",q[1]);
    return 0;
}
/*
*/
