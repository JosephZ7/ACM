#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<stack>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX_N = 1e5+10;
const LL inf = 0x7fffffffffffffff;
int f[10][10],a[10][MAX_N];
int calc(int x,int k)
{
    int sum = 0;
    while(x)
    {
        sum+=f[x%10][k];
        x/=10;
    }
    return sum;
}
vector<LL> v;
void init()
{
    for(int i = 1;i <= 9;i++)
    {
        f[i][0] = 1;
        for(int j = 1;j <= 9;j++)
            f[i][j] = f[i][j-1]*i;
    }
    for(int i = 1;i <= 9;i++)
        for(int j = 0;j < MAX_N;j++)
            a[i][j] = calc(j,i);
}
int main()
{
    init();
    int T,K,X,ti = 1;
    scanf("%d",&T);
    while(T--)
    {
        v.clear();
        scanf("%d%d",&X,&K);
        for(int i = 0;i < MAX_N;i++)
            v.push_back(i-a[K][i]);
        int ans = 0;
        sort(v.begin(),v.end());
        for(int i = 0;i < MAX_N;i++)
        {
            LL d = a[K][i]-(LL)i*100000-X;
            ans+=upper_bound(v.begin(),v.end(),d)-lower_bound(v.begin(),v.end(),d);
        }
        printf("Case #%d: %d\n",ti++,ans-(X == 0));
    }

    return 0;
}
/*
*/
