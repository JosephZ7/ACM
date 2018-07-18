#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#define PI 3.141592653589793
#define LL long long
#define MAX 0x3fffffff
#define INF 0x3f3f3f3f
#define mem(a,v) memset(a,v,sizeof(a))
const int MAX_N = 1e6+10;
const double eps = 1e-7;
const LL mod = 999999997;
const LL inf = 1LL<<60;
using namespace std;
int ans[1005];
int n,m,sz,H[1005],S[1005],res;
int U[MAX_N],D[MAX_N],R[MAX_N],L[MAX_N],Row[MAX_N],Col[MAX_N];
void init()
{
    for(int i = 0;i <= m;i++)
    {
        S[i] = 0;
        U[i] = R[i] = i;
        L[i] = i-1;
        R[i] = i+1;
    }
    R[m] = 0;
    L[0] = m;
    sz = m+1;
    for(int i = 1;i <= n;i++)
        H[i] = -1;
}
void link(int r,int c)
{
    if(H[r] < 0)
        H[r] = L[sz] = R[sz] = sz;
    else
    {
        int p = L[H[r]];
        R[p] = sz;
        L[sz] = p;
        R[sz] = H[r];
        L[H[r]] = sz;
    }
    D[U[c]] = sz;
    U[sz] = U[c];
    U[c] = sz;
    D[sz] = c;
    Col[sz] = c;
    Row[sz++] = r;
}
void Remove(int c)
{
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for(int i = D[c];i!=c;i = D[i])
        for(int j = R[i];j!=i;j = R[j])
        {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
        }
}
void Resume(int c)
{
    L[R[c]] = R[L[c]] = c;
    for(int i = U[c];i!=c;i = U[i])
        for(int j = L[i];j != i;j = L[j])
            U[D[j]] = D[U[j]] = j;

}
bool Dance(int d)
{
    if(R[0] == 0)
    {
        res = d;
        printf("%d ",d);
        sort(ans,ans+d);
        for(int i = 0;i < d;i++)
            printf("%d ",ans[i]);
        printf("\n");
        return true;
    }
    int c = R[0];
    Remove(c);
    for(int i = D[c];i!=c;i = D[i])
    {
        ans[d] = Row[i];
        for(int j = R[i];j != i;j = R[j]) Remove(Col[j]);
        if(Dance(d+1)) return true;
        for(int j = L[i];j != i;j = L[j]) Resume(Col[j]);
    }
    Resume(c);
    return false;
}
int main()
{
    int c,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&c);
            for(int j = 0;j < c;j++)
            {
                scanf("%d",&v);
                link(i,v);
            }
        }
        if(!Dance(0))
            printf("NO\n");
    }
    return 0;
}
/*
6 7
3 1 4 7
2 1 4
3 4 5 7
3 3 5 6
4 2 3 6 7
2 2 7
*/
