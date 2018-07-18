#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#define LL long long
using namespace std;
const int MAX_N = 2e5 + 10;
int Euler(int n)
{
    if(n == 1) return 1;
    int ans = n,tmp = n;
    for(int i = 2;i*i <= tmp;i++)
    {
        if(tmp%i == 0)
        {
            ans=ans/i*(i-1);
            while(tmp%i == 0) tmp/=i;
        }
    }
    if(tmp > 1)
        ans= ans/tmp*(tmp-1);
    return ans;
}
int q[MAX_N],p[MAX_N];
int q_pow(int a,int b)
{
    int tmp = 1;
    while(b)
    {
        if(b&1)
            tmp = tmp*a;
        b>>=1;
        a = a*a;
    }
    return tmp;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m;
        scanf("%d",&m);
        int n = 1;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&p[i],&q[i]);
            n = n*q_pow(p[i],q[i]);
        }
        cout<<n<<endl;
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            if(n%i == 0)
            {
                cout<<i<<" "<<Euler(i)<<endl;
                ans+=Euler(i)*n/i;
            }
        }
        printf("ans:   %d\n",ans);
    }
    return 0;
}
/*
*/
