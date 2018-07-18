#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define INF 0x3f3f3f3f
const int MAX_N = 4e5+10;
const LL mod = 1e9+7;
const double eps = 1e-6;
using namespace std;
int a[MAX_N];
int ch[MAX_N<<5][2];
int sz;
void clr()
{
    sz = 1;
    memset(ch,0,sizeof(ch));
}
void Insert(int x)
{
    int u = 0;
    for(int i = 31;i >= 0;i--)
    {
        int zt = (x>>i)&1;
        if(!ch[u][zt])
            ch[u][zt] = ++sz;

        u = ch[u][zt];
    }
}
int getsum(int x)
{
    int u = 0;
    int sum = 0;
    for(int i = 31;i >= 0;i--)
    {
        int zt = (x>>i)&1;
        if(ch[u][!zt])
        {
            sum+=1<<i;
            u = ch[u][!zt];
        }
        else
            u = ch[u][zt];
    }
    return sum;
}
int L[MAX_N],R[MAX_N];
int main()
{
    clr();
    Insert(0);
    int N;
    scanf("%d",&N);
    int tmp = 0;
    for(int i = 1;i <= N;i++)
    {
        scanf("%d",&a[i]);
        tmp^=a[i];
        Insert(tmp);
        L[i] = max(L[i-1],getsum(tmp));
    }
    clr();
    Insert(0);
    tmp = 0;
    R[N+1] = 0;
    for(int j = N;j >= 1;j--)
    {
        Insert(a[j]);
        tmp^=a[j];
        R[j] = max(R[j+1],getsum(tmp));
    }
    int ans = 0;
    for(int i = 1;i < N;i++)
    {
        ans = max(ans,L[i]+R[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}
/*
*/
