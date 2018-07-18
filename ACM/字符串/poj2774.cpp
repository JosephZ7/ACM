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
const int MAX_N = 2e5+10;
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
int a[MAX_N],l;
char s1[MAX_N],s2[MAX_N];
int main()
{
    l = 0;
    scanf("%s",s1);
    scanf("%s",s2);
    int len = strlen(s1);
    for(int i = 0;i < len;i++)
        a[l++] = s1[i];
    len = strlen(s2);
    for(int i = 0;i < len;i++)
        a[l++] = s2[i];
    a[l] = 0;
    int ans = 0;
    da(a,l,233);
    len = strlen(s1);
    for(int i = 1;i < l;i++)
    {
        if(ans < height[i])
        {
            if(0<=SA[i-1]&&SA[i-1] < len&&SA[i] > len||0<=SA[i]&&SA[i] < len&&SA[i-1] > len)
                ans = height[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
*/
