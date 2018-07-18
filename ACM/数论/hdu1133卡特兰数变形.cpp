#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int MAX_N = 500;
const LL p = 998244353;
int ans[501];
int main()
{
    int ti = 1;
    int n,m,i,j,s,c,k;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(ans,0,sizeof(ans));
        if(!n&&!m) break;
        printf("Test #%d:\n",ti++);
        if(n > m)
        {
            puts("0");
            continue;
        }
        ans[0] = 1;
        for(i = 2,c = 0;i <= m+n;i++)
        {
            for(j = 0;j <= MAX_N;j++)
            {
                s = ans[j]*i+c;
                ans[j] = s%10;
                c = (s-ans[j])/10;
            }
        }
        for(c = j = 0;j <= MAX_N;j++)
        {
            s = ans[j]*(m-n+1)+c;
            ans[j] = s%10;
            c = (s-ans[j])/10;
        }
        for(k = MAX_N;ans[k] == 0;k--);
        for(c = 0,j = k;j>=0;j--)
        {
            s = (ans[j]+10*c);
            c = s%(m+1);
            ans[j] = (s-c)/(m+1);
        }
        for(k = MAX_N;ans[k] == 0;k--);
        for(j = k;j >= 0;j--)
            printf("%d",ans[j]);
        printf("\n");
    }
    return 0;
}
