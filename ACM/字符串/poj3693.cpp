#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#define LL long long
#define INF 0x7fffffff
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MAX_N = 1e5+10;
const LL inf = 1e15+10;
const int mod = 1e9+7;
int wa[MAX_N],wb[MAX_N],wv[MAX_N],c[MAX_N];
int Rank[MAX_N],height[MAX_N],SA[MAX_N];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int n,int m)
{
    n++;
    int i,j,p,*x = wa,*y = wb,*t;
    for(i = 0;i < m;i++) c[i] = 0;
    for(i = 0;i < n;i++) c[x[i] = r[i]]++;
    for(i = 1;i < m;i++) c[i]+=c[i-1];
    for(i = n-1;i >= 0;i--) SA[--c[x[i]]] = i;
    for(j = 1,p = 1;p < n; j<<=1,m = p)
    {
        for(p = 0,i = n-j;i < n;i++) y[p++] = i;
        for(i = 0;i < n;i++) if(SA[i] >= j) y[p++] = SA[i]-j;

        for(i = 0;i < n;i++) wv[i] = x[y[i]];

        for(i = 0;i < m;i++) c[i]=0;
        for(i = 0;i < n;i++) c[wv[i]]++;
        for(i = 1;i < m;i++) c[i]+=c[i-1];
        for(i = n-1;i >= 0;i--) SA[--c[wv[i]]] = y[i];

        for(t = x,x = y,y = t,p = 1,x[SA[0]] = 0,i = 1;i < n;i++)
            x[SA[i]] = cmp(y,SA[i-1],SA[i],j) ? p-1:p++;
    }
    n--;
    int k = 0;
    for(i = 1;i <= n;i++) Rank[SA[i]] = i;
    for(i = 0;i < n;height[Rank[i++]] = k)
        for(k ? k--:0,j = SA[Rank[i]-1];r[i+k] == r[j+k];k++);
}
int dp[MAX_N][40];
void init(int len)
{
    int m = floor(log(len+0.0)/log(2.0));
    for (int i = 1; i <= len; i++) dp[i][0] = height[i];
    for(int i = 1;i <= m;i++)
    {
        for(int j = len;j;j--)
        {
            dp[j][i] = dp[j][i-1];
            if(j+(1<<(i-1)) <= len)
                dp[j][i] = min(dp[j][i],dp[j+(1<<(i-1))][i-1]);
        }
    }
}
int RMQ(int l, int r)
{
    l = Rank[l],r = Rank[r];
    if(l > r) swap(l,r); l++;
    int k = floor(log(r-l+1.0)/log(2.0));
    int a = dp[l][k], b = dp[r-(1<<k)+1][k];
    return min(a,b);
}
int a[MAX_N],ls[MAX_N];
char s[MAX_N];
int main()
{
    int ti = 1;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0] == '#') break;
        int len = strlen(s);
        for(int i = 0;i < len;i++)
            a[i] = s[i];
        a[len] = 0;
        da(a,len,130);
        init(len);
        int k = 0,Ma = 0;
        for(int l = 1;l < len;l++)
        {
            for(int i = 0;i+l < len;i+=l)
            {
                int r = RMQ(i,i+l);
                int lt = r/l+1;
                int f = i-(l-r%l);
                if(f >= 0&&r%l&&RMQ(f,f+l) >= r)
                    lt++;
                if(lt > Ma)
                {
                    Ma = lt;
                    k = 0;
                    ls[k++] = l;
                }
                else if(lt == Ma)
                    ls[k++] = l;
            }
        }
        int ln = -1,st;
        for(int i = 1;i <= len&&ln == -1;i++)
        {
            for(int j = 0;j < k;j++)
            {
                int l = ls[j];
                if(RMQ(SA[i],SA[i]+l) >= (Ma-1)*l)
                {
                    ln = l;
                    st = SA[i];
                    break;
                }
            }
        }
        printf("Case %d: ",ti++);
        for(int i = st,j = 0;j < Ma*ln;j++,i++)
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
/*
*/
